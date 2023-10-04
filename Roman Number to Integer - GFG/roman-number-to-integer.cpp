//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        int count=0;
        for(int i =0;i<s.size();i++){
            if(s[i]== 'I'){
                count++;
            }
            else if(s[i]=='V'){
                count = count + 5;
            }
            else if(s[i]=='X'){
                count = count + 10;
            }
            else if(s[i]=='L'){
                count = count + 50;
            }
            else if(s[i]=='C'){
                count = count + 100;
            }
            else if (s[i]=='D'){
                count = count +500;
            }
            else if (s[i]=='M'){
                count = count +1000;
            }
            if ((s[i]=='I'&& s[i+1]=='V')||(s[i]=='I'&& s[i+1]=='X')){
                count-=2;
            }
            if ((s[i]=='X'&& s[i+1]=='L')||(s[i]=='X'&& s[i+1]=='C')){
                count-=20;
            }
            if((s[i]=='C'&& s[i+1]=='D')||(s[i]=='C'&& s[i+1]=='M')){
                count-=200;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends