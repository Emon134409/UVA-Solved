#include<iostream>
#include<cstdio>

using namespace std;


void multiply(unsigned long long int F[2][2],unsigned long long int M[2][2]);

void power(unsigned long long int F[2][2], int n);


unsigned long long int fib(int n)
{
 unsigned long long int F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}


void power(unsigned long long int F[2][2], int n)
{
  if( n == 0 || n == 1)
      return;
 unsigned long long int M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}

void multiply(unsigned long long int F[2][2],unsigned long long int M[2][2])
{
 unsigned long long int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
 unsigned long long int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
 unsigned long long int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
 unsigned long long int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

unsigned long long int sqr(int n)
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
       unsigned long long int a=fib(n);
       int mod=fastexp(2,m);
       printf("%lld\n",a%mod);
    }
    return 0;
}

