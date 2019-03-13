#include <chrono>
#include <iostream>
using namespace std;

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
	int size;
	cout << "¬веди размерность квадратной матрицы: ";
	cin >> size;
	int* M = new int[size];
	volatile int s = 0;
	Timer t;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			M[i * size + j] = i + j;
		}
	}
	system("pause>nul");
	return 0;
}