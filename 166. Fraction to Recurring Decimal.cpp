class Solution {
public:

	struct MyT {
		int d;
		int n;
	};

	MyT
	adjustDividend( int num, int den ) {

		MyT rVal;
		int shift = 0;
		while( num < den ) {
			num *= 10;
			shift++;
		}

		rVal.d = num;
		rVal.n = shift-1;

		return rVal;
	};


    string 
    fractionToDecimal(int numerator, int denominator) {

        
        //numerator = -100;
        //denominator = -2;
               
        
        string sign="";
        if( numerator < 0 && denominator < 0 ) {
            numerator *= -1;
            denominator *= -1;
        }
        if( numerator < 0 && denominator > 0 ) {
            sign = "-";
            numerator *= -1;
        }
        if( numerator > 0 && denominator < 0 ) {
            sign = "-";
            denominator *= -1;
        }
        
        if( numerator == 0 )
            return "0";
        
        if( denominator == 0 )
            return "nan";
        
        if( denominator == 1 ) 
            return to_string(numerator);
        
        string bDec="";
        if( numerator > denominator ) {
            int q = numerator/denominator;
            int r = numerator % denominator;
            bDec = to_string(q);
            if( r == 0 )
                return sign + to_string(q);
            numerator = r;
        }
        
		MyT tmp = adjustDividend( numerator, denominator );
	
	    int leadZero = tmp.n;
		
        int num = tmp.d;
		int den = denominator;
		int rem = num/10;
		int quot = 0;
		bool done = false;
	
	    int isRecur = false;
		int fRecurIdx = 0;
		int lRecurIdx = 0;

		map<int,int> nMap;
		nMap[num] = 0;
		vector<int> qVec;

		size_t i=0;
		while( !done ) {
            /*
            cout << "num " << num
                 << " i " << i << endl;
            */
		    quot = num/den;	
			qVec.push_back(quot);
            i++;

			rem = num % den;
			num = rem*10;
            
			if( rem == 0 ) 
                done = true;
		
			if( nMap.find(num) == nMap.end() ) {
				nMap[num] = i;
			} else {
				isRecur = true;
				fRecurIdx = nMap[num];
				lRecurIdx = i;
				done = true;
			}

            /*
            for( auto const& [k,v] : nMap )
                cout << "[" << k << "," << v << "]" << " ";
            cout << endl;
            */
		}

        /*
        for( auto const& q : qVec )
            cout << q;
        cout << endl;
        cout << "fRecuridx = " << fRecurIdx << " lRecurIdx = " << lRecurIdx << endl;
        */
        
        string rVal=sign;

        if( bDec == "" )
            rVal += "0.";
        else 
            rVal += bDec + ".";
        
        for( int i=0; i<leadZero; i++ )
			rVal += to_string(0);

        if( isRecur ) {
            for( int i=0; i<fRecurIdx; i++ )
                rVal += to_string(qVec[i]);
            rVal += "(";
            for( int i=fRecurIdx; i<lRecurIdx; i++ )
                rVal += to_string(qVec[i]);
            rVal += ")";
        } 
        else {
		    for( int i=0; i<qVec.size(); i++ )
			    rVal += to_string(qVec[i]);
        }
		
		return rVal;

    }
};


