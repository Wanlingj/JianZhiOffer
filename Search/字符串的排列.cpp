class Solution {
public:
    void perm(int pos, string s, set<string> &ret) {
        if (pos+1 == s.length()) {
            ret.insert(s);
            return;
        }
        // for循环和swap的含义：对于“ABC”，
        // 第一次'A' 与 'A'交换，字符串为"ABC", pos为0， 相当于固定'A'
        // 第二次'A' 与 'B'交换，字符串为"BAC", pos为0， 相当于固定'B'
        // 第三次'A' 与 'C'交换，字符串为"CBA", pos为0， 相当于固定'C'
        for (int i = pos; i < s.length(); ++i) {
            swap(s[pos], s[i]);
            perm(pos+1, s, ret);
            swap(s[pos], s[i]);
            // 回溯的原因：比如第二次交换后是"BAC"，需要回溯到"ABC"
            // 然后进行第三次交换，才能得到"CBA"
        }
    }
    vector<string> Permutation(string str) {
        if (str.empty()) return {};
        set<string> ret;
        perm(0, str, ret);
        return vector<string>({ret.begin(), ret.end()});
    
    }
};
