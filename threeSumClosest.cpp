class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result = 0;
        if(num.size() < 3)
            return 0;
        int sum = num[0] + num[1] + num[2];
        int diff = sum-target;
        int i,j;
        map<int,int> m;
        for(i = 0; i < num.size(); i++) {
            map<int,int>::iterator it = m.find(num[i]);
            if(it == m.end())
                m.insert(map<int,int>::value_type(num[i],1));
            else
                m[num[i]]++;
        }
        for(i = 0; i < num.size(); i++) {
            for(j = 0; j < num.size(); j++) {
                if(i != j) {
                    m[num[i]]--;
                    m[num[j]]--;
                    int test;
                    for(test = target; test-target < abs(diff); test++) {
                        map<int,int>::iterator it = m.find(test-num[i]-num[j]);
                        if(it != m.end() && m[test-num[i]-num[j]] > 0) {
                            if(test == target)
                                return test;
                            else
                                diff = test-target;
                        }
                    }
                    for(test = target - 1; target-test < abs(diff); test--) {
                        map<int,int>::iterator it = m.find(test-num[i]-num[j]);
                        if(it != m.end() && m[test-num[i]-num[j]] > 0) 
                                diff = test-target;                        
                    }
                    m[num[i]]++;
                    m[num[j]]++;
                }
                
            }
        }
        return target+diff;
      
    }
};
