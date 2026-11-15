class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int s = nums.size();
        int cnt = 0;
        for(int i=0;i<s;i++){
            int crrand = nums[i];
            int crrmin = nums[i];

            for(int j=i;j<s;j++){
                crrand &= nums[j];
                crrmin = min(crrmin, nums[j]);

                if(crrand == crrmin) cnt++;
            }
        }
        return cnt;
    }
    
};