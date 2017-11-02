
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int arr[10];

    for(int i=0;i<5;i++)
        scanf("%d",&arr[i]);

    int c_sum=arr[0];
    int t_sum=arr[0];

    for(int i=1;i<5;i++)
    {
//        if(c_sum<0)
//            c_sum=arr[i];
//        else
        c_sum=max(arr[i],arr[i]+c_sum);
        t_sum=max(c_sum,t_sum);
    }

    printf("%d",t_sum);
    return 0;
}
