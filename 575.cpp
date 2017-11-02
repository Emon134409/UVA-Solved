#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>

using namespace std;

int square(long int n)
{
    return n*n;
}

int fastexp(long int base,long int power)
{
    if (power == 0)
        return 1;
    else if (power%2 == 0)
        return square(fastexp(base,power/2));
    else
        return base * (fastexp(base,power-1));
}


int main()
{
    string str;
    char strr[2];
    int decimal,counter;
    while(cin>>str && str!="0")
    {
        decimal=0;
        counter=0;
        int l=str.size();

        for(int i=l-1; i>=0; i--)
        {
            strr[0]=str[i];
            strr[1]='\0';

            int digit=atoi(strr);
            decimal=decimal+digit*((fastexp(2,counter+1))-1);
            counter++;
        }
        printf("%d\n",decimal);
    }

    return 0;
}
