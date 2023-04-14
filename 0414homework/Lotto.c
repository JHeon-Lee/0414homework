#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
	srand((unsigned int)time(NULL));
	rand();

	int LottoNumbers[7] = { 0 };
	int PlayerNumbers[6] = { 0 };
	int count = 0;
	bool bonus = 0;

	for (int i = 0; i < 7; i++)
	{
		LottoNumbers[i] = rand() % 45 + 1;
		for (int j = 0; j < i; j++)
		{
			if (LottoNumbers[i] == LottoNumbers[j])
			{
				i--;
				break;
			}
		}
	}
	
	printf("***** 로또 프로그램 *****\n");
	printf("1등 : 6개 모두 일치\n");
	printf("2등 : 5개 + 보너스 일치\n");
	printf("3등 : 5개 일치\n");
	printf("4등 : 4개 일치\n");
	printf("5등 : 3개 일치\n\n");
	printf("1 ~ 45의 숫자 6개를 골라주세요.\n");

	for (int i = 0; i < 6; i++)
	{
		if (i == 5)
		{
			printf("마지막 숫자!\t\t");
			scanf_s("%d", &PlayerNumbers[i]);
			printf("\n");
		}
		else
		{
			printf("%d 개 골랐습니다.\t", i);
			scanf_s("%d", &PlayerNumbers[i]);
		}
		if (PlayerNumbers[i] > 45 || PlayerNumbers[i] < 1)
		{
			i--;
			printf("1 ~ 45 사이의 숫자를 골라주세요.\n");
		}
		for (int j = 0; j < i; j++)
		{
			if (PlayerNumbers[i] == PlayerNumbers[j])
			{
				i--;
				printf("중복된 숫자는 선택 불가능합니다.\n");
				break;
			}
		}
	}

	printf("내가 고른 숫자들 :\t");
	for (int i = 0; i < 6; i++)
		printf("%d\t", PlayerNumbers[i]);
	printf("\n");

	printf("당첨 번호!! :\t\t");
	for (int i = 0; i < 7; i++)
	{
		if (i == 6)
			printf("보너스 숫자!! : %d", LottoNumbers[6]);
		else
			printf("%d\t", LottoNumbers[i]);
	}
	printf("\n");

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (LottoNumbers[6] == PlayerNumbers[j])
				bonus = true;
			if (LottoNumbers[i] == PlayerNumbers[j])
				count++;
		}
	}

	switch (count)
	{
	case 0:
	case 1:
	case 2:
		printf("꽝입니다...\n");
		break;
	case 3:
		printf("5등입니다!\n");
		break;
	case 4:
		printf("4등입니다!\n");
		break;
	case 5:
		{
		if (bonus == true)
			{
				printf("2등입니다!\n");
				break;
			}
		else
			{
				printf("3등입니다!\n");
				break;
			}
		}
	case 6:
		printf("축하합니다! 1등입니다!!\n");
		break;
	}

	return 0;
}