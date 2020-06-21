class Solution {
public:
	int
	getNext( int x ) {
		if( x%2 )
			return 3*x+1;
		else
			return x/2;
	}


    int getKth(int lo, int hi, int k) {
             
		struct PowerT {
		    int p;		// power
			int n;		// number
			PowerT( int _p, int _n ) {
				p = _p;
				n = _n;
			};
		};


		// Use Dynamic Programming & memoization
		map<int,int> mem;
        // Fill up pow2 for some values
        int val = 1;
        for( int i=1; i<8; i++ ) {
            val *= 2;
            mem[val] = i;
        }

		vector<PowerT> pVec;
	

		for( int i=lo; i<=hi; i++ ) {
			int count = 0;
			int x = i;
            vector<int> val;
			while( x > 1 ) {
                if( mem.find(x) != mem.end() ) {
                    count += mem[x];
                    break;
                } else {               
				    count++;
                    val.push_back(x);
                    x = getNext(x);
                }
            }
            for( int i=0; i<val.size(); i++ ) {
                if( mem.find(val[i]) != mem.end() )
                    mem[val[i]] = count - i;
            }
			PowerT tmp(count,i);
			pVec.push_back(tmp);
		}

		sort(pVec.begin(), pVec.end(),
            [&](const PowerT& rhs, const PowerT& lhs) {
                if( rhs.p < lhs.p )
                    return true;
                if( rhs.p == lhs.p ) {
                    if( rhs.n < lhs.n )
                        return true;
                    else
                        return false;
                }
                return false;
            });
  
        /*
        for( auto const& p : pVec )
			cout << "[" << p.p << ","  << p.n << "] ";
		cout << endl;
        */

        return pVec[k-1].n;
    }

};


