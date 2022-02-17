#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
string code;
string line;
int count=0,t;
char var[10];
int length;
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


/*void undefined_variable()
{
    int i=0,j=0;

    for(i=0; i<length; i++)
    {
        if(code[i]=='='|| code[i]=='('|| code[i]== ')'|| code[i]=='['|| code[i]== ']'|| code[i]=='{'||code[i]=='}')
        {
            if(code[i-1]==var[j]|| code[i+1]==var[j] || code[i+2]==var[i])
            {
                i++;
                j++;
            }
            else if(code[i-1]!=var[i]||code[i+1]!=var[i])
            {
                cout<<"Data type has not declared "<< code[i-1]<< endl;
            }
            {

            }
        }

    }
}

*/
void parenthesis_parse()
{
    int i=0;

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
int declare[50],trace=0;

void Declare()
{
    int j=0;
    int i;
    string str(code);
    string str2("int");

    size_t found = str.find(str2);
    cout<<  found << endl;
    t=found;
    i=t+4;
    while(code[i]!=';')
    {
        //cout<<"variable: "<< code[i]<<" "<<"index number: "<< i << endl;
        if(code[i]==',')
        {
            i++;
        }
        else
        {
            var[j]=code[i];
            cout<<  endl;
            cout<<"Declared variable: "<< var[j]<< endl;;
            i++;
            j++;
        }

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
    Declare();
    //undefined_variable();
    }

