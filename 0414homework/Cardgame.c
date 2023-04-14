#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
	srand((unsigned int)time(NULL));
	rand();

	int Cards[4][13] = { 0 };
	int RandNum1 = 0, RandNum2 = 0;
	int PlayerNum = 0;
	int PlayerMoney = 50000;
	bool ContinueGame = true;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			Cards[i][j] = rand() % 13 + 1;
			for (int k = 0; k < j; k++)
			{
				if (Cards[i][j] == Cards[i][k])
				{
					j--;
					break;
				}
			}
		}
	}

	printf("***** ������ ī����� ���α׷� *****\n");
	printf("52���� ī��(1 ~ 13 4����)�� �����մϴ�.\n");
	printf("������ ������ ī��ȿ� �ڽ��� ������ ī�尡 ���� �ȿ� ���ԵǸ� �¸��Դϴ�.\n");
	printf("���ñ��� �ּ� 1000������ �Դϴ�.\n");
	printf("�̱�� ���þ��� �ι踦 ����ϴ�.\n");
	printf("���� ���þ��� �ҽ��ϴ�.\n\n");
	printf("���� ī��� �ٽ� ������ �ʽ��ϴ�.\n");
	printf("ī�尡 �� �������ų�, ���ñ��� 0�� �Ǹ� ����˴ϴ�.\n\n");

	while (ContinueGame)
	{
		int Bet = 0;
		int CardCount = 0;

		/*for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				printf("%d ", Cards[i][j]);
			}
			printf("\n\n");
		}*/

		while (true)
		{
			int rand1 = rand() % 4;
			int rand2 = rand() % 4;
			int rand3 = rand() % 4;
			int rand4 = rand() % 13;
			int rand5 = rand() % 13;
			int rand6 = rand() % 13;

			RandNum1 = Cards[rand1][rand4];
			RandNum2 = Cards[rand2][rand5];
			PlayerNum = Cards[rand3][rand6];

			if (RandNum1 != 0 && RandNum2 != 0 && PlayerNum != 0)
			{
				Cards[rand1][rand4] = 0;
				Cards[rand2][rand5] = 0;
				Cards[rand3][rand6] = 0;
				CardCount++;
				break;
			}
		}

		if (RandNum1 > RandNum2)
		{
			int temp;
			temp = RandNum2;
			RandNum2 = RandNum1;
			RandNum1 = temp;
		}

		printf("�÷��̾� �����ݾ� : %d\n", PlayerMoney);
		printf("ī�� �ΰ� ���� : %d\t%d\n", RandNum1, RandNum2);
		printf("�� �����Ͻðڽ��ϱ�? : ");
		scanf_s("%d", &Bet);

		if (Bet < 1000)
		{
			printf("���ñ��� 1000�� �̻� �ɾ�� �մϴ�.\n");
			printf("�� �����Ͻðڽ��ϱ�? : ");
			scanf_s("%d", &Bet);
		}

		printf("�÷��̾� ī�� : %d\n", PlayerNum);

		if(PlayerNum>=RandNum1 && PlayerNum<=RandNum2)
			printf("�¸��߽��ϴ�!\n\n");
		else
		{
			PlayerMoney -= Bet;
			printf("�����ϴ�..\n\n");
		}

		if (CardCount == 16 || PlayerMoney <= 0)
			break;
	}

	return 0;
}