#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
};
void InsertAtEnd(Node** head,int val){

 //creating a new node
  Node* newNode= new Node();
 newNode->data=val;
    newNode->next=NULL;

    //CHECKING THE HEAD NODE
    if(*head==NULL){
        *head=newNode;
        return;
    }
    //traversing through node


    Node* last=*head;
    while(last->next!=NULL){

        last=last->next;
    }

    //inserting a insert at last Node

    last->next=newNode;
}

void InsertAtStart(Node** head,int val){
//Prepare new node
Node* newNode=new Node();
newNode->data=val;
//Put it infront of current head
newNode->next=*head;

//move head of the list to point to the new node
*head=newNode;

}
void print(Node* n){
while(n!=NULL)
{
 cout<<n->data<<" ";
 n=n->next;
}
}

int main(){
Node *head=NULL;
InsertAtEnd(&head,-1);
InsertAtEnd(&head,2);
InsertAtEnd(&head,3);
InsertAtStart(&head,0);
InsertAtStart(&head,5);

print(head);
return 0;
}
