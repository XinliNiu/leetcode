class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x == 0) return 0;
        if(x == 1) return 1;
        double guess = x/2+1;
        double y = x;
        while(fabs(guess*guess-y) > 0.1)
        {
            guess = (guess + y/guess)/2;
            
        }
        return (int)guess;
    }
};
