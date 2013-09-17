class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 + len2 != s3.size())
            return false;
        if(len1 == 0)
            return s2 == s3;

        if(len2 == 0)
            return s1 == s3;


        int D[len1+1][len2+1];
        D[0][0] = 1;

        int m;
        for(m = 0; m < s1.size(); m++)
        {
            if(s1[m] == s3[m])
                D[m+1][0] = 1;
            else
                break;
        }
        for(;m < s1.size();m++)
            D[m+1][0] = 0;        

        for(m = 0; m < s2.size(); m++)
        {
            if(s2[m] == s3[m])
                D[0][m+1] = 1;
            else
                break;
        }
        for(;m < s2.size();m++)
            D[0][m+1] = 0;       

        if(D[0][1] == 0 && D[1][0] == 0)
            return false;
            
        int i,j;
        for(i = 1; i <= s1.size(); i++)
        {
            for(j = 1; j <= s2.size(); j++){
                if(s1[i-1] != s3[i+j-1] && s2[j-1] != s3[i+j-1])
                    D[i][j] = 0;
                else if(s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-1])
                    D[i][j] = D[i][j-1] || D[i-1][j];
                else if(s1[i-1] == s3[i+j-1])
                    D[i][j] = D[i-1][j];
                else
                    D[i][j] = D[i][j-1];
            
            }    
        }
        
        return D[len1][len2];
    }
    
};
