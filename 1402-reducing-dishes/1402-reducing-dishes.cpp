class Solution {
public:


    int solve (vector<int>& satisfaction, int index, int timer,vector<vector<int>>& dp ){

        if (index==satisfaction.size()){
            return 0;
        }

        if(dp[index][timer] != -1){
            return dp[index][timer];
        }

        int include= satisfaction[index]* (timer+1) + solve(satisfaction, index+1, timer+1, dp);

        int exclude= 0 +solve(satisfaction, index+1, timer , dp);

        return dp[index][timer] = max(include, exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {

        sort(satisfaction.begin(), satisfaction.end());
        int n= satisfaction.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1, -1));

        return solve (satisfaction ,0,0, dp);
        
    }
};