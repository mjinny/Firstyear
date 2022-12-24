#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    ifstream fin("abc.txt");
    cout<<"\nText File wordcount is opened\n";
    int line=1,word=1,size;
    char ch;
    fin.seekg(0,ios::end);
    size=fin.tellg();
    fin.seekg(0,ios::beg);
    while(fin){
        fin.get(ch);
        if (ch==' '||ch=='\n')
        word++;
        if(ch=='\n')
        line++;
    }
    cout<<"no of linr ;"<<line;
    cout<<"size: "<<size;
    fin.close();
    return 0;
}