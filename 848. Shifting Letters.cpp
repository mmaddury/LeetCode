class Solution {
public:
    string 
    shiftingLetters(string S, vector<int>& shifts) {
        

        
        vector<char> a{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        map<char,int> m;
        for( int i=0; i<a.size(); i++ ) {
            m[a[i]] = i;
        }
        string r = S;
        
        
        /*
        // Brute force method       
        for( int i=0; i<shifts.size(); i++ ) {
            for( int j=0; j<i+1; j++ ) {
                int idx = (m[r[j]] + shifts[i]) % a.size();
                r[j] = a[idx];
            }
        }
        */
        
        
        // Using reverse prefix sum
        vector<long long int> tShift(shifts.size(), 0);
        tShift[shifts.size()-1] = shifts[shifts.size()-1];
        for( int i=shifts.size()-2; i>=0; i-- ) {
            tShift[i] = tShift[i+1] + shifts[i];
        }
        for( int i=0; i<tShift.size(); i++ ) {
            r[i] = a[(m[r[i]]+tShift[i])%26];
        }

        return r;
        
    }
};