#include <vector>
#include <algorithm>
class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n+2, 0);

        for(int i = n-1; i>=0; i--){
            long long sum1 = nums[i];
            long long b = (sum1 % 3 == 0)? (sum1 - dp[i+1]) : (sum1 + dp[i+1]);
            if(i+1 < n){
                long long sum2 = (long long)nums[i] + nums[i+1];
                long long opt2 = (sum2 %3 == 0) ? (sum2-dp[i+2]) : (sum2+dp[i+2]);
                b = max(b, opt2);
            } 
            dp[i] = b;
        }
        return dp[0];
    }
};