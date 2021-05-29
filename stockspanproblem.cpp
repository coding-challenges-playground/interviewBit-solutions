#include <iostream>
#include <stack>

using namespace std;
// stock span problem
int main() {
    stack <pair<int, int>> s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
         int el;
        cin>>el;
        if (i == 0){
           cout<<"1 ";
           s.push(make_pair(el, 1));
        }
        else {
            pair<int , int> topel = s.top();
            if (el >= topel.first) {
                cout<<topel.second+1<<" ";
                s.push(make_pair(el, topel.second+1));
            }
            else {
                cout<<"1 ";
                s.push(make_pair(el, 1));
            }
        }
    }
    cout<<"END";
    return 0;
}
