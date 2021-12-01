class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        unordered_map<int,int> m;
        for(int i=0;i<array.size();i++){
            if(m[sum-array[i]]>0){
                res.push_back(array[i]);
                res.push_back(sum-array[i]);
                break;
            }
            m[array[i]]+=1;
        }
        return res;
    }
};
