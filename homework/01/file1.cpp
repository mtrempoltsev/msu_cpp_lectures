#include <chrono>
#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

class Timer
{
	using clock_t = chrono::high_resolution_clock;
	using microseconds = chrono::microseconds;
public:
	Timer()
		: start_(clock_t::now())
	{
	}

	~Timer()
	{
		const auto finish = clock_t::now();
		const auto us = chrono::duration_cast<microseconds> (finish - start_).count();
		cout << "Time = " << us << endl;
		system("pause");
	}

private:
	const clock_t::time_point start_;
};
int main()
{
	Timer t;
	volatile int sum;
	int **mas = new int* [10000];
	for (int i = 0; i < 10000; i++)
		mas[i] = new int[10000];
	srand(time(NULL));
	cout << "summes of lines: "<<endl;
	for (int i = 0; i < 10000; i++)
	{
		 sum = 0;
		for (int j = 0; j < 10000; j++)
		{
			mas[i][j] = rand() % 100;
			sum += mas[i][j];
		}
		cout << sum << " ";
	}
	cout << endl;
	cout << "summes of coloumnsпппрп: "<<endl;
	for (int i = 0; i < 10000; i++)
	{
		 sum = 0;
		for (int j = 0; j < 10000; j++)
			sum += mas[j][i];
		cout << sum << " ";
	}
	system("pause");
	return 0;
}