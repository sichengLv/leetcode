// #include <stdio.h>
// #include <windows.h>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i]++;
            //写法一
            //if(digits[i]==10){
            //    digits[i] = 0;
            //}
            //else{
            //    return digits;
            //}

            //写法二
            digits[i] = digits[i] % 10;
            if (digits[i]) {//不等于0就返回
                return digits;
            }
        }
        //写法一  digits.insert(digits.begin(), 1);
        //写法二
        digits = vector<int>(digits.size() + 1); //长度digits.size() + 1，默认不写初始值为0
        digits[0] = 1;

        return digits;
    }
};


int main() {
    
    int a = 7;
    const int *p;
    p = &a;
    
    cout << *p << endl;
    system("pause");
    return 0;
}
