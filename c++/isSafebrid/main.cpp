#include <iostream>
using namespace std;

int main()
{
   string str;
   int i,x=0;
   getline(cin,str);
   int len=str.size();
   for(i=0;i<len;i++){
        if(str[i]==' ')
        x+=1;
   }
   if(x==1)
    cout<<"false";
    else
        cout<<"true";
    return 0;
}
