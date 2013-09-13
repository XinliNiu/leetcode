class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        while(str && *str != '\0' && *str == ' ')
            str ++;
        if(!str || *str == '\0')
            return 0;  
            
        int flag = 0;
        if(str[0]!= '+' && str[0] != '-' && !(str[0] <= '9' && str[0] >= '0'))
            return 0;
        if(str[0] == '-')
            flag = 1;
        if(str[0] == '-' || str[0] == '+')
            str++;
 
        long long result = 0;
        for(;str && *str != '\0'; str++)
        {
            if(!(*str <= '9' && *str >= '0'))
            {   

                if(flag == 0 && result >= 0x7fffffff)
                    return 0x7fffffff;
                if(flag == 1 && result >=0x80000000)
                    return (int)0x80000000;
                if(flag == 1)
                    result = result * (-1);
                return (int)result;
            }
            else
            {
                result = result*10 + (*str - '0');
                if(flag == 0 && result >= 0x7fffffff)
                    return 0x7fffffff;
                if(flag == 1 && result >=0x80000000)
                    return (int)0x80000000;
            }
        }
        if(flag == 1)
            result = result * (-1);
        return (int)result;
        
    }
};
