/* Project 2.c */

#include <stdio.h>

int main()
{
	int total;	//�Ѵ� �뵷
	int today[31];	//���� �����
	int i,sum;

	printf("@@@@@@@@@@@@@@@�� ���α׷��� ���л��� �뵷��� �Ѵ� ����׿� ���� ������ �����մϴ�.@@@@@@@@@@@@@@@\n\n");
	printf("�� �� �뵷�� ������ �Է����ּ��� : (��)");
	scanf_s("%d", &total);
	
	if (total <= 0)
	{
		printf("�뵷�� ���� ������ �Է��� �ֽñ� �ٶ��ϴ�.\n");
	}
	else
	{
		for (i = 0, sum = 0; i < 31; i++)
		{
			printf("%d�Ͽ� ������ ���� ������ �Է����ּ��� : ", i + 1);
			scanf_s("%d", &today[i]);	//�迭�� ���ʷ� ���� ������� �Է¹޴´�.
			
			sum += today[i];	// ���ձ��ϱ�
			
			if (sum > total)
			{
				printf("�Է��Ͻ� �� �� �뵷�� �ʰ��Ǿ����ϴ�.");	//�Ѵ� �뵷 �̻��� �� �� ����.(�뵷�����̱� ������)
				return -1;
			}
			
			if (today < 0)
			{
				printf("���� ������� ���� ������ �Է��� �ֽñ� �ٶ��ϴ�.");
				return -1;
			}
		}
		/*31��ġ �뵷 �迭�� ��������*/

		int i, j, index;
		int temp;

		for (i = 0; i < 30; i++)
		{
			index = i;
			
			for (j = i + 1; j < 31; j++)
			{
				if (today[index] > today[j])
					index = j;
			}
			
			temp = today[i];
			today[i] = today[index];
			today[index] = temp;
		}

		printf("====================================================\n");
		printf("�̹� �� �� ������� %d���Դϴ�\n.", sum);
		printf("1�� ��� ������� %d���Դϴ�\n.", sum / 31);
		printf("�̹� �� �� �Ϸ� ������� �ִ��� %d���Դϴ�.\n ",today[30]);
		
	}
	return 0;
}
