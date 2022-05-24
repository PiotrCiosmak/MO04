#ifndef MO04_FUNKCJE_HPP
#define MO04_FUNKCJE_HPP

double fun1(double x, double y, double z)
{
    return x * x + y * y + z * z - 2;
}

double fun2(double x, double y, double)
{
    return x * x + y * y - 1;
}

double fun3(double x, double y, double)
{
    return x * x - y;
}

double fun1_dx(double x, double, double)
{
    return 2 * x;
}

double fun2_dx(double x, double, double)
{
    return 2 * x;
}

double fun3_dx(double x, double, double)
{
    return 2 * x;
}

double fun1_dy(double, double y, double)
{
    return 2 * y;
}

double fun2_dy(double, double y, double)
{
    return 2 * y;
}

double fun3_dy(double, double, double)
{
    return -1;
}

double fun1_dz(double, double, double z)
{
    return 2 * z;
}

double fun2_dz(double, double y, double)
{
    return 0;
}

double fun3_dz(double, double, double)
{
    return 0;
}

double max(double a, double b, double c)
{
    double max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    return max;
}

void setJakobyMatrix(double JakobyMatrix[][3], double x, double y, double z)
{
    JakobyMatrix[0][0] = fun1_dx(x, y, z);
    JakobyMatrix[0][1] = fun1_dy(x, y, z);
    JakobyMatrix[0][2] = fun1_dz(x, y, z);
    JakobyMatrix[1][0] = fun2_dx(x, y, z);
    JakobyMatrix[1][1] = fun2_dy(x, y, z);
    JakobyMatrix[1][2] = fun2_dz(x, y, z);
    JakobyMatrix[2][0] = fun3_dx(x, y, z);
    JakobyMatrix[2][1] = fun3_dy(x, y, z);
    JakobyMatrix[2][2] = fun3_dz(x, y, z);
}

#endif //MO04_FUNKCJE_HPP