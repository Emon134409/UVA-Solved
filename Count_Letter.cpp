#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    int arr[128];
    getline(cin,str);
    int l=str.size();

    memset(arr,0,sizeof(arr));

    for(int i=0;i<l;i++)
    {
        int temp=(int)str[i];
        arr[temp]+=1;
    }

    char ch='A';

    for(int i=0;i<26;i++)
    {
        printf("%c ",ch);
        printf("%d\n",arr[i+65]+arr[i+97]);
        ch++;
    }


    return 0;
}
