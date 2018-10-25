#include <iostream>

#include "matrix.h"

#define check_equal(x, y)  do { if ((x) != y) std::cout << "line " << __LINE__ << ": expected " << y << " got " << (x) << '\n'; } while(0)
#define check(cond) do { if (!(cond)) std::cout << "line " << __LINE__ << ": " << #cond << '\n'; } while(0)
#define check_throw(expr, err) do { try { expr; } catch (const err&) { break ; } catch (...) { } std::cout << "line " << __LINE__ << '\n'; } while(0)

int main()
{
    int n = 0;

    Matrix m1(2, 3);
    for (int row = 0; row < 2; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            m1[row][col] = ++n;
        }
    }

    check_equal(m1[0][0], 1);
    check_equal(m1[0][1], 2);
    check_equal(m1[0][2], 3);
    check_equal(m1[1][0], 4);
    check_equal(m1[1][1], 5);
    check_equal(m1[1][2], 6);

    check_equal(m1.getRows(), 2);
    check_equal(m1.getColumns(), 3);

    check_throw(m1[0][3], std::out_of_range);
    check_throw(m1[2][0], std::out_of_range);

    m1 *= 2;

    const Matrix& m2 = m1;

    check_equal(m2[0][0], 1 * 2);
    check_equal(m2[0][1], 2 * 2);
    check_equal(m2[0][2], 3 * 2);
    check_equal(m2[1][0], 4 * 2);
    check_equal(m2[1][1], 5 * 2);
    check_equal(m2[1][2], 6 * 2);

    Matrix m3(0, 0);
    check_throw(m3[0][0], std::out_of_range);

    const Matrix& m4 = m1;

    Matrix m5(2, 3);

    check(m1 == m1);
    check(m1 != m3);
    check(m1 == m4);
    check(m1 != m5);

    std::cout << "done\n";

    return 0;
}
