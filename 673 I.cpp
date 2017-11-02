
#include<bits/stdc++.h>

using namespace std;



void clearr( stack< char > &q )
{
   stack< char > emp;
   swap( q, emp );
}


int main()
{
    int n,l;
    char temp,ch;
    bool flag;
    stack<char> v;
    string str;


    scanf("%d",&n);
    scanf("%c",&ch);



    for(int i=0; i<n; i++)
    {
        flag=false;
        getline(cin,str);
        //gets(str);
        //scanf("%s",str);
        l=str.size();

            for(int j=0; j<l; j++)
            {
                if(str[j]=='(' || str[j]=='['  )
                {
                    v.push(str[j]);
                }

                else
                {
                    if(!v.empty())
                    {
                        temp=v.top();
                        v.pop();
                    }

                    else
                    {
                        flag=true;
                        break;
                    }

                    if((str[j]==')' && temp !='(') || (str[j]==']' && temp !='[') )
                    {
                        flag=true;
                        break;
                    }

                }

            }

        if(!v.empty())
        {
            flag=true;
        }

        if(flag)
        {

            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }

        clearr(v);

    }

    return 0;

}
