#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&arr){
    int n = arr.size();
    bool flag;
    for(int i=0; i<n-1; i++){
        flag = false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = true;
            }
        }
        if(flag != true){
            break;
        }
    }
}
void printArray(vector<int>&arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    vector<int>arr = {64,34,52,12,40,45,60};
    bubbleSort(arr);
    cout<<"Sorted Array: \n";
    printArray(arr);
    return 0;
}