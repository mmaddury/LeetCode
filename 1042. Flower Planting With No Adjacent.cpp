class Solution {
public:
	// v contains the flowers of the 
	// attached nodes. 0 if not yet
	// assigned. Sort and select one
	// larger than max.
	int
	getNext( vector<int> v ) {
        if( v.size() == 0 )
            return 1;

        set<int> s{1,2,3,4};
        for( auto const& i : v )
            s.erase(i);
        
        return *(s.begin());
    }
		

    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {

		vector<int> sel(N,0);
            
		// First create a graph of all connections
		// Bidirectional connections lead to a symmetric
		// matrix

		vector<list<int>> adjList(N);

		for( int i=0; i<paths.size(); i++ ) {
            vector<int> p = paths[i];
            adjList[p[0]-1].push_back(p[1]-1);
            adjList[p[1]-1].push_back(p[0]-1);
		}

		// Iterate through all the nodes and assign
		// selection
		sel[0] = 1;
		for( int i=1; i<N; i++ ) {
			vector<int> adjSel;
            list<int> vList = adjList[i];
            for( auto it=vList.begin(); it!=vList.end(); it++ )
                adjSel.push_back(sel[*it]);
			sel[i] = getNext( adjSel );
		}

		return sel;

    }
};


