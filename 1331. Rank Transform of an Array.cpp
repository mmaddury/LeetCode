class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        /*
        set<int> aSet;
        for( auto const& a : arr ) {
            aSet.insert(a);
        }
        cout << aSet.size() << endl;
        
        for( int i=0; i<retval.size(); i++ ) {
            auto it = aSet.find(arr[i]);
            retval[i] = (int) std::distance(aSet.begin(), it) + 1;
        }
        for( auto const& a : retval ) {
            cout << a << " ";
        }
        cout << endl;
        */
        
        vector<int> retval(arr.begin(), arr.end());
        sort(retval.begin(), retval.end());
        map<int,int> m;
        int rank = 1;
        for( int i=0; i<retval.size(); i++ ) {
            if(m.find(retval[i]) == m.end()) {
                m[retval[i]] = rank;
                rank++;
            }
        }
        
        for( int i=0; i<retval.size(); i++ ) {
            retval[i] = m[arr[i]];
        }
        
        return retval;

    }
};