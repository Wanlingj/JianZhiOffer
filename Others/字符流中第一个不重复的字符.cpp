class Solution
{
public:
  //Insert one char from stringstream
    vector<char> vch;
    unordered_map<char,int> m;
    void Insert(char ch) {
        vch.push_back(ch);
        m[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        for(int i=0;i<vch.size();i++){
            if(m[vch[i]]==1)
                return vch[i];
        }
        return '#';
        
    }

};
