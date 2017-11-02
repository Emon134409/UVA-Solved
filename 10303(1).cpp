
#include<bits/stdc++.h>
#define size 3000

using namespace std;

int arr[size+5];
int number[size+5];
int num[size-1000];

void fillup(int n)
{
    int g;
    for(int i=n+2; i<=2*n; i++)
    {
        g=i;
        if(g%2==0) g=2;
        number[i-n-2]=g;
    }
}

void opt(int n)
{
    for(int i=2; i<=((n+2)/2)-1; i++)
    {
          num[i-2]=i;
    }
}




int main()
{
    int x;

    ostream_iterator<int> out(cout," ");

    while(scanf("%d",&x)!=EOF)
    {
        fillup(x);
        opt(x);
        copy(num,num+((x+2)/2)-2,out);
    }
}
