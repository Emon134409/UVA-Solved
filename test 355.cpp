
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

int dec_base(int num,int n)
{
    int rem;
    int digit=0;
    int i=0;
    while(num>0)
    {
        rem=num%n;
        num=num/n;

        digit=digit+rem*(int)pow(10,i);
        i++;
    }

    return digit;
}

int main()
{
   cout<< dec_base(2322,11);
}
