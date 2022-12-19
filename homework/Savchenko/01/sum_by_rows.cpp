#include "Timer.hpp"
#include <iostream>

#define N 998

int sum_by_rows()
{
    int arr[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            arr[i][j] = (i + j) % 100;
    
    Timer timer;
    
    int sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += arr[i][j];
    
    return sum;
    
}

int main()
{
    std::cout << sum_by_rows() << std::endl;
}
