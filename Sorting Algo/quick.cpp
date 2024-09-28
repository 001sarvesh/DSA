#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr,int low,int high){
    int pivot = arr[high];

    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    for(int j = low; j<= high-1; i++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    // Move pivot after smaller elements and
    // return its position
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int>&arr, int low, int high){
// 1. Choose a pivot
// 2. Partition the array around pivot. After partition, it is ensured that all elements are smaller than all right and we get index of the end point of smaller elements. The left and right may not be sorted individually.
// 3. Recursively call for the two partitioned left and right subarrays.
// 4. We stop recursion when there is only one element is left.
    int n = arr.size();
    if(low < high){
        int partition_idx = partition(arr,low,high);
        quickSort(arr,low,partition_idx-1);
        quickSort(arr,partition_idx+1,high);
    }
}

void printArray(vector<int>&arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int>arr = {22,12,34,1,3,5,6};
    int n = arr.size();
    quickSort(arr,0,n-1);
    printArray(arr);
    return 0;
}