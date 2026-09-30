class Solution {
public:

    int solve(int index,int endindex, vector<int>& slices, int n){

        if (n==0 || n > endindex)
        return 0;

        int take = slices[0]+ solve (index+2, endindex, slices, n-1);
        int Ntake = 0 + solve (index+1, endindex, slices, n);

        return max(take, Ntake);
    }

    int solve2(int index,int endindex, vector<int>& slices, int n, vector<vector<int >>&dp){

        if (n==0 || index > endindex)
        return 0;

        if (dp[index][n]!= -1){
            return dp[index][n];
        }
        

        int take = slices[index]+ solve2 (index+2, endindex, slices, n-1, dp);
        int Ntake = 0 + solve2 (index+1, endindex, slices, n, dp);

        return dp[index][n] = max(take, Ntake);
    }
    int maxSizeSlices(vector<int>& slices) {

        int k= slices.size();
        vector<vector<int >> dp1(k+2 , vector<int>(k+2, -1));
        int case1= solve2 (0, k-2, slices,k/3, dp1);

         vector<vector<int >> dp2(k+2 , vector<int>(k+2, -1));
        int case2= solve2 (1, k-1, slices,k/3, dp2);
        return max(case1, case2);

        
    }
};