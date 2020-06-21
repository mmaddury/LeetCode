class Solution {
public:
    int 
    firstUniqChar(string s) {
    
        if( s.size() == 0 )
            return -1;
        
		struct MyT {
			int     n;
            size_t  i;
			char    c;
			MyT( int _n, size_t _i, char _c ) { 
                n = _n; 
                i = _i;
                c = _c; 
            };
        };

    	map<char,size_t> cMap;
        vector<MyT>      cCount;

        size_t i=0;
        size_t j=0;
        for( auto const& c : s ) {

            if( cMap.find(c) == cMap.end() ) {
                MyT tmp(1,j,c);
                cCount.push_back(tmp);
                cMap[c] = i++;
            }
            else {
                size_t k = cMap[c];
                MyT tmp = cCount[k];
                tmp.n++;
                cCount[k] = tmp;
            }
            j++;
        }

        sort( cCount.begin(), cCount.end(),
              [&]( const MyT& rhs, const MyT& lhs )
              {
                if( rhs.n < lhs.n )
                    return true;
                if( rhs.n == lhs.n ) {
                    if( rhs.i < lhs.i )
                        return true;
                }
                return false;
              } );

        if( cCount[0].n > 1 )
            return -1;
        
        return static_cast<int>(cCount[0].i);

    }
};


