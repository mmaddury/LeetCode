class Solution {
public:
    
    void
    showVec( const vector<int>& v, const string& s="" ) {
        if( s!="" )
            cout << s << " ";
        for( auto const& i : v )
            cout << i << " ";
        cout << endl;
    }
    
    
    vector<int> 
    numOfBurgers(int tomatoSlices, int cheeseSlices) {
        
        //
        // J is the number of jumbo burgers
        // S is the number of small burgers
        //
        // Write two equations and solve them
        //      4J + 2S = tomatoSlices
        //       J +  S = cheeseSlices
        //
        // Solve the equations to write
        //       J = (tomatoSlices - 2*cheeseSlices)/2
        //       S = cheeseSlices - J
        //
        // If J is a whole number, we have solution
        //
        
        vector<int> res;
        
        double exactJ = (static_cast<double>(tomatoSlices) - 2*cheeseSlices)/2;

        if( exactJ == floor(exactJ) ) {
            int J = static_cast<int>(exactJ);
            int S = cheeseSlices - J;
            if( (J >= 0) && (S >= 0) ) {
                res.push_back(J);
                res.push_back(S);
            }
        }
        
        return res;
        
    }
};