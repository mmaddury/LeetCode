class Solution {
public:
    string 
    getHint(string secret, string guess) {
    
        int numA = 0;
        int numB = 0;

        // To calculate numA, check how positions
        // match
        for( size_t i=0; i<secret.size(); i++ ) {
            if( secret[i] == guess[i] )
                numA++;
        }

        //  To calculate numB, check how many digits
        // match & subtract numA
        vector<int> sDist(10,0);
        vector<int> gDist(10,0);
        for( auto const& i : secret )
            sDist[static_cast<size_t>(i-'0')]++;
        for( auto const& i : guess )
            gDist[static_cast<size_t>(i-'0')]++;

        int tmp = 0;
        for( size_t i=0; i<sDist.size(); i++ )
            tmp += (sDist[i] < gDist[i]) ? sDist[i] : gDist[i];

        numB = tmp - numA;

        string rval = to_string(numA) + "A" + to_string(numB) + "B";

        return rval;
    
    }
};


