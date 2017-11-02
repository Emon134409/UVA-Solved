#include<bits/stdc++.h>
using namespace std;

string call_rem(string number,long int div)
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
    // cout<<extra<<endl;
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

string call_mult(string first,string sec)
{
    string F,S,temp;
    string result;

    int f_len,s_len,f,s,r,t_len,hold,res;

    f_len=first.size();
    s_len=sec.size();

    reverse_copy(first.begin(),first.end(),back_inserter(F));
    reverse_copy(sec.begin(),sec.end(),back_inserter(S));

    t_len=f_len+s_len;
    r=-1;

    temp.resize(t_len+1);

    for(f=0; f<=t_len; f++)
        temp[f]='0';

    for(s=0; s<s_len; s++)
    {
        hold=0;

        for(f=0; f<f_len; f++)
        {
            res=(F[f]-'0')*(S[s]-'0') + hold+(temp[f+s]-'0');
            temp[f+s]=res%10+'0';
            hold=res/10;
            if(f+s>r) r=f+s;

        }

        while(hold!=0)
        {
            res=hold+(temp[f+s]-'0');
            hold=res/10;
            temp[f+s]=res%10+'0';
            if(r<f+s) r=f+s;
            f++;
        }



    }

    for(; r>0 && temp[r]=='0'; r--);
    temp.resize(r+1);

    reverse_copy(temp.begin(),temp.end(),back_inserter(result));

    return result;

}


string result(string &str,string &n,string &N)
{
    stack<string> v;

    string res,temp;

    int k;

    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='x')
        {
            v.push(n);
        }
        else if(str[i]=='N')
        {
            v.push(N);
        }
        else if(str[i]>='0' && str[i]<='9')
        {
            k=0;
            while(str[i]!=' ')
            {
                temp.resize(k+1);
                temp[k]=str[i];
                i++;
                k++;
            }
            v.push(temp);
        }

        else if(str[i]=='+')
        {
            string a=v.top();
            v.pop();

            string b=v.top();
            v.pop();
            res=call_sum(a,b);
            v.push(res);

        }
        else if(str[i]=='*')
        {
            string a=v.top();
            v.pop();

            string b=v.top();
            v.pop();
            res=call_mult(a,b);
            v.push(res);
        }

        else if(str[i]=='%')
        {
            string a=v.top();
            v.pop();

            string b=v.top();
            v.pop();

            char str[20];

            int z=0,size_a=a.size();

            while(z<size_a)
            {
                str[z]=a[z];
                z++;

            }
              str[z]='\0';
           long int digit=atoi(str);

        //    cout<<digit<<a<<endl;

            res=call_rem(b,digit);
            v.push(res);
            //  cout<<res<<endl;
        }

    }

    return res;

}


int main()
{
    freopen("11036.txt","r",stdin);
    int tor,khor;
    string m,k;
    string equ,n,N;

    while(cin>>N>>n)
    {
        getline(cin,equ);

        if(!N.compare("0")) break;
        tor=2;
        khor=3;


        for(int j=0;; j++)
        {
            m=n;
            k=n;

            for(int i=0; i<tor; i++)
            {
                k=result(equ,k,N);
            }

            for(int i=0; i<khor; i++)
            {
                m=result(equ,m,N);
            }

//              cout<<k<<" "<<m<<endl;
//            break;

            if(m==k)
            {
                //            cout<<k<<" "<<m<<endl;
                //cout<<k<<endl;
                int i;

                for(int z=1;; z++)
                {
                    k=n;
                    for( i=0; i<=tor; i++)
                    {
                        k=result(equ,k,N);

                    }

                    //cout<<k<<endl;
                    //break;
//                    if(j==5) break;
                    if(m==k)
                    {
                        cout<<z<<endl;

                        break;
                    }
                    else tor++;

                }

                break;
            }

            else
            {
                tor++;
                khor+=2;
            }

        }
    }

    return 0;
}