
#ifndef sum_by_rows_hpp
#define sum_by_rows_hpp

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

#endif /* sum_by_rows_hpp */
