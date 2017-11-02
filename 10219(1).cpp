
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long  double n,k,r;

    long double s1,s2;

    while(cin>>n>>k)
    {
        s1=0,s2=0;

        if(k>=n-k)  r=k;
        else r=n-k;

        for(long long int i=r+1; i<=n; i++)
        {

            s1=s1+log10l(i);
        }

        for(long long int i=1; i<=n-r; i++)
        {
            s2=s2+log10l(i);
        }

       // cout<<s1<<" "<<s2<<endl;

        cout<<(int)(floor(s1-s2)+1)<<endl;

    }
    return 0;
}
