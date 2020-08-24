/* Project 2.c */

#include <stdio.h>

int main()
{
	int total;	//한달 용돈
	int today[31];	//일일 지출액
	int i,sum;

	printf("@@@@@@@@@@@@@@@이 프로그램은 대학생의 용돈기반 한달 지출액에 대한 정보를 제공합니다.@@@@@@@@@@@@@@@\n\n");
	printf("한 달 용돈이 얼마인지 입력해주세요 : (원)");
	scanf_s("%d", &total);
	
	if (total <= 0)
	{
		printf("용돈을 양의 값으로 입력해 주시기 바랍니다.\n");
	}
	else
	{
		for (i = 0, sum = 0; i < 31; i++)
		{
			printf("%d일에 지출한 돈의 총합을 입력해주세요 : ", i + 1);
			scanf_s("%d", &today[i]);	//배열에 차례로 일일 지출액을 입력받는다.
			
			sum += today[i];	// 총합구하기
			
			if (sum > total)
			{
				printf("입력하신 한 달 용돈이 초과되었습니다.");	//한달 용돈 이상을 쓸 수 없다.(용돈통장이기 때문에)
				return -1;
			}
			
			if (today < 0)
			{
				printf("일일 지출액을 양의 값으로 입력해 주시기 바랍니다.");
				return -1;
			}
		}
		/*31일치 용돈 배열의 선택정렬*/

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
		printf("이번 달 총 지출액은 %d원입니다\n.", sum);
		printf("1일 평균 지출액은 %d원입니다\n.", sum / 31);
		printf("이번 달 중 하루 지출액의 최댓값은 %d원입니다.\n ",today[30]);
		
	}
	return 0;
}
