
#include<bits/stdc++.h>
#define size 3000

using namespace std;

int arr[size+5];
int number[size+5];

void fillup(int n)
{
    for(int i=n+2;i<=2*n;i++){
        number[i-n-2]=i;

    }

}



void factorial(int n)
{
  int i,j,temp,m,x;

  arr[0]=1;
  m=1;

  int g;
  temp=0;

  for( i=n+2;i<=2*n;i++)
  {
      g=i;

      if(g%2==0) g=2;

      for(int j=0;j<m;j++)
      {
          x=arr[j]*g+temp;
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
//
//

//  {
//      for(int j=0;j<m;j++)
//      {
//          x=arr[j]*i+temp;
//          arr[j]=x%10;
//          temp=x/10;
//      }
//
//      while(temp>0)
//      {
//
//          arr[m]=temp%10;
//          temp=temp/10;
//          m++;
//      }
//  }

  for(i=m-1;i>=0;i--)
    printf("%d",arr[i]);

  printf("\n");

}


int main()
{
    int n;

    while(scanf("%d",&n)!=EOF)
    {
        fillup(n);
           factorial(n);
    }

    return 0;
}

