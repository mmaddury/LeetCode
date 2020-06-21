class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> r(nums.size(),0);
        size_t m = nums.size()/2;
        for( size_t i=0; i<nums.size()-1; i+=2 ) {
            r[i] = nums[i];
            r[i+1] = nums[m+i];
        }
        return r;
    }
};