class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int> m;
        for( int i=0; i<nums.size(); i++ ) {
            m[nums[i]] = i;
        }

        vector<int> r;
        for( int i=0; i<nums.size(); i++ ) {
            int c = target - nums[i];
            if( ( m.find(c) != m.end() ) && ( m[c] != i ) ) {
                r.push_back(i);
                r.push_back(m[c]);
                return r;
            }
        }
        
    
        /*
        vector<int> r;  
    
        for( auto it = nums.begin(); it != nums.end(); it++ ) {
            int a = *it;
            int b = target - a;
            
            for( auto jt = std::next(it); jt != nums.end(); jt++ ) {
                if( *jt == b ) {    
                    r.push_back(std::distance(nums.begin(), it)); 
                    r.push_back(std::distance(nums.begin(), jt)); 
                    return r;   
                }   
            }
        }
        */
        
        r.push_back(NULL);
        r.push_back(NULL);  
        return r;
        
    }
};