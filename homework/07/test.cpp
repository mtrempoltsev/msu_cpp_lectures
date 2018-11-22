#include <chrono>
#include <iostream>

#include <deque>
#include <list>
#include <vector>

#include "vector.h"

template <class T>
int benchmark(T& c)
{
    const int N = 1000000;

    int res = 0;

    for (int j = 0; j < 20; ++j)
    {
        for (int i = 0; i < N / 2; ++i)
        {
            c.push_back(i + j);
        }

        for (int i : c)
        {
            res += i;
        }

        c.resize(N / 4);

        for (int i : c)
        {
            res += i;
        }

        c.resize(N);

        for (int i : c)
        {
            res += i;
        }

        for (int i = 0; i < N / 2; ++i)
        {
            c.pop_back();
        }

        for (int i : c)
        {
            res += i;
        }

        for (int i = 0; i < N / 2; ++i)
        {
            c.push_back(i + j);
        }

        for (int i : c)
        {
            res += i;
        }

        c.clear();
    }

    return res;
}

template <class X, class Y>
void doCheckEqual(const X& actual, const Y& expected, size_t line)
{
    if (actual != expected)
    {
        std::cout << "at line " << line << ": " << actual << " != " << expected << '\n';
    }
}

#define checkEqual(x, y) do { doCheckEqual((x), (y), __LINE__); } while(0)
#define checkTrue(cond) do { if (!(cond)) std::cout << "at line " << __LINE__ << ": " << #cond << '\n'; } while(0)

static int Counter = 0;

struct Counterable
{
    Counterable()
    {
        ++Counter;
    }

    Counterable(const Counterable&)
    {
        ++Counter;
    }

    Counterable& operator=(const Counterable&)
    {
        ++Counter;
        return *this;
    }

    ~Counterable()
    {
        --Counter;
    }
};

class Timer
{
public:
    Timer()
        : start_(std::chrono::high_resolution_clock::now())
    {
    }

    ~Timer()
    {
        const auto finish = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(finish - start_).count() << " us" << std::endl;
    }

private:
    const std::chrono::high_resolution_clock::time_point start_;
};

int main()
{
    {
        Vector<int> v;

        checkTrue(v.empty());
        checkEqual(v.size(), 0);

        v.push_back(1);

        checkTrue(!v.empty());
        checkEqual(v.size(), 1);
        checkEqual(v[0], 1);

        v.pop_back();

        checkTrue(v.empty());
        checkEqual(v.size(), 0);

        v.push_back(3);
        v.push_back(2);
        v.push_back(1);

        checkTrue(!v.empty());
        checkEqual(v.size(), 3);
        checkEqual(v[0], 3);
        checkEqual(v[1], 2);
        checkEqual(v[2], 1);

        auto r = v.rbegin();
        checkTrue(r != v.rend());
        checkEqual(*r, 1);
        ++r;
        checkTrue(r != v.rend());
        checkEqual(*r, 2);
        ++r;
        checkTrue(r != v.rend());
        checkEqual(*r, 3);
        ++r;
        checkTrue(r == v.rend());

        auto f = v.begin();
        checkTrue(f != v.end());
        checkEqual(*f, 3);
        ++f;
        checkTrue(f != v.end());
        checkEqual(*f, 2);
        ++f;
        checkTrue(f != v.end());
        checkEqual(*f, 1);
        ++f;
        checkTrue(f == v.end());

        v.reserve(10000);
        checkEqual(v.size(), 3);
        checkTrue(v.capacity() >= 10000);

        const auto c = v.capacity();

        v.resize(2);
        checkEqual(v.size(), 2);
        checkEqual(v.capacity(), c);
        checkEqual(v[0], 3);
        checkEqual(v[1], 2);

        v.resize(3);
        checkEqual(v.size(), 3);
        checkEqual(v.capacity(), c);
        checkEqual(v[0], 3);
        checkEqual(v[1], 2);
        checkEqual(v[2], 0);

        v.resize(0);
        checkEqual(v.size(), 0);
        checkTrue(v.begin() == v.end());

        v.resize(2);
        checkEqual(v.size(), 2);
        checkEqual(v[0], 0);
        checkEqual(v[1], 0);
    }

    {
        Vector<Counterable> v;
        v.resize(100);

        checkEqual(Counter, 100);

        for (int i = 0; i < 100; ++i)
        {
            v.push_back(Counterable());
        }

        checkEqual(Counter, 200);

        v.resize(150);

        checkEqual(Counter, 150);

        for (int i = 0; i < 100; ++i)
        {
            v.pop_back();
        }

        checkEqual(Counter, 50);

        v.resize(25);

        checkEqual(Counter, 25);

        v.clear();

        checkEqual(Counter, 0);

        v.resize(25);

        checkEqual(Counter, 25);
    }

    checkEqual(Counter, 0);

    int res = 0;

    {
        std::vector<int> v;
        res += benchmark(v);
    }

    {
        std::cout << "Vector<int>: ";
        Timer t;
        Vector<int> v;
        res += benchmark(v);
    }

    {
        std::cout << "std::vector<int>: ";
        Timer t;
        std::vector<int> v;
        res += benchmark(v);
    }

    {
        std::cout << "std::deque<int>: ";
        Timer t;
        std::deque<int> v;
        res += benchmark(v);
    }

    {
        std::cout << "std::list<int>: ";
        Timer t;
        std::list<int> v;
        res += benchmark(v);
    }

    return res;
}
