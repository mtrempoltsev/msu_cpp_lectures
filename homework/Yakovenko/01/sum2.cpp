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
	int size = 1000;
	int array[size][size];

	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			array[i][j] = 3;
	
	Timer t;
	
	int res = 0;
	
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			res += array[j][i];
	return res;
}

