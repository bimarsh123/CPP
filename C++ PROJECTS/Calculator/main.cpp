#include <iostream>
#include <windows.h>
#include "conio.h"
#include <cmath>
#include <iomanip>
using namespace std;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
unsigned long long int power(int base,int exp){
    unsigned long long int z=1;
    for(int i=0;i<exp;i++)
  {
    z = z*base;
  }
  return z;
}
int GCD(int a,int b){
    if(a==0)
        return b;
    return GCD(b%a,a);
}
int LCM(int a,int b)
{

return a*b/GCD(a,b);
}

void MainMenu(){
    cout<<"\n"<<endl;

cout<<"\t\t\t==================== I love c++ ===================="<<endl;
cout<<"\t\t\t********************** Numbers *********************"<<endl;
cout<<"\t\t\t$                1.Perfect Number                  $"<<endl;
cout<<"\t\t\t$                                                  $"<<endl;
cout<<"\t\t\t$                2.Friendly Number                 $"<<endl;
cout<<"\t\t\t$                                                  $"<<endl;
cout<<"\t\t\t$                3.Narcissistic Number             $"<<endl;
cout<<"\t\t\t$                                                  $"<<endl;
cout<<"\t\t\t$                4.Armstrong Number                $"<<endl;
cout<<"\t\t\t$                                                  $"<<endl;
cout<<"\t\t\t$                5.Pythagorean Number              $"<<endl;
cout<<"\t\t\t$                                                  $"<<endl;
cout<<"\t\t\t$                6.Mantissa                        $"<<endl;
cout<<"\t\t\t$                                                  $"<<endl;
cout<<"\t\t\t$   7.Lowest common multiple and Grestest common   $"<<endl;
cout<<"\t\t\t$                Divisor                           $"<<endl;
cout<<"\t\t\t$                                                  $"<<endl;
cout<<"\t\t\t$                8.Exit                            $"<<endl;
cout<<"\t\t\t$                                                  $"<<endl;
cout<<"\t\t\t$***************Copyright@BIMARSH******************$"<<endl;
cout<<endl;
cout<<endl;
}
void Perfect_Number(){
cout<<endl;
SetConsoleTextAttribute(h,10);
cout<<"\t\t\t----------------- Perfect Number --------------------"<<endl;
cout<<endl;
cout<<"\t\t\tA perfect number is a positive integer that is"<<endl;
cout<<"\t\t\tequal to the sum of all its proper divisors.For example,"<<endl;
cout<<"\t\t\t6, whose proper divisors are 1, 2, and 3, and indeed 6 = 1 + 2 + 3."<<endl;
cout<<endl;
SetConsoleTextAttribute(h,12);
cout<<"\t\t\tNotice: Input 888 to Return to the Main menu"<<endl;
cout<<endl;
SetConsoleTextAttribute(h,0XF);

int n1,n2,i,j,k,b,num[20],y,c=0;
do{
        cout<<"\t\t\tPlease input the start number:";

        while(!(cin>>n1)||(n1<0)){
cout<<"\t\t\tInvalid !Please enter Again:";
        cin.clear();
        cin.sync();
        }
        cout<<endl;
        if(n1==888)
            break;
        cout<<"\t\t\tPlease input the end number:";
        while(!(cin>>n2)||(n2<=0)){
cout<<"\t\t\tInvalid !Please enter Again:";
        cin.clear();
        cin.sync();
        }
        cout<<endl;
    for(i=n1;i<=n2;i++){
            b=0;
            y=0;
            for(j=1;j<=i/2;j++){
                    if(i%j==0){
                        b+=j;
                        num[y]=j;
                        y++;
                    }
            }
            if(b==i){
                    c++;
                    cout<<"\t\t\t"<<b<<" is a perfect Number:"<<b<<"=";
                    for(k=0;k<y-1;k++){
                        cout<<num[k]<<"+";
                    }cout<<num[k];
                    cout<<endl;
                    cout<<endl;
            }


    }SetConsoleTextAttribute(h,10);
    cout<<"\t\t\tThere are "<<c<<" perfect Numbers in between "<<n1<<" and "<<n2;
cout<<endl;
cout<<endl;
SetConsoleTextAttribute(h,0XF);

c=0;

}while(n1!=888);
cout<<endl;
cout<<endl;
}
void Friendly_Number(){

int n1,n2,i,j,k,sum1,sum2,fac1[1000],fac2[1000],n,m,cnt=0;
SetConsoleTextAttribute(h,10);
cout<<"\t\t\tThere are two integers a and b. If the sum of"<<endl;
cout<<"\t\t\tb's divisors equals to a, and the sum of a's divisors"<<endl;
cout<<"\t\t\tequals to b, we call these two integers are \"Friendly Numbers\"."<<endl;
cout<<endl;
cout<<"\t\t\tE.g:"<<endl;

cout<<"\n\t\t\t284 and 220"<<endl;

cout<<"\n\t\t\t284's divisors: 1+2+4+71+142=220"<<endl;

cout<<"\n\t\t\t220's divisors: 1+2+4+5+10+11+20+22+44+55+110=284"<<endl;

cout<<"\n\t\t\tSo 9 and 4 are not Friendly numbers."<<endl;
cout<<endl;
SetConsoleTextAttribute(h,12);
cout<<"\t\t\tNotice: Input 888 to return to Main menu"<<endl;
cout<<endl;
while(n1!=888){
        SetConsoleTextAttribute(h,0XF);
        cout<<"\t\t\tPlease Enter the starting number:";
while(!(cin>>n1)|| n1<=0){
    cout<<"\t\t\tInvalid.Input again:";
cin.clear();
cin.sync();
}
if(n1==888)
    break;
    cout<<"\t\t\tPlease Enter the ending number:";
while(!(cin>>n2)|| n2<=0){
    cout<<"\t\t\tInvalid.Input again:";
cin.clear();
cin.sync();
}
for(i=n1;i<=n2;i++){
    sum1=0;sum2=0;n=0;m=0;
    for(j=1;j<i;j++){
        if(i%j==0){
            fac1[n]=j;
            n++;
            sum1+=j;
        }
    }
    for(j=1;j<sum1;j++){
        if(sum1%j==0){
            fac2[m]=j;
            m++;
            sum2+=j;
        }
    }
    if((sum2==i) && (sum1<sum2)){
      cnt++;
      cout<<endl;
      SetConsoleTextAttribute(h,10);
      cout<<"\n\t"<<i<<" and "<<sum1<<" are friendly numbers."<<endl;
       SetConsoleTextAttribute(h,0XF);
        cout<<"\n\t"<<i<<"\'s divisors: ";
        for(k=0;k<n-1;k++){
            cout<<fac1[k]<<"+";

        }
        cout<<fac1[n-1]<<"="<<sum1<<endl;

        cout<<"\n\t"<<sum1<<"\'s divisors: ";
        for(k=0;k<m-1;k++){
            cout<<fac2[k]<<"+";

        }
        cout<<fac2[m-1]<<"="<<sum2<<endl;

    }
}
}
cout<<endl;
cout<<endl;
}

void Narcissistic_Number(){
    SetConsoleTextAttribute(h,10);
      cout<<endl;
cout<<"\t\t\tIf a positive 3-digits integer is equal to the sum of its every figure's 3th power,"<<endl;
 cout<<"we call the number Narcissistic Number. The Narcissistic Numbers are: 153 370 371 407"<<endl;
 cout<<endl;
 SetConsoleTextAttribute(h,0XF);
    cout<<"\t\t\tThe Narcissistic Number are:";
    int i,a,x=0,b,r;
    for(i=100;i<1000;i++){
        a=i;
        x=0;
        r=a;

         while(a>0)  {
                b=a%10;
                a/=10;
                x+=(b*b*b);

            }
            if(x==r)
     cout<<r<<" ";
    }
    cout<<endl;
    cout<<endl;
}

void Armstrong_Number(){
	SetConsoleTextAttribute(h,10);
	cout<<"\t\t\tAn Armstrong number is a number that is equal to the sum of"<<endl;
	cout<<"digits raise to the power total number of digits in the number."<<endl;
	cout<<endl;
	cout<<endl;
	SetConsoleTextAttribute(h,0XF);
    cout<<"\t\t\tThe Armstrong Number of 1 digit are:";

int i,n,y,z,c,f;
long int x;

    for(i=1;i<10;i++)
{
    n=i;
    z=0;
    f=n;
    c=f;
    x=0;
    while(n!=0){
        y=n%10;
        n=n/10;
        z++;
    }

    while(c!=0){
            y=c%10;
             c=c/10;
             x+=(power(y,z));


    }
    if(x==f)
        cout<<x<<" ";
}
cout<<endl;
cout<<endl;

     cout<<"\t\t\tThe Armstrong Number of 2 digit are:";

    for(i=10;i<100;i++)
{
    n=i;
    z=0;
    f=n;
    c=f;
    x=0;
    while(n!=0){
        y=n%10;
        n=n/10;
        z++;
    }

    while(c!=0){
            y=c%10;
             c=c/10;
             x+=(power(y,z));


    }
    if(x==f)
        cout<<x<<" ";
}
cout<<endl;
cout<<endl;



     cout<<"\t\t\tThe Armstrong Number of 3 digit are:";
    for(i=100;i<1000;i++)
{
    n=i;
    z=0;
    f=n;
    c=f;
    x=0;
    while(n!=0){
        y=n%10;
        n=n/10;
        z++;
    }

    while(c!=0){
            y=c%10;
             c=c/10;
             x+=(power(y,z));


    }
    if(x==f)
        cout<<x<<" ";
}
cout<<endl;
cout<<endl;


     cout<<"\t\t\tThe Armstrong Number of 4 digit are:";

    for(i=1000;i<10000;i++)
{
    n=i;
    z=0;
    f=n;
    c=f;
    x=0;
    while(n!=0){
        y=n%10;
        n=n/10;
        z++;
    }

    while(c!=0){
            y=c%10;
             c=c/10;
            x+=(power(y,z));


    }
    if(x==f)
        cout<<x<<" ";
}
cout<<endl;
cout<<endl;


     cout<<"\t\t\tThe Armstrong Number of 5 digit are:";
     for(i=10000;i<100000;i++)
{
    n=i;
    z=0;
    f=n;
    c=f;
    x=0;
    while(n!=0){
        y=n%10;
        n=n/10;
        z++;
    }

    while(c!=0){
            y=c%10;
             c=c/10;
             x+=(power(y,z));


    }
    if(x==f)
        cout<<x<<" ";
}
cout<<endl;
cout<<endl;


     cout<<"\t\t\tThe Armstrong Number of 6 digit are:";
for(i=100000;i<1000000;i++)
{
    n=i;
    z=0;
    f=n;
    c=f;
    x=0;
    while(n!=0){
        y=n%10;
        n=n/10;
        z++;
    }

    while(c!=0){
            y=c%10;
             c=c/10;
             x+=(power(y,z));


    }
    if(x==f)
        cout<<x<<" ";
}
cout<<endl;
cout<<endl;


     cout<<"\t\t\tThe Armstrong Number of 7 digit are:";
for(i=1000000;i<10000000;i++)
{
    n=i;
    z=0;
    f=n;
    c=f;
    x=0;
    while(n!=0){
        y=n%10;
        n=n/10;
        z++;
    }

    while(c!=0){
            y=c%10;
             c=c/10;
             x+=(power(y,z));


    }
    if(x==f)
        cout<<x<<" ";
}
cout<<endl;
cout<<endl;



     cout<<"\t\t\tThe Armstrong Number of 8 digit are:";
for(i=10000000;i<100000000;i++)
{
    n=i;
    z=0;
    f=n;
    c=f;
    x=0;
    while(n!=0){
        y=n%10;
        n=n/10;
        z++;
    }

    while(c!=0){
            y=c%10;
             c=c/10;
             x+=(power(y,z));


    }
    if(x==f)
        cout<<x<<" ";
}
cout<<endl;
cout<<endl;
}
void Pythagorean_theorm(){
    SetConsoleTextAttribute(h,10);
    cout<<"\t\t\tPythagorean triples: Triples of positive integers can"<<endl;
    cout<<"\t\t\tconstruct a right triangle with segments of lengths corresponding to triple."<<endl;
cout<<"\t\t\tFor example (3,4,5) (5,12,13) (6,8,10)"<<endl;

cout<<endl;

SetConsoleTextAttribute(h,12);
cout<<"\t\t\tNotice: Input 888 to Return to the Main Menu"<<endl;
cout<<endl;
SetConsoleTextAttribute(h,0XF);
    int i,j,k,n1,n2,x;
    while(n1!=888){
x=0;
cout<<"\t\t\tPlease input the start number:";

while(!(cin>>n1)||n1<=0){
cout<<"\t\t\tInvalid input. Input again:";
	cin.clear();
	cin.sync();

}
cout<<endl;
if(n1==888)
    break;
cout<<"\t\t\tPlease input the end number:";
while(!(cin>>n2)||n2<=0){
cout<<"\t\t\tInvalid input. Input again:";
	cin.clear();
	cin.sync();

}
cout<<endl;
	for( i=n1;i<=n2;i++)
	{
		for(j=1;j<i;j++)
		{
			for(k=1;k<j;k++)
			{
				if((i*i)==(j*j)+(k*k)){
                    x++;
					cout<<"\t"<<k<<" "<<j<<" "<<i<<" "<<setw(12)<<left<<" ";
            }
		}
	}
	}
	cout<<endl;
	SetConsoleTextAttribute(h,10);
	cout<<"\t\tThere are "<<x<<" Pythagorean triples in between "<<n1<<" "<<n2<<".";
SetConsoleTextAttribute(h,0XF);
	cout<<endl;
    }
	cout<<endl;
	cout<<endl;

	cout<<endl;
}
void Mantissa(){
    SetConsoleTextAttribute(h,10);
    cout<<"\t\t\tFind the last n digits of Base to the Exponent power."<<endl;
    cout<<"\t\t\tFor example, find the last 3 digits of 13^13."<<endl;
    cout<<endl;
    SetConsoleTextAttribute(h,12);
cout<<"\t\t\tNotice: Input 888 to Return to the Main Menu"<<endl;
cout<<endl;
    SetConsoleTextAttribute(h,0XF);

int base,expo,digit,z;
unsigned long long int a,p;
while(base!=888){
        z=0;
cout<<"\t\t\tInput a positive integer for base:";

while(!(cin>>base)||base<=0){
cout<<"\t\t\tInvalid input. Input again:";
	cin.clear();
	cin.sync();

}
if(base==888)
    break;

cout<<"\t\t\tInput a positive integer for Exponent:";
while(!(cin>>expo)||expo<=0){
cout<<"\t\t\tInvalid input. Input again:";
	cin.clear();
	cin.sync();
}
cout<<"\t\t\tInput a positive integer for digit(1-6):";
while(!(cin>>digit)||digit<=0){
cout<<"\t\t\tInvalid input. Input again:";
	cin.clear();
	cin.sync();
}


a=power(base,expo);

cout<<endl;
for(int i=0;i<digit;i++){
    p=a%10;
a=a/10;

z=z+(p*(power(10,i)));
}
    SetConsoleTextAttribute(h,10);
cout<<"\t\t\tThe last three digit of "<<base<<" to the power "<<expo<<" is "<<z;
cout<<endl;
cout<<endl;
    SetConsoleTextAttribute(h,0XF);
}
cout<<endl;
}
void LCM_GCD(){
    SetConsoleTextAttribute(h,10);
    cout<<"\t\t-------------- Lowest Common Multiple--------------"<<endl;
    cout<<endl;
    cout<<"Lowest Common Multiple:the smallest common multiple of two or more numbers."<<endl;
    cout<<endl;
    cout<<"\t\t-------------- Greatest Common Divisor --------------:"<<endl;
    cout<<endl;
    cout<<"The largest integer that is an exact divisor of each of two or more integers."<<endl;
    cout<<endl;
SetConsoleTextAttribute(h,12);
cout<<"\t\t\tNotice: Input 888 to return to the Main Menu"<<endl;
cout<<endl;
int n1,n2;
while(n1!=888){

        SetConsoleTextAttribute(h,0XF);
    cout<<"\t\t\tPlease input the first Number:";
  while(!(cin>>n1)||n1<=0){
        cout<<"\t\t\tInvalid. Please Input again:";
    cin.clear();
    cin.sync();
  }
  if(n1==888)
    break;
  cout<<endl;
  cout<<"\t\t\tPlease input the Second Number:";
  while(!(cin>>n2)||n2<=0){
        cout<<"\t\t\tInvalid. Please Input again:";
    cin.clear();
    cin.sync();
  }
  cout<<endl;


   SetConsoleTextAttribute(h,10);
cout<<"\t\t\tThe lowest common multiple of "<<n1<<" and "<<n2<<" is "<<LCM(n1,n2)<<endl;

cout<<endl;

cout<<"\t\t\tThe Greatest common divisor of "<<n1<<" and "<<n2<<" is "<<GCD(n1,n2)<<endl;
SetConsoleTextAttribute(h,12);
cout<<endl;
}
cout<<endl;
cout<<endl;
}


int main() {

    MainMenu();
    int choice=1;
    while(choice!=8){

        cout<<"Please choose:";
        while(!(cin>>choice)||choice<1||choice>8){
        cout<<"Invalid Choice. Please choose again:";
        cin.clear();
        cin.sync();
        }
        cout<<"Your choice is:"<<choice<<endl;

        switch(choice){
    case 1:
        Perfect_Number();
        break;
    case 2:
        Friendly_Number();
        break;
    case 3:
        Narcissistic_Number();
            break;
    case 4:
        Armstrong_Number();
        break;
    case 5:
    Pythagorean_theorm();
        break;
    case 6:
        Mantissa();
        break;
    case 7:
        LCM_GCD();
        break;

    }
    if(choice==8){
        cout<<"The end"<<endl;
        break;
    }
        cout<<"\t\t\tPRESS ANY KEY TO RETURN TO MAIN MENU"<<endl;
        getch();
        MainMenu();
    }
    return 0;
}
