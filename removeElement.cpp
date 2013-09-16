class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int j = 0;
        for(int i = 0; i < n; i++){
            while(i < n && A[i] == elem)
                i++;
            if(i == n)
                return j;
            else
                A[j++] = A[i];
        }
        return j;
    }
};
