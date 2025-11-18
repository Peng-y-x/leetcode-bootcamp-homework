class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        vector<int> dp (amount + 1, amount + 1);
        dp[0] = 0;
        int c = coins.size();
        for(int i = 1; i < amount + 1; i++){
            int mini = amount + 1;
            for(int j = 0; j < c; j++){
                if(coins[j] <= i){
                    mini = min(mini, dp[i - coins[j]] + 1);
                }
            }
            if(mini != amount + 1){
                dp[i] = mini;
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
