class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size() <= 1)
            return s.size();
        int pre1=0,pre2=0;
        int cur1=0,cur2=0;
        int i,j;
        for(i = 1; i < s.size(); i++)
        {
            for(j = cur1; j <= cur2; j++)
            {
                if(s[i] == s[j])
                {
                    if(cur2-cur1 > pre2-pre1)
                    {
                        pre2 = cur2;
                        pre1 = cur1;
                    }
                    cur2 = i;
                    cur1 = j+1;
                    break;
                }
            }
            if(j > cur2)
                cur2 = i;
        }
        if(cur2 - cur1 > pre2 - pre1)
            return cur2-cur1+1;
        else 
            return pre2-pre1+1;
    }
};
