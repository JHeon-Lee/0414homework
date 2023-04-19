#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void RandomNum(int baseBall[]);
void baseballGame(int baseBall[], int UserNum[]);

int main()
{
    int baseBall[3];
    int UserNum[3];

    RandomNum(baseBall);
    baseballGame(baseBall, UserNum);

    return 0;
}

void RandomNum(int baseBall[])
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 3; i++)
    {
        baseBall[i] = rand() % 9 + 1;

        for (int j = 0; j < i; j++)
        {
            if (baseBall[i] == baseBall[j])
                i--;
        }
    }
}

void baseballGame(int baseBall[], int UserNum[])
{
    int chance = 0;

    printf("\n");

    while (chance != 10)
    {
        chance++;

        int strike = 0;
        int ball = 0;

        printf("숫자를 입력 하시오 : ");

        for (int i = 0; i < 3; i++)
            scanf_s("%d", &UserNum[i]);

        for (int i = 0; i < 3; i++)
        {
            if (baseBall[i] == UserNum[i])
                strike++;
            for (int j = 0; j < 3; j++)
            {
                if (baseBall[i] == UserNum[j])
                    ball++;
            }
        }

        ball -= strike;

        printf("%d strike %d ball", strike, ball);

        if (strike == 3)
        {
            printf("승리!!\n");
            exit(0);
        }

        printf("\n\n");
    }
}
