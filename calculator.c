#include <stdio.h>
int a,a1;

int expression(void);

int get_number(void){
    int i = 0;
    while ('0' <= a && a <= '9') {
        i = i * 10 + a - '0';
        a = getchar();
    }
    return i;
}


int kakko1(void){
    int i = get_number();
        if(a=='('){
            a = getchar();          //（　を捨てて（）の先頭文字を取得（多分数字）
            expression();           //（）内の計算開始
            a = getchar();          //)　を捨てて（）外の先頭文字を取得（多分符号）
            return a1;              //a1の中に（）中の計算結果があるため、それを返す。
        }
return i;                      
}

int term(void) {
    int i = kakko1();
    while(a == '*' || a == '/') {
        if (a == '*') {
            a = getchar();
            i = i * kakko1();
        } else if (a == '/') {
            a = getchar();
            i = i / kakko1();
        }
        a1=i;                    //どの計算が終わったときでもグローバル関数a1へ値の格納
    }
    return i;
}


int expression(void) {
    int i = term();
    while(a == '+' || a == '-') {
        if (a == '+') {
            a = getchar();
            i = i + term();
        } else if (a == '-') {
            a = getchar();
            i = i - term();
        }
        a1=i;                   //どの計算が終わったときでもグローバル関数a1へ値の格納
    }

    return i;


}
int main(void) {
    a = getchar();
    expression();
    printf("%d\n",a1 );
}