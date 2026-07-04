class Solution {
public:



int solve(vector<int>&nums , int i){
  /*int n= nums.size();

    if(i>=n) return 0;
    

     if(dp[i]!=-1) return dp[i];

    int inc = solve(nums, i+2,dp) + nums[i];
    int exl = solve(nums, i+1, dp) + 0;

   

   

    dp[i]= max(inc, exl);
    return dp[i];

    */
    int n= nums.size();
    vector<int> dp(n+2,0);

    for(int i= n-1 ; i>=0; i--){
        int incl = dp[i+2]+nums[i];
        int excl = dp[i+1];

        dp[i]= max(incl, excl);
    }
    return dp[0];

    

}
    int rob(vector<int>& nums) {
         /* int n= nums.size();

       vector<int> dp(n,-1);

        int ans= solve(nums,0,dp);
        return ans;
        */

        return solve(nums, 0);
        
    }
};