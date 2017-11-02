
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

long long int poww(long long int base,int pow)
{
    int i;
    long long result=1;
    for(i=0;i<pow;i++)
    {
        result*=base;
    }
    return result;
}

void dec_base(long long int num,int n)
{

    int rem;
   long long int digit=0;
    int i=0;
    while(num>0)
    {
        rem=num%n;
        num=num/n;

        i++;
    }


}

int main()
{
    freopen("355.txt","r",stdin);

    int m,n;
    string str;
    bool flag=0;
    while(cin>>m>>n>>str)
    {
        flag=0;
       long long int decimal=0;
        int l=str.size();
        for(int i=0; i<l; i++)
        {
            if(char_to_int(str[i])>=m)
            {
                flag=1;
                break;
            }
            else
            {
               long long int gh= char_to_int(str[i])*poww(m,l-i-1);
                decimal=decimal+gh;

            }

        }



        if(flag==0)
        {

             cout<<str<<" base "<<m<<" = ";
             dec_base(decimal,n);
             cout<<" base "<<n<<endl;
            //printf("%s base %d = %d base %d\n",str,m,ans,n);

        }

        else
        {
            cout<<str<<" is an illegal base "<<m<<" number "<<m<<endl;
           // printf("%s is an illegal base %d number\n",str,m);
        }


    }

    return 0;
}
