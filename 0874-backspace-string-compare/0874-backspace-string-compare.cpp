class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>ss;
        for(int i=0;i<s.size();i++) 
        {
            if(s[i]=='#') 
            {
                if(ss.empty())
                    continue;
                else
                    ss.pop();
            }
            else
                ss.push(s[i]);
        }
        stack<char>st;
        for(int i=0;i<t.size();i++) 
        {
            if(t[i]=='#') 
            {
                if(st.empty())
                    continue;
                else
                    st.pop();
            }
            else
                st.push(t[i]);
        }
        while(!ss.empty() && !st.empty()) {
            if(ss.top()!=st.top())
                return false;
            else
            {
                ss.pop();
                st.pop();
            }
        }
        if(!ss.empty() ^ !st.empty())
            return false;
        return true;
    }
};