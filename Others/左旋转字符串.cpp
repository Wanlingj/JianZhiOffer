class Solution {
public:
    string LeftRotateString(string str, int n) {
        string res;
        if (str.length()==0) return res;
        res=str;
        while(n--)
            res=res.substr(1,str.length()-1)+res.substr(0,1);
        return res;
    }
};
