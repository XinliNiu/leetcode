class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(!s && !p) return true;
        if(!s && p) return false;
        if(s && !p) return false;
        int flag = 0;
        while(s && p && *s != '\0' && *p != '\0')
        {
            if(*p == '.')
            {
                //fuck ".*" means zero or more "."
                if(*(p+1) == '*')
                {
                    // the order here is very important 
                    if(isMatch(s+1,p+2))
                        return true;                    
                    if(isMatch(s,p+2))
                        return true;
                    s = s + 1;     
                    
                }
                else
                { 
                    p++;
                    s++;
                }  
              
            }
            else if(*p == '*')
            {
                if(isMatch(s+1,p+1))
                    return true;
                if(isMatch(s,p+1))
                    return true;
                s++;
                
            }
            else if(*p == *s && *(p+1) == '*')
            {

 
               if(isMatch(s,p+2))
                    return true;
               if(isMatch(s+1,p+2))
                    return true;
                s++;
            }
            else if(*p == *s && *(p+1) != '*')
            {
                p++;
                s++;
            }
            else if(*p != *s && *(p+1) == '*')
            {
                p = p + 2;
            }
            else if(*p != *s && *(p+1) != '*')
            {
                return false;
            }

        }
        if(*s != '\0')
            return false;
        while(*p != '\0')
        {
            if(*p == '*')
                p++;
            else if(*p != '*' && *(p+1) == '*')
                p = p + 2;
            else
                return false;
        }
        return true;
    }
};
