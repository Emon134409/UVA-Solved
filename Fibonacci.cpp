#include<cstdio>

long long int fib(int n)
{
    /* Declare an array to store Fibonacci numbers. */
   long long int f[n+1];
    int i;

    /* 0th and 1st number of the series are 0 and 1*/
    f[0] = 0;
    f[1] = 1;

    for (i = 2; i <= n; i++)
    {
        /* Add the previous 2 numbers in the series
           and store it */
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];
}

long long int sqr(int n)
{
    return n*n;
}

int fastexp(int base,int powe)
{
    if(powe==0) return 1;
    else if(powe%2==0) return sqr(fastexp(base,powe/2));
    else return base*(fastexp(base,powe-1));
}

int main ()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
       long long int a=fib(n);
       int mod=fastexp(2,m);
       printf("%lld",a%mod);
    }
    return 0;
}
