/*lesson learned*/
/*
1.a<<1 + 1 not runs as you expected , a<<1 + 1 is equalient to a<<2, use (a<<1)+1 instead
2.When +,-,*,/ are prohabited, think about your primary school when you were just starting to learn +,-,*,/, but at this
time, you should think in a binary way
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( divisor == 1)
            return dividend;
        long long a = dividend;
        long long b = divisor;
        int flag = 1;
        if(a < 0 && b > 0)
            flag = -1;
        if(a > 0 && b < 0)
            flag = -1;
        return flag * div(abs(a),abs(b));
    }
    long long div(long long a,long long b)
    {
        if(a < b)
            return 0;
        if(a == b)
            return 1;
        if(b == 1)
            return a;
        long long len = 1;

        long long d = 0;
        long long tmp = a;
        long long result = 0;
        while(tmp > 1)
        {
            tmp = tmp >> 1;
            len = len << 1;
            
        }
        while(d < b)
        {
            d = (d<<1) + (a&len?1:0);
            a = a&(len-1);
            len = len>>1;
            result = result<<1;
        }
        d = d - b;
        result = (result<<1) + 1;
        while(len > 0)
        {
            result = result<<1;
            d = d<<1;
            len = len>>1;
        }
        return result +div(a+d,b);
    }
};
