//Mock ka code!

#include <iostream>
using namespace std;

class node{
    int data;
    node* next;
    node* prev;

    public:
    node(int data = 0){
        this->data = data;
        next = prev = nullptr;
    }
    friend class operations;
};

class operations{
    public:
    node* head = nullptr;
    int n;

    void createll(){
    cout<<"\nHow many nodes you want in the list(As it is binary operation consider moving with 8 or 16)";
    cin>>n;
    if(head == nullptr){
        int val;
        cout<<"\nEnter value for first node :";
        cin>>val;
        node* newnode = new node(val);
        head = newnode;
        n--;
    }
    node* t = head;
    for(int i=0;i<n;i++){
        int val;
        cout<<"\nEnter value for "<<i+2<<" node :";
        cin>>val;
        node* newnode = new node(val);
        t->next = newnode;
        newnode->prev = t;
        t = newnode;
    }
    }

    node* ones(){
        node *t = head;
        while(t){
            t->data = !t->data;
            t = t->next;
        }
        return head;
    }

    node* twos(node* head2){
        node* t = head2;
        while (t->next)
        {
            /* code */
            t = t->next;
        }
        int carry = 1;
        while(t){
            t->data = !t->data;
            if(t->data == 1 && carry == 1){
                carry = 1;
                t->data = 0;
            }
            else if((t->data == 0 && carry == 1) || (t->data == 1 && carry == 0)){
                carry = 0;
                t->data = 1;
            }
            else carry = 0;
            t = t->prev;
        }
        return head2;
    }

    node* add_2_bin(node* head3,node* head4){
        node* t1 = head3;
        node* t2 = head4;
        while(t1->next) t1 = t1->next;
        while(t2->next) t2 = t2->next;

        int carry = 0;
        while (t1 || t2){
            int sum = carry;
            if(t1) sum += t1->data;
            if(t2) sum += t2->data;

            int value = sum % 2;
            carry = sum/2;

            if(t1){
                t1->data = value;
                t1 = t1->prev;
            }
            else if(!t1){
                node* newnode = new node(value);
                newnode->next = head3;
                head3->prev = newnode;
                head3 = newnode;
            }
            if(t2) t2 = t2->prev;
        }
        return head3;
    }

    void display(node* head1){
        node* t = head1;
        while (t)
        {
            cout<<t->data<<"->";
            t = t->next;
        }
        cout<<"NULL";
    }
};

int main(){
    operations op;
    op.createll();

    node* head1 = op.ones();
    cout<<"\n\nOnes === ";
    op.display(head1);
    
    cout<<"\n\nTwos of Ones's is === ";
    node* twos_comp = op.twos(head1);
    op.display(twos_comp);
    
    cout<<"\n\n Additon of two binary numbers is: ";
    node* added = op.add_2_bin(twos_comp,twos_comp);
    op.display(added);
    
    return 0;
}
