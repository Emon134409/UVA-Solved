
#include<bits/stdc++.h>

using namespace std;

int result(string str,int n,int N)
{
    stack<int> v;

    char temp[105];
    int k,res;

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
                temp[k]=str[i];
                i++;
                k++;
            }

            temp[k]='\0';
            int digit=atoi(temp);

          //  cout<<digit<<endl;

            v.push(digit);
        }

        else if(str[i]=='+')
        {
            int a=v.top();
            v.pop();

            int b=v.top();
            v.pop();
            res=a+b;
            v.push(res);

        }
        else if(str[i]=='*')
        {
            int a=v.top();
            v.pop();

            int b=v.top();
            v.pop();
            res=a*b;
            v.push(res);
        }

        else if(str[i]=='%')
        {
            int a=v.top();
            v.pop();

            int b=v.top();
            v.pop();
            res=b%a;
            // v.push(res);
            //  cout<<res<<endl;
        }

    }

    return res;

}

int main()
{
    freopen("11036.txt","r",stdin);

//      cout<<result();
    string a,dummy;
    int m,N,n,c,d,t,k;

    while(cin>>N>>n)
    {
        //getline(cin,dummy);
        getline(cin,a);
        cout<<result(a,n,N);
    }
     // cout<<a;
//        if(N==0) break;
//         m=n;
//         t=1,k=2;
//        for(int i=0;;i++)
//        {
//            for(int j=1;j<=t;j++)
//            {
//                n=result(a,n,N);
//
//            }
//
//            for(int j=1;j<=k;j++)
//            {
//                m=result(a,m,N);
//            }
//
//          //  cout<<n<<" "<<m<<endl;
//
//            if(n==m){
//                 int j;
//                 for( j=1;;j++)
//                 {
//                     n=result(a,n,N);
//
//
//                     if(n==m)
//                        break;
//                 }
//
//                 cout<<j<<endl;
//                  break;
//            }
//
//            else {
//                t++;
//                k+=2;
//            }
//
//
//        }
//
//
//
//    }
//
////    int N,n;
////    string a;
//    cin>>N>>n;
//    getline(cin,a);
//    cout<<result(a,n,N);

    return 0;
}

