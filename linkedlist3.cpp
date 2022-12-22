#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
       int data;
        Node* next;

        Node(int data){
            this->data=data;
            this->next=NULL;
        }
};

class LinkedList{
    private:
        Node* head;
        int length;
        
    public:
        LinkedList(){
            head=NULL;
            length = 0;
        }
        //time complexityo(1)
        void insertHead(int data){
            Node* ptr= new Node(data);
            length++;
            if(head==NULL){
                head=ptr; 
                return ;
            }
            ptr->next=head;
            head=ptr;

        }
        //TC o(1)
        void insertLast(int data){
            Node* ptr=new Node(data);
            length++;
            if(head==NULL){
                head=ptr;
                return ;
            }
            Node*temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=ptr;

        }
        //o(n)
        void insert(int data, int pos){
            if(pos==1){
                insertHead(data);
            }
            else if(pos==length){
                insertLast(data);
            }
            else{
                Node* ptr=new Node(data);
                length++;
                Node* temp=head;

                for(int i=0; i<pos-2; i++){
                    temp=temp->next;
                }
                ptr->next=temp->next;
                temp->next=ptr;
            }
        }
       
        // TC o(n) 
        int deleteHead(){
            if(head==NULL){
                cout<<"Your LinkedList is Empty..\n";
                return -1;
            }else if(head->next==NULL){
                int deleted=head->data;
                delete(head);
                head=NULL;
                return deleted;
            }else{
                int deleted=head->data;
                Node* temp=head;
                head=head->next;
                delete(temp);
                return deleted;
            }
        }

        //TC o(n)
        int deleteLast(){
            if(head==NULL){
                cout<<"Your LinkedList is Empty..\n";
                return -1;
            }else if(head->next==NULL){
                int deleted=head->data;
                delete(head);
                head=NULL;
                return deleted;
            }else{
                Node* temp=head;
                while(temp->next->next != NULL){
                    temp=temp->next;
                }
                int deleted=temp->next->data;
                delete(temp->next);
                temp->next=NULL;
                return deleted;
            } 
        }

        //o(n)
        int deletePos(int pos){
            if(pos==1){
                return deleteHead();
            }
            else if(pos==length){
                return deleteLast();
            }
            else{
                Node* temp=head;
                length--;
                for(int i=0; i<pos-2; i++){
                    temp=temp->next;
                }
                Node* X= temp->next;
                temp->next=X->next;
                int deleted=X->data;
                delete(X);
                return deleted;
            }
        }

        //TC o(n)
        void Display(){
            Node*temp=head;
            while(temp != NULL){
                cout<<temp->data<<" , ";
                temp= temp->next;
            }
            cout<<"\n";
        }
};
int main(){
    LinkedList ll1;
    ll1.insertLast(5);
    ll1.insertLast(6);
    ll1.insertLast(10);
    ll1.insertLast(12);
    ll1.insertLast(14);

    ll1.Display();
    ll1.insert(7,4);
    
    ll1.Display();
    ll1.deletePos(3);
    ll1.Display();
    return 0;
}
 

