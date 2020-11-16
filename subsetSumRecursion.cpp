#include <iostream>
#include <set>
using namespace std;

void printArray (int arr[], int size) {
    for (int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}

// function to sort the array
void selectionSort(int a[], int n) {
   int i, j, min, temp;
   for (i = 0; i < n - 1; i++) {
      min = i;
      for (j = i + 1; j < n; j++)
      if (a[j] < a[min])
      min = j;
      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
   }
}

void printSumSubsets (int inp[], int out[], int i, int j, int n, int sum, int outLength) {

    // base case
    if (i == n) {
        if (sum == 0) {
            // this means this the required combination. print the solution
            printArray(out, outLength);
        }
        return;
    }
    // rec case
    // include the current element
    out[j] = inp[i];
    printSumSubsets(inp, out, i+1, j+1, n, sum - inp[i], outLength+1);

    // exclude the current element
    printSumSubsets (inp, out, i+1, j, n, sum, outLength);
    return ;
}

int main() {
    int n, sum;
    cin>>n;
    int *arr = new int[n];
    int *out = new int[n];
    // input the array
    // add the sorting logic also
    for (int k=0;k<n;k++) {
        cin>> arr[k];
    }
    cin>>sum;
    selectionSort(arr, n);
    printSumSubsets(arr, out, 0, 0, n, sum, 0);
    return 0;
}
