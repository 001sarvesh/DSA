#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>&arr){
    int n = arr.size();
    for(int i=0; i<n-1; i++){
        //assuming curr pos hold min ele
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(arr[min_idx] > arr[j]){
                min_idx = j;
            }
        }
        if(min_idx != i){
            swap(arr[i], arr[min_idx]);
        }
    }
}

void printArray(vector<int> &arr) {
    for(int &val : arr) {
        cout << val << " ";
    }
    cout<<endl;
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original array: ";
    printArray(arr); 

    selectionSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}