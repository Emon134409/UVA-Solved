
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    double  n,p;
    while(scanf("%lf %lf",&n,&p)!=EOF)
    {
        double a=exp(log(p)*(1/n));
        printf("%.0lf\n",a);
    }
    return 0;
}
