/* Project 1.c */

#include <stdio.h>

int main(void)
{
	int unit = 0; //����
	float hei, wei;	//Ű,������
	float BMI = 0;

	float BMI_level(float BMI);	//�Լ�����

	printf("@@@@@@@@@@@@@@@�� ���α׷��� Ű�� �����Ը� �Է¹޾�BMI������ �����Ͽ� �ǰ����¸� �˷��ݴϴ�.@@@@@@@@@@@@@@@\n\n");
	printf("�Է��Ͻ� Ű�� �������� ������ in/lb �� ��� 1��, m/kg �� ��� 2�� �Է����ּ��� : ");	//�� ���� ��� ���ð���
	scanf_s("%d", &unit);
	if (unit == 1 || unit == 2)
		switch (unit)	//�Է¹��� ������ ������ BMI���
		{
		case 1: 
		{
			printf("Ű�� �Է����ּ��� : (��ġ �����Դϴ�.(in))");
			scanf_s("%f", &hei);
			printf("�����Ը� �Է����ּ��� : (�Ŀ�� �����Դϴ�.(lb))");
			scanf_s("%f", &wei);
			
			BMI = wei * 703 / (hei*hei);
			
			if ((hei > 0 && hei < 110) && (wei < 1300 && wei>0))	 //����� ���� BMI���� ���α׷��̹Ƿ� �ΰ��� �Ѱ�� ��������
			{
				BMI_level((float)BMI);	//�Լ�ȣ��
			}
			else
				printf("�߸� �Է��ϼ̽��ϴ�.\n ����� Ű Ȥ�� �����԰� �ƴմϴ�.");
		}
		case 2:
		{
			printf("Ű�� �Է����ּ��� : (���� �����Դϴ�.(m))");
			scanf_s("%f", &hei);
			printf("�����Ը� �Է����ּ��� : (ų�α׷� �����Դϴ�.(kg))");
			scanf_s("%f", &wei);
			
			BMI = wei / (hei*hei);
			
			if ((hei > 0 && hei < 3) && (wei < 600 && wei>0))	//����� ���� BMI���� ���α׷��̹Ƿ� �ΰ��� �Ѱ�� ��������
			{
				BMI_level((float)BMI);	//�Լ�ȣ��
			}
			else
				printf("�߸� �Է��ϼ̽��ϴ�.\n����� Ű Ȥ�� �����԰� �ƴմϴ�.");

		}
		}
	else
		printf("�߸� �Է��ϼ̽��ϴ�. ���������� ���� 1�� 2�θ� �Է����ֽʽÿ�.\n");
}
float BMI_level(float BMI)	/*�Լ�����-���:BMI���� ���� �ǰ����¸� ������ش�.
									  -����:BMI��*/
{
	if (BMI < 18.5)
		printf("����� ��ü���Դϴ�.\n");
	else if (BMI >= 18.5&&BMI <= 24.9)
		printf("����� ����ü���Դϴ�.\n");
	else if (BMI>24.9 && BMI <= 29.9)
		printf("����� ��ü���Դϴ�.\n");
	else if (BMI > 29.9)
		printf("����� ���Դϴ�.\n");
	return (float)BMI;
}