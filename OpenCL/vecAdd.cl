#pragma OPENCL EXTENSION cl_khr_fp64 : enable

__kernel void vecAdd( __global double *a,
                      __global double *b,
                      __global double *c,
                      const unsigned int len)
{
    //Getting our global therad ID
    int id = get_global_id(0);

    if(id < len)
        c[id] = a[id] + b[id];
}
