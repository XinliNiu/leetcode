class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S)
    {
        map<vector<int>,int> nochoice;
        sort(S.begin(),S.end());
        return subsetsWithDup(S,nochoice);
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S, map<vector<int>,int> &nochoice) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
   
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
            result = subsetsWithDup(S,nochoice);
            vector<vector<int> > new_result;
            for(int i = 0; i < result.size(); i++)
            {
                vector<int> tmp(result[i].begin(),result[i].end());
                tmp.push_back(last);
                map<vector<int>,int>::iterator it = nochoice.find(tmp);
                if(it == nochoice.end())
                {
                    nochoice.insert(map<vector<int>,int>::value_type(tmp,1));
                    new_result.push_back(tmp);
                }
            }
            for(int i = 0; i < new_result.size(); i++)
                result.push_back(new_result[i]);
            return result;
        }
        
    }
};
