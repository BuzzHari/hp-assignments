#include <cilk/cilk.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{

    int size = 4;
    clock_t t, k;
    for (int i = 8; i <= 128; i = i * 2) 
    {
        size = i;
        int A[size];
        int B[size];
        A[:] = i;
        B[:] = i + 5;
        A[:] = A[:] + A[:];
        int init = 0;
        int end = i;
        // int i = 0;

        t = clock();
        _Cilk_for(int i = init; i < end; ++i)
        {
            A[i] = B[i] + i;
        }
        t = clock() - t;
        double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
        cout << time_taken << "s taken by cilk_for loop" << endl;
    }
    return 0;
}
