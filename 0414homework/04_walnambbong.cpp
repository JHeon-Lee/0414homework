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

    printf("***������ ����!!***\n");

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

        printf("�� ������ : %d\n", money);
        printf("���� �ݾ��� �Է��ϼ��� : ");
        scanf_s("%d", &betting);

        if (betting < 1000 || betting > money)
        {
            printf("���� �ݾ��� �ٽ� Ȯ���� �ּ���\n");
            continue;
        }

        if (card[cardcount + 0] < card[cardcount + 2] &&
            card[cardcount + 2] < card[cardcount + 1])
        {
            printf("�¸�!!\n");
            printf("���� ī�� : %d\n\n", card[cardcount + 2]);
            money += betting;
        }
        else
        {
            printf("�й�!!\n");
            printf("���� ī�� : %d\n\n", card[cardcount + 2]);
            money -= betting;
        }

        cardcount += 3;

        if (cardcount > 49 || money < 1000)
        {
            printf("����!!\n");
            break;
        }
    }

    return 0;
}