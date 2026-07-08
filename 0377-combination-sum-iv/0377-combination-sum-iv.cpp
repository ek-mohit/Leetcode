

/*int solve (vector<int>& nums,int tar , vector<int> &dp){

    if (tar< 0) return 0;
    if(tar==0) return 1;

    if( dp[tar] != -1) return dp[tar];

    int ans=0;

    for (int i=0;  i < nums.size()  ; i++){
         ans += solve(nums, tar-nums[i], dp);


    }
    dp[tar]= ans;
    return dp[tar];
}
*/
class Solution {
public:

    int solveTab(vector<int>& nums, int target) {

        vector<unsigned int> dp(target + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {

                if (i >= nums[j]) {
                    dp[i] += dp[i - nums[j]];
                }

            }
        }

        return dp[target];
    }

    int combinationSum4(vector<int>& nums, int target) {

        return solveTab(nums, target);

    }
};