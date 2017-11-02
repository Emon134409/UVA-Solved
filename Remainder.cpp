
#include<bits/stdc++.h>

using namespace std;

string call_div(string number,long int div)
{
    int len=number.size();
    int now;
    long int extra;

    string result;

    for(now=0,extra=0; now<len; now++)
    {
        extra = extra * 10 + (number[now] - '0');
        extra%=div;
    }
    cout<<extra<<endl;
    int k=0;
    while(1)
    {
        result.resize(k+1);
        result[k]=extra%10+'0';
        extra/=10;
        k++;
        if(extra==0) break;
    }

     string str;

     reverse_copy(result.begin(),result.end(),back_inserter(str));
     return str;
}

int main()
{
    cout<<call_div("5889",100);
    return 0;
}
