#include <iostream>
#include <chrono>
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
int main(){
    Timer t;
    int** f=new int*[10000];
    for(int i=0;i<10000;i++)
        f[i]=new int[10000];

    int sum=0;

    for(int i=0;i<10000;i++)
        for(int j=0;j<10000;j++)
            sum+=f[i][j];
    
    cout << "You are so cool!";
    return 0;
}