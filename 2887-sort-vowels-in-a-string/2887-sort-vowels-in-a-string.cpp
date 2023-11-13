class Solution {
public:
    string sortVowels(string s) {
        string vow = "";
        int n = s.length();

        for(int i=0;i<n;i++) {
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {    vow += s[i];
                s[i] = '@';}
        }

        sort(vow.begin(), vow.end());

        int j = 0;
        for(int i=0;i<n;i++) {
            if(s[i]=='@') s[i] = vow[j++];
        }
        return s;
    }
};