#include "Timer.h"

#include <iostream>

#define SIZE 506


int my_function()

{

	volatile int arr[SIZE][SIZE];
	volatile int sum = 0;

	for (int i = 0; i < SIZE; i++)

		for (int j = 0; j < SIZE; j++)

			arr[i][j] = 1;

	Timer t;

	for (int i = 0; i < SIZE; i++)

		for (int j = 0; j < SIZE; j++)

			sum += arr[j][i];

	return sum;

}


int main()

{

	std::cout << my_function() << std:: endl;

	int n;

	std::cin >> n;

	return 0;

}

	