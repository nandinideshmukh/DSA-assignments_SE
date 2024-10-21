
#include <iostream>
using namespace std;

#define size 100

template<typename S>
class Dq{
    int count =-1;
    template<typename N>
    struct ele{
    N data;
    int priority;
    };
    
    public:
    ele<S> arr[size];
    Dq(){ }
    void enqueue(S val,int p){
        count++;
        arr[count].data = val;
        arr[count].priority = p;
    }
    
    int top()
    {
        int max = 0;
        for(int i=0;i<=count;i++) {
            if(arr[i].priority > arr[max].priority)
                max = i;
        }
        return max;
    }
    
    void deque(){
        int max = top();
        for(int i=max;i<count;i++){
            arr[i] = arr[i+1];
        }
        count--;
    }
    
    void display()
    {
        for(int i=0;i<=count;i++)
            cout<<"( "<<arr[i].data<<" -> "<<arr[i].priority<<" )"<<endl;
    }
};

int main()
{
    Dq<float> dq;
    dq.enqueue(2.3,0);
    dq.enqueue(1.0,2);
    dq.deque();
    dq.display();
    

    return 0;
}
