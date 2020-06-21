class Solution {
public:
    int 
longestPalindrome(string s) {

		vector<int> sCount(128,0);
		for( auto const& c : s )
			sCount[static_cast<size_t>(c-'A')]++;

		int totalCount = 0;
		for( auto const& i : sCount ) {
			if( i%2 == 0 )
				totalCount += i;
            else
                totalCount += i-1;
		}

        if( totalCount == s.size() )
            return totalCount;
        
        return totalCount+1;
        
    }
};


