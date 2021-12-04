#include <iostream>
#include<stdlib.h>
#include<cstdio>
#include "conio.h"
#include <iomanip>
#include<ctype.h>
#include<windows.h>

using namespace std;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
void MainMenu(){
cout<<"\t\t\t======================= C++ Programming ========================"<<endl;
cout<<"\t\t\t************************* Application **************************"<<endl;
cout<<"\t\t\t@               1-Hundred Dollars & Hundreds Chickens          @"<<endl;
cout<<"\t\t\t@               2-Five Books to Three Children                 @"<<endl;
cout<<"\t\t\t@               3-Criminal's Car Plate                         @"<<endl;
cout<<"\t\t\t@               4-Time Table 9 x 9                             @"<<endl;
cout<<"\t\t\t@               5-Chess Board                                  @"<<endl;
cout<<"\t\t\t@               6-Factorization                                @"<<endl;
cout<<"\t\t\t@               7-Character Analysis                           @"<<endl;
cout<<"\t\t\t@               8-Exit                                         @"<<endl;
cout<<"\t\t\t@                                                              @"<<endl;
cout<<"\t\t\t*********************** Copyright@Bimarsh **********************"<<endl;
cout<<"\n"<<endl;
cout<<"\n"<<endl;
}
void Chicken(){
 SetConsoleTextAttribute(h,10);
        cout<<"Zhang Qiujian, an ancient Chinese mathematician, once put forward the famous"<<endl;
        cout<<"problem of \"a hundred dollars buys a hundred chickens\": A rooster's price is 5 dollars;"<<endl;
        cout<<"a hen's price is 3 dollars; three chicks' price is one dollar. Question: To buy 100 chickens"<<endl;
        cout<<"with 100 dollars, how many are each of the roosters, hens and chickens?\""<<endl;
        cout<<"\n";
        cout<<"\t\tPress any key to get solution"<<endl;
        cout<<"\n";
        getch();
SetConsoleTextAttribute(h,0XF);
int rooster,hen,chick,i=0;
for(rooster=0;rooster<100/5;rooster++)
{
    for(hen=0;hen<100/3;hen++){
        chick=100-rooster-hen;
        if(rooster*15+hen*9+chick==300){
            i++;
            cout<<"Solution "<<i<<": "<<rooster<<" "<<hen<<" "<<chick<<endl;
            cout<<endl;

        }

    }

}
cout<<"\n";
}
void Five_Books(){
    SetConsoleTextAttribute(h,10);
    cout<<"There are five books to lend to A, B and C."<<endl;
    cout<<"If everyone could borrow only one book,"<<endl;
     cout<<"how many different ways could they borrow the books?\""<<endl;
     cout<<endl;
     cout<<"\t\tPress any key to see the solution"<<endl;
     getch();
       cout<<endl;
              SetConsoleTextAttribute(h,0XF);
int a,b,c,i=0;
for(a=1;a<=5;a++){
    for(b=1;b<=5;b++){
        for(c=1;c<=5;c++){

        if(a!=b&&b!=c&&a!=c){

i++;
        cout<<"Solution "<<setw(2)<<left<<i<<":"<<a<<" "<<b<<" "<<c<<"\t";
        if(i%3==0)
            cout<<endl;
    }

    }
}
}
cout<<"\n";
}
void Car_plate(){
int i,j,k,num;
 SetConsoleTextAttribute(h,10);
cout<<"A car hit a man and ran away. No one remembers"<<endl;
cout<<"the car plate number, only some characteristics of it."<<endl;
cout<<"A said: the first two Numbers of the licence are the same."<<endl;
cout<<"B said: the last two Numbers of the licence are the same, "<<endl;
cout<<"but different from the first two."<<endl;
cout<<"C is a mathematician, and he said: the four-digit car number"<<endl;
cout<<"is exactly the square of an integer."<<endl;
cout<<"What is the car plate number?"<<endl;
cout<<endl;
cout<<"\t\tPress any key to find out the solution"<<endl;
cout<<endl;
getch();


SetConsoleTextAttribute(h,0XF);
for(i=1;i<=9;i++){
    for(j=1;j<=9;j++){
        if(i!=j){
            num=1000*i+100*i+10*j+j;
        }
        for(k=32;k<=99;k++){
            if(k*k==num)

                cout<<"\t\tThe criminal's number plate is:"<<num<<endl;
        }
    }

}cout<<endl;

}

void Timetable(){
int i,j;
 SetConsoleTextAttribute(h,10);
for(i=1;i<10;i++){
    for(j=1;j<=i;j++){
        cout<<" "<<j<<'x'<<i<<'='<<setw(2)<<left<<i*j<<" ";
    }
    cout<<"\n";
}
cout<<"\n";
}

void Chess_board(int row,int col){
SetConsoleTextAttribute(h,0XF);
int i,j;
char a=168,b=128;
for(i=1;i<=row;i++)
  {
    cout<<"\t";
    for(j=1;j<=col;j++)
    {
      if( (i+j)%2==0)//even-numbered block, print  ¦
      {
        cout<<a<<b; 
      
      }
      else  //odd-numbered block, print  ?
      {
        cout<<"  ";
      }
    }
    cout<<endl;    
  }    
}
void Factorization(){
    int i,j,num,temp,factors[20];
    SetConsoleTextAttribute(h,0XF);
    cout<<"Input 888 to end the prime factorization"<<endl;
    do{


    cout<<"\tPlease input a positive integer:";
    while(!(cin>>num)||(num<=0)){
      cin.clear();
      cin.sync();

      cout<<"\n\tInvalid.Please input again:";
    }
    cin.ignore(1000,'\n');
    temp=num;
    i=2;
    j=0;
    factors[0]=1;
    while(temp!=1){

        if(temp%i==0){
            factors[j]=i;
            temp=temp/i;
            j++;
        }
        else{
            i++;
        }
    }
     SetConsoleTextAttribute(h,10);
    cout<<"\n\t"<<num<<" = ";
    for(i=0;i<j-1;i++){
        cout<<factors[i]<<" x ";
    }
    cout<<factors[i]<<endl;

    }while(num!=888);



}
void cout_character(){
    char choose,cExit;
    SetConsoleTextAttribute(h,10);
    cout<<"\n\tString ending with 8 will return to the Menu."<<endl;
    cout<<endl;

     do{
        int letters=0,numbers=0,spaces=0,others=0;

SetConsoleTextAttribute(h,0XF);
    cout<<"\tPlease input your string:";
    STEP:
    while((choose=getchar())!='\n'){
        if((choose>='a'&&choose<='z')||(choose>='A'&&choose<='Z'))
            letters++;
        else if(choose>='0'&&choose<='9')
            numbers++;
        else if(choose==' ')
            spaces++;
        else{
            others++;
        }
        cExit=choose;

    }

      if(letters>0){
    cout<<"\n\tLetters:"<<letters<<endl;
    cout<<"\n\tNumbers:"<<numbers<<endl;
    cout<<"\n\tSpaces:"<<spaces<<endl;
    cout<<"\n\tOthers:"<<others<<endl;
      }
      else
        goto STEP;



}while(cExit!='8');


}

int main()
{
    int choice;
    MainMenu();
    while(choice!=8){
        cout<<"Please choose:";
        while(!(cin>>choice)||choice<1||choice>8){
            cout<<"Invalid choice! Please choose again:";
        cin.clear();
        cin.sync();
        }
if(choice==8)
    break;
        cout<<"Your choice is "<<choice<<endl;
       switch(choice){
    case 1:
        Chicken();
        break;
    case 2:
        Five_Books();
        break;
    case 3:
        Car_plate();
        break;
    case 4:
         Timetable();
        break;
    case 5:
        Chess_board(8,8);
        break;
    case 6:
        Factorization();
        break;
    case 7:
        cout_character();
        break;
       }

        cout<<"Please press any key to return to main menu"<<endl;
        getch();
        MainMenu();

    }
return 0;
    }


