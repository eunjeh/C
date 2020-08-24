/* Project 3.c */

#define MAX 1024
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>		//strtok함수 사용
#include< stdlib.h >	//malloc 동적메모리 사용


/*함수 선언*/

int retToken(char * ori[], char * ptr);		// 문자열을 조각내어 새로운 배열에 입력.
char Search(char * ori[], int n, char key[][20]);	// 특정 문자조각을 찾아 인덱스를 리턴.

int arr[25] = { 0 };	//일치하는 인덱스 대입할 배열 - 전역변수 선언

main()
{
	int index;
	char key[3][20];	//입력받을 값
	char * ori[MAX]; // 문자열이 들어갈 배열 
	char * inp;	//파일로부터 문자열을 읽어들일 공간
	int i,j,k;	//for문을 위한 변수들
	FILE * fp;

	fp = fopen("recipe.txt", "r");
	inp = malloc(MAX);	//메모리 동적할당

	while (fgets(inp, MAX, fp))	//파일속 문자열 끝까지 읽어오기
	{
		index = retToken(ori, inp);	// 함수 호출. 함수로 ori 배열의 주소와 입력받은 스트링을 전달, 전체 문자열 인덱스 리턴.
	}
	
	printf("재료입력 예시: 김 계란 토마토\n");
	
	/*음식 재료 입력받기*/

	for (i= 0; i < 3; i++)
	{
		printf("가지고 있는 %d 번째 음식재료를 입력하세요:\n",i+1);
		scanf("%s,", key[i]);
	}
	
	Search(ori, index, key);	//함수 호출
	
	/*index 값 기반, 재료와 음식 매칭하여 출력*/

	for (k = 0; k < 3; k++)
	{
		for (j = 0; j < 5; j++)	//음식 총 5개
		{
			if (arr[k] > 0 + j * 6 && arr[k] < 6 + j * 6)	//재료 각각 5개씩
			{
				printf("\n%s를 바탕으로 %s를 만드실 수 있습니다!\n", key[k], ori[0 + j * 6]);
			}
		}
	}
	
	free(inp);	//동적 메모리 해제
	fclose(fp);
}

int retToken(char*ori[], char *inp)	//함수정의
{
	int i = 0;
	char* ptr = strtok(inp, " ,=");	// strtok()을 이용하여 문자열을 ''/ ','/'=' 토큰을 기준으로 자름
	while (ptr != NULL)	//끝까지 인식
	{
		ori[i] = ptr;	//strtok로 자른 조각을 ori배열에 대입
		ptr = strtok(NULL, " ,=");
		i++;
	}
	return i;	//ori배열에서 제일 큰 index값을 리턴
}
char Search(char* ori[], int n, char key[][20])	//함수정의
{
	int i, j, k=0;
	for (i = 0; i < 3; i++)	//입력받은 재료 총 3개
	{
		for (j = 0; j < n; j++)	//배열 내용 끝까지 비교
		{

			if (strcmp(ori[j], key[i]) == 0)
			{
				arr[k] = j;	//일치하는 값의 인덱스 대입
				k += 1;	//arr에 순차적으로 넣기
			}

		}
	}
	return j;
	
}




