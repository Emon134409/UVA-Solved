
#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("10340.txt","r",stdin);
    string s,tut;

    while(cin>>s>>tut)
    {
        int size_s=s.size();
        int size_tut=tut.size();

        int counter=0;

        bool flag;

        for(int i=0; i<size_s; i++)
        {
            flag=false;

            char ch=s[i];
            for(int j=counter; j<=size_tut; j++)
            {
                if(ch==tut[j])
                {
                    counter=j+1;
                    flag=true;
                    break;

                }
            }

            if(!flag) break;

        }

        if(flag) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
