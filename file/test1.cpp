#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    FILE *fp;
    fp=fopen("rafsun.txt","w");
    char ch;
    ch=getchar();
    //cout<< ch << endl;
    putc(ch,fp);
    fgets(ch,fp);


}
