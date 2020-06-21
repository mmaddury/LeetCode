class Solution {
public:
    
    string
    getMoveString( const int i ) {
        if( i%2 ) {
            return "O";
        } else {
            return "X";
        }
    }
    
    
    string
    getWinnerString( const string& s ) {
        if( s=="X" ) {
            return "A";
        } else {
            return "B";
        }
    }
    
    
    string 
    tictactoe(vector<vector<int>>& moves) {
        
        /*
        moves.clear();
        vector<int> m;
        m.push_back(2); m.push_back(1); moves.push_back(m); m.clear();
        m.push_back(2); m.push_back(0); moves.push_back(m); m.clear();
        m.push_back(2); m.push_back(2); moves.push_back(m); m.clear();
        m.push_back(1); m.push_back(1); moves.push_back(m); m.clear();
        m.push_back(0); m.push_back(0); moves.push_back(m); m.clear();
        m.push_back(0); m.push_back(1); moves.push_back(m); m.clear();
        m.push_back(0); m.push_back(2); moves.push_back(m); m.clear();
        m.push_back(1); m.push_back(0); moves.push_back(m); m.clear();
        m.push_back(1); m.push_back(2); moves.push_back(m); m.clear();
        */
        
        vector<vector<string>> ttt(3, vector<string>(3," "));
        for( int i=0; i<moves.size(); i++ ) {
            int r = moves[i][0];
            int c = moves[i][1];
            //cout << r << " " << c << endl;
            ttt[r][c] = getMoveString(i);
        }
        
        for( auto const& t : ttt ) {
            for( auto const& s : t ) {
                cout << s;
            }
            cout << endl;
        }
        
        
        for( int i=0; i<3; i++ ) {
            // Check rows
            if( ( ttt[i][0] == ttt[i][1] ) && ( ttt[i][0] == ttt[i][2] ) && ( ttt[i][0] != " " ) ) {
                cout << "Row = " << i << endl;
                return getWinnerString(ttt[i][0]);
            }
            // Check cols
            if( ( ttt[0][i] == ttt[1][i] ) && ( ttt[0][i] == ttt[2][i] ) && ( ttt[0][i] != " " )  ) {
                cout << "Col = " << i << endl;
                return getWinnerString(ttt[0][i]);
            }
        }
        // Check diagonals
        if( ( ttt[0][0] == ttt[1][1] ) && ( ttt[0][0] == ttt[2][2] ) && ( ttt[0][0] != " " )  ) {
            return getWinnerString(ttt[0][0]);
        }
        if( ( ttt[0][2] == ttt[1][1] ) && ( ttt[0][2] == ttt[2][0] ) && ( ttt[0][2] != " " )  ) {
            return getWinnerString(ttt[0][2]);
        }
        
        int freeSpace = 0;
        for( auto const& row : ttt ) {
            for( auto const& c : row ) {
                if( c == " " ) {
                    freeSpace++;
                }
            }
        }
        if( freeSpace ) {
            return "Pending";
        }
        
        return "Draw";
        
    }
};