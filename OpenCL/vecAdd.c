/*
 * reference: https://www.olcf.ornl.gov/tutorials/opencl-vector-addition/
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <CL/opencl.h>

#define MAX_KERNEL_SIZE 1024*1024

int main(int argc, char* argv[]) {

    char *kernel_source = (char*) malloc(sizeof(char) * MAX_KERNEL_SIZE );
    size_t kernel_size;

    FILE *fp = fopen("vecAdd.cl", "r");
    if(!fp) {
        perror("Kernel not available\n");
        return EXIT_FAILURE;
    }

    kernel_size = fread(kernel_source, sizeof(char), MAX_KERNEL_SIZE, fp);
    fclose(fp);
    unsigned int len; 
    if(argc > 1)
        len = atoi(argv[1]);
    else
        len = 100000;

    // Host input vectors
    int *h_a;
    int *h_b;
    // Host output vectors
    int *h_c;

    // Device input buffers
    cl_mem d_a;
    cl_mem d_b;
    // Device output buffers
    cl_mem d_c;

    cl_platform_id *cpPlatform;  // OpenCL platform
    cl_device_id device_id;     // device ID
    cl_context context;         // context
    cl_command_queue queue;     // command queue
    cl_program program;         // program
    cl_kernel kernel;           // kernel

    // Size, in bytes of each vector
    size_t bytes = len*sizeof(int);
    printf("Bytes: %lu\n",bytes);

    h_a = (int*) malloc(bytes);
    
    if(!h_a){
        printf("h_a malloc error\n");
        return 0;
    }

    h_b = (int*) malloc(bytes);
    
    if(!h_b){
        printf("h_b malloc error\n");
        return 0;
    }
    
    h_c = (int*) malloc(bytes);
    
    if(!h_c){
        printf("h_c malloc error\n");
        return 0;
    }
    // Initializing the input host vectors.

    for(size_t i = 0; i < len; ++i) {
        h_a[i] = 17;
        h_b[i] = 25;
    }

    size_t global_size, local_size;
    cl_int err;
    cl_uint num_platforms;
    // Number of work items in each local work group
    local_size = 512;

    global_size = ceil(len / (float)local_size) * local_size;
    printf("Global Size: %lu\n", global_size);
    // Get Platform id.
    err = clGetPlatformIDs(0, NULL, &num_platforms);

    if(err != CL_SUCCESS || num_platforms == 0){
        perror("Couldn't get platforms\n");
        return EXIT_FAILURE;
    }

    printf("Number of platforms: %u\n", num_platforms);

    cpPlatform = (cl_platform_id*) malloc(sizeof(cl_platform_id)*num_platforms);
    err = clGetPlatformIDs(num_platforms, cpPlatform, NULL);
    
    if(err != CL_SUCCESS){
        perror("Couldn't get platforms\n");
        return EXIT_FAILURE;
    }
    
    /* Platform Info Start */  
    cl_platform_info param_name[5] = {CL_PLATFORM_PROFILE,
                                      CL_PLATFORM_VERSION,
                                      CL_PLATFORM_NAME,
                                      CL_PLATFORM_VENDOR, 
                                      CL_PLATFORM_EXTENSIONS};
    size_t param_value_size;
    
    for(int i = 0; i <num_platforms; ++i) {
        printf("\nPlatform ID: %d\n", i+1);
        for(int j = 0; j < 5; ++j) {
            // Getting size of param.
            err = clGetPlatformInfo(cpPlatform[i], param_name[j], 0, NULL, &param_value_size );
            char *param_value = (char*) malloc(sizeof(char) * param_value_size);
            // Getting param info.
            err = clGetPlatformInfo(cpPlatform[i], param_name[j], param_value_size, param_value,NULL );
            printf("%s\n", param_value);
            free(param_value);
        }
    }
    printf("\n\n");
    /* Platform Info End*/ 
    
    // Get ID for the device.
    err = clGetDeviceIDs(cpPlatform[0], CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);

    if(err != CL_SUCCESS) {
        perror("Not able to get device ID\n");
        printf("Error Code: %d\n", err);
        return EXIT_FAILURE;
    }

    // Creating a context.
    // Contexts are used by the OpenCL runtime for managing objects such as 
    // command-queues, memory, program and kernel objects and fro executing 
    // kernels on one or more devices specified in the context.
    context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &err);

    if(err != CL_SUCCESS) {
        perror("Problem creating context\n");
        printf("Error Code: %d\n", err);
        return EXIT_FAILURE;
    }
    // Creatign a command queue.
    queue = clCreateCommandQueueWithProperties(context, device_id, 0, &err);
    
    if(err != CL_SUCCESS) {
        perror("Problem creating command queue\n");
        printf("Error Code: %d\n", err);
        return EXIT_FAILURE;
    }

    // Creating compute program from kernel source.
    // Creates a program object for a context,
    // and loads the source code specified by kernel_source.
    program = clCreateProgramWithSource(context, 1, (const char **)& kernel_source,
            (const size_t *)& kernel_size , &err);
    
    if(err != CL_SUCCESS) {
        perror("Problem creating program\n");
        printf("Error Code: %d\n", err);
        return EXIT_FAILURE;
    }

    // Building the program executable
    // Builds(compiles and links) a program executable from the program source or binary.
    err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
     
    if(err != CL_SUCCESS) {
        perror("Problem building program executable.\n");
        printf("Error Code: %d\n", err);
        if(err == CL_BUILD_PROGRAM_FAILURE) {
            size_t log_siz;
            clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_siz );
            char *log = (char *) malloc(log_siz);
            clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, log_siz, log, NULL);
            printf("%s\n", log);
        }
        return EXIT_FAILURE;
    }

    // Create teh compute kernel in the program we wish to run.
    // Creates a kernel object.
    // A kernel is a function declared in a program. Is is identified
    // by the __kernel qualifier applied to any function in a program.
    // A kernel object encapsulates the specific __kernel function declared in a 
    // program and the argument calus to be used when executing this __kernel function.
    kernel = clCreateKernel(program, "vecAdd", &err);
    
    if(err != CL_SUCCESS) {
        perror("Problem creating kernel.\n");
        printf("Error Code: %d\n", err);
        return EXIT_FAILURE;
    }
    
    // Creating input and output arrays in device memory for calculations.
    d_a = clCreateBuffer(context, CL_MEM_READ_ONLY, bytes, NULL, &err) ;
    if(err != CL_SUCCESS) {
        perror("Problem creating buffer d_a.\n");
        printf("Error Code: %d\n", err);
        return EXIT_FAILURE;
    }
    
    d_b = clCreateBuffer(context, CL_MEM_READ_ONLY, bytes, NULL, &err) ;
    if(err != CL_SUCCESS) {
        perror("Problem creating buffer d_b.\n");
        printf("Error Code: %d\n", err);
        return EXIT_FAILURE;
    }
    
    d_c = clCreateBuffer(context, CL_MEM_WRITE_ONLY, bytes, NULL, &err) ;
    if(err != CL_SUCCESS) {
        perror("Problem creating buffer d_c.\n");
        printf("Error Code: %d\n", err);
        return EXIT_FAILURE;
    }
    // Writing our data set into the device input buffer.
    // Enqueue commands to write to a buffer object from host memory.
    err = clEnqueueWriteBuffer(queue, d_a, CL_TRUE, 0, bytes, h_a, 0, NULL, NULL);
    err |= clEnqueueWriteBuffer(queue, d_b, CL_TRUE, 0, bytes, h_b, 0, NULL, NULL);
    
    if(err != CL_SUCCESS) {
        perror("Problem enqueing writes.\n");
        EXIT_FAILURE;
    }

    // Setting the arguments to the compute kernel.
    err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &d_a);
    err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &d_b);
    err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &d_c);
    err |= clSetKernelArg(kernel, 3, sizeof(unsigned int), &len);
    
    if(err != CL_SUCCESS) {
        perror("Problem setting arguments.\n");
        printf("Error Code: %d\n", err);
        return EXIT_FAILURE;
    }

    // Executing the kernel over the data set.
    // Enqueues a command to execute a kernel on a device. 
    err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &global_size,
            &local_size, 0, NULL, NULL);
    
    if(err != CL_SUCCESS) {
        perror("Problem enqueing kernel.\n");
        printf("Error Code: %d\n", err);
        return EXIT_FAILURE;
    }
    
    // Waiting for the command queue to get serviced before reading back results.
    // Blocks until all previousl queued OpenCL commands in a command-queue
    // are issued the devices and have completed.
    err = clFinish(queue);
    if(err != CL_SUCCESS) {
        perror("Problem with CL Finish.\n");
        printf("Error Code: %d\n", err);
        return EXIT_FAILURE;
    }
    // Read teh reuslts from the device.
    err = clEnqueueReadBuffer(queue, d_c, CL_TRUE, 0, bytes, h_c, 0, NULL, NULL);
    if(err != CL_SUCCESS) {
        perror("Problem reading from buffer.\n");
        printf("Error Code: %d\n", err);
        return EXIT_FAILURE;
    }
    
    size_t sum = 0;
    for(size_t i = 0; i < len; ++i) {
        sum += h_c[i];
       // printf("Sum: %lu\n", sum);
    }
    printf("Result: %lu\n", sum/len); // Should print 42.

    // Releasing OpenCL resources.
    
    clReleaseMemObject(d_a);
    clReleaseMemObject(d_b);
    clReleaseMemObject(d_c);
    clReleaseProgram(program);
    clReleaseKernel(kernel);
    clReleaseCommandQueue(queue);
    clReleaseContext(context);

    // Releasing host memory.
    free(h_a);
    free(h_b);
    free(h_c);
    return 0;
}
