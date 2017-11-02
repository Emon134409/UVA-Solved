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

//
//string call_minus(string large,string small)
//{
//    string result;
//    string L,S;
//
//    int l,s,now,hold,diff;
//
//    l=large.size();
//    s=small.size();
//
//    bool sign=0;
//
////    if(l<s)
////    {
////        result.assign(large);
////        large.assign(small);
////        small.assign(result);
////
////        now=l;
////        l=s;
////        s=now;
////        sign=l;
////    }
////
////    if(l==s)
////    {
////        if(large.compare(small)<0)
////        {
////            result.assign(large);
////            large.assign(small);
////            small.assign(result);
////
////            now=l;
////            l=s;
////            s=now;
////            sign=l;
////        }
////    }
//
//    reverse_copy(large.begin(),large.end(),back_inserter(L));
//    reverse_copy(small.begin(),small.end(),back_inserter(S));
//
//    S.resize(l);
//    for(; s<l; s++)
//    {
//        S[s]='0';
//    }
//     result.resize(l);
//    for(now=0,hold=0; now<l; now++)
//    {
//        diff=L[now]-(S[now]+hold);
//        if(diff<0)
//        {
//            hold=1;
//            result[now]=10+diff+'0';
//        }
//        else
//        {
//            result[now]=diff+'0';
//            hold=0;
//        }
//
//    }
//
//    for(now=l-1; now>0; now--)
//    {
//        if(result[now]!='0')
//            break;
//    }
//    result.resize(now+1);
//    string temp;
//    reverse_copy(result.begin(),result.end(),back_inserter(temp));
//    result.assign(temp);
//
//    return result;
//
//
//}



string fib(string n)
{
    string c,a="1",b="1";
    int i;
    const char * d = n.c_str();
    int l=atoi(d);
    for(int i=3;i<=l;i++)
    {
        c=call_sum(a,b);
        //cout<<c<<" ";
        a.assign(b);
        b.assign(c);
    }

    return b;
}


int main()
{
    string a;
    while(cin>>a)
    {
        cout<<"The Fibonacci number for "<<a<<" is "<<fib(a)<<endl;
    }
    return 0;
}
