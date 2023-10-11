class Solution {
public:
    bool isValid(string s) {
     stack<char>st;
        int l = s.size();
        char temp;
        for(int i=0;i<l;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else{
                if(st.size()==0)//Checking weather the stack is already empty
                    return false;
                temp = st.top();
                if(s[i]==')' and temp != '('){
                    return false;
                }else if(s[i]=='}' and temp != '{' ){
                    return false;
                }else if(s[i]==']' and temp != '['){
                    return false;
                }
                st.pop(); 
            }
        }
        if(st.size()!=0){
            return false;
        }
        return true;   
    }
};