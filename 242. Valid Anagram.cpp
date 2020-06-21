class Solution {
public:
    bool 
    isAnagram(string s, string t) {

	if( s.size() != t.size() )
		return false;
    
vector<int> sCount(26, 0);
vector<int> tCount(26, 0);

for( auto const& c : s )
	sCount[static_cast<size_t>(c-'a')]++;

for( auto const& c : t )
	tCount[static_cast<size_t>(c-'a')]++;
        
	for( size_t i=0; i<sCount.size(); i++ ) {
		if( sCount[i] != tCount[i] )
			return false;
	}

	return true;
    }
};

