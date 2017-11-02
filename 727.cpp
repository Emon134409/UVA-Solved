
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

    string b;

    stack<char> s;
    s.push('#');

    int i=0,k=0;

    while(s.top()!='$')
    {
       
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
        else
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
	
	freopen("727.txt","r",stdin);
   
    char ch,h;

    string input;

    bool flag=false;

    int i=0,n,k;

    scanf("%d",&n);
    getchar();
    getchar();
    
    int hj=n;
  
    int counter=1;

    while(hj--)
    {

        k=0;

      

        while(1)
        {
            char g;
          
           ch=getchar();
           if(ch!='\n')
            g=getchar();

            if(ch==EOF || g==EOF){

                  input.resize(k+1);
 				break;

           }

         
            input.resize(k+1);
            if(ch=='\n')
            {
               break;
            }

            input[k]=ch;
            k++;


        }
      
        input[k]='$';
        
    
       cout<<infixToPostfix(input)<<endl;
         if(hj>0)
        cout<<"\n";
		  

    }

  
    //for(int j=0; j<i; j++)
    //{

      //  cout<<infixToPostfix(input[j])<<endl;
       //  if(j<i-1)
     //   cout<<"\n";
   // }

    return 0;
}


