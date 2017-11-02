#include<bits/stdc++.h>

using namespace std;

string call_sum(string first,string sec)
{

    string result,F,S,RES;

    int f,s,sum,extra,now;

    f=first.size();
    s=sec.size();

    reverse_copy(first.begin(),first.end(),back_inserter(F));
    reverse_copy(sec.begin(),sec.end(),back_inserter(S));

    //cout<<F<<" "<<S<<endl;

    int counter=0;

    for(now=0,extra=0; (now<f && now <s); now++)
    {
        RES.resize(++counter);
        sum=(F[now]-'0') + (S[now]-'0') + extra;
        RES[now]=sum%10 +'0';
        extra= sum/10;
    }

    for(; now<f; now++)
    {
        RES.resize(++counter);
        sum=F[now] + extra-'0';
        RES[now]=sum%10 +'0';
        extra=sum/10;
    }

    for(; now<s; now++)
    {
        RES.resize(++counter);

        sum=S[now] + extra-'0';

        RES[now]=sum%10 +'0';

        extra=sum/10;
    }

    if(extra!=0)
    {
        RES.resize(++counter);
        RES[now++]=extra+'0';
    }


    if(RES.size()==0)
    {

        RES.resize(1);
        RES.assign("0");
    }

    reverse_copy(RES.begin(),RES.end(),back_inserter(result));

     return result;
}


int main()
{
    cout<<call_sum("5","10");
}
