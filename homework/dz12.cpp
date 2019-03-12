#include <iostream>
#include <chrono>
#define MAX 10000

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
	int ar[MAX][MAX];
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			ar[i][j]=rand() % 3;
	Timer t;

	int sum = 0;
    for(int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX; j++)
			sum += ar[j][i];
	return sum;
}