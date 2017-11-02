
#include<bits/stdc++.h>

using namespace std;

struct data
{
    int first;
    int second;
};




int main()
{
    freopen("442.txt","r",stdin);

    data v[30];
    data s[30];

    memset(v,0,sizeof(v));
    memset(s,0,sizeof(s));

    int n;
    scanf("%d",&n);

    char ch ;
    int f, l;

    getchar();

    for(int i=0; i<n; i++)
    {

        scanf("%c %d %d",&ch,&f,&l);

        getchar();

        v[ch-65].first=f;
        v[ch-65].second=l;

    }
//    for(int i=0;i<26;i++)
//        printf("%d %d\n",v[i].first,v[i].second);

    stack<char> tada;

    string str;

    int len;

    bool flag;
    long long int sum;

    while(cin>>str)
    {

        getchar();

        //   cout<<str<<endl;
        sum=0;
        flag=false;

        char k='a';

        len=str.size();

        if(len==1)
        {
            printf("0\n");

        }

        else
        {

            for(int i=0; i<len; i++)
            {
                if(str[i]==')')
                {
                    char ch1=tada.top();

                    tada.pop();

                    char ch2=tada.top();

                    tada.pop();

                    tada.pop();

                    data temp1,temp2;

                    if(ch2>='A' && ch2<='Z')
                        temp2=v[ch2-65];
                    else
                        temp2=s[ch2-98];

                     if(ch1>='A' && ch1<='Z')
                        temp1=v[ch1-65];
                     else
                        temp1=s[ch1-98];


                    if(temp2.second != temp1.first)
                    {
//                        cout<<ch1<<" "<<ch2<<endl;
//                        cout<<v[ch1-65].second<<" "<<v[ch1-65].first<<endl;
                        flag=true;
                        break;
                    }

                    else
                    {

                        sum+=temp2.first*temp2.second*temp1.second;

                        tada.push(k);

                        s[k-98].first=temp2.first;
                        s[k-98].second=temp1.second;

                        k++;

                    }

                }

                else
                    tada.push(str[i]);



            }

            if(flag) printf("error\n");

            else
                printf("%lld\n",sum);

        }
    }




    return 0;
}
