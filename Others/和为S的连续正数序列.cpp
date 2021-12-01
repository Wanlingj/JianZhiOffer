class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
       vector<vector<int>> ret;
        int tmp = 0;
        for (int i=1; i<=sum/2; ++i) {
            for (int j=i; j<sum; ++j) {
                tmp += j;
                if (sum == tmp) {
                    vector<int> ans;
                    for (int k=i; k<=j; ++k) ans.push_back(k);
                    ret.push_back(ans);
                }
                else if (tmp > sum) {
                    // 提前剪枝
                    tmp = 0;
                    break;
                }
            }
        }
        return ret;
    }
};
