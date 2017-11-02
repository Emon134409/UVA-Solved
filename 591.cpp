
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int arr[55];
    int n,sum,swapp;
    int sett=0;
    while(cin>>n && n!=0)
    {
        sum=0;
        swapp=0;

        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            sum=sum+arr[i];
        }

        int div=sum/n;

        for(int i=0; i<n; i++)
        {
              if(arr[i]>div)
              {
                  swapp=swapp+(arr[i]-div);
              }
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n",sett+1,swapp);

        printf("\n");
        sett++;

    }

    return 0;
}
