
#include<cstdio>
int main()
{
    int n;
    long long int ans,m;
    while(scanf("%d",&n) && n>=0)
    {
        m=n-2;
        ans=(n*2)+((m*(m+1))/2);
        printf("%lld\n",ans);
    }
    return 0;
}
