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
		system("pause>nul");
	}

private:
	const clock_t::time_point start_;
};

int main()
{
	setlocale(LC_ALL, "");
	int size;
	std::cout << "¬веди размерность квадратной матрицы: ";
	std::cin >> size;
	int** M = new int*[size];
	for (int i = 0; i < size; i++) {
		M[i] = new int[size];
		for (int j = 0; j < size; j++) {
			M[i][j] = i + j;
		}
	}
	volatile int s = 0;
	Timer t;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			s += M[j][i];
		}
	}
	return 0;
}