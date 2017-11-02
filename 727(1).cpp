
#include<bits/stdc++.h>

using namespace std;

int presedence(char ch)
{
    if(ch=='#') return 0;
    else if(ch=='$') return 1;
    else if(ch=='(') return 2;
    else if(ch=='+' || ch=='-') return 3;
    else if(ch=='*' || ch=='/') return 4;
}

string infixToPostfix(string a)
{
//     cout<<a<<endl;
//     exit(0);
    string b;

    stack<char> s;
    s.push('#');

    int i=0,k=0;

    while(s.top()!='$')
    {
        //cout<<"dsd"<<endl;
        if(a[i]>='0' && a[i]<='9')
        {
            b.resize(k+1);
            b[k]=a[i];

            k++;
        }
        else if(a[i]=='(')
        {
            s.push('(');
        }
        else if(a[i]==')')
        {
            while(s.top()!='(')
            {
                b.resize(k+1);
                b[k]=s.top();
                s.pop();
                k++;
            }
            s.pop();
        }
        else //if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/' )
        {
            while(presedence(a[i])<=presedence(s.top()))
            {
                b.resize(k+1);

                b[k]=s.top();

                s.pop();

                k++;
            }
            s.push(a[i]);


        }

        i++;

    }

    return b;

}

int main()
{
    //freopen("727.txt","r",stdin);
    char ch;

    string input[55];

    bool flag=false;

    int i=0,n,k;

    scanf("%d",&n);

 //   getchar();
   // getchar();

    for(int i=0; i<n; i++)
    {
        k=0;
        while( scanf( "%c", &ch ) != EOF && ch != '\n')
        {
      //      getchar();

            input[i].resize(k+1);

            input[i][k]=ch;
            k++;
        }
    }

    for(int j=0; j<i; j++)
    {

        cout<<infixToPostfix(input[j])<<endl;

        cout<<"\n";
    }

    return 0;
}

