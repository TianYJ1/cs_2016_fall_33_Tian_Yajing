#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Encrypt (string key,string fname, string oname){
ifstream fin;
char c;
int keyi;
    for (int i=0;i < key.size();i++)
        keyi*=key[i];
string kname=oname;
oname.append(".cxpt");
kname.append(".ckey");
ofstream fo, keyo(kname.c_str());
fin.open(fname.c_str());
fo.open(oname.c_str());

while(fin >> std::noskipws >> c)
    {
    c=c^keyi;
    fo<<c;
        }
            keyo<<keyi<<endl<<oname<<endl<<fname<<endl<<key;
}


int main(){
string in,key,fname,oname;
//initializes more variables
cout<<"What is the file name?"<<endl;
getline(cin,fname);
cout<<"What will the output file be?"<<endl;
getline(cin,oname);
check:
cout<<"Enter an encryption key."<<endl;
getline(cin,key);
if (key=="1") {cout<<"Invalid key, enter a different one"<<endl; goto check;}
// inputting one doesn't decrypt properly
Encrypt (key,fname,oname);
cout<<"The file has been encrypted/decrypted."<<endl;
string wait;
getline(cin,wait);
//input to pause before closing program
return 0;
}

