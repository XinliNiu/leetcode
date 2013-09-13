class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if((m+n)%2 == 1)
            return findKth(A,m,B,n,(m+n)/2+1);
        else
            return (findKth(A,m,B,n,(m+n)/2) + findKth(A,m,B,n,(m+n)/2+1))/2.0;
    }
    int findKth(int A[],int m,int B[],int n,int k)
    {
        if(m == 0)
            return B[k-1];
        if(n == 0)
            return A[k-1];
        if(k <= 1)
            return min(A[0],B[0]);
        int x = k/2 - 1;
        int y = x;
        if(x >= m)
            x = m - 1;
        if(y >= n)
            y = n - 1;
        if(A[x] == B[y])
            return findKth(A+x+1,m-x-1,B+y,n-y,k-x-y-1);
        if(A[x] > B[y])
            return findKth(A,m,B+y+1,n-y-1,k-y-1);
        if(A[x] < B[y])
            return findKth(A+x+1,m-x-1,B,n,k-x-1);
         
    }
};
