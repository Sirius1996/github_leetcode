class Solution {
public:
    bool isMatch(string s, string p) {
        //if(s==null||p==null)
        //    return false;
        if(p.length()==0)
            return s.length()==0;
        if(p.length()==1)
            return s.length()==1&&(p[0]=='.'||p[0]==s[0]);
        if(p[1]=='*'){
            if(isMatch(s,p.substr(2)))
                return true;
            return s.length()>0 && (p[0]=='.'||p[0]==s[0]) && isMatch(s.substr(1),p);
        }
        else{
            return s.length()>0 && (p[0]=='.'||p[0]==s[0]) && isMatch(s.substr(1),p.substr(1));
        }
    }
};