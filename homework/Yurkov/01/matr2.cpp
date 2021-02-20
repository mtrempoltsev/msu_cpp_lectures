#include <chrono>
#include <iostream>
//по строкам
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
    const int n = 1000;
    int mas[n][n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            mas[i][j]=6;

    Timer t;
    int sum=0;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            sum+=mas[j][i]; 

    return sum;
}