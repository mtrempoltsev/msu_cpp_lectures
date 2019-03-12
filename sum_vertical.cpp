#include <chrono>
#include <iostream>

class Timer
{
    using clock_t = std::chrono::high_resolution_clock;
    using microseconds = std::chrono::microseconds;
public:
    Timer()
        : start_(clock_t::now())
    {
    }

    ~Timer()
    {
        const auto finish = clock_t::now();
        const auto us = 
            std::chrono::duration_cast<microseconds>
                (finish - start_).count();
        std::cout << us << " us" << std::endl;
    }

private:
    const clock_t::time_point start_;
};


int main(){
    int size = 10000;
    int arr[size][size];

    for(int i = 0; i<size; i++)
        for (int j = 0; j < size; j++)
           arr[i][j] = j;

    Timer t;

    int sum = 0;

    for (int j = 0; j < size; j++)
        for (int i = 0; i < size; i++)
            sum += arr[i][j];
    
    return sum;
}

