#include <iostream>
using namespace std ;

struct node{
    int data ;
    node* next ;
} ;
class Queue {
    private: 
        node* front ;
        node* rear ;

    public :
        Queue(){
            front = rear = nullptr ;
        }

        bool isempty() {
            return (front == nullptr) ;
        }

        void enqueue(int x){
            node* newnode = new node() ;
            newnode -> data = x ;
            newnode -> next = nullptr ;

            if(rear == nullptr){ 
                front = rear = newnode ;
            } else {
                rear -> next = newnode ;
                rear = newnode ;
            }

            cout << x << " Enqueueed into the Queue.\n" ;
        }

        void dequeue(){
            if(isempty()) {
                cout << "Queue is empty. Cannot dequeue:(" << endl ;
                return ;
            }

            node* temp1 = front  ;
            cout << "Removed " << temp1 -> data << " from the queue." << endl ;
            front = front -> next ;

            if(front == nullptr) {
                rear = nullptr ;
            }
            
            delete temp1 ;
        }

        void frontptr(){
            if(isempty()){
                cout << "Queue is empty.\n" ;
                return ;
            }
            cout << "Front of the Queue is: " << front -> data << endl ;
            return ;
        }

        void rearptr() {
            if (isempty()) {
                cout << "Queue is empty." << endl ;
                return ;
            }
            cout << "Rear of the queue is: " << rear -> data << endl ;
        }

        void display(){
            node* temp = front ;
            cout << "Queue elements: \n" ;
            while(temp != nullptr){
                cout << temp -> data << " " ;
                temp = temp -> next ; 
            }
            cout << endl ;
            return ;
        }
};

int main() {
    Queue q ;
    int value, choice ;
    cout << "--MENU--" ;
    cout << "\n1.Enqueue\n2.Dequeue\n3.Front\n4.Display\n5.Rear\n6.Exit\n" ;
    do{
        cout << "Enter your choice: " ;
        cin >> choice ;
        switch(choice) {

            case 1 :
                cout << "Enter a number to Enqueue: " ;
                cin >> value ;
                q.enqueue(value) ;
                break ;
            
            case 2 :
                q.dequeue() ;
                break ;
            
            case 3 :
                q.frontptr() ;
                break ;

            case 4 :
                q.display() ;
                break ;

            case 5 :
                q.rearptr() ;
                break ;

            case 6 :
                cout << "Exiting........." ;
                break ;

            default :
                cout << "Invalid input! " ;
                break ;
        }
    } while(choice != 6) ;
    return 0 ;
}