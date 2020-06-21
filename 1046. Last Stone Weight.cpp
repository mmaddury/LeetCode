class Solution {
public:
    
    int
    smash( int x, int y ) {
        
        if( x == y )
            return -1;
        else
            return y-x;
        
    }
    
    /*
    int 
    lastStoneWeight(vector<int>& stones) {
        
        // Use greedy approach. Sort all stones to begin with
        // Pick the top two and figure out the new size
        // Insert the new stone back into the array and resort
        
        if( stones.size() == 1 )
            return stones[0];
        
        sort(stones.begin(), stones.end());
        while( stones.size() > 1 ) {
            int a = stones.back();
            stones.pop_back();
            int b = stones.back();
            stones.pop_back();
            int c = smash(b, a);
            if( c != -1 ) {
                stones.push_back(c);
                sort(stones.begin(), stones.end());
            }
            if( stones.size() == 1 )
                return stones[0];
        }
        
        return 0;        
        
    }
    */
    
    int 
    lastStoneWeight(vector<int>& stones) {
        
        // Use greedy approach. Sort all stones to begin with
        // Pick the top two and figure out the new size
        // Faster solution using priority queue (max heap)
        
        if( stones.size() == 1 )
            return stones[0];
        
        priority_queue<int> pq;
        for( auto const& s : stones ) 
            pq.push(s);
        
        while( pq.size() > 1 ) {
        
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            
            int c = smash(b, a);
            if( c != -1 ) 
                pq.push(c);
            
            if( pq.size() == 1 )
                return pq.top();
            
        }
        
        return 0;        
        
    }
    
};