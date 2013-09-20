class Solution {
public:
 
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<vector<string> > result;
        if(s.empty()) 
        {
            vector<string> tmp;
            result.push_back(tmp);
            return result;
        }
        
        for(int i = 0; i < s.size(); i++) {
            string first = s.substr(0,i+1);
            if(!isPalindrome(first))
                continue;
            vector<vector<string> > tmp = partition(s.substr(i+1));
            for(int j = 0; j < tmp.size(); j++) {
                vector<string> t;
                t.push_back(first);
                for(int k =0; k < tmp[j].size(); k++)
                    t.push_back(tmp[j][k]);
                result.push_back(t);
            }
        }
        return result;
    }
    bool isPalindrome(string s) {
        
        if(s.size() <= 1)
            return true;
        int i=0,j=s.size()-1;
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
