
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

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
    for(i=0;i<pow;i++)
    {
        result*=base;
    }
    return result;
}

int dec_base(int num,int n)
{

    int rem;
    int digit=0;
    int i=0;
    while(num>0)
    {
        rem=num%n;
        num=num/n;

        digit=digit+rem*poww(10,i);
        i++;
    }

    return digit;
}

int main()
{

    int m,n;
    char str[1000000];
    bool flag=0;
    while(scanf("%d %d %s",&m,&n,str)!=EOF)
    {
        flag=0;
        int decimal=0;
        int l=strlen(str);
        for(int i=0; i<l; i++)
        {
            if(char_to_int(str[i])>=m)
            {
                flag=1;
                break;
            }
            else
            {
                int gh= char_to_int(str[i])*poww(m,l-i-1);
                decimal=decimal+gh;

            }

        }



        if(flag==0)
        {
             int ans=dec_base(decimal,n);
            printf("%s base %d = %d base %d\n",str,m,ans,n);

        }

        else
        {

            printf("%s is an illegal base %d number\n",str,m);
        }


    }

    return 0;
}
