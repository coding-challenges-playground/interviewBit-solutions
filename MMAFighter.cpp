#include <iostream>
#include <deque>

using namespace std;
int main() {
    int n, k;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cin>>k;
    deque<int> Q(k);
    int i=0;
    // handle the first k elements separately
    for (;i<k;i++) {
        while (!Q.empty() && arr[i] > arr[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i);
    }

    // handle rest of the elements
    for (;i<n;i++) {
        cout<<arr[Q.front()]<<" ";
        // remove those elements which are not part of the window
        while (!Q.empty() && (Q.front() <= i-k)) {
            Q.pop_front();
        }
        // check for the new window to find the greater element
        while (!Q.empty() && arr[i] > arr[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i);
    }
    cout<<arr[Q.front()];
    return 0;
}
