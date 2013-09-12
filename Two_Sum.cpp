class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int,int> num;
        vector<int> result;
        if(numbers.size() < 2)
            return result;
        for(int i = 0; i < numbers.size(); i++)
        {
            map<int,int>::iterator it = num.find(target-numbers[i]);
            if(it == num.end())
                num.insert(map<int,int>::value_type(numbers[i],i));
            else
            {
                result.push_back(num[target-numbers[i]]+1);
                result.push_back(i+1);
                return result;
            }
                
        }
        return result;
    }
};
