class Solution {
public:
    int solve(string &s1, string &s2){
        int n1= s1.size();
        int n2= s2.size();

        //vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));
        vector<int> curr(n2+1, 0);
        vector<int> next(n2+1, 0);


        for (int i = n1-1; i>=0 ; i--){
            for (int j = n2-1 ; j>=0 ; j--){

                int ans=0;

                if(s1[i] ==s2[j]){
                    ans = 1+ next[j+1];
                }

                else{
                    ans = max(next[j] , curr[j+1]);
                }
                curr[j] = ans;

            }
            next = curr;;
        }
        return next[0];

    }
    int longestPalindromeSubseq(string s) {
        

        string s1= s; 
        reverse(s1.begin() , s1.end());

        return solve(s, s1);
        
    }
};