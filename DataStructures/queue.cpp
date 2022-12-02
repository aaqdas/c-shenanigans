//#define DEBUG
#include<iostream>
#include <bits/stdc++.h>



using namespace std;

struct Node{
    int data = 0;
    struct Node *next = NULL;
};
class Queue
{
    private:
    Node* queue = new Node;
    public:
    Queue(int new_element)
    {
        queue->data = new_element;
        queue->next = NULL;

    }
    

    void enqueue(int new_element)
    {
            Node* newNode = new Node;
            newNode -> data = new_element;
            newNode -> next = NULL;

            Node* cNode = queue;
            #ifdef DEBUG
                cout << "Enqueue -  DEBUG_LOG_BEGIN\n" << queue->data << " , " << queue->next << endl;   
                cout << "Enqueue -  DEBUG_LOG_END" << endl;       
            #endif 
                
            while(cNode->next)
            {
                cNode = cNode -> next;
            }
            cNode->next = newNode;
    }
    int dequeue()
    {
        int retVal = queue->data;
        queue = queue->next;
        return retVal;
    }
    
    int peek()
    {
        
        if(queue == NULL)
        {
            return NULL;
        }
        int retVal;
        
        return queue->data;
        
        
    }



};

int main()
{
Queue my_queue = Queue(10);

my_queue.enqueue(20);
my_queue.enqueue(30);

cout << my_queue.dequeue() << endl;

cout << my_queue.dequeue() << endl;

cout << my_queue.peek() << endl;

cout << my_queue.peek() << endl;



#ifdef DEBUG
#endif


}