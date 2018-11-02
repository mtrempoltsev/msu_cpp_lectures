#include <iostream>
#include <limits>
#include <sstream>

#include "bigint.h"

std::string toString(const BigInt& value)
{
    std::stringstream buf;
    buf << value;
    return buf.str();
}

void check(int64_t x, int64_t y)
{
    const BigInt bigX = x;
    const BigInt bigY = y;

    if (bigX + bigY != BigInt(x + y))
    {
        std::cout << x << " + " << y << " != " << x + y << " got " << bigX + bigY << '\n';
    }

    if (bigX - bigY != BigInt(x - y))
    {
        std::cout << x << " - " << y << " != " << x - y << " got " << bigX - bigY << '\n';
    }
}

void doCheckEqual(const BigInt& actual, const char* expected, size_t line)
{
    const auto str = toString(actual);
    if (str != expected)
    {
        std::cout << "at line " << line << ": " << str << " != " << expected << '\n';
    }
}

#define checkEqual(x, y) do { doCheckEqual((x), (y), __LINE__); } while(0)
#define checkTrue(cond) do { if (!(cond)) std::cout << "at line " << __LINE__ << ": " << #cond << '\n'; } while(0)

int main()
{
    BigInt x = 3;
    checkEqual(x, "3");
    BigInt y = x;
    checkEqual(y, "3");
    BigInt z;
    checkEqual(z, "0");

    checkEqual(BigInt(-10), "-10");

    checkTrue(x == y);
    checkTrue(y == x);
    checkTrue(x != z);
    checkTrue(z != x);

    z = y;
    checkEqual(z, "3");

    x = 100;
    checkEqual(x, "100");

    checkTrue(!(x < x));
    checkTrue(x < 200);
    checkTrue(BigInt(50) < x);
    checkTrue(BigInt(-500) < x);
    checkTrue(BigInt(-500) < BigInt(-200));

    checkTrue(!(x > x));
    checkTrue(BigInt(200) > x);
    checkTrue(x > BigInt(50));
    checkTrue(x > BigInt(-500));
    checkTrue(BigInt(-200) > BigInt(-500));

    checkTrue(x <= x);
    checkTrue(x <= 200);
    checkTrue(BigInt(50) <= x);
    checkTrue(BigInt(-500) <= x);
    checkTrue(BigInt(-500) <= BigInt(-200));

    checkTrue(x >= x);
    checkTrue(BigInt(200) >= x);
    checkTrue(x >= BigInt(50));
    checkTrue(x >= BigInt(-500));
    checkTrue(BigInt(-200) >= BigInt(-500));
    checkTrue(BigInt(0) == -BigInt(0));

    checkEqual(BigInt(10) + BigInt(10), "20");
    checkEqual(BigInt(-10) + BigInt(10), "0");
    checkEqual(BigInt(10) + BigInt(-10), "0");
    checkEqual(BigInt(-10) + BigInt(-10), "-20");

    checkEqual(BigInt(10) - BigInt(10), "0");
    checkEqual(BigInt(-10) - BigInt(10), "-20");
    checkEqual(BigInt(10) - BigInt(-10), "20");
    checkEqual(BigInt(-10) - BigInt(-10), "0");

    checkEqual(BigInt(0) + BigInt(-1), "-1");
    checkEqual(BigInt(0) - BigInt(1), "-1");

    checkEqual(BigInt(100) - BigInt(100), "0");
    checkEqual(BigInt(99) - BigInt(100), "-1");
    checkEqual(BigInt(10) - BigInt(11), "-1");
    checkEqual(BigInt(20) - BigInt(19), "1");

    for (int i = -21; i <= 21; ++i)
    {
        for (int j = -21; j <= 21; ++j)
        {
            check(i, j);
        }
    }

    const int64_t step = std::numeric_limits<uint32_t>::max() / 99;
    const int64_t lower = std::numeric_limits<int32_t>::min() + step;
    const int64_t upper = std::numeric_limits<int32_t>::max() - step;

    for (int64_t i = lower; i < upper; i += step)
    {
        for (int64_t j = -99; j < 99; ++j)
        {
            check(i, j);
        }
    }

    const BigInt big1 = std::numeric_limits<int64_t>::max();
    checkEqual(big1, "9223372036854775807");

    const BigInt big2 = big1 + big1;
    checkEqual(big2, "18446744073709551614");

    const BigInt big3 = big2 - big1;
    checkEqual(big3, "9223372036854775807");

    std::cout << "done\n";

    return 0;
}
