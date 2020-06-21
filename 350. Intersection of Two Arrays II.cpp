class Solution {
public:
    vector<int> 
    intersect(vector<int>& nums1, vector<int>& nums2) {

		map<int, int> n1Map;
		map<int, int> rMap;
		
		for( auto const& i : nums1 ) {
			if( n1Map.find(i) == n1Map.end() )
				n1Map[i] = 1;
			else
				n1Map[i]++;
		}

		for( auto const& i : nums2 ) {
			if( n1Map.find(i) != n1Map.end() ) {
				n1Map[i]--;
				if( n1Map[i] == 0 )
					n1Map.erase(i);

                if( rMap.find(i) == rMap.end() )
					rMap[i] = 1;
				else
					rMap[i]++;
		    }
        }

		vector<int> rVal;
		for( auto const& [k,v] : rMap ) {
			for( int i=0; i<v; i++ )
				rVal.push_back(k);
		}

		return rVal;

    }
};


