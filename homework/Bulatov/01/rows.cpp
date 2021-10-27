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



int main()
{

	Timer t;
	
	
	int n=1000;	
	int arr[n][n] = {1};
	int i=0, j=0, sum=0;
	
	for(i=0; i<n; ++i)
		for(j=0; j<n; ++j){
			sum += arr[i][j];
		}
	
	return sum;

}
