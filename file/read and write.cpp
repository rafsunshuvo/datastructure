#include<iostream>
#include<fstream>
using namespace std;
 int main()
 {
     char data[100];
     ofstream file;
     file.open("file11.dat");
     cout<< "Writng to the file"<< endl;
     cout<< "Enter your name"<< endl;
     //cin>> data;
     cin.getline(data,100);
     file<<data<< endl;
     file.close();

     /*ifstream readfile;
     readfile.open("file11.dat");
     //cin.ignore();
     readfile>>data;

     cout<< data << endl;
     file.close();*/


     string line;
    ifstream file11("file11.dat");
    if(file11.is_open())
       {
            while(getline(file11,line))
                {
                    cout<< line << endl;
                }
                 file11.close();
       }
       else
       {
           cout<< "Unable to open file "<< endl;
       }





 }
