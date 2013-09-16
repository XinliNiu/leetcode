class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        sort(S.begin(),S.end());
        if(S.size() == 0)
        {
            vector<int> empty;
            result.push_back(empty);
            return result;
        }
        else
        {
            int last = S[S.size()-1];
            S.pop_back();
            result = subsets(S);
            vector<vector<int> > new_result;
            for(int i = 0; i < result.size(); i++)
            {
                vector<int> tmp(result[i].begin(),result[i].end());
                tmp.push_back(last);
                new_result.push_back(tmp);
            }
            for(int i = 0; i < new_result.size(); i++)
                result.push_back(new_result[i]);
            return result;
        }
        
    }
};
