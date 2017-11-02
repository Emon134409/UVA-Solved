
#include<iostream>
#include<cstdio>

using namespace std;

long long int gcd(long long int a,long long int b);
long long int C(long long int n,long long int k);

void Divbygcd(long long int &a,long long int &b)
{
    long long int g=gcd(a,b);

    printf("%d\n",g);

    a/=g;
    b/=g;
}

int main()
{
    long long int m,n;

    while(scanf("%lld %lld",&n,&m) && (n!=0 || m!=0))
    {
        long long int ans=C(n,m);
        printf("%lld\n",ans);
    }
    return 0;
}


long long int gcd(long long int a,long long int b)
{
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

 long long int C(long long int n,long long int k)
{
    long long int numerator=1,demon=1,toMul,toDiv;

    if(k>n/2) k=n-k;

    for(long long int i=k;i;i--)
    {
        toMul=n-k+i;
        toDiv=i;
        Divbygcd(toMul,toDiv);
        Divbygcd(numerator,toDiv);
        Divbygcd(toMul,demon);
        numerator*=toMul;
        demon*=toDiv;
    }

    return numerator/demon;
}



