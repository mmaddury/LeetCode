class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> r(nums.size(),0);
        r[0] = nums[0];
        for( size_t i=1; i<nums.size(); i++ ) {
            r[i] = r[i-1]+nums[i];
        }
        return r;
    }
};