class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        
        /*
        // Unsorted array using map
        map<int,int> m;
    
        for( auto const& i : nums ) {
            if( m.find(i) == m.end() )
                m[i] = 1;
            else
                m[i]++;
        }
        
        for( auto const& [k,v] : m ) {
            if( v > n/2 )
                return k;
        }
        
        return -1;
        */
        
        // Sorted array
        sort(nums.begin(), nums.end());
        if( n == 1 )
            return nums[0];
        
        // Since the majority element exists, we 
        // need to find the middle element
        // n is even, return nums[n/2]
        // n is odd, element occurs more than
        // floor(n/2). So the element must be at
        // the mid
        
        int m = n/2;
        
        return nums[m];
        
    }
};