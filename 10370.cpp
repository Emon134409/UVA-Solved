
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n;
    double avg;
    int counter,sum;

    int arr[1005];
    int t;
    scanf("%d",&t);

    for(int j=0; j<t; j++)
    {

        scanf("%d",&n);

        sum=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
            sum=sum+arr[i];
        }
        counter=0;

        avg=double(sum)/n;

        for(int i=0; i<n; i++)
        {
            if(arr[i]>avg)
            {
                counter++;
            }
        }
        double per=((double)(counter)/n)*100;

        printf("%.3lf%%\n",per);


    }

    return 0;
}
