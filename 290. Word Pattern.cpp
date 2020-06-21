class Solution {
public:

	void
	extractWords( const string& str, vector<string>& v ) {
		stringstream ss(str);
		string word;
		while( ss >> word )
			v.push_back(word);
	}


    bool 
    wordPattern(string pattern, string str) {
        
        // pattern = "abba";
        // str = "dog cat cat hellotheredog";
        
        // Extract words
        vector<string> words;
        extractWords( str, words );

        if( pattern.size() != words.size() )
            return false;

        // Create a map of word to char
        // This should be checked as we go along
        map<string, char> wcMap;
        map<char, string> cwMap;

        for( size_t i=0; i<words.size(); i++ ) {

            string w = words[i];
            char   c = pattern[i];
            
            //cout << "char : " << c << " word : " << w << endl;

            bool wState = (wcMap.find(w) != wcMap.end() );
            bool cState = (cwMap.find(c) != cwMap.end() );
            
            // wState , cState
            //    F   ,    F    : populate both maps
            //    F   ,    T    : return false
            //    T   ,    F    ; return false
            //    T   ,    T    : check if char and word match
            
            if( !wState && !cState ) {
                wcMap[w] = c;
                cwMap[c] = w;
            }
            

            if( ( wState && !cState ) || ( !wState && cState ) )
                return false;
            
            if( wState && cState ) {
                if( ( wcMap[w] == c ) && ( cwMap[c] == w ) )
                    continue;
                else
                    return false;
            }
            
            /*
            cout << "wcMap : ";
            for( auto const& [k,v] : wcMap )
                cout << "[" << k << "," << v << "]";
            cout << endl;

            cout << "cwMap : ";
            for( auto const& [k,v] : cwMap )
                cout << "[" << k << "," << v << "]";
            cout << endl;
            */
            
        }
            
        return true;
        
    }
};


