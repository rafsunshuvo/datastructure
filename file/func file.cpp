#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
string code;
string line;
int count=0;
struct node
{
    char data;
    int line;
    node *next;
};
node *top,*curr;
node *temp1;
void push(int l)
{
    curr= new node;
    curr->next=NULL;
    curr->data='(';

    if(top==NULL)
    {
        top=curr;
        //cout<<"Top assigned"<< "  ";
    }
    else
    {
        curr->next=top;
        top=curr;
        cout<< "top shifted"<<" "<<  "Line: "<< count <<  endl;
    }
    curr->line=l;

}

void pop()
{

    temp1=top;
    //cout<< temp1 << endl;
    if(temp1==NULL)
    {
        //cout<< temp1 << endl;
        cout<< "Open parenthesis missing"<< " "<< "Line:"<< count+1<< endl;
    }

    else
    {
//cout<< top << endl;
    top=temp1->next;
    free(temp1);
    //cout<< "temp1 deteted"<< " ";

    }
}





void parenthesis_parse()
{
    int i=0;
    int length;
    length=code.size();
    //cout<< length<< endl;
    for(i=0; i<length; i++)
    {
        if(code[i]== '(')
        {

            push(count+1);
            //cout<< "Pushed ( "<< "  "<< " Line"<< count+1 <<endl;
            //cout<< code[i]<< endl;
        }
        else if(code[i]==')')
        {

             pop();
            // cout<< "popped )"<< " ";
            // cout<< " Line : "<<  count+1 << endl
        }





        if(code[i]=='\n')
        {
            count++;
            //cout<<count<<endl;
        }

    }
    if(top!=NULL)
    {
        struct node *temp=top;
        while(temp!=NULL)
        {
           cout<<") missing at line "<<temp->line<<endl;
           temp=temp->next;
        }

    }
}


void create_file()
{
    char data[100];
    ofstream file;
    file.open("file11.dat");
    cout<< "Writng to the file"<< endl;
    //cout<< "Enter your name"<< endl;
    //cin>>data;
    cin.ignore();
    cin.getline(data,100);
    file<<data<< endl;
    file.close();

}




void read_file()
{

    ifstream file11("file11.dat");
    if(file11.is_open())
    {
        while(getline(file11,line))
        {
            //cin.ignore();

            //cout<< line << endl;
            code.append(line);
            code.append("\n");
        }
        file11.close();
    }
    else
    {
        cout<< "Unable to open file "<< endl;
    }
}
int main()
{
    top=NULL;
    //create_file();
    read_file();
    cout<<code;
    parenthesis_parse();
//cout<< top << endl;
}
