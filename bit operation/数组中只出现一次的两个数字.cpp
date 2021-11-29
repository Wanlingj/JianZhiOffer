class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        // write code here
        // 先将全部数进行异或运算，得出最终结果
        int tmp = 0;
        for(int num: array){
            tmp ^= num;
        }
        
        // 找到那个可以充当分组去进行与运算的数
        // 从最低位开始找起
        int mask = 1;
        while((tmp&mask) == 0){
            mask <<= 1;
        }
        
         // 进行分组，分成两组，转换为两组 求出现一次的数字 去求
        int a = 0;
        int b = 0;
        for(int num:array){
            if((num&mask) == 0){
                a ^= num;
            }else{
                b ^= num;
            }
        }
         // 因为题目要求小的数放前面，所以这一做个判断
        if(a > b){
            int c = a;
            a = b;
            b = c;
        }
        
        return vector<int>{a,b}; 
        
    }
};
