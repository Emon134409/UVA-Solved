
#include<bits/stdc++.h>

using namespace std;

#define MAX 1000

void reverse(char *from, char *to )
{
    int len=strlen(from);
    int l;
    for(l=0; l<len; l++)
        to[l]=from[len-l-1];
    to[len]='\0';
}
void call_sum(char *first, char *sec, char *result)
{
    char F[MAX], S[MAX], Res[MAX];
    int f,s,sum,extra,now;
    f=strlen(first);
    s=strlen(sec);
    reverse(first,F);
    reverse(sec,S);



    for(now=0,extra=0; (now<f && now<s); now++)
    {
        sum=(F[now]-'0') + (S[now]-'0') + extra;
        Res[now]=sum%10 +'0';
        extra= sum/10;
    }

    for(; now<f; now++)
    {
        sum=F[now] + extra-'0';
        Res[now]=sum%10 +'0';
        extra=sum/10;
    }
    for(; now<s; now++)
    {
        sum=F[now] + extra-'0';
        Res[now]=sum%10 +'0';
        extra=sum/10;
    }
    if(extra!=0) Res[now++]=extra+'0';
    Res[now]='\0';
    if(strlen(Res)==0) strcpy(Res,"0");
    reverse(Res,result);
}


int main()
{
   char str[100];
   char str1[]="5";
   char str2[]="10";
   call_sum(str1,str2,str);

   for(int i=0;i<=strlen(str)-1;i++)
   {
       cout<<str[i];
   }


    return 0;
}
