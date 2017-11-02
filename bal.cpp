#include<iostream>
using namespace std;
class student
{
protected:
    string name;
    int roll;
    string subject[5];
};
class marks:private student
{
    int mark[5];
public:
    void setn()
    {
        cout<<"Name- ";
        getline(cin,name);
    }
    void setr()
    {
        cout<<" Roll- ";
        cin>>roll;
    }
    void sets()
    {
        int i;
        for(i=0; i<5; i++)
        {
            cout<<i+1<<". ";
            cin>>subject[i];
        }
    }
    void setm()
    {
        int i;
        for(i=0; i<5; i++)
        {
            cout<<i+1<<". "<<subject[i]<<": ";
            cin>>mark[i];
        }
    }

    void print()
    {
        int i;
        cout<<endl<<"Name- "<<name<<" Roll- "<<roll<<endl;
        cout<<"*******Marks*******"<<endl;
        for(i=0; i<5; i++)
        {
            cout<<i+1<<". "<<subject[i]<<": "<<mark[i]<<endl;
        }
    }
    string getn()
    {
        return name;
    }
};
int main()
{
    string nam;
    int j;
    marks abc[2];
    for(j=0; j<2; j++)
    {
        cout<<endl<<"Enter new students information : ";
        abc[j].setn();
        abc[j].setr();
        cout<<"Enter the subjects :"<<endl;
        abc[j].sets();
        cout<<"Enter the Marks :"<<endl;
        abc[j].setm();
        cin.ignore();
    }
    cout<<endl<<"***********************************"<<endl;
    cout<<"Enter the name to know the marks : ";
    getline(cin,nam);
    for(j=0; j<5; j++)
    {
        if(!nam.compare(abc[j].getn()))
        //if(abc[j].getn()==nam)
        {
            abc[j].print();
            break;
        }
        else
        {
            cout<<"NOT FOUND";
            break;
        }
    }
}

