/*
Student Name:Bimarsh Khatri
Student Id:20170903
Project 8:Conjectures
*/



#include <iostream>
#include<iomanip>
#include <windows.h>
#include "conio.h"
using namespace std;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
bool isprime(int n){
int i;
for(i=2;i<=n;i++){
    if(n%i==0)
    {
        break;
    }
}
    if(n==i)
        {
        return true;
        }
    return false;


}
void Showmenu(){
cout<<"\t\t\t ----------------- C++ Programming -----------------"<<endl;
cout<<endl;
cout<<"\t\t\t******************** Conjectures *******************"<<endl;
cout<<"\t\t\t$                                                  $"<<endl;
cout<<"\t\t\t$              1-Goldbach's Conjectures            $"<<endl;
cout<<"\t\t\t$                                                  $"<<endl;
cout<<"\t\t\t$              2-CollatzConjectures                $"<<endl;
cout<<"\t\t\t$                                                  $"<<endl;
cout<<"\t\t\t$              3-Nico-Chester Theorem              $"<<endl;
cout<<"\t\t\t$                                                  $"<<endl;
cout<<"\t\t\t$              4-Four Square Theorem               $"<<endl;
cout<<"\t\t\t$                                                  $"<<endl;
cout<<"\t\t\t$              5-Sieve of Eratosthenes             $"<<endl;
cout<<"\t\t\t$                                                  $"<<endl;
cout<<"\t\t\t$              6-Bride & Groom                     $"<<endl;
cout<<"\t\t\t$                                                  $"<<endl;
cout<<"\t\t\t$              7-Truth or Lie                      $"<<endl;
cout<<"\t\t\t$                                                  $"<<endl;
cout<<"\t\t\t$              8-Exit                              $"<<endl;
cout<<"\t\t\t$                                                  $"<<endl;
cout<<"\t\t\t**************** Copyright@BIMARSH *****************"<<endl;
}

void GoldbachConjectures(){
    int n;
    SetConsoleTextAttribute(h,10);
cout<<"\t-------------- Goldbach\'s conjecture --------------"<<endl;
cout<<endl;
cout<<"\tFor any even number N greater than or equal to 4, there exists"<<endl;
cout<<"\tat least one pair of prime numbers p1 and p2 such that N = p1 + p2."<<endl;
cout<<endl;

do{
            SetConsoleTextAttribute(h,12);
        cout<<"\t\tNotice: Input 888 to Return to Main Menu"<<endl;
cout<<endl;
    SetConsoleTextAttribute(h,0XF);
    cout<<"\tInput a positive integer:";
    while(!(cin>>n)|| n<4 || (n%2!=0)){
        cout<<"\tInvalid input! Please Enter again:";
        cin.clear();
        cin.sync();
    }
    int j;
    int x=0;
    for(j=1;j<=n/2;j++){
        if(isprime(j)){
            if(isprime(n-j)){
                    x++;
            cout<<"\t"<<n<<" = "<<j<<" + "<<(n-j)<<endl;

            }
        }



    }
    cout<<"\tThere are "<<n<<" pairs of prime number that add upto "<<n<<"."<<endl;


}while(n!=888);



}
void collatz_conjecture(){
    SetConsoleTextAttribute(h,10);
    cout<<"\t\t\t-------------- Collatz_conjecture --------------"<<endl;
    cout<<endl;
    cout<<"Take any positive number: if it's even you divide it by 2 and if it's odd multiply"<<endl;
     cout<<"it by 3 and add 1. Repeat this process indefinitely, no matter what number"<<endl;
     cout<<"you start with, you will always end up at 1."<<endl;
     cout<<endl;
    cout<<"The conjecture remains stubbornly unproven. Mathematics is not yet ready"<<endl;
    cout<<"for such problems."<<endl;
     cout<<endl;
     SetConsoleTextAttribute(h,12);
     cout<<"\t\t\tNotice: Input 888 to Return to the Main Menu."<<endl;
     SetConsoleTextAttribute(h,0XF);
int num,x,b;
while(num!=888){
        x=0;
        cout<<"Input a positive integer:";
while(!(cin>>num)||num<=0){
    cout<<"Invalid. Please Input again:";
    cin.clear();
    cin.sync();
}
if(num==888)
    break;
b=num;
cout<<num<<"->";
while(num!=1){


        if(num%2==0){
            num=num/2;
        }
        else{
            num=(num*3)+1;

}
x++;
if(num==1){
cout<<num;
}
else
cout<<num<<"->";


}
SetConsoleTextAttribute(h,10);
cout<<endl;
cout<<endl;
cout<<"\t\t\tThere are "<<x<<" steps to get 1 for "<<b;
cout<<endl;
cout<<endl;
SetConsoleTextAttribute(h,0XF);
}
cout<<endl;
cout<<endl;

}
void Nico_chester(){
     SetConsoleTextAttribute(h,10);
cout<<"\t\t\t------------------ Nico Chester Theorem ------------------"<<endl;
cout<<"\t\t\tAny integer to the third power can be represented as the sum of a series of consecutive odd Numbers."<<endl;
cout<<endl;
 SetConsoleTextAttribute(h,12);
cout<<"\t\t\tNotice: Input 888 to return to main menu"<<endl;
cout<<endl;

int n;
do{
         SetConsoleTextAttribute(h,0XF);
    cout<<"\t\t\tPlease input a positive integer:";
    while(!(cin>>n)||n<=0)
    {
        cout<<"\t\t\tInvalid! Input again:";
        cin.clear();
        cin.sync();
    }
    if(n==888)
        break;
    int cube=n*n*n;
    int i,j,k,sum=0;

    for(i=1;i<cube;i+=2){
        sum=0;
        for(j=i;j<cube;j+=2){
            sum+=j;
            if(sum==cube){
             cout<<"\t\t\t"<<n<<"^3="<<cube<<"=";
             for(k=i;k<j;k+=2){
                cout<<k<<" + ";
             }
             cout<<j<<endl;
             cout<<endl;
             if(n>50){
                cout<<"\t\t\tThere are too many solution"<<endl;
                i=cube;
             }

            }
        }

    }

}while(n!=888);

}

void FourSquare(){
     SetConsoleTextAttribute(h,10);
cout<<"\t\t\t------------------ Four Square Theorem ------------------"<<endl;
cout<<endl;
cout<<"\t\t\tFour-square Theorem: Each positive integer may be expressed as the"<<endl;
cout<<"\t\t\tsum of the squares of four integers."<<endl;
cout<<endl;
SetConsoleTextAttribute(h,12);
cout<<"\t\t\tNotice: Input 888 to return to main menu"<<endl;
cout<<endl;
SetConsoleTextAttribute(h,0XF);
int n;
do{
         SetConsoleTextAttribute(h,0XF);
    cout<<"\t\t\tPlease input a positive integer:";
    while(!(cin>>n)||n<=0)
    {
        cout<<"\t\t\tInvalid! Input again:";
        cin.clear();
        cin.sync();
    }
    if(n==888)
        break;

int i,j,k,m;
int x=0;
for(i=0;i<=(n+1)/2;i++){
    for(j=0;j<=i;j++){
        for(k=0;k<=j;k++){
            for(m=0;m<=k;m++){
                    x++;
                if(i*i+j*j+k*k+m*m==n){
                    cout<<"\t\t\t"<<n<<"="<<i<<"x"<<i<<"+";
                    cout<<j<<"x"<<j<<"+"<<k<<"x"<<k<<"+"<<m<<"x"<<m<<endl;
                }
            }
        }
    }

}
cout<<endl;
cout<<"\t\tTotal loop is "<<x<<endl;
cout<<endl;

}  while(n!=888);

cout<<endl;
cout<<endl;

}

void Sieve_of_Eratosthenes(){
    int j,n,a,m;
    SetConsoleTextAttribute(h,10);
    cout<<"\t\t\t-------------- Sieve of Eratosthenes --------------"<<endl;
    cout<<endl;
    cout<<endl;
    SetConsoleTextAttribute(h,12);
    cout<<"\t\t\tNotice: Input 888 to return to main menu"<<endl;
    SetConsoleTextAttribute(h,0XF);
cout<<endl;

    while(n!=888){
    cout<<"\t\t\tStart from 1, Please input the end number:";
    while(!(cin>>n)||n<=0){
        cout<<"\t\t\tInvalid Input!Please Enter again:";
        cin.clear();
        cin.sync();
    }
    SetConsoleTextAttribute(h,10);
    cout<<endl;
    if(n==888)
        break;

cout<<"\t\t\tThere are "<<m<<" Prime number between 1 and "<<n<<endl;

 a=0;
for(j=1;j<=n;j++)
    {

    if(isprime(j)==1)
    {
        cout<<" "<<j<<setw(2);
        a++;
    }

}a=m;
cout<<endl;

cout<<endl;
cout<<endl;
    }
    cout<<endl;
    cout<<endl;

}
void Bride_Groom(){
    SetConsoleTextAttribute(h,10);
    cout<<"\t\t\tThere are 3 brides (A, B, C) and 3 grooms (X, Y, Z)."<<endl;
    cout<<endl;

cout<<"\t\t\tA: I will marry X."<<endl;
cout<<endl;

cout<<"\t\t\tX: My fiance is C."<<endl;
cout<<endl;

cout<<"\t\t\tC: I will marry Z."<<endl;
cout<<endl;

cout<<"\t\t\tIt is known that they are all kidding."<<endl;
cout<<endl;
cout<<"\t\t\tThen, do you know who and who are a couple?"<<endl;
cout<<endl;
    SetConsoleTextAttribute(h,0XF);
    cout<<"\t\t\tPress any key to check the answer"<<endl;
    cout<<endl;
    getch();
char x,y,z; // 3 grooms
for(x='A';x<='C';x++){ //'A' be the first bride and followed by 'B' and 'C' consecutively
    for(y='A';y<='C';y++){
        for(z='A';z<='C';z++){
                if((x!='A')&&(x!='C')&&(z!='C')&&(x!=y)&&(x!=z)&&(y!=z)){ //this condition needs to be satisfied
                cout<<"\t\t\tThe groom X's bride is "<<x<<endl;
                cout<<"\t\t\tThe groom Y's bride is "<<y<<endl;
                cout<<"\t\t\tThe groom Z's bride is "<<z<<endl;
                }
        }
    }
}
}




void TruthOrLie()
{
  int accusations[3][3] = { {0, 1, 0},       // Ben accuses Bob.
                {0, 0, 1},            // Bob accuses Bill.
                {1, 1, 0} };            // Bill accuses everyone else.
  // 0=Ben, 1=Bob, 2=Bill.
  int susCount[3] = {0, 0, 0};
  int amtOfHonestPeople=1;

  string result;

  cout<<"\t===================Truth or Lies====================="<<endl;
    cout<<"\n";
 SetConsoleTextAttribute(h,10);
    cout<<"\t\t\tBen says that Bob is lying."<<endl;
    cout<<endl;
    cout<<"\t\t\tBob says that Bill is lying."<<endl;
     cout<<endl;
    cout<<"\t\t\tBill says that they are all lying."<<endl;
     cout<<endl;
    cout<<"\t\t\tThen, do you know who is lying?"<<endl;
     cout<<endl;
    cout<<endl;

 SetConsoleTextAttribute(h,0XF);
 cout<<"\t\t\tPress any key to show the answer."<<endl;
 getch();


    int i, j;
    for(i=0; i<3; i++)  // 0: Ben, 1: Bob, 2: Bill
  {
    for (j=0; j<3; j++)
    {
      if (accusations[j][i] == 1)
      {
        if     (i == 0) susCount[0]++;
        else if (i == 1) susCount[1]++;
        else if (i == 2) susCount[2]++;
      }
    }
    switch(i)
     {
       case 0:
         result = susCount[0] > amtOfHonestPeople ? "true" : "lying";
          cout<<"\n\t\t\tBen is "<<result<<"."<<endl;
          break;
        case 1:
          result = susCount[1] > amtOfHonestPeople ? "true" : "lying";
          cout<<"\n\t\t\tBob is "<<result<<"."<<endl;
          break;
      case 2:
        result = susCount[2] > amtOfHonestPeople ? "true" : "lying";
          cout<<"\n\t\t\tBill is "<<result<<"."<<endl;
          break;
     }
    susCount[0] = 0; susCount[1] = 0; susCount[2] = 0;
     }
     cout<<endl;
     cout<<endl;
}
int main()
{
    Showmenu();
    int choice;
    while(choice!=8){
            cout<<endl;
        cout<<"\t\t\tPlease Choose:";
        while(!(cin>>choice)||choice<=0||choice>8){
            cout<<"\t\t\tInvalid choice! Please choose again:";
            cin.clear();
             cin.sync();
            }
            if(choice==8)
                break;
    cout<<endl;
        switch(choice){

    case 1:
        GoldbachConjectures();
        break;
    case 2:
        collatz_conjecture();
        break;
    case 3:
        Nico_chester();
        break;
    case 4:
        FourSquare();
        break;

    case 5:
        Sieve_of_Eratosthenes();
        break;
    case 6:
        Bride_Groom();
        break;
    case 7:
        TruthOrLie();
        break;
        }

        cout<<"\t\t\tPress any key to return MainMenu"<<endl;
        getch();
        Showmenu();

    }

    return 0;
}
