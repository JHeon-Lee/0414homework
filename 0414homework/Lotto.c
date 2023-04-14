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
	
	printf("***** �ζ� ���α׷� *****\n");
	printf("1�� : 6�� ��� ��ġ\n");
	printf("2�� : 5�� + ���ʽ� ��ġ\n");
	printf("3�� : 5�� ��ġ\n");
	printf("4�� : 4�� ��ġ\n");
	printf("5�� : 3�� ��ġ\n\n");
	printf("1 ~ 45�� ���� 6���� ����ּ���.\n");

	for (int i = 0; i < 6; i++)
	{
		if (i == 5)
		{
			printf("������ ����!\t\t");
			scanf_s("%d", &PlayerNumbers[i]);
			printf("\n");
		}
		else
		{
			printf("%d �� ������ϴ�.\t", i);
			scanf_s("%d", &PlayerNumbers[i]);
		}
		if (PlayerNumbers[i] > 45 || PlayerNumbers[i] < 1)
		{
			i--;
			printf("1 ~ 45 ������ ���ڸ� ����ּ���.\n");
		}
		for (int j = 0; j < i; j++)
		{
			if (PlayerNumbers[i] == PlayerNumbers[j])
			{
				i--;
				printf("�ߺ��� ���ڴ� ���� �Ұ����մϴ�.\n");
				break;
			}
		}
	}

	printf("���� �� ���ڵ� :\t");
	for (int i = 0; i < 6; i++)
		printf("%d\t", PlayerNumbers[i]);
	printf("\n");

	printf("��÷ ��ȣ!! :\t\t");
	for (int i = 0; i < 7; i++)
	{
		if (i == 6)
			printf("���ʽ� ����!! : %d", LottoNumbers[6]);
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
		printf("���Դϴ�...\n");
		break;
	case 3:
		printf("5���Դϴ�!\n");
		break;
	case 4:
		printf("4���Դϴ�!\n");
		break;
	case 5:
		{
		if (bonus == true)
			{
				printf("2���Դϴ�!\n");
				break;
			}
		else
			{
				printf("3���Դϴ�!\n");
				break;
			}
		}
	case 6:
		printf("�����մϴ�! 1���Դϴ�!!\n");
		break;
	}

	return 0;
}