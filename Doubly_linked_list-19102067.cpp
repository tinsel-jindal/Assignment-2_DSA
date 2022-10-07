#include<iostream>
using namespace std;

class DLLNode{
    public:
    int val;
    DLLNode *prev;
    DLLNode *next;
    DLLNode(int v){
        val = v;
        prev = NULL;
        next = NULL;
    }
};

void printList(DLLNode *head){
    DLLNode* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

DLLNode* findNode(int val, DLLNode*head){
    DLLNode* temp = head;
    while(temp!=NULL){
        if(temp->val == val)return temp;
        temp = temp->next;
    }
    return NULL;
}

int main(){
    //Creating List
     int n;
    DLLNode *head_prev = new DLLNode(-1);
    DLLNode *last = head_prev;

    cout<<"Enter number of elements required initially"<<endl;
    cin>>n;
    int t;
    cout<<"Start entering values"<<endl;
    for(int i=0;i<n;i++){
        cin>>t;
        last->next = new DLLNode(t);
        last->next->prev = last;
        last = last->next;
    }
    cout<<"The Linked List is"<<endl;
    printList(head_prev->next);


    //Deleting node
    cout<<"Enter value to delete Node"<<endl;
    cin>>t;
    DLLNode *temp = findNode(t, head_prev->next);

    if(temp == NULL){
        cout<<"Can not delete node"<<endl;
    }else{
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        cout<<"New linked list"<<endl;
        printList(head_prev->next);
    }

}