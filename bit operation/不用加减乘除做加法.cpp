class Solution {
public:
    int Add(int num1, int num2) {
        while (num2 != 0) {//循环把进位加到num1上
            int c = ((unsigned int)(num1 & num2)) << 1; //进位
            num1 ^= num2;
            num2 = c;
        }
        return num1;
    }
};
