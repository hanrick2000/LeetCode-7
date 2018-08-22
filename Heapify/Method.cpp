//Given an integer array, heapify it into a min-heap array.
//
//For a heap array A, A[0] is the root of heap, and for each A[i], A[i * 2 + 1] is the left child of A[i] and A[i * 2 + 2] is the right child of A[i].

class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    
    void heapifyHelper(vector<int> &A, int k) {
        
        while(2*k+1 < A.size()) {
            if(2*k+2 < A.size() && A[2*k+1] < A[k]&&A[2*k+2] < A[k]) {
                if(A[2*k+1] < A[2*k+2]) {
                    swap(A[k], A[2*k+1]);
                    k = 2*k+1;
                }
                else {
                    swap(A[k],A[2*k+2]);
                    k = 2*k+2;
                }
            }
            
            else if (A[2*k+1] < A[k]) {
                swap(A[k], A[2*k+1]);
                k = 2*k+1;
            }
            
            else if (2*k+2 < A.size() && A[2*k+2] < A[k]) {
                swap(A[k],A[2*k+2]);
                k = 2*k+2;
            }
            
            
            else {
                break;
            }
        }
    }
    
    
    void heapify(vector<int> &A) {

        write your code here
        
        if(A.size()<2) return;
    
        int i = 0;
        
        while(i < A.size()) {
            i = i*2+1;
        }
        
        i/=2;
        
        while(i >= 0) {
            for(int j = i; j < 2*i+1; ++j) {
                heapifyHelper(A,j);
            }
            if(!i) break;
            
            i /= 2;
        }
        
    }
};

递归法 O(n)

class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    
    void heapifyHelper(vector<int> &A, int k) {
        if(k >= A.size() || 2*k+1>= A.size()) return;
        
        if(2*k+2 < A.size() && A[2*k+2] < A[k] && A[2*k+2] < A[2*k+1] ) {
            swap(A[k], A[2*k+2]);
            heapifyHelper(A,2*k+2);
        }
        
        if(A[k] > A[2*k+1]) {
            swap(A[k], A[2*k+1]);
            heapifyHelper(A,2*k+1);
        }
    }
    
    
    void heapifyRec(vector<int> &A, int j) {
        if(j >= A.size() || 2*j+1>= A.size()) return;
        heapifyRec(A,2*j+1);
        heapifyRec(A,2*j+2);
        heapifyHelper(A,j);
    }
    
    
    void heapify(vector<int> &A) {

        heapifyRec(A,0);
    }
};