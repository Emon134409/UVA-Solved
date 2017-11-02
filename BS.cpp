
#include<bits/stdc++.h>

using namespace std;


int CeilIndex(int A[], int l, int r, int key)
{
    while (r - l > 1)
    {
        int m = A[l] + (r - l)/2;
        if (A[m]>=key)
            r = m;
        else
            l = m;
    }
    return r;
}


int main()

{
    int arr[]={5,7,10,15,1,9};
     int t[]={4,0,1,5,2,3};
    cout<<CeilIndex(arr,t[0],t[5],2)<<endl;
    return 0;
}
