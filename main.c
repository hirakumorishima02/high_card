#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_rand();
void card_start(int *money);

int main(void){
    int money=100;
    card_start(&money);
    return 0;
}

void init_rand(){
    srand((unsigned int)time(NULL));
}

void card_start(int *money){
    int cards[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int kakekin,rate=1;

    while(*money>1 || *money <= 1000) {
        init_rand();
        int a = 0 + rand() % 13;
        printf("|%d|\n", cards[a]);
        printf("いくら賭けますか?($1〜$%d)", *money);
        scanf("%d", &kakekin);
        int b = 1 + rand() % 13;
        printf("|%d|\n", cards[b]);

        // 条件分岐
        if(cards[a] <= cards[b]) {
            puts("WIN!");
            kakekin *= rate;
            *money += kakekin;
            printf("倍率は%d倍。続けますか? YES=>1 NO=>2", rate);
            int question;
            scanf("%d", &question);

            if(question == 1) {
                rate++;
                printf("持ち金：%d\n", *money);
            } else puts("終わり");
        };

        if(cards[a] > cards[b]) {
            puts("LOSE!");
            *money -= kakekin;
            printf("持ち金：%d\n", *money);
            rate = 1;
        }

        if(*money==0) {
            puts("持ち金が$0になりました。");
            break;
        } else if(*money>=1000) {
            puts("持ち金が$1000を超えました。");
            break;
        };

    };

    puts("Game Over");

    return;
}
