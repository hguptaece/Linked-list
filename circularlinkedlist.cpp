#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
        T data;
        Node<T>* next;

        Node(T data){
            this->data=data;
            this->next=NULL;
        }
};

template<class T>
class CircularLL{
    private:
        Node<T>* head;
        int length;

    public:
        CircularLL(){
            head=NULL;
            length=0;
        }

        void display(){
            Node<T>* temp=head;

            do{
                cout<<temp->data<<" --> ";
                temp=temp->next;
            }while(temp != head);
            cout<<"\n";
        }

        //O(1)
        void insertHead(T data){
            Node<T>* ptr=new Node<T>(data);
            length++;

            if(head == NULL){
                head=ptr;
                ptr->next=head;
            }else{
                Node<T>* temp=head;
                while(temp->next != head){
                    temp=temp->next;
                }

                //rewiring
                ptr->next=head;
                temp->next=ptr;
                head=ptr;
            }
        }
        //O(1)
        void insertLast(T data){
            Node<T>* ptr=new Node<T>(data);
            length++;

            if(head == NULL){
                head=ptr;
                ptr->next=head;
            }else{
                Node<T>* temp=head;
                while(temp->next != head){
                    temp=temp->next;
                }

                //rewiring
                temp->next=ptr;
                ptr->next=head;
            }
        }

        void insert(T data,int pos){
            if(pos==1){
                insertHead(data);
            }else if(pos==length){
                insertLast(data);
            }else{
                length++;
                Node<T>* ptr=new Node<T>(data);       
                length++;
                Node<T>* temp=head;

                for(int i=0;i<pos-2;i++){
                    temp=temp->next;
                }
                ptr->next=temp->next;
                temp->next=ptr;
            }
        }
        T deleteHead(){
            if(head==NULL){
                cout<<"LinkedList is Empty\n";
                return NULL;
            }else if(head->next == head){
                T deleted=head->data;
                delete(head);
                head=NULL;
                length--;
                return deleted;
            }else{
                length--;
                Node<T>* temp=head;
                while(temp->next != head){
                    temp=temp->next;
                }

                //rewiring
                temp->next=head->next;
                T deleted=head->data;
                Node<T>* ptr=head;
                head=head->next;
                delete(ptr);
                return deleted;
            }
        }

        T deleteLast(){
            if(head==NULL){
                cout<<"LinkedList is Empty\n";
                return NULL;
            }else if(head->next == head){
                T deleted=head->data;
                delete(head);
                head=NULL;
                length--;
                return deleted;
            }else{
                length--;
                Node<T>* temp=head;
                while(temp->next->next != head){
                    temp=temp->next;
                }

                //rewiring
                Node<T>* ptr=temp->next;
                temp->next=head;
                T deleted=ptr->data;
                delete(ptr);
                return deleted;
            }
        }

        T deletePos(int pos){
            if(pos==1){
                return deleteHead();
            }else if(pos==length){
                return deleteLast();
            }else{
                Node<T>* temp=head;
                length--;
                
                for(int i=0;i<pos-2;i++){
                    temp=temp->next;
                }

                Node<T>* X=temp->next;
                temp->next=X->next;
                T deleted=X->data;
                delete(X);
                return deleted;
            }
        }
};

int main(){
    CircularLL<char> cll;
    cll.insertHead('a');
    cll.insertHead('b');
    cll.insertHead('c');
    cll.insertLast('d');
    cll.display();
    cll.insert('z',3);
    cll.display();
    cout<<" deleted is: "<<cll.deletePos(2)<<"\n";
    cll.display();


    return 0;
}