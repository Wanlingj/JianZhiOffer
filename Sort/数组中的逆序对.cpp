class Solution {
public:
    int mod = 1000000007;
    int mergeSort(int left, int right, vector<int>& data, vector<int>& temp){
        if (left >= right)    // 停止划分
            return 0;
        int mid = (left + right) / 2; //取中间
        int res = mergeSort(left, mid, data, temp) + mergeSort(mid + 1, right, data, temp); //左右划分
        res %= mod;  //防止溢出
        int i = left, j = mid + 1;
        for (int k = left; k <= right; k++)
            temp[k] = data[k];
        for (int k = left; k <= right; k++) {
            if (i == mid + 1)
                data[k] = temp[j++];
            else if (j == right + 1 || temp[i] <= temp[j])
                data[k] = temp[i++];
            else { //左边比右边大，答案增加,[1,2,3,4,0,5,6,7]
                data[k] = temp[j++];
                res += mid + 1 - i; // 统计逆序对
            }
        }
        return res % mod;
    }
    int InversePairs(vector<int> data) {
        int n = data.size();
        vector<int> res(n);
        return mergeSort(0, n - 1, data, res);
    }
};
