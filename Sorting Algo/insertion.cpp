#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>&arr){
//We start with second element of the array as first element in the array is assumed to be sorted.
// Compare second element with the first element and check if the second element is smaller then swap them.
// Move to the third element and compare it with the second element, then the first element and swap as necessary to put it in the correct position among the first three elements.
// Continue this process, comparing each element with the ones before it and swapping as needed to place it in the correct position among the sorted elements.
// Repeat until the entire array is sorted.
    int n = arr.size();
    for(int i=1; i<n; i++){
    int element = arr[i];
    int j = i-1;

    while(j>=0 && arr[j] > element){
        arr[j+1] = arr[j];
        j = j-1;
    }
    arr[j+1] = element;
}
}

void printArray(vector<int>&arr){
    int n = arr.size();
    for(int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    vector<int>arr = {22,12,34,1,3,5,6};
    insertionSort(arr);
    printArray(arr);
    return 0;
}