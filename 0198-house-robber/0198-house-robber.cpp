class Solution {
public:



int solve(vector<int>&nums , int i, vector<int> &dp){
  int n= nums.size();

    if(i>=n) return 0;

     if(dp[i]!=-1) return dp[i];

    int inc = solve(nums, i+2,dp) + nums[i];
    int exl = solve(nums, i+1, dp) + 0;

   

   

    dp[i]= max(inc, exl);
    return dp[i];
}
    int rob(vector<int>& nums) {
          int n= nums.size();

       vector<int> dp(n,-1);

        int ans= solve(nums,0,dp);
        return ans;
        
    }
};