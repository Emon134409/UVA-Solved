
#include<iostream>

using namespace std;

long long int fac(int n)
{
    if(n==1) return 1;

    else return n*fac(n-1);
}

int main()
{
    int x;
    while(cin>>x)
    {
        int a=2*x;
        long long int fib = fac(a) ;
        long long int gib = ( fac(x) * fac(x) *(x+1));

        cout<<fib/gib<<" ";

         a=x-1;

        cout<<double((2*a + 2) * (2*a +1))/ ((a+1) *(a+2)) ;



    }

}
