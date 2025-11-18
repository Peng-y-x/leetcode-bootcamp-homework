class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return false;
        }
        vector<int> prefix = {nums[0]};
        for(int i = 1; i < n; i++){
            prefix.push_back(prefix[i-1] + nums[i]);
        }
        if(prefix[n-1] % 2 == 1){
            return false;
        }
        int subSum = prefix[n-1] / 2;
        vector<vector<int>> dp (n+1, vector<int>(subSum + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= subSum; j++){
                if(j < nums[i-1]){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][subSum];
    }
};
