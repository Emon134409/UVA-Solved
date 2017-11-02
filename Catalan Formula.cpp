
#include<cstdio>
#include<algorithm>
#include<iterator>

#include<cmath>
#include<iostream>

using namespace std;

#define size 300

int number[size+5];

void intit()
{
    std::fill( number, number + size, -1 );
    number[1]=1;
}

int catalan(int n)
{

    if(number[n]!=-1)
        return number[n];
    else
    {
        double a= (double((2*(n-1) + 2)*(2*(n-1)+1) )/ ((n)*(n+1) ) );
        return    round(a*catalan(n-1));

    }
}

int main()
{
    intit();

    int x;

    while(1)
    {
        scanf("%d",&x);
        printf("%d\n",catalan(x));

    }

//    ostream_iterator<int> out(cout," ");
//
//    copy(&number[0], &number[size],out);

    return 0;
}
