
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<vector>

using namespace std;

int char_to_int(char ch)
{
     if(ch>='0' && ch<='9') return ch-48;
    else
    {
        return ch-55;
    }
}

char int_to_char(int n)
{
    return n+55;
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
    vector<int> v;


    int rem=0;
    int i=0;
    if(num==0) v.push_back(rem);
    else
    while(num>0)
    {
        rem=num%n;
        v.push_back(rem);
        num=num/n;

        i++;
    }

    for(int j=v.size()-1;j>=0;j--)
    {
        if(v[j]>=10) cout<<int_to_char(v[j]);
        else cout<<v[j];
    }


}



int main()
{
    freopen("355.txt","r",stdin);

    string input;
    int m,n;
    bool flag;
    long long int decimal;
    long long int temp;


    while(cin>>m>>n>>input)
    {
        flag=0;
        decimal=0;

        int l=input.size();

        for(int i=0;i<l;i++)
        {
            if(char_to_int(input[i])>=m)
            {
                flag=1;
                break;
            }

            temp=char_to_int(input[i])*poww(m,l-i-1);
            decimal=decimal+temp;

        }

        if(flag==0)
        {
             cout<<input<<" base "<<m<<" = ";
               dec_base(decimal,n);
             cout<<" base "<<n<<endl;
        }

          else
        {
            cout<<input<<" is an illegal base "<<m<<" number"<<endl;

        }

    }

    return 0;
}
