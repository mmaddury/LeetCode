class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int tSum = 0;
        for( auto const& n : nums ) {
            tSum += n;
        }
        
        if( nums.size() ==  0 ) {
            return -1;
        }
        if( (tSum - nums[0]) == 0 ) {
            return 0;
        }
        
        int lSum = 0;
        int rSum = 0;
        for( int i=1; i<nums.size(); i++ ) {
            lSum += nums[i-1];
            rSum = tSum - lSum - nums[i];
            if( lSum == rSum ) {
                return i;
            }
        }
        
        return -1;
        
    }
};