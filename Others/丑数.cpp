class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        //1,2,3,4,5,6,8,9,10,12,15,16,18,20,24,25,27,30
        //
        if(index <= 6)
            return index;   // 加快程序输出
        
        // 三个变量 后面有大作用！
        int i2 = 0,i3 = 0,i5 = 0;
        vector<int> res(index,0);
        res[0] = 1;  // 第一个丑数为 1
 
        for(int i = 1; i < index; i++){
            // 得到下一个丑数，三者中最小的
            res[i] = min(res[i2]*2,min(res[i3]*3,res[i5]*5));
             /*第一次是 2、3、5比较，得到最小的是2*/
            /*第二次是 4、3、5比较，为什么是4了呢？因为上次2已经乘了一次了，所以接下去可以放的丑数在4、3、5之间*/
            // 所以开头的三个指针就是来标记2 3 5 乘的次数的
            if(res[i] == res[i2]*2)
                i2++;
            if(res[i] == res[i3]*3)
                i3++;
            if(res[i] == res[i5]*5)
                i5++;
        }
        return res[index-1];
        
    }
};
