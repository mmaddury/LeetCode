class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
               
        // Use a map with O(n) space
        
        // O(1) space solution
        
        int n = nums.size();

	    if( n <= 1 )
		    return nums;
        
		vector<int> rVal;

        if( n == 2 ) {
            rVal.push_back(nums[0]);
            if( nums[1] != nums[0] )
                rVal.push_back(nums[1]);
            return rVal;
        }

        // sort the array
        sort(nums.begin(), nums.end());
		
		int threshold = n/3;
		int curr = nums[0];
		bool currDone = false;
		int count = 1;

		for( int i=1; i<n; i++ ) {
	        if( nums[i] == curr ) {
		        count++;
		        if( count > threshold && !currDone ) {
			        rVal.push_back(curr);
			        currDone = true;
	        	}
	        } else {          
		        curr = nums[i];
		        count = 1;
		        currDone = false;
	        }
        }

        return rVal;
        
    }
};


