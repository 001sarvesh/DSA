class Solution{
public:
int dp[1002][1002];
    int helper(string &str1, string &str2, int i, int j, int &res){
        if(i<0 || j < 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(str1[i] == str2[j]){
            int len =  1+ helper(str1,str2,i-1,j-1,res);
            res = max(res,len);
            return dp[i][j] = len;
        }
        else{
            return dp[i][j] = 0;
        }
    }
    int longestCommonSubstr(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        memset(dp,-1,sizeof(dp));
        
        int res = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                helper(str1,str2,i,j,res);
            }
        }
        return res;
    }
};
