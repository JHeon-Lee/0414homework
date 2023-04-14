#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
	srand((unsigned int)time(NULL));
	rand();

	int ComNumbers[3] = { 0 };
	int PlayerNumbers[3] = { 0 };
	int Strike = 0, Ball = 0, Out = 0;
	
	for (int i = 0; i < 3; i++)
	{
		ComNumbers[i] = rand() % 9 + 1;
		for (int j = 0; j < i; j++)
		{
			if (ComNumbers[i] == ComNumbers[j])
			{
				i--;
				break;
			}
		}
	}
	
	printf("***** ���ھ߱� ���α׷� *****\n");
	printf("��ǻ���� 1 ~ 9 ������ ���� 3���� �����ּ���!\n");
	printf("��ǻ���� ���ڿ� �ߺ��� ���� ����!\n");
	printf("Strike : ����, �ڸ� ��� ��ġ.\n");
	printf("Ball : ���ڸ� ��ġ.\n");
	printf("Out : �ش� ���� ����.\n\n");
	printf("1 ~ 9�� ���� 3���� ����ּ���\n");
	while (true)
	{
		for (int i = 0; i < 3; i++)
		{
			printf("%d ��° �ڸ� ���� : \t", i + 1);
			scanf_s("%d", &PlayerNumbers[i]);

			if (PlayerNumbers[i] > 9 || PlayerNumbers[i] < 1)
			{
				i--;
				printf("1 ~ 9 ������ ���ڸ� ����ּ���.\n");
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
		for (int i = 0; i < 3; i++)
			printf("%d\t", PlayerNumbers[i]);
		printf("\n");

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (ComNumbers[i] == PlayerNumbers[j])
				{
					if (ComNumbers[i] == PlayerNumbers[i])
						Strike++;
					else
						Ball++;
				}
				Out = 3 - (Strike + Ball);
			}
		}

		printf("\n");

		printf("Strike	: %d ��\n", Strike);
		printf("Ball	: %d ��\n", Ball);
		printf("Out	: %d ��\n\n", Out);

		if (Strike == 3)
		{
			printf("�����մϴ�! �����Դϴ�!!\n");
			printf("��ǻ�� ���� :\t\t");
			for (int i = 0; i < 3; i++)
			{
				printf("%d\t", ComNumbers[i]);
			}
			break;
		}

		Strike = 0;
		Ball = 0;
		Out = 0;
	}
	
	return 0;
}