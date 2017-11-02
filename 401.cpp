
#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

bool palindromeCheck(string str);
bool mirrorCheck(string str);
char returnReverse(char ch);

int main()
{
    string str;
    while(cin>>str)
    {
        bool test=palindromeCheck(str);
        bool test1=mirrorCheck(str);

        if(test && !test1 )
            cout<<str<<" -- is a regular palindrome."<<endl;

        else if(!test1 && !test)
            cout<<str<<" -- is not a palindrome."<<endl;
        else if(test1 && !test)
            cout<<str<<" -- is a mirrored string."<<endl;
        else cout<<str<<" -- is a mirrored palindrome."<<endl;

        printf("\n");

    }

    return 0;
}

bool mirrorCheck(string str)
{
    int i,l=str.size();
    string test(str);

    for(i=0; i<l; i++)
    {
       char ch=returnReverse(str[i]);
        if(ch!='?') test[i]=ch;
        else return  0;
    }
    for(i=0; i<l; i++)
    {
        if(str[i]!=test[l-i-1])
            return 0;
    }
    return 1;

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
    else if(ch=='A'||ch=='H'||ch=='I'||ch=='M'||ch=='T'||ch=='U'||ch=='V'||ch=='W'||ch=='X'||ch=='Y'||ch=='1'||ch=='8'||ch=='O')
        return ch;
    else return '?';
}
