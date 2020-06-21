class Solution {
public:
    int
    getChoices( int x ) {
        return (x*(x-1))/2;
    }
    
    int
    getChoices( int x, int y ) {
        return x*y;
    }
    
    int 
    numPairsDivisibleBy60(vector<int>& time) {
    
        vector<int> mTime(60, 0);
        for( int i=0; i<time.size(); i++ ) {
            int idx = time[i] % 60;
            mTime[idx]++;
        }
        /*
        for( auto const& m : mTime ) {
            cout << m << " ";
        }
        cout << endl;
        */
        
        int r=0;
        for( int i=0; i<=30; i++ ) {
            if( (i==0) || (i==30) ) {
                r += getChoices(mTime[i]);
            } else {
                r += getChoices(mTime[i], mTime[60-i]);
            }
        }
        
        return r;
    }
};