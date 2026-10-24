
class Solution {
public:
    int solve(string &s1, string &s2, int i, int j,
              vector<vector<int>>& dp) {

        if (i >= s1.size() || j >= s2.size()) {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] =
                1 + solve(s1, s2, i + 1, j + 1, dp);
        }

        return dp[i][j] = max(
            solve(s1, s2, i + 1, j, dp),
            solve(s1, s2, i, j + 1, dp)
        );
    }

    int solvetab(string &s1, string &s2){
        
        int n1 = s1.size();
        int n2= s2.size();
        vector<vector<int >> dp(n1+1, vector<int>(n2+1 ,0));

        for (int i = n1-1 ; i >=0; i-- ){
            for (int j = n2-1 ; j>=0 ; j--){

                if (s1[i] == s2[j]) {
                    dp[i][j]=  1 + dp[i+1][j+1];
                }


                else{
                    dp[i][j]= max ( dp[i+1][j], dp[i][j+1] );
                }
        


            }
            
        }
        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        //vector<vector<int>> dp( n1, vector<int>(n2, -1) );

        return solvetab(text1, text2);
    }
};
