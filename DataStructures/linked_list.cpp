#include<iostream>



using namespace std;

struct Node{
    int data = 0;
    Node* next = NULL;
};

Node* initNode(int value)
{
    Node* head = new Node;
    head->data = value;
    head->next = NULL;
    return head;
}

void appendNode(struct Node* head, int value)
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

void getPosition(struct Node* head,int position)
{
    //position starting from zero
    Node* cNode = head;
    for(int i = 0; i < position; i++)
    {
        if(i == position - 1)
        {
            printf("%d",cNode->data) ;
        }
        cNode = cNode->next;
    }

}

int main()
{
Node* head ;
head = initNode(10);
appendNode(head,20);
appendNode(head,30);
appendNode(head,40);
getPosition(head,1);
}