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


const int SIZE = 1000;

int main() {
	
	int result = 0;

	int arr [SIZE][SIZE];

	for (int i =0; i<SIZE; i++) 
		for (int j = 0 ;j < SIZE; j++) 
		       arr[i][j] = 5;
	/*stolbec*/
	Timer t;
	for (int i = 0; i< SIZE; i++)
		for (int j = 0; j< SIZE; j++)
			result+=arr[i][j];	

	return result;
}

