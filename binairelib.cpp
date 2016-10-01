#include "binairelib.h"

double MyPow(const double &x, int i)
{
    return x * MyPow(x, i-1);
}
/*
double MyCos(double x)
{
    double integral(0);
    integral = 1.0/479001600*MyPow(x, 12);
}
*/
