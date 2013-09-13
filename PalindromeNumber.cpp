class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x < 0)
            return false;
        if(x < 10)
            return true;
        int head = 1;
        int y = x;
        while(y >= 10)
        {
            head *= 10;
            y /= 10;
        }
        while(x >=10 )
        {
            if(x/head != x%10)
                return false;
            x = x%head/10;
            head = head/10;
        }
        return true;
    }
};
