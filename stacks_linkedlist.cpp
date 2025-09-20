#include <iostream>
using namespace std ;

struct node{
    int data ;
    node* next ;
} ;
class Stack {
    private: 
        node* top ;
    
    public :
        Stack(){
            top = nullptr ;
        }

        bool isempty() {
            return (top == nullptr) ;
        }

        void push(int x){
            node* newnode = new node() ;
            newnode -> data = x ;
            newnode -> next = top ;
            top = newnode ;
            cout << x << " pushed into the stack.\n" ;
            return ;
        }

        void pop() {
            if (isempty()){
                cout << "Stack underflow. Cannot pop :(\n" ;
                return ;
            }
            node* temp = top ;
            cout << temp -> data << " popped out of the stack.\n" ;
            top = top -> next ;
            delete temp ;

        }

        void stacktop(){
            if (isempty()) {
                cout << "Stack is empty.\n" ;
                return ;
            }
            cout << "Top element is: " << top->data << endl;

        }

        void display() {
            node* temp = top ;
            cout << "Your stack is: \n" ;
            while(temp != nullptr) {
                cout << temp->data << "\n";
                temp = temp -> next ;
            }
        }  
} ;

int main() {
    Stack s ;
    int value, choice ;
    cout << "--MENU--" ;
    cout << "\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n" ;
    do{
        cout << "Enter your choice: " ;
        cin >> choice ;
        switch(choice) {

            case 1 :
                cout << "Enter a number to push: " ;
                cin >> value ;
                s.push(value) ;
                break ;
            
            case 2 :
                s.pop() ;
                break ;
            
            case 3 :
                s.stacktop() ;
                break ;

            case 4 :
                s.display() ;
                break ;

            case 5 :
                cout << "Exiting........." ;
                break ;

            default :
                cout << "Invalid input! " ;
                break ;
        }
    } while(choice != 5) ;
    return 0 ;
}