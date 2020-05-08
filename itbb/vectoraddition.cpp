#include <iostream>
#include <algorithm>
#include <numeric>

#include <tbb/tbb.h>

struct Sum {
    int value;

    Sum() : value(0) {}
    Sum(Sum&s, tbb::split) : value(0) {}

    void operator()(const tbb::blocked_range<std::vector<int>::iterator>& r) {

        value = std::accumulate(r.begin(), r.end(), value);
    }

    void join(Sum& rhs) { value += rhs.value; }
};


int main()
{   
    std::vector<int> arr(50);
    std::fill(arr.begin(), arr.end(), 1);

    Sum sum;
    tbb::parallel_reduce(tbb::blocked_range<std::vector<int>::iterator>(arr.begin(), arr.end()), sum);

    std::cout << sum.value << std::endl;

    return 0;  
}
