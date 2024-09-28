#include<bits/stdc++.h>
using namespace std;

// Merge function to combine two sorted subarrays
void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // Merge elements from both subarrays in sorted order
    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    // Add remaining elements from the left subarray
    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }

    // Add remaining elements from the right subarray
    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }

    // Copy sorted elements back to the original array
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
}

// MergeSort function to recursively sort the array
void mergeSort(vector<int>& nums, int low, int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}
vector<int> sortArray(vector<int>& nums) {
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
}

void printArray(vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {12, 11, 13, 5, 6, 7};
    cout << "Original array: ";
    printArray(nums);
    vector<int> sortedArray = sortArray(nums);

    cout << "Sorted array: ";
    printArray(sortedArray);

    return 0;
}
