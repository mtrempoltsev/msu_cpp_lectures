#include <iostream>
#include <chrono>

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
using namespace std;
int main() {
    int n;
    n = 500;
   int arr[n][n];
   long long int sum = 0;
   Timer t;
   for (int i = 0; i < n; i++){
       for (int k = 0; k < n; k++){
           arr[i][k] = i+k+1;
           sum+=arr[i][k];
       }
   }
   cout << sum;

    return 0;
}