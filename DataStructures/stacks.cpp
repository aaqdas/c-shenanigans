#include<iostream>
#include <bits/stdc++.h>



using namespace std;

struct Node{
    int data = 0;
    struct Node *next = NULL;
};

Node* initNode(int value)
{
    Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = value;
    head->next = NULL;
    return head;
}

Node* push(Node* head, int value)
{
    // if(head == NULL)
    // {
    //     head -> data = value;
    //     head -> next = NULL;
    // }
    // else
    // {
        Node* c = (struct Node*)malloc(sizeof(struct Node));
        c -> data = value;
        c -> next = head;
        #ifdef DEBUG
        cout <<  "During Insert\n" << c-> data << endl << c->next << endl;
        #endif
        head =  c;
        #ifdef DEBUG
        cout << head-> data << endl << head->next << endl;
        #endif
        return head;
    // }
}

Node* pop(Node* head)
{
    
    if(head == NULL)
    {
        return NULL;
    }
    Node* toDel = head;
    head = head->next;
    delete(toDel);
    return head;
    
    
}

void appendNode(Node* head, int value)
{
    Node* appended = new Node;
    appended->data = value;
    appended->next = NULL;

    Node* cNode = head;
    while(cNode->next != NULL)
    {   
        cNode = cNode->next;
    }
    cNode->next = appended;    
    
}

void getPosition(Node* head,int position)
{
    //position starting from zero
    Node* cNode = head;
    for(int i = 0; i < position; i++)
    {
        if(i == position - 1)
        {
            cout << cNode->data ;
            cout <<"\n";
        }
        cNode = cNode->next;
    }

}

int main()
{
struct Node* stack = new Node;
stack = initNode(10);

#ifdef DEBUG
cout << "Before Insert \n" << stack->data << endl;
cout << stack->next << endl;
#endif

stack = push(stack,20);

#ifdef DEBUG
cout << "After Insert \n" << stack->data << endl;
cout << stack->next << endl;
#endif

stack = push(stack,30);

stack = push(stack,40);

getPosition(stack,1);
getPosition(stack,3);

stack = pop(stack);

getPosition(stack,1);
getPosition(stack,3);







}