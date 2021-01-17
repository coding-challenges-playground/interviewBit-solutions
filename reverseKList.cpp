#include <iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node (int d) {
        data = d;
        next=NULL;
    }
};

// recursive function to reverse the k list elements
node* reverseList (node* head, int k) {
    // base case
    if (head == NULL) {
        return head;
    }
    
    // recursive case
    // reverse the first k elements in the list
    node* subListTail = head;

    for (int i=0;i<k-1;i++) {
        subListTail = subListTail->next;
    }
    node* rest = subListTail->next;
    node* currptr = head;
    node* nextptr = head->next;

    // reverse the sublist
    while (nextptr != rest) {
        node* temp = nextptr->next;
        nextptr->next = currptr;
        currptr = nextptr;
        nextptr = temp;
    }
    head->next = reverseList(rest, k);
    return subListTail;
}

int main() {
    int n, k, data;
    node* head=NULL;
    node* tail = head;
    cin>>n>>k;
    for (int i=0;i<n;i++) {
        cin>>data;
        node* newnode = new node(data);
        if (head == NULL) {
            head = newnode;
            tail = head;
        }
        else {
            tail->next = newnode;
            tail = newnode;
        }
    }
    head = reverseList(head, k);
    // print the linked list
    node* temp = head;
    while (temp->next !=NULL) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
    return 0;
}
