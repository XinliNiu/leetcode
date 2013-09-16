class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 1)
            return n;
        int len = 0;
        for(int i = 1; i < n; i++)
        {
            while(i < n && A[i] == A[len])
                i++;
            if(i >= n)
                return len+1;
            A[++len] = A[i];
        }
        return len+1;
    }
};
