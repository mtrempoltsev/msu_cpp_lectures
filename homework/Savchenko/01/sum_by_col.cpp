#include "Timer.hpp"
#include <iostream>

#define N 998

int sum_by_col()
{
    int arr[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            arr[i][j] = (i + j) % 100;
    
    Timer timer;
    
    int sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += arr[j][i];
    
    return sum;
    
}

int main()
{
    std::cout << sum_by_col() << std::endl;
}
