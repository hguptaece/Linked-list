#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data){
            this->data=data;
            next=NULL;
            prev=NULL;
        }
};

class DoublyLL{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        DoublyLL(){
            head=NULL;
            tail=NULL;
            length=0;
        }

        void display(){
            Node* temp=head;
            
            while(temp != NULL){
                cout<<temp->data<<" , ";
                temp=temp->next;
            }
            cout<<"\n";
        }

        void rDisplay(){
            Node* temp=tail;

            while(temp != NULL){
                cout<<temp->data<<" , ";
                temp=temp->prev;
            }
            cout<<"\n";
        }

        //O(1);
        void insertHead(int data){
            Node* ptr=new Node(data);
            length++;

            if(head==NULL){
                head=ptr;
                tail=ptr;
            }else{
                ptr->next=head;
                head->prev=ptr;
                head=ptr;
            }
        }
        //O(1)
        void insertTail(int data){
            Node* ptr=new Node(data);
            length++;

            if(head==NULL){
                head=ptr;
                tail=ptr;
            }else{
                tail->next=ptr;
                ptr->prev=tail;
                tail=ptr;
            }
        }

        void insert(int data,int pos){
            if(pos==1){
                insertHead(data);
            }else if(pos==length){
                insertTail(data);
            }else{
                length++;
                Node* ptr=new Node(data);

                Node* temp=head;

                for(int i=0;i<pos-2;i++){
                    temp=temp->next;
                }

                Node* temp2=temp->next;
                temp->next=ptr;
                ptr->prev=temp;
                temp2->prev=ptr;
                ptr->next=temp2;
            }
        }

        //O(1)
        int deleteHead(){
            if(head==NULL){
                cout<<"Doubly Linked List is Empty..\n";
                return -1;
            }else if(head==tail){
                int deleted=head->data;
                delete(head);
                head=NULL;
                tail=NULL;
                return deleted;
            }else{
                Node* ptr=head;
                head=head->next;
                int deleted=ptr->data;
                delete(ptr);
                head->prev=NULL;
                return deleted;
            }
        }
        //O(1)
        int deleteTail(){
            if(head==NULL){
                cout<<"Doubly Linked List is Empty..\n";
                return -1;
            }else if(head==tail){
                int deleted=head->data;
                delete(head);
                head=NULL;
                tail=NULL;
                return deleted;
            }else{
                Node* ptr=tail;
                tail=tail->prev;
                tail->next=NULL;
                int deleted=ptr->data;
                delete(ptr);
                return deleted;
            }
        }

        int deletePos(int pos){
            if(pos==1){
                return deleteHead();
            }else if(pos==length){
                return deleteTail();
            }else{
                Node* temp=head;

                for(int i=0;i<pos-1;i++){
                    temp=temp->next;
                }

                Node* x=temp->prev; //deleted node previos
                Node* y=temp->next; //deleted node next
                y->prev=x;
                x->next=y;
                int deleted=temp->data;
                delete(temp);
                return deleted;
            }
        }
};

int main(){
    DoublyLL dll;
    dll.insertHead(10);
    dll.insertHead(20);
    dll.insertTail(30);
    dll.display();
    dll.insertTail(40);
    dll.display();
    dll.deleteTail();
    dll.display();
    return 0;
}