
#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

char returnReverse(char ch)
{
    if(ch=='E') return '3';
    else if(ch=='J') return 'L';
    else if(ch=='L') return 'J';
    else if(ch=='S') return '2';
    else if(ch=='Z') return '5';
    else if(ch=='2') return 'S';
    else if(ch=='3') return 'E';
    else if(ch=='5') return 'Z';
    else return ch;
}


bool palindromeCheck(string str)
{
    int l=str.size();
    for(int i=0; i<l; i++)
    {
        if(str[i]!=str[l-i-1])
            return false;
    }
    return true;
}



bool mirrorCheck(string str)
{
    int i,l=str.size();
    string test(str);

    for(i=0; i<l; i++)
    {
        test[i]=returnReverse(str[i]);
    }
    for(i=0;i<l;i++)
    {
        if(str[i]!=test[l-i-1])
            return 0;
    }
    return 1;


}







int main()
{
    string str;
    while(cin>>str)
    {
        bool test=palindromeCheck(str);
        bool test1=mirrorCheck(str);

        if(test1)
            cout<<"sdsd";
    }
    return 0;
}
