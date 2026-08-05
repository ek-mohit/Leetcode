class Solution {
public:
    bool judgeSquareSum(int c) {

        long long i= 0;
        long long j = sqrt(c);

        while (i<= j){

            long long x= i*i + j*j;

            if (x==c){
                return true;
            }

            else if (x < c){
                i++;
            }

            else{
                j--;
            }
        }
        return false;
        
    }
};