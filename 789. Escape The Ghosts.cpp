class Solution {
public:
    bool 
    escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        
        int myDist = abs(target[0])+abs(target[1]);
        
        for( auto const& g : ghosts ) {
            int gDist = abs(target[0]-g[0]) + abs(target[1]-g[1]);
            if( gDist <= myDist )
                return false;
        }
        
        return true;
    }
};