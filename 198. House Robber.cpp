class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        
		// Corner cases
		if( n == 0 )
			return 0;

		if( n == 1 )
			return nums[0];
        
		// Bottom up solution
		
        //
		// amt[i] contains the money robbed till the ith house
		// Use a version of prefix sum
        //
		// Base cases
	    // house 0 : choose to rob it
        // 	amt[0] = nums[0];	
		// house 1 : choose to rob it
        //	amt[1] = max(nums[0], nums[1]);
		// house 2 : Either rob 0 + 2 or 1
        // 	amt[2] = max(nums[2] + amt[0], amt[1])
        // Iterate through nums, the last value is max
        //
        vector<int> amt(n,0);

        amt[0] = nums[0];
        amt[1] = max(nums[0], nums[1]);
 		for( int i=2; i<n; i++ ) 
			amt[i] = max(nums[i]+amt[i-2],amt[i-1]);

        cout << amt.back();
        
		return amt.back();
    }
};


