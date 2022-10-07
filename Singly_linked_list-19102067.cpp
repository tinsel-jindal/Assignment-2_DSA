#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node *next;
    Node(int v){
        val = v;
        next = NULL;
    }
};

void printList(Node *head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* findNode(int val, Node*head){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->val == val)return temp;
        temp = temp->next;
    }
    return NULL;
}

int main(){
    //creating a linked list
    int n;
    Node *head_prev = new Node(-1);
    Node *last = head_prev;

    cout<<"Enter number of elements required initially"<<endl;
    cin>>n;
    int t;
    cout<<"Start entering values"<<endl;
    for(int i=0;i<n;i++){
        cin>>t;
        last->next = new Node(t);
        last = last->next;
    }
    cout<<"The Linked List is"<<endl;
    printList(head_prev->next);

    //Inserting after a value
    cout<<"Enter value after which to insert node"<<endl;
    cin>>t;
    Node *temp = findNode(t, head_prev->next);
    if(temp == NULL){
        cout<<"Can't insert Node"<<endl;
    }else{
        int p;
        cout<<"Enter value to insert"<<endl;
        cin>>p;
        Node* nn = new Node(p);
        nn->next = temp->next;
        temp->next = nn;
        cout<<"New linked list is"<<endl;
        printList(head_prev->next);
    }
}