#include <bits/stdc++.h>
using namespace std;

#define SIZE_N 48255000
#define SIZE_P 48255000

bool flag[SIZE_N+5];
int primes[SIZE_P+5];

int seive()
{
    int i,j,total=0,val;
    for(i=2; i<=SIZE_N; i++) flag[i]=1;
    val=sqrt(SIZE_N)+1;
    for(i=2; i<val; i++) if(flag[i]) for(j=i; j*i<=SIZE_N; j++) flag[i*j]=0;

    for(i=2; i<=SIZE_N; i++) if(flag[i]) primes[total++]=i;
    return total;
}


int divisor(int N)
{
    int i,val,counter,sum;
    val=sqrt(N)+1;
    sum=1;
    for(i=0; primes[i]<val; i++)
    {
        if(N%primes[i]==0)
        {
            counter=0;
            while(N%primes[i]==0)
            {
                N/=primes[i];
                counter++;
            }
            sum*=(counter+1);
        }
    }
    if(N>1) sum=sum*2;
    return sum;
}


int main()
{
    int total=seive();
    int n;
    int L,U;
//    while(scanf("%d",&n)==1)
//    {
//        printf("%d No Of divisor:%d\n",n,divisor(n));
//    }

      scanf("%d",&n);

      for(int j=0;j<n;j++)
      {
          scanf("%d %d",&L,&U);

          int maximum=-1;
          int divi;
          int number;

          for( int i=L;i<=U;i++)
          {
              divi=divisor(i);

              if(divi>maximum)
              {
                  maximum=divi;
                  number=i;
              }
              else if(divi==maximum)
              {
                  number=min(number,i);
              }
          }
          if(maximum==-1) maximum=0;

          printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,number,maximum);

      }
    return 0;
}
