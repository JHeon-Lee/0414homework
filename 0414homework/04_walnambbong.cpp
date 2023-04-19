#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int money = 50000;
    int betting = 0;
    int card[52];
    int cardcount = 0;

    srand((unsigned int)time(NULL));

    printf("***월남뽕 게임!!***\n");

    for (int i = 0; i < 52; i++)
    {
        //card[i] = i % 13 + 1; // 1 2 3 4 5 ... 13 1 2 3 4

        card[i] = i / 4 + 1; //1 1 1 1 2 2 2 2 3 3 3 3
    }

    //for (int i = 0; i < 4; i++)
    //{
    //    for (int j = 0; j < 13; j++)
    //    {
    //        card[i * 13 + j] = j + 1;
    //    }
    //}

    for (int i = 0; i < 1000; i++)
    {
        int sour = rand() % 52;
        int dest = rand() % 52;

        int temp = card[sour];
        card[sour] = card[dest];
        card[dest] = temp;
    }

    while (1)
    {
        if (card[cardcount + 0] > card[cardcount + 1])
        {
            int temp = card[cardcount + 0];
            card[cardcount + 0] = card[cardcount + 1];
            card[cardcount + 1] = temp;
        }

        printf("%d, %d, ?\n", card[cardcount + 0], card[cardcount + 1]);

        printf("내 소지금 : %d\n", money);
        printf("베팅 금액을 입력하세요 : ");
        scanf_s("%d", &betting);

        if (betting < 1000 || betting > money)
        {
            printf("베팅 금액을 다시 확인해 주세요\n");
            continue;
        }

        if (card[cardcount + 0] < card[cardcount + 2] &&
            card[cardcount + 2] < card[cardcount + 1])
        {
            printf("승리!!\n");
            printf("히든 카드 : %d\n\n", card[cardcount + 2]);
            money += betting;
        }
        else
        {
            printf("패배!!\n");
            printf("히든 카드 : %d\n\n", card[cardcount + 2]);
            money -= betting;
        }

        cardcount += 3;

        if (cardcount > 49 || money < 1000)
        {
            printf("종료!!\n");
            break;
        }
    }

    return 0;
}