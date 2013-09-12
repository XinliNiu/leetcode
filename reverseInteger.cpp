class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long result,tmp;
        tmp = x;
        if(tmp < 0)
            tmp = 0 - tmp;
        result = 0;
        while(tmp)
        {
            result = result * 10 + tmp%10;
            tmp = tmp/10;
        }
        //better if there is a global flag indicate an overflow
        if(x < 0 && result > 0x80000000)
            return -1;
        if(x > 0 && result > 0x7fffffff)
            return -1;
        if(x > 0)
            return result;
        else
            return 0 - result;
    }
};
