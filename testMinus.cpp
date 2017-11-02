#include<bits/stdc++.h>

using namespace std;

string call_minus(string large,string small)
{
    string result;
    string L,S;

    int l,s,now,hold,diff;

    l=large.size();
    s=small.size();

    bool sign=0;

    if(l<s)
    {
        result.assign(large);
        large.assign(small);
        small.assign(result);

        now=l;
        l=s;
        s=now;
        sign=l;
    }

    if(l==s)
    {
        if(large.compare(small)<0)
        {
            result.assign(large);
            large.assign(small);
            small.assign(result);

            now=l;
            l=s;
            s=now;
            sign=l;
        }
    }

    reverse_copy(large.begin(),large.end(),back_inserter(L));
    reverse_copy(small.begin(),small.end(),back_inserter(S));

    S.resize(l);
    for(; s<l; s++)
    {
        S[s]='0';
    }
     result.resize(l);
    for(now=0,hold=0; now<l; now++)
    {
        diff=L[now]-(S[now]+hold);
        if(diff<0)
        {
            hold=1;
            result[now]=10+diff+'0';
        }
        else
        {
            result[now]=diff+'0';
            hold=0;
        }

    }

    for(now=l-1; now>0; now--)
    {
        if(result[now]!='0')
            break;
    }
    result.resize(now+1);
    string temp;
    reverse_copy(result.begin(),result.end(),back_inserter(temp));
    result.assign(temp);

    return result;


}

int main()
{
    string a,b;

    while(cin>>a>>b)
    {
        cout<<call_minus(a,b);
    }
}
