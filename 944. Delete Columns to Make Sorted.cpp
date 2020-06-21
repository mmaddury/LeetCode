class Solution {
public:
    int 
    minDeletionSize(vector<string>& A) {
        
        /*
        A.clear();
        A.push_back("rrjk");
        A.push_back("furt");
        A.push_back("guzm");
        */
        
        int nRow = A[0].size();
        int nCol = A.size();
        
        vector<string> At(nRow);
        for( int i=0; i<nRow; i++ ) {
            At[i] = "";
        }
        
        for( auto const& s : A ) {
            for( int i=0; i<s.size(); i++ ) {
                At[i] += s[i];
            }
        }
        /*
        for( auto const& s : At ) {
            cout << s << endl;
        }
        */
        
        int r = 0;
        for( auto const& s : At ) {
            string t = s;
            sort(t.begin(), t.end());
            if( t != s ) {
                r++;
            }
        }
        
        return r;

    }
};