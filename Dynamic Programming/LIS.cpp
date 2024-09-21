class Solution {
public:
    int n;
    int helper(vector<int>&nums, int idx, int prev, vector<vector<int>>&dp){
        if(idx>=n) return 0;

        if(dp[idx][prev+1] != -1){
            return dp[idx][prev+1];
        }

        int take =0;

        if(prev == -1 || nums[idx] > nums[prev]){
            take = 1+ helper(nums,idx+1,idx,dp);
        }
        int nottake = helper(nums,idx+1,prev,dp);

        int maxi = max(take,nottake);
        return dp[idx][prev+1] =maxi;

    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return helper(nums,0,-1,dp);
    }
};