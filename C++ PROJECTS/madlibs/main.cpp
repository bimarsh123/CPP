#include <iostream>
#include<stdlib.h>
#include "conio.h"
using namespace std;

void MainMenu(){
cout<<"\n\t================= Mad Libs =================="<<endl;
cout<<"\n"<<endl;
cout<<"\n\t********************************************"<<endl;
cout<<"\n\t$   1.Summer camp             2.War        $"<<endl;
cout<<"\n\t$                                          $"<<endl;
cout<<"\n\t$   3.Alien Encounter         4.Halloween  $"<<endl;
cout<<"\n\t$                                          $"<<endl;
cout<<"\n\t$                 5.Exit                   $"<<endl;
cout<<"\n\t********************************************"<<endl;
cout<<"\n"<<endl;
}
 void summercamp(){
string Name,Camp,Adjective,Activity,activity,Noun,adjective,noun,nickname;
cout<<"Enter name of a family member:";
cin>>Name;
cout<<"Enter name of a camp:";
cin>>Camp;
cout<<"Enter an adjective:";
cin>>Adjective;
cout<<"Enter an activity:";
cin>>Activity;
cout<<"Enter an activity:";
cin>>activity;
cout<<"Enter a plural noun:";
cin>>Noun;
cout<<"Enter an adjective:";
cin>>adjective;
cout<<"Enter a noun:";
cin>>noun;
cout<<"Enter a nickname:";
cin>>nickname;
cout<<"\n";
cout<<"\n";
cout<<"Dear "<<Name<<','<<endl;
cout<<"Here I am at "<<Camp<<" camp!.I am having a "<<Adjective<<" time."<<endl;
cout<<"So far I have gone "<<Activity<<" and "<<activity<<'.'<<endl;
cout<<"My favorite thing about camp is "<<Noun<<'.'<<endl;
cout<<"They are so "<<adjective<<".I miss "<<noun<<" though.See you soon!"<<endl;
cout<<"\t\t\t\t\t\t\t\t\tYours "<<nickname<<endl;
cout<<"\n";
cout<<"\n";
}
void War(){
string noun1,noun2,noun3,occupation,verb,place,verb1,noun4,verb2,plural_noun,noun5,emotion;
cout<<"Enter a Noun:";
cin>>noun1;
cout<<"Enter a Noun:";
cin>>noun2;
cout<<"Enter a Noun:";
cin>>noun3;
cout<<"Enter an occupation:";
cin>>occupation;
cout<<"Enter a verb:";
cin>>verb;
cout<<"Enter a place:";
cin>>place;
cout<<"Enter a verb:";
cin>>verb1;
cout<<"Enter a Noun:";
cin>>noun4;
cout<<"Enter a verb:";
cin>>verb2;
cout<<"Enter a plural noun:";
cin>>plural_noun;
cout<<"Enter a Noun:";
cin>>noun5;
cout<<"Enter a emotion:";
cin>>emotion;
cout<<"\n";
cout<<"\n";
cout<<"It was during the battle of "<<noun1<<" when I was running through a "<<noun2<<" when a "<<noun3<<" went off right next to my platoon."<<endl;
cout<<"Our "<<occupation<<" yelled for us to "<<verb<<" to the nearest "<<place<<" we could find."<<endl;
cout<<"When we got to the "<<place<<" we "<<verb1<<" to start a fire."<<endl;
cout<<"As we were starting the fire the enemy saw the "<<noun4<<" from the fire and started "<<verb2<<" "<<plural_noun<<" at us."<<endl;
cout<<"we all quickly ducked behind the "<<noun5<<" at the "<<place<<" and returned fire."<<endl;
cout<<"we quickly eliminated the enemy and were "<<emotion<<" that we had won the battle."<<endl;
cout<<"\n";
cout<<"\n";
}
void Alien(){
string verb_ing,verb_ed,vehicle,animal,food,noun,number;
cout<<"Enter a movement verb ending with 'ing':";
cin>>verb_ing;
cout<<"Enter a verb ending with 'ed':";
cin>>verb_ed;
cout<<"Enter a vehicle:";
cin>>vehicle;
cout<<"Enter an animal:";
cin>>animal;
cout<<"Enter a food:";
cin>>food;
cout<<"Enter a noun:";
cin>>noun;
cout<<"Enter a number:";
cin>>number;
cout<<"\n";
cout<<"\n";

cout<<"I was "<<verb_ing<<" along the sidewalk when an alien "<<verb_ed<<" me. I was into their "<<vehicle<<" and it blasted off."<<endl;
cout<<"Then the alien asked me to switch on the T.V. I was suprised they spoke English."<<endl;
cout<<"The aliens had a pet "<<animal<<", which is a bit strange but I'll let it slide."<<endl;
cout<<"As we came back into the galaxy, one alien asked me if I wanted a "<<food<<". I said no but I would like a "<<noun<<endl;
cout<<"He got it for me and then dropped me off at my place. Then I realized I had been gone for "<<number<<" years!"<<endl;
cout<<"\n";
cout<<"\n";

}

void Halloween(){
string season,clothes,place,person,adjective,body_part,verb,adjective2,noun2,food,plural_noun;
cout<<"Enter a season:";
getline(cin,season);
cout<<"Enter a clothes:";
getline(cin,clothes);
cout<<"Enter a place:";
getline(cin,place);
cout<<"Enter a person:";
getline(cin,person);
cout<<"Enter an adjective:";
getline(cin,adjective);
cout<<"Enter a body part(plural):";
getline(cin,body_part);
cout<<"Enter a verb:";
getline(cin,verb);
cout<<"Enter an adjective:";
getline(cin,adjective2);
cout<<"Enter a noun:";
getline(cin,noun2);
cout<<"Enter a food:";
getline(cin,food);
cout<<"Enter a plural noun:";
getline(cin,plural_noun);
cout<<"\n";
cout<<"\n";

cout<<"I can't believe it's already "<<season<<" holiday! I can't wait to put on my "<<clothes<<" and visit every "<<place<<" in my neighborhood."<<endl;
cout<<"This year, I am going to dress up as (a) "<<person<<" with "<<adjective<<" "<<body_part<<"."<<endl;
cout<<"Before I "<<verb<<", I make sure to grab my "<<adjective2<<" "<<noun2<<" to hold all of my "<<food<<"."<<endl;
cout<<"Finally, all of my "<<plural_noun<<" are ready to go!"<<endl;
cout<<"\n";
cout<<"\n";

}
int main()
{
    system("color 1A");
    int choice=1;
    while(choice!=5)
    {

         MainMenu();
         cout<<"Please choose:";

        while(!(cin>>choice)||choice<1||choice>5){
            cout<<"Invalid choice. Choose again:";
            cin.clear(); //clear the status of cin
            cin.sync();// clear input buffer
        }
        if(choice==5)
            break;


        cout<<"Your choice is:"<<choice<<endl;
        cin.sync();//clear input buffer
        switch(choice)
        {
        case 1:
            system("color 8e");
            summercamp();
            break;

        case 2:
            system("color 1f");
            War();
            break;

        case 3:
            system("color 6e");
            Alien();
            break;

        case 4:
            system("color 2e");
            Halloween();
            break;


        }
    }
    cout<<"See you next time.Bye Bye";



    return 0;
}
