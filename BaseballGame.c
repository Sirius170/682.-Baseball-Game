/*
題目要求「紀錄分數」、「移除最後一筆」、「參考前一、兩筆紀錄」
->動作特徵： 所有的操作（新增、加總、加倍、移除）都發生在記錄的末尾。
->對應結構： Stack（堆疊），符合「後進先出」(LIFO) 的特性。
*/
#include "BaseballGame.h"

int calPoints(char** operations, int operationsSize) {
    // 建立一個堆疊(Stack) 存放有效的分數
    int* stack=(int*)malloc(sizeof(int) * operationsSize);

    // top 用來記錄目前堆疊最頂端的索引位置，初始值為 -1 代表空堆疊
    int top = -1;

    //歷遍陣列
    for(int i = 0; i < operationsSize; i++){
        //取得當前字串位置
        char* op = operations[i];

        //"+"規則: 新紀錄為前兩筆資料相加
        if(strcmp(op, "+") == 0){
            int NewScore = stack[top] + stack[top-1];  
            // top:最新的資料    top-1:第二新的資料
            
            top++;  //將top移動到下一個空格，等待新資料進入
            stack[top] = NewScore;
        }

        //"D"規則: 新資料為前一筆資料*2
        else if(strcmp(op, "D") == 0){
            int NewScore = stack[top] *2;
            top++;
            stack[top] = NewScore;
        }

        //"C"規則: 移除前一筆資料
        else if(strcmp(op, "C") == 0){
            top--;   //將指標下移，讓最上層資料掉出陣列
        }

        //整數規則: 存入陣列
        //atoi (Array to Integer) 是標準函式，會處理正負號，負責將字串轉成整數
        else{
            top++;
            stack[top] = atoi(op);
        }  
    }
    
    //計算分數總合
    int total = 0;
    for(int i = 0; i <= top; i++){
        total += stack[i];
    }  

    // 釋放我們動態申請的記憶體
    free(stack);

    //回傳結果
    return total;
}

