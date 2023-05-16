#include <iostream>
using namespace std;

int main()
{
   string str;
   int i,x=0;
   cout<<"this is your input:";
   getline(cin,str);
   
   for(i=0;i<str.size();i++){
        if(str[i]==' ')
        x+=1;
   }
   if(x==1)
    cout<<"false";
    else
        cout<<"true";
    return 0;
}
