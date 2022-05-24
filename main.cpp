#include <iostream>
#include "funkcje.hpp"
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    constexpr double TOLX{1e-8}, TOLF{1e-8}, MAX_N{30};
    double x{1}, y{1}, z{1}, value[3]{fun1(x, y, z), fun2(x, y, z), fun3(x, y, z)};
    double JakobyMatrix[3][3]{}, errorEstimator, residuum, change[3];

    for (int n = 0; n < MAX_N; ++n)
    {
        for (int i = 0; i < 3; ++i)
        {
            change[i] = 0;
        }
        setJakobyMatrix(JakobyMatrix, x, y, z);
        change[0] = x / 2 - ((y * y + 1) / (4 * y * x + 2 * x));
        change[1] = (y * y + y - 1) / (2 * y + 1);
        change[2] = (z * z - 1) / (2 * z);

        x -= change[0];
        y -= change[1];
        z -= change[2];

        errorEstimator = max(fabs(change[0]), fabs(change[1]), fabs(change[2]));
        residuum = max(fabs(value[0]), fabs(value[1]), fabs(value[2]));

        cout << setprecision(2) << n + 1 << ". x = " << setprecision(5) << x << " | y = " << setprecision(5) << y
             << " | z = " << setprecision(5) << z << " | estymator bledu = " << setprecision(5) << errorEstimator
             << " | residuum = " << setprecision(5) << residuum << endl;

        if (errorEstimator <= TOLX && residuum <= TOLF)
            break;

        value[0] = fun1(x, y, z);
        value[1] = fun2(x, y, z);
        value[2] = fun3(x, y, z);
    }
}