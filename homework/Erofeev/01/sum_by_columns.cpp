#include <chrono>
#include <iostream>

using ll = long long;

const int SIZE = 10000;
int matrix[SIZE][SIZE];
volatile ll sum = 0;

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
        std::cout << us << std::endl;
    }

private:
    const clock_t::time_point start_;
};

int main() {
    for (int i = 0; i < SIZE; i++) 
        for (int j = 0; j < SIZE; j++) 
            matrix[j][i] = i + j;

    Timer t;
    sum = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            sum += matrix[j][i];    
}
