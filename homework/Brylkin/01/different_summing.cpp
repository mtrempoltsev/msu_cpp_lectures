#include <iostream>
#include "profile.h"
#include <cstdint>
#include <random>

using namespace std;

int main()
{
    std::cerr << "Starting program!" << std::endl;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int8_t> dis(-10, 10);
    int64_t sum1 = 0, sum2 = 0;
    const int N = 10000;
    int8_t** arr = new int8_t*[N];
    for (int i = 0; i < N; ++i)
    {
        arr[i] = new int8_t[N];
    }
    std::cerr << "Memory allocated!" << std::endl;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            arr[i][j] = dis(gen);
        }
    }
    std::cerr << "Elements initialized!" << std::endl;
    // считаем сумму
    {
        LOG_DURATION("Summing by rows");
        for (int k = 0; k < N/100; ++k)
        {
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < N; ++j)
                {
                    sum1 += arr[i][j];
                }
            }
        }
    }
    {
        LOG_DURATION("Summing by cols");
        for (int k = 0; k < N/100; ++k)
        {
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < N; ++j)
                {
                    sum2 += arr[j][i];
                }
            }
        }
    }
    std::cerr << "Summing ended!" << std::endl;
    for (int i = 0; i < N; ++i)
    {
        delete [] arr[i];
    }
    delete[] arr;
    std::cerr << "Memory cleared!" << std::endl;
    std::cout << "Sum1 = " << sum1 << "; Sum2 = " << sum2;
    return 0;
}
