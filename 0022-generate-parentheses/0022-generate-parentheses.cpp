class Solution {
public:
    vector<string>ans;
    auto backtrack(int curr , char next,stack<char>s,int required,string temp){
        if(s.empty() && next==')'){
            return;
        }
        if(next==')'){
            s.pop();
            temp+=')';
        }
        if(next=='('){
            s.push(next);
            temp+='(';
        }
        if(curr==required){
           if(s.empty()){
            ans.push_back(temp);
           }
           return;
        }
       
        backtrack(curr+1,'(',s,required,temp);
        backtrack(curr+1,')',s,required,temp);
    }
    vector<string> generateParenthesis(int n) {
        int req=2*n;
        stack<char>s;
        string temp="";
        backtrack(1,'(',s,req,temp);
        return ans;
    }
};