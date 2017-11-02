
#include<bits/stdc++.h>
using namespace std;

int is_prime(int n)
{
    for (int i=3; i*i<=n; i+=2) // start from 3, jump 2 numbers
        if (n%i == 0) // no need to check even numbers
            return 0;
    return 1;
}

int main()
{

    int n,minimum,low,high;

    while(scanf("%d",&n) && n!=0)
    {
        minimum=INT_MIN;

        for(int i=3; i<=n/2; i+=2)
        {

            if(is_prime(i) && is_prime(n-i) )

                if(((n-i)-i)>minimum)
                {
                    minimum=((n-i)-i);

                    low=i;
                    high=n-i;
                //   cout<<minimum<<" "<<low<<" "<<high<<endl;

                }

        }

        printf("%d = %d + %d\n",n,low,high);
    }
    return 0;
}
