#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MYNUM 6
#define LOTTONUM 7

void Lotto();

int main()
{
    Lotto();

    return 0;
}

void Lotto()
{
    srand((unsigned int)time(NULL));

    while (true)
    {
        int num[MYNUM];
        int lotto[LOTTONUM];
        int count = 0;
        int bonus = 0;

        for (int i = 0; i < LOTTONUM; i++)
        {
            lotto[i] = rand() % 45 + 1;

            for (int j = 0; j < i; j++)
            {
                if (lotto[i] == lotto[j])
                    i--;
            }
        }

        printf("�̹��� ��÷ ��ȣ : ");
        for (int i = 0; i < LOTTONUM; i++)
        {
            printf("%d ", lotto[i]);
        }

        printf("�ζ� ��ȣ�� �Է��Ͻÿ� : ");

        for (int i = 0; i < MYNUM; i++)
        {
            scanf_s("%d", &num[i]);
        }

        for (int i = 0; i < LOTTONUM; i++)
        {
            for (int j = 0; j < MYNUM; j++)
            {
                if (lotto[i] == num[j])
                {
                    count++;
                }
            }
        }

        for (int i = 0; i < MYNUM; i++)
        {
            if (lotto[LOTTONUM - 1] == num[i])
                bonus++;
        }



        printf("\n");

        printf("���� ���� ��ȣ : ");
        for (int i = 0; i < MYNUM; i++)
        {
            printf("%d ", num[i]);
        }

        if (count == 6 && bonus != 1)
        {
            printf("1�� �Դϴ�!!\n");
            break;
        }
        else if(count == 6 && bonus == 1)
        {
            printf("2�� �Դϴ�!!\n");
            break;
        }
        else if (count == 5)
        {
            printf("3�� �Դϴ�!!\n");
            break;
        }
        else if (count == 4)
        {
            printf("4�� �Դϴ�!!\n");
            break;
        }
        else if (count == 3)
        {
            printf("5�� �Դϴ�!!\n");
            break;
        }
        else
        {
            printf("������ �ٽ� �������ּ���!\n");
            break;
        }
    }
}
