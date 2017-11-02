
#include<bits/stdc++.h>

int presedence(char ch)
{
    if(ch=='#') return 0;
    else if(ch=='$') return 1;
    else if(ch=='(') return 2;
    else if(ch=='+' || ch=='-') return 3;
    else if(ch=='*' || ch=='/') return 4;
}




