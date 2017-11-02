#include<iostream>
#include<cstdio>

using namespace std;


long long int sqr(long long int a)
{
    return a*a;
}
int bigmod(int b,int p,int m)
{
    if(p==0) return 1;
    else if(p%2==0)  return sqr((bigmod(b,p/2,m)))%m;
    else return ((b%m)*bigmod(b,p-1,m))%m;
}
int main()
{

    int b,p,m;

    while(scanf("%d %d %d",&b,&p,&m)!=EOF)
    {
        cout<< bigmod(b,p,m)<<endl;
    }

    return 0;
}
