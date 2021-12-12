#include <iostream>
#include<stdlib.h>
#include "conio.h"
#include<time.h>


using namespace std;


void
ShowMenu ()
{


cout << "\n";


cout << "\n";

cout << "\t\t$$$$$$$$$$$$$$$$$$$$ Math Problem $$$$$$$$$$$$$$$$$$" <<endl;

cout << "\t\t&                                                  &" <<endl;

cout << "\t\t&   1.Addition(+)             2.Subtraction(-)     &" <<endl;

cout << "\t\t&                                                  &" <<endl;

cout << "\t\t&                                                  &" <<endl;

cout << "\t\t&   3.Multiplication(*)       4.Division(/)        &" <<endl;

cout << "\t\t&                                                  &" <<endl;

cout << "\t\t&                                                  &" <<endl;

cout << "\t\t&   5.Mixed(+,-,*,/)          6.Exit               &" <<endl;

cout << "\t\t&                                                  &" <<endl;

cout << "\t\t$$$$$$$$$$$$$$$$ Copyright@Bimarsh $$$$$$$$$$$$$$$$$" <<endl;


cout << "\n";


cout << "\n";


}
void Addition ();





void Subtraction ();



void Multiplication ();



void Division ();



void correct (int a);



void Mixed (int k);



int k;
static int a = 0;


int main ()
{

system ("color 0e");

int choice;

for (choice = 1; choice <= 7; choice++)

    {

    ShowMenu ();


cout << "Please Choose:";


while (!(cin >> choice) || choice < 1 || choice > 7)

	{


cout << "Invalid Choice.Please enter again:";


cin.clear ();


cin.sync ();



}


if (choice == 6)


break;


cout << "\n";


cout << "Your choice is:" << choice << endl;


cout << "\t\t\tEnter 888 to exit the practice" << endl;



switch (choice)

	{


case 1:


system ("color 0c");


Addition ();


break;


case 2:


system ("color 08");


Subtraction ();


break;


case 3:


system ("color 0f");


Multiplication ();


break;


case 4:


system ("color 09");


Division ();


break;


case 5:


system ("color 0b");


Mixed (k);


break;


}


cout << "Press any key to return to main menu" << endl;


getch ();


}




return 0;


}





void
correct (int a)
{


switch (a)

    {


case 0:


cout << "\t\t\t\tWrong! Try again" << endl;


break;


case 1:


cout << "\t\t\t\tHurry" << endl;


break;


case 2:


cout << "\t\t\t\tBravo" << endl;


break;


case 3:


cout << "\t\t\t\tWell done" << endl;


break;


case 4:


cout << "\t\t\t\tIntermediate" << endl;


break;


case 5:


cout << "\t\t\t\tApplause" << endl;


break;


case 6:


cout << "\t\t\t\tExcellent" << endl;


break;


case 7:


cout << "\t\t\t\tAmazing" << endl;


break;


case 8:


cout << "\t\t\t\tPerfect" << endl;


break;


default:


cout << "\t\t\t\tWell done" << endl;


break;


}


}





void Addition ()
{


int n1, n2, x, y;



while (1)

    {


srand (time (0));


n1 = (rand () % 10) + 1;


n2 = (rand () % 10) + 1;


x = n1 + n2;


cout << "\n\t\t\t" << n1 << "+" << n2 << "=";


cin >> y;


cin.clear ();


cin.sync ();


if (y == 888)

	{


cout << "" << endl;


break;


}


if (x == y)


	{


a++;


correct (a);


}


      else


	{


a = 0;


correct (a);


while (!0)

	    {


cout << "\n\t\t\t" << n1 << "+" << n2 << "=";


cin >> y;


cin.clear ();


cin.sync ();


if (y == 888)

		{


cout << "" << endl;


break;


}


	      else if (x == y)


		{


a++;


correct (a);


break;



}


	      else

		{


a = 0;


correct (a);



}


}




}


if (y == 888)


break;


}


}






void Subtraction ()
{

int n1, n2, x, y, temp;

while (1)
    {

srand (time (0));

n1 = (rand () % 10) + 1;

n2 = (rand () % 10) + 1;

if (n1 < n2)

	{


temp = n2;



n2 = n1;


n1 = temp;


}


x = n1 - n2;


cout << "\n\t\t\t" << n1 << "-" << n2 << "=";


cin >> y;


cin.clear ();


cin.sync ();


if (y == 888)

	{


cout << "" << endl;


break;


}


if (x == y)


	{


a++;


correct (a);


}


      else


	{


a = 0;


correct (a);


while (!0)

	    {


cout << "\n\t\t\t" << n1 << "-" << n2 << "=";


cin >> y;


cin.clear ();


cin.sync ();


if (y == 888)

		{


cout << "" << endl;


break;


}


	      else if (x == y)


		{


a++;


correct (a);


break;



}


	      else

		{


a = 0;


correct (a);



}


}




}


if (y == 888)


break;


}


}






void Multiplication ()
{

int n1, n2, x, y;

while (1)
    {

srand (time (0));

n1 = (rand () % 10);

n2 = (rand () % 10);

x = n1 * n2;

cout << "\n\t\t\t" << n1 << "*" << n2 << "=";


cin >> y;


cin.clear ();


cin.sync ();


if (y == 888)

	{


cout << "" << endl;


break;


}


if (x == y)


	{


a++;


correct (a);


}


      else


	{


a = 0;


correct (a);


while (!0)

	    {


cout << "\n\t\t\t" << n1 << "*" << n2 << "=";


cin >> y;


cin.clear ();


cin.sync ();


if (y == 888)

		{


cout << "" << endl;


break;


}


	      else if (x == y)


		{


a++;


correct (a);


break;



}


	      else

		{


a = 0;


correct (a);



}


}



}


if (y == 888)


break;


}


}

void Division ()
{

int n1, n2, x, y, mul;

while (1)
    {

srand (time (0));

n1 = (rand () % 10);

n2 = (rand () % 10);

while (n1 == 0 || n2 == 0)
	{

n1 = (rand () % 10) + 1;

n2 = (rand () % 10) + 1;

}

mul = n1 * n2;

x = mul / n2;

cout << "\n\t\t\t" << mul << "/" << n2 << "=";

cin >> y;

cin.clear ();

cin.sync ();


if (y == 888)

	{


cout << "" << endl;


break;

}


      else if (x == y)


	{


a++;


correct (a);


}


      else


	{


a = 0;


correct (a);


while (!0)

	    {


cout << "\n\t\t\t" << mul << "/" << n2 << "=";


cin >> y;


cin.clear ();


cin.sync ();


if (y == 888)

		{


cout << "" << endl;


break;


}


	      else if (x == y)


		{


a++;


correct (a);


break;



}


	      else

		{


a = 0;


correct (a);



}


}




}


if (y == 888)


break;


}


}


void Mixed (int k){
srand (unsigned (time (NULL)));
k = rand () % 4;
switch (k)  {

case 0:
Addition ();
break;

case 1:
Subtraction ();
break;

case 2:
Multiplication ();
break;

case 3:
Division ();
break;


}
}
