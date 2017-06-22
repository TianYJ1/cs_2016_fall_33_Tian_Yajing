#include<iostream>
#include<string>
#include<fstream> 
using namespace std;
int main()
{
char c;
ifstream source;
ofstream target;
string source_fname;
string target_fname;
 
cout<<"Please enter the path of the file to be encrypted/decrypted: "<<endl;
cin>>source_fname;
source.open(source_fname.c_str());
cout<<endl;
cout<<"Please enter the path and name of the new file, that the first file is to";
cout<<"be encrypted/decrypted to: "<<endl;
cin>>target_fname;
target.open(target_fname.c_str());
 
 

string code;
cout<<"\n\nPlease input a code/password of not greater than 32 characters (including no spaces/blanks),";
cout<<"[Note: if a space is entered the program will consider the code/password to be only what before the";
cout<<"space/blank]: "<<endl;
cin>>code;
 
int codeNO; // number of characters of the code
codeNO = code.length();
 
while(codeNO>32)
{
cout<<"The code entered is greater than 32 characters, please reenter a new code: ";
getline(cin,code);
codeNO = code.length();
}
char code_array[32];
for(int m=0; m<codeNO; m++)
{
code_array[m] = code[m];
}
// END CODE INPUT INTO AN ARRAY ==================================
 
while(!source.eof())
{
 

char file_array[32];
 
for(int j=0; j<codeNO; j++)
{
source.get(c);
file_array[j] = c;
}

char enc_dec_array[32];
for(int k=0; k<codeNO; k++)
{
enc_dec_array[k] = file_array[k] ^ code_array[k];
target.put(enc_dec_array[k]);
}

}
 
return 0;
}
