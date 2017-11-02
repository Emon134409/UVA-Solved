
#include<bits/stdc++.h>
#define size 3000

using namespace std;




int arr[size+5];

void factorial(int n)
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

  printf("%d!\n",n);

  for(i=m-1;i>=0;i--)
    printf("%d",arr[i]);

  printf("\n");

}


int main()
{
    int n;

    while(scanf("%d",&n)!=EOF)
    {
           factorial(n);
    }

    return 0;
}

