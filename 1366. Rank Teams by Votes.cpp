class Solution {
public:
    
    void
    showTable( const vector<vector<int>>& table ) const {
        cout << "--" << endl;
        for( auto const& vector : table ) {
            for( auto const& v : vector ) {
                cout << v << " ";
            }
            cout << endl;
        }
        cout << "--" << endl;
    }
    
    
    
    static bool
    tableSort( const vector<int>& lhs, const vector<int>& rhs ) {
        for( int i=0; i<lhs.size(); i++ ) {
            if( lhs[i] == rhs[i] ) {
                continue;
            } else if( lhs[i] > rhs[i] ) {
                return true;
            } else {
                return false;
            }
        }
        return lhs < rhs;
    }
    
    
    /*
    bool
    customSort( const char lhs, const char rhs ) {
        for( )
    }
    */
    
    
    string 
    rankTeams(vector<string>& votes) {
    
        int nv = votes.size();
        int nt = votes[0].size();
        
        // Handle simple cases
        if( (nv == 1) || (nt == 1) ) {
            return votes[0];
        }
        
        vector<vector<int>> rTable(26, vector<int>(nt,0));
        //showTable(rTable);
        
        for( auto const& v : votes ) {
            int cIdx = 0;
            for( auto const& c : v ) {
                int rIdx = (int) (c - 'A');
                rTable[rIdx][cIdx]++;
                cIdx++;
            }
        }
        //showTable(rTable);
        
        string r = votes[0];
        sort(r.begin(), r.end(), [&](const auto& lhs, const auto& rhs) {
            for( int i=0; i<nt; i++ ) {
                if( rTable[lhs-'A'][i] == rTable[rhs-'A'][i] ) {
                    continue;
                } else if( rTable[lhs-'A'][i] > rTable[rhs-'A'][i] ) {
                    return true;
                } else {
                    return false;
                }
            }
            return lhs < rhs;            
        });
        
        /*
        sort(rTable.begin(), rTable.end(), tableSort );
        sort(rTable.begin(), rTable.end(), [&](const auto& lhs, const auto& rhs) {
            for( int i=0; i<lhs.size(); i++ ) {
                if( lhs[i] == rhs[i] ) {
                    continue;
                } else if( lhs[i] > rhs[i] ) {
                    return true;
                } else {
                    return false;
                }
            }
            return lhs < rhs;            
        });
        */
        //showTable(rTable);
        
        
        return r;
        
    }
};