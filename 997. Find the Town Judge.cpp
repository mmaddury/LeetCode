class Solution {
public:
    void
    showVec( const vector<int>& v ) {
        cout << "[";
        for( auto const& i : v )
            cout << i << " ";
        cout << "] ";
    }
    
    int findJudge(int N, vector<vector<int>>& trust) {
        
        
		// Create a trust graph
		// Search for a node whose outDegree is 0 &
		// inDegree is N-1

		vector<vector<int>> adjMatrix(N, vector<int>(N,0));

		for( auto const& v : trust ) {
            showVec(v);
			adjMatrix[v[0]-1][v[1]-1] = 1;
        }

		// outDegree is sum of row
		// inDegree is sum of column
		for( int i=0; i<N; i++ ) {
			int outDegree = 0;
			for( int j=0; j<N; j++ )
				outDegree += adjMatrix[i][j];
			if( outDegree == 0 ) {
				int inDegree = 0;
				for( int j=0; j<N; j++ )
					inDegree += adjMatrix[j][i];
				if( inDegree == N-1 )
					return i+1;
			}
		}

		return -1;

    }
};


