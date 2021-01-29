#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void init_rand();

int main(void){
    init_rand();
    // 持ち金、iの変数を宣言
    int money=100,kakekin;
    // “A”,“2”,“3”～“J”,“Q”,“K”の配列を宣言
    int cards[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    // カード1枚が出る(配列からランダムで)
    int a = 1 + rand() % 13;
    printf("%d\n", cards[a]);
    // いくら掛けるかscanf
    scanf("%d", &kakekin);
    // 1枚目のカードと2枚目のカードの大小を比較
    int b = 1 + rand() % 13;
    printf("%d\n", cards[b]);
    // 条件分岐:大きければ持ち金はそのまま
    if(cards[a] <= cards[b]) puts("WIN!");
    // 条件分岐:小さければ持ち金-掛け金
    if(cards[a] > cards[b]) {
        puts("LOSE!");
        money -= kakekin;
        printf("持ち金：%d\n", money);
    }
    return 0;
}

void init_rand(){
    srand((unsigned int)time(NULL));
}

