class Solution {
public:
    int kthGrammar(int n, int k) {
        // go to recursion
        // current number at (n,k) will be dependent on previous (n-1,k/2+k%2)
        if(n==1) return 0;
        int p = kthGrammar(n-1,k/2+k%2);
        if(p==0) {
            if(k&1) return 0;
            return 1;
        } else {
            if(k&1) return 1;
            return 0;
        }
    }
};