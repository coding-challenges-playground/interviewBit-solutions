#include <iostream>
using namespace std;

// recursive program to generate brackets

void bracket (char *out, int n, int open, int close, int index) {
    // base case
    if (index == 2*n) {
        out[index] = '\0';
        cout<<out<<endl;
        return ;
    }

    // rec case
    if (open < n) {
        out[index] = '(';
        bracket(out, n, open+1, close, index+1);
    }

    if (close < open) {
        out[index] = ')';
        bracket(out, n, open, close+1, index+1);
    }
    return;
}

int main () {
    char out[1000];
    int n;
    cout<<"enter the no of brackets:- ";
    cin>>n;
    bracket(out, n, 0, 0, 0);
    return 0;
}
