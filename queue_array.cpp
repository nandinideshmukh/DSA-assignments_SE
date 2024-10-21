/******************************************************************************

DQueue using array

*******************************************************************************/
#include <iostream>
using namespace std;

#define size 10

class Dq{
    
    int arr[size];
    int front;
    int rear;
    public:
    Dq(){
        front = -1;
        rear = -1;
    }
    
    bool empty(){
        return front ==-1;
    }
    
    bool full(){
        return (front==0 && rear == size-1);
    }
    
   void push_front(int val){
        if (full()) {
            cout << "\nDeque is full!";
            return;
        }
        
        if (empty()) {
            front = rear = 0;  
        } 
        else if (front == 0) {
            front = size - 1;
        } 
        else {
            front--;
        }
        arr[front] = val;
    }
    
    void push_rear(int val){
        if(full()) cout<<"\nFull!!";
        else{
            arr[++rear ] = val;
        }
    }
    void pop_front(){
        if(empty()) return;
        else{
            front++;
        }
    }
    int getfront(){
        return arr[front];
    }
    int getback(){
        return arr[rear];
    }
};

int main()
{
    Dq dq;
    dq.push_front(10);
    dq.push_rear(20);
    cout<<dq.getfront();
    cout<<dq.full();

    return 0;
}
