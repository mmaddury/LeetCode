class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     
		int sum = 0;
        int maxSum = numeric_limits<int>::min();
		for( size_t i=0; i<nums.size(); i++ ) {
			// Reset subarray start is aggregate
			// sum is less than zero
			if( sum < 0 ) 
				sum = nums[i];
			else
				sum += nums[i];
            maxSum = sum > maxSum ? sum : maxSum;
        }

        return maxSum;
    }
};

