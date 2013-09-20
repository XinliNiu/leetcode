class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int,int> mp;
        sort(num.begin(),num.end());
        int n1=0,n2=0,p1=0,p2=num.size()-1;
        int i;
        vector<vector<int> > result;
        if(num.size() < 3)
            return result;
        if(num[0] > 0)
            return result;
        if(num[0] == 0) {
            if(num[1] == 0 && num[2] == 0) {
                vector<int> tmp;
                tmp.push_back(0);
                tmp.push_back(0);
                tmp.push_back(0);
                result.push_back(tmp);   
            }
            return result;
        }
        
        for(i = 1; i < num.size(); i++) {
            map<int,int>::iterator it = mp.find(num[i]);
            if(it == mp.end())
                mp.insert(map<int,int>::value_type(num[i],1));
            else
                mp[num[i]] ++;
    
            if(num[i-1] < 0 && num[i] >= 0) 
                n2 = i-1;
            if(num[i-1] <= 0 && num[i] > 0) 
                p1 = i;
        }

            
        map<int,int>::iterator it = mp.find(0);
        if(it != mp.end()) {
            if(mp[0] >= 3) {
                vector<int> tmp;
                tmp.push_back(0);
                tmp.push_back(0);
                tmp.push_back(0);
                result.push_back(tmp);
            }
        }
        for(i = n1; i <= n2;i++) {
            for (int j = p1; j <= p2; j++ ) {
                if(0-num[i]-num[j] <= num[j] && 0-num[i]-num[j] >= num[i]) {
                    mp[num[i]]--;
                    mp[num[j]]--;
                    map<int,int>::iterator it = mp.find(0-num[i]-num[j]);
                    if(it != mp.end() && mp[0-num[i]-num[j]] > 0) {
                        vector<int> tmp;
                        tmp.push_back(num[i]);
                        tmp.push_back(0-num[i]-num[j]);
                        tmp.push_back(num[j]);
                        result.push_back(tmp);                 
                    }
                    mp[num[i]]++;
                    mp[num[j]]++;   
                }
                    j++;
                    while(j <= p2 && num[j]==num[j-1])
                        j++;
                    if(j > p2)
                        break;
                    else if(num[j] != num[j-1])
                        j--;
            }
            i++;
            while(i <= n2 && num[i] == num[i-1])
                i++;
            if(i > n2)
                break;
            else if(num[i] != num[i-1])
                i--;
        }
        return result;
    }
};
