#include<bits/stdc++.h>
using namespace std;

#define SIZE_N 32768
//#define SIZE_P 1000000

bool flag[SIZE_N+5];
//int primes[SIZE_P+5];
void seive()
{
    int i,j,total=0,val;

    //  for(i=2; i<=SIZE_N; i++) flag[i]=1;
    memset(flag,1,sizeof(flag));
    val=sqrt(SIZE_N)+1;

    for(i=2; i<val; i++)
        if(flag[i])
            for(j=i; j*i<=SIZE_N; j++) flag[i*j]=0;

//    for(i=2; i<=SIZE_N; i++)
//        if(flag[i])
//            primes[total++]=i;

}


int main()
{
    seive();

    int n,minimum,low,high;

    while(scanf("%d",&n) && n!=0)
    {
        minimum=0;

        if(flag[2] && flag[n-2]) minimum++;

        for(int i=3; i<=n/2; i+=2)
        {

            if(flag[i] && flag[n-i])
                minimum++;

        }

        printf("%d\n",minimum);
    }

    return 0;
}
