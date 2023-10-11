class Solution {
public:
    bool isPalindrome(int x) {
        string a = to_string(x);
        int i=0;
        int j=a.size()-1;
        while(i<=j) {
            if(a[i]!=a[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};