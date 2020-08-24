/* Project 4.c */
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1024
#include <stdio.h>
#include <string.h>		//strtok�Լ� ���
#include< stdlib.h >	//malloc �����޸� ���

/*�Լ� ����*/

int retToken(char * ori[], char * ptr);	// ���ڿ��� �������� ���ο� �迭�� �Է�.
char Search(char * ori[], int n, char key[]);	// Ư�� ���������� ã�� �ε����� ����.

main()
{
	int index;
	char * ori[MAX]; // ���ڿ��� �� �迭 
	char * inp;	//���Ϸκ��� ���ڿ��� �о���� ����
	char key[40];	//�Է¹��� ��������
	FILE * fp; 

	fp = fopen("recipe2.txt", "r");
	inp = malloc(MAX);	//�޸� �����Ҵ�

	while (fgets(inp, MAX, fp))	//���ϼ� ���ڿ� ������ �о����
	{
		index = retToken(ori, inp);	// �Լ� ȣ��. �Լ��� ori �迭�� �ּҿ� �Է¹��� ��Ʈ���� ����, ��ü ���ڿ� �ε��� ����.
	}

	printf("\n���Ͻô� �����̸��� �Է��ϼ���:");
	scanf("%s,", key);

	int j = Search(ori, index, key);	//�Լ� ȣ��. �Լ��� ori�迭�� �ּڰ�, �迭 ��ü �ε�����, ��Ḧ ����
	
	if (j == -1)	//���ϰ��� -1�̸� ��ġ�ϴ� �׸� ����
	{
		printf("ã���ô� ������ �����ǿ� �غ�Ǿ����� �ʽ��ϴ�.");
	}
	
	int k,l;
	
	for (k = 0; k < 5; k++)	//��� ��¹�
	{
		if (j == 0 + k * 9)	//�����̸��� index�� 9�� ���̳�
		{	
			printf("�غ��Ͻ� ���:");
			for (l = 1 + k * 9; l < 9 + k * 9; l++)
			{
				printf("%s", ori[l]);
			}
			printf("\n#������ ���� 4�κ� �����Դϴ�!#\n");
			
		}

	}
	
	free(inp);	//���� �޸� ����
	fclose(fp);
}


int retToken(char * ori[], char * inp)	//�Լ�����
{
	int i=0,j = 0;
	char * ptr = strtok(inp, " ,=");	// strtok()�� �̿��Ͽ� ���ڿ��� ''/ ','/'=' ��ū�� �������� �ڸ�
	
	while (ptr != NULL)	//������ �ν�
	{
		ori[i] = ptr;	//strtok�� �ڸ� ������ ori�迭�� ����
		ptr = strtok(NULL, " ,=");
		i++;
	}
	
	printf("@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ �����ǰ� �غ�� �����Դϴ�. @ @ @ @ @ @ @ @ @ @ @ @ @ @ @\n");
	
	for (j = 0; j < 5; j++)	//�����̸��� 5�� ��� ���
	{
		printf(" %d. %s", j + 1, ori[0 + j * 9]);
	}
	
	return i;	//ori�迭���� ���� ū index���� ����
}

char Search(char * ori[], int n, char key[])	//�Լ�����
{
	int j, k;

	for (j = 0, k = 0; j < n; j++)	//ori�迭�� index������ ��
	{
		if (strcmp(ori[j], key) == 0)
			return j;	//��ġ�ϴ� index�� ����
	}
	return -1;	//�迭 �ȿ� ���� ���� �Է�������. return -1
}




