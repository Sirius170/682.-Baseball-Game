#include "BaseballGame.h"

int main(){
    char* ops[] = {"5","2","C","D","+"};
    //char* ops[] = {"5","-2","4","C","D","9","+","+"};
    //char* ops[] = {"1","C"};
    
    // 使用 sizeof 公式自動計算長度
    // 原理：整個陣列的記憶體大小 / 單個元素的大小 = 元素個數
    int size = sizeof(ops) / sizeof(ops[0]);

    int res = calPoints(ops, size);

    printf("Total = %d\n", res);

    return 0;
}