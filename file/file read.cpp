#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    /*ofstream myfile;
    myfile.open("Test.txt");
    myfile<< "Writing this to a file"<< endl;
    myfile.close();*/

    string line;
    ifstream myfile("example.txt");
    if(myfile.is_open())
       {
            while(getline(myfile,line))
                {
                    cout<< line << endl;
                }
                 myfile.close();
       }
       else
       {
           cout<< "Unable to open file "<< endl;
       }


}

