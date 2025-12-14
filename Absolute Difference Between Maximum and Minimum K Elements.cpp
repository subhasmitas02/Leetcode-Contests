class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int smallestSum = 0, largestSum = 0;

        for(int i=0; i<k; i++)
        {
            smallestSum += nums[i];
            largestSum += nums[n-1-i];
        }
        return abs(largestSum - smallestSum);
    }
};