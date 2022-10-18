#include <iostream>
#include <iomanip>
#include <math.h>
#include <unistd.h>



long double f(long double x)
{
    return (2*(x*x*x))+(x*x)-(20*x)+12;
}

long double regula(long double a,long double b)
{
    long double x = a;

    for(int i=0;i<330;i++)
    {
        x = ((a*f(b)) - (b* f(a)))/(f(b)-f(a));

        if(f(x) == 0)
        {
            return x;
        }
        else if(f(a)*f(x)<0)
        {
            b = x;
        }
        else 
        {
            a=x;
        }
    }
    return x;

}

long double bisection(long double a, long double b)
{   
    long double x = a;

    for(int i=0;i<90000;i++)
    {
        x = (a+b)/2;
        if(f(x) == 0)
        {
            return x;
        }
        else if(f(x)*f(a)<0)
        {
            b =x;
        }
        else 
        {
            a =x;
        }
    }
    return x;
}

int main(void)
{
    std::cout<<std::setprecision(5)<<regula(2,3);
}