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

using namespace std;

int main() {
    const int n_rows = 100;
    const int n_cols = 100;

    using matrix = int[n_cols][n_rows];

    matrix M;
    Timer t;

    // filling the array
    for (int i = 0; i < n_cols; i++) {
        for (int j = 0; j < n_rows; j++) {
            M[i][j] = i + j;
        };
    };

    // finding the sum
    volatile int sum = 0;
    for (int i = 0; i < n_cols; i++) {
        for (int j = 0; j < n_rows; j++) {
            int sum = sum + M[i][j];
        };
    };

    cout << "sum = " << "s" << endl;

    return 0;
}
