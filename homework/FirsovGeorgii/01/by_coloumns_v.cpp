#include <chrono>
#include <iostream>

const int SIZE = 1000;

class Timer
{
    using clock_t = std::chrono::high_resolution_clock;
    using microseconds = std::chrono::microseconds;
public:
    Timer() : start_(clock_t::now())
    {}

    ~Timer()
    {
        const auto finish = clock_t::now();
        const auto us = std::chrono::duration_cast<microseconds>(finish - start_).count();
        std::cout << us << " us" << std::endl;
    }

private:
    const clock_t::time_point start_;
};

int main()
{
    std::cout << "h";
    int arr[SIZE][SIZE];
    int s = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            arr[i][j] = 2;
    Timer t;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            s += arr[j][i];
    return s;
}