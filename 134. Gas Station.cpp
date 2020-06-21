class Solution {
public:
    
    void
    showVec( const vector<int>& v, const string& s="") {
        if( s!="" )
            cout << s << " ";
        for( auto const& i : v )
            cout << i << " ";
        cout << endl;
    }
    
    bool
    checkPrefixSum( const vector<int>& diff, int idx ) {
        vector<int> tmp;
        tmp = diff;

        rotate(tmp.begin(), tmp.begin()+idx, tmp.end());
        
        // Calculate prefix sum
        for( int i=1; i<tmp.size(); i++ )
            tmp[i] = tmp[i] + tmp[i-1];
        
        for( auto const& t : tmp ) {
            if( t < 0 )
                return false;
        }
        return true;
    }
    
    
    int 
    canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        // 
        // Optimized code
        //
        
        // Total cost
        int s1 = 0;
        // Total gas
        int s2 = 0;
        // Total difference
        int s = 0;
        // Tmp variable
        int diff;
        // Minimum total difference
        int minS = numeric_limits<int>::max();
        
        int sIdx = 0;
        
        // Difference between gas and cost
        vector<int> v;
        
        // Prefix sum of differences
        vector<int> pre;
        pre.push_back(0);
        
        
        for( int i=0; i<cost.size(); i++ ) {
            s1 += cost[i];
            s2 += gas[i];
            diff = gas[i]-cost[i];
            s  += diff;
            minS = min(s, minS);
            pre.push_back(s);
            v.push_back(diff);
        }
        
        // Not enough gas for all cost
        if( s2<s1 )
            return -1;
        
        for( int i=0; i<cost.size(); i++ ) {
            if( v[i]>0 && pre[i]==minS ) {
                sIdx = i;
                break;
            }
        }
        
        return sIdx;
        
    
        /*    
        // Trivial case
        if( gas.size() == 1 ) {
            if( gas[0] >= cost[0] )
                return 0;
            else 
                return -1;
        }
        
        // Start points can only be stations where gas[i] > cost[i]
        // On top of this, the cumulative gas should never be negative
        // This is a prefix sum.
        
        vector<int> diff(gas.size(),0);
        for( int i=0; i<gas.size(); i++ )
            diff[i] = gas[i] - cost[i];
        //showVec( diff, "diff");
        
        
        int sIdx=-1;
        for( int i=0; i<diff.size(); i++ ) {
            if( ( diff[i] > 0 ) && checkPrefixSum(diff, i) )
                sIdx = i;
        }
        

        // Did not find a starting point
        if( sIdx == -1 )
            return -1;
        

        // Go around the loop and check
        int gBal = 0;
        int lCnt = 0;
        while( lCnt != gas.size() ) {
            gBal += gas[sIdx];
            gBal -= cost[sIdx];
            sIdx = (sIdx + 1) % gas.size();
            lCnt++;
            if( ( gBal <= 0 ) && ( lCnt != gas.size() ) )
                return -1;
        }

        
        return sIdx;   
        */
    }
    
};