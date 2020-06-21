class Solution {
public:
    vector<int> 
    intersection(vector<int>& nums1, vector<int>& nums2) {
     
		map<int,bool> n1Map;
		map<int,bool> rMap;

		for( auto const& i : nums1 ) {
			if( n1Map.find(i) == n1Map.end() )
				n1Map[i] = true;
		}

		for( auto const& i : nums2 ) {
   			if( n1Map.find(i) != n1Map.end() ) {
				if( rMap.find(i) == rMap.end() ) {
					rMap[i] = true;
				}
			}
		}

		vector<int> rVal;
		for( auto const& [k,v] : rMap )
			rVal.push_back(k);

		return rVal;

    }
};


