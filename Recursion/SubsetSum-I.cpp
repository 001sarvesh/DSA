 void helper(int idx, int sum, vector<int> &arr, int N,vector<int>&result){
        if(idx== N){
            result.push_back(sum);
            return;
        }
        helper(idx+1, sum+arr[idx], arr,N, result);
        
        helper(idx+1, sum, arr,N, result);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>result;
        sort(arr.begin(), arr.end());
        helper(0,0,arr,N, result);
        return result;
    }