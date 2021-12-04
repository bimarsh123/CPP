#include <iostream>
#include<stdlib.h>
#include "conio.h"
#include<cmath>
#include<windows.h>


using namespace std;
void ShowMenuCN(){
    cout<<"\t   \n";
     cout<<"\t \"A thousand long journey starts from the first step\"\n";
    cout<<"\t$                                                      $\n";
    cout<<"\t$                                                      $\n";
    cout<<"\t$                                                      $\n";
    cout<<"\t$                                                      $\n";
    cout<<"\t****************Copyright@Bimarsh***********************\n";
    cout<<"\n";
}
void ShowMenu(){
    cout<<"\t*************************Hello World************************\n";
    cout<<"\t+                                                          +\n";
    cout<<"\t+    1.Pyramid                            2.Diamond        +\n";
    cout<<"\t+                                                          +\n";
    cout<<"\t+    3.Heart Shape                        4.Swastik        +\n";
    cout<<"\t+                         5.Exit                           +\n";
    cout<<"\t******************Copyright@Bimarsh************************\n";
}

void Pyramid()
{
int n,i,j,k,s;
   cout<<"Enter the height of pyramid:";
   cin>>n;
   cout<<"Input printing speed:";
   cin>>s;

   for(i=1;i<=n;i++){
       for(k=n;k>i;k--){
        cout<<' ';
       }
        for(j=1;j<=i;j++){
                Sleep(s);
            cout<<"* ";

        }
    cout<<"\n";
   }

}
void Diamond(){
     int n,i,j,k,s;
   cout<<"Enter the size of Diamond:";
   cin>>n;
   cout<<"Input printing speed:";
   cin>>s;

   for(i=1;i<=n;i++){
       for(k=n;k>i;k--){
        cout<<' ';
       }
        for(j=1;j<=i;j++){
                Sleep(s);
            cout<<"* ";

        }
    cout<<"\n";
   }
 for(i=1;i<=n;i++){
        for(k=1;k<=i;k++){
            cout<<' ';

        }
       for(j=n;j>i;j--){
            Sleep(s);
        cout<<"* ";
       }

    cout<<"\n";
   }

}
void HeartShape(){
double x, y,
size=10;
char ch=3;
string message(" Happy Valentine's Day ");
int print_line = 4;
if(message.length() % 2 != 0)
message += " ";
for(x=0;x<size;x++)
{
for(y=0;y<=4*size;y++)
{
double dist1 = sqrt( pow(x-size,2) + pow(y-size,2) );
double dist2 = sqrt( pow(x-size,2) + pow(y-3*size,2) );
if (dist1 < size + 0.5 || dist2 < size + 0.5 ) {
cout<< ch;
}
else
cout<< " ";
}
cout<<"\n";
}
for(x=1;x<2*size;x++)
{
for(y=0;y<x;y++)
cout << " ";
for (y=0;y<4*size + 1 - 2*x; y++)
{
if (x>= print_line - 1 && x <= print_line + 1) {
int idx = y - (4*size - 2*x - message.length()) / 2;
if(idx < message.length() && idx >= 0) {
if (x == print_line)
cout<<message[idx];
else cout << " ";
}
else
cout << ch;
}
else
cout<< ch;
}
cout<<endl;
}
}
void Swastik(){
cout<<"\n"<<endl;
cout<<"\n\t   *          * * * * * * *"<<endl;
cout<<"\n\t   *          *            "<<endl;
cout<<"\n\t   *          *            "<<endl;
cout<<"\n\t   *          *            "<<endl;
cout<<"\n\t   *          *            "<<endl;
cout<<"\n\t   * * * * * * * * * * * *"<<endl;
cout<<"\n\t              *          * "<<endl;
cout<<"\n\t              *          * "<<endl;
cout<<"\n\t              *          * "<<endl;
cout<<"\n\t              *          * "<<endl;
cout<<"\n\t  * * * * * * *          * "<<endl;
cout<<"\n"<<endl;
}
int main()
{
    int choice=0;
    bool CNmenu=0;
    do{

              if(CNmenu!=0)
                ShowMenu();
              else
                ShowMenuCN();
            cout<<"\nPlease choose:";
            while(!(cin>>choice)||(choice<0||(choice>5)))
            {
                cin.clear();
                cin.sync();
                cout<<"\n\tInvalid. Please choose again.";
            }


            switch(choice)
{
case 0:
CNmenu=!CNmenu;
break;
case 1:
    system("color 1f");
    Pyramid();
    break;
    case 2:
    system("color 2f");
    Diamond();
    break;
    case 3:
    system("color 3f");
    HeartShape();
    break;
    case 4:
    system("color 4f");
    Swastik();
    break;
    default:
        cout<<"See you next time.Bye Bye";
        break;
}
if((choice!=5)&& (choice!=0))
{
    cin.sync();
    cout<<"\n\tPress any key to return to the Menu"<<endl;
    getch();
}

    }while(choice!=5);

    return 0;
}
