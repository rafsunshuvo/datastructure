#include<iostream>
#include<fstream>
using namespace std;

void  write_file()
{
     ofstream myfile;
    myfile.open("Test.txt");
    myfile<< "Writing this to a file"<< endl;
    myfile.close();
}

void read_file()
{

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

int main()
{
   int n;
   cin>> n;
   if(n==1)
   {
       write_file();
   }
   else if(n==2)
   {
     read_file();
   }


}
