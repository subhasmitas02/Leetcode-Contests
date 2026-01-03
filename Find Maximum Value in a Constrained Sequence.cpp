class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<long long> a(n, 2e18);
        a[0] = 0;
        for(auto it : restrictions)
        {
            int index = it[0];
            int maxValue = it[1];
            a[index] = min(a[index], (long long)maxValue);
        }
        for(int i=1; i<n; i++)
            a[i] = min(a[i], a[i-1] + diff[i-1]);            
        for(int i= n-2; i>= 0; i--)
            a[i] = min(a[i], a[i+1] + diff[i]); 

        long long maxVal = 0;
        for(long long v : a)
        {
            maxVal = max(maxVal, v);
        }
        return (int)maxVal;
    }
};©leetcode