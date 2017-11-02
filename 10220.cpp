

#include<bits/stdc++.h>
#define size 3000

using namespace std;




int arr[size+5];

int factorial(int n)
{
  int i,j,temp,m,x;

  arr[0]=1;
  m=1;

  temp=0;

  for(int i=1;i<=n;i++)
  {
      for(int j=0;j<m;j++)
      {
          x=arr[j]*i+temp;
          arr[j]=x%10;
          temp=x/10;
      }

      while(temp>0)
      {

          arr[m]=temp%10;
          temp=temp/10;
          m++;
      }
  }

   int sum=0;

  for(i=m-1;i>=0;i--)
    sum=sum+arr[i];

   return sum;

}



int main()
{
    int n;

    while(scanf("%d",&n)!=EOF)
    {
           printf("%d\n",factorial(n));
    }

    return 0;
}

