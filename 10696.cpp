
#include<iostream>
#include<cstdio>
using namespace std;

long long int recursion(int n)
{
    if(n>100) return n-10;
    else if(n<=100) return recursion(recursion(n+11));


}

int main()
{
   int n;
   while(scanf("%d",&n)&& n!=0)
   {
       printf("f91(%d) = %lld\n",n,recursion(n));
   }

    return 0;
}
