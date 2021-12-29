#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, target;
    cin>>n;

    int arr[n];
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cin>>target;
    // 1. sort the array so that we can apply two-pointer approach
    sort(arr, arr+n);

    // 2. apply two-pointer approach fixing one element each time
    for (int i=0;i<=(n-3);i++) {
        int left=i+1;
        int right=n-1;
        while (left<right) {
            int sum=arr[left]+arr[right]+arr[i];
            if (sum == target) {
                cout<<arr[i]<<", "<<arr[left]<<" and "<<arr[right]<<endl;
                left++;
                right--;
            } else if (sum < target) {left++;}
            else if (sum > target) {right--;}
        }
    }

    return 0;
}
