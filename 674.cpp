
#include<iostream>
#include<cstdio>

using namespace std;

int arr[]= {50,25,10,5,1};

int coinChange(int n);

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d",coinChange(n) );
    }
    return 0;
}

int coinChange(int n)
{
    int counter=0;
    int temp;
    for(int i=0; i<5; i++)
    {
        temp=arr[i];
        if(arr[i]>n) continue;
        else if(arr[i]==n) counter++;
        else
        {
            temp1=temp;
            for(int j=i; j<5; j++)
            {

                if(temp1>n)
                {
                    temp1=temp1-arr[j];
                    continue;
                }
                else if(temp==n){

                    counter++;

                }


                else

                    j--;


            }


        }

    }

    return counter;
}
