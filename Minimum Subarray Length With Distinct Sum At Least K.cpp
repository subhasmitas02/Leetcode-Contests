class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size(), length = INT_MAX;
        int left = 0, right = 0, sum = 0;
        unordered_map<int, int> frequency;
        
        while(right < n)
        {
            if(frequency[nums[right]] == 0)
                sum += nums[right];
            frequency[nums[right]]++;
            while(sum >= k)
            {
                length = min(length, right - left + 1);
                frequency[nums[left]]--;
                if(frequency[nums[left]] == 0)
                    sum -= nums[left];
                left++;
            }
            right++;
        }
        if(length == INT_MAX) return -1;
        return length;
    }
};