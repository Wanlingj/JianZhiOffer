class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    int findNthDigit(int n) {
        // write code here
        //先错误判断
        if(n<0){
            return 0;
        }
        // 0
        // 1 ~ 9      | digit = 1 start = 1 * 1       count = 1 * 9 * 1
        // 10 ~ 99    | digit = 2 start = 1 * 10      count = 10 * 9 * 2
        // 100 ~ 999  | digit = 3 start = 1 * 10 * 10 count = 100 * 9 * 3
        
        long width=1, num = n-1;
        long scope_start=1 ,scope_len=9;
        while(num>width*scope_len){
            num-=width*scope_len;
            width++;
            scope_len*=10;
            scope_start*=10;
        }
        long number = (scope_start+num/width);
        if(number>9){
            //number's total width
            //num%width num's num%width location from the left of number
            //so divide number by width-num%width-1 times
            for(long i=(width-(num%width)-1);i>0;i--){
                number=number/10;
            }
        }
        return (int)number%10;
        
    }
};
