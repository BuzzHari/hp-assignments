
#include <cilk/cilk.h>
#include <iostream>
#include <time.h>
#define SIZE 8
using namespace std;

int qsort(int A[], int beg, int end);
void partition(int A[], int beg, int end);

int main()
{
	int A[SIZE] = {10, 2, 1, 3, 5, 9, 0, 66};

	clock_t t;
	t = clock();
	partition(A, 0, SIZE - 1);
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
	for (int i = 0; i < SIZE; i++)
		cout << A[i] << " ";
    cout << endl;
	cout << "Time to execute: "<< time_taken << endl;

	return 0;
}

int qsort(int A[], int beg, int end)
{
	int p = A[end], i;
	int ind = beg - 1;
	int temp = 0;
	i = beg;
	while (i < end)
	{
		if (A[i] < p)
		{
			temp = A[ind + 1];
			A[ind + 1] = A[i];
			A[i] = temp;
			ind += 1;
		}
		i++;
	}
	ind += 1;
	temp = A[ind];
	A[ind] = A[end];
	A[end] = temp;
	return ind;
}

void partition(int A[], int beg, int end)
{
	if (beg < end)
	{
		int indmid = qsort(A, beg, end);
		cilk_spawn partition(A, beg, indmid - 1);
		partition(A, indmid + 1, end);
		cilk_sync;
	}
}
