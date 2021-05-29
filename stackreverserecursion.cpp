#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom (stack<int> &s, int element) {
    // base case
    if (s.empty()) {
        s.push(element);
        return;
    }
    //rec case
    int topElement = s.top();
    s.pop();
    insertAtBottom(s, element);
    s.push(topElement);
    return;
}

void reverseStack(stack<int> &s) {
    // base case
    if (s.empty()) {
        return;
    }
    //rec case
    int element = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, element);
}

int main() {
    stack <int> s;
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        int element;
        cin>>element;
        s.push(element);
    }

    reverseStack(s);
    // printing the stack
    while (!s.empty()) {
        int topelement = s.top();
        cout<<topelement<<endl;
        s.pop();
    }
    return 0;
}
