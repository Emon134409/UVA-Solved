
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

char int_to_char(int n)
{
    return n+55;
}

int char_to_int(char ch)
{
    if(ch>='0' && ch<='9') return ch-48;
    else
    {
        return ch-55;
    }
}

int poww(int base,int pow)
{
    int i,result=1;
    for(i=0; i<pow; i++)
    {
        result*=base;
    }
    return result;
}

void dec_base(long long int num,int n)
{
    char v[10000];

    bool flag=0;
    int rem=0;
    int i=0;
    if(num==0)
    {
        v[i]=rem+48;
        i++;
    }
    else
        while(num>0)
        {
            rem=num%n;

            if(rem<=9)
            {
                v[i]=rem+48;
            }
            else
            {
                v[i]=int_to_char(rem);
            }

            num=num/n;

            i++;
        }
    v[i]='\0';


    if(i>7) flag=1;
    if(flag==1) printf("%7s\n","ERROR");
    else
    {
        char s[10];
        for(int i=0; i<strlen(v); i++)
        {
            s[i]=v[(strlen(v))-i-1];
        }
        s[i]='\0';


        printf("%7s\n",s);
    }
}

int main()
{

    int m,n;
    long long int decimal,gh;
    string str;
    bool flag=0;
    while(cin>>str>>m>>n)
    {
        flag=0;
        decimal=0;
        int l=str.size();
        for(int i=0; i<l; i++)
        {

            gh= char_to_int(str[i])*poww(m,l-i-1);
            decimal=decimal+gh;

        }

        dec_base(decimal,n);




    }

    return 0;
}

