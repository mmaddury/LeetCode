class Solution {
public:
    bool divisorGame(int N) {

        /*
        N   x   N-x A wins?
        1   -   -   F
        2   1   -   T
        3   1   2   F
        4   1   3   T
        5   1   4   F
        6   3   3   T
        7   1   6   F
        8   1   7   T
        9   3   6   F

        If the starting number is even, always a way to win
        If the starting number is odd, will always lose
        */      

        return N%2 == 0;

    }
};


