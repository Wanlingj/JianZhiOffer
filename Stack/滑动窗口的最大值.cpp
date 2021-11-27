class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        int n=num.size();
        vector<int> res;
        if (n==0 || size < 1 || n<size)
            return res;
        for(int start=0;start<n-size+1;start++){
            int maxnum=0;
            for(int i=start;i<start+size;i++){
                if(num[i]>maxnum)
                    maxnum=num[i];
            }
            res.push_back(maxnum);
        }
        return res;
    }
};
