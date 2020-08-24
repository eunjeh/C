/* Project 4.c */
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1024
#include <stdio.h>
#include <string.h>		//strtok함수 사용
#include< stdlib.h >	//malloc 동적메모리 사용

/*함수 선언*/

int retToken(char * ori[], char * ptr);	// 문자열을 조각내어 새로운 배열에 입력.
char Search(char * ori[], int n, char key[]);	// 특정 문자조각을 찾아 인덱스를 리턴.

main()
{
	int index;
	char * ori[MAX]; // 문자열이 들어갈 배열 
	char * inp;	//파일로부터 문자열을 읽어들일 공간
	char key[40];	//입력받을 문자조각
	FILE * fp; 

	fp = fopen("recipe2.txt", "r");
	inp = malloc(MAX);	//메모리 동적할당

	while (fgets(inp, MAX, fp))	//파일속 문자열 끝까지 읽어오기
	{
		index = retToken(ori, inp);	// 함수 호출. 함수로 ori 배열의 주소와 입력받은 스트링을 전달, 전체 문자열 인덱스 리턴.
	}

	printf("\n원하시는 음식이름을 입력하세요:");
	scanf("%s,", key);

	int j = Search(ori, index, key);	//함수 호출. 함수로 ori배열의 주솟값, 배열 전체 인덱스값, 재료를 전달
	
	if (j == -1)	//리턴값이 -1이면 일치하는 항목 없음
	{
		printf("찾으시는 음식은 레시피에 준비되어있지 않습니다.");
	}
	
	int k,l;
	
	for (k = 0; k < 5; k++)	//재료 출력문
	{
		if (j == 0 + k * 9)	//음식이름의 index는 9씩 차이남
		{	
			printf("준비하실 재료:");
			for (l = 1 + k * 9; l < 9 + k * 9; l++)
			{
				printf("%s", ori[l]);
			}
			printf("\n#음식의 재료는 4인분 기준입니다!#\n");
			
		}

	}
	
	free(inp);	//동적 메모리 해제
	fclose(fp);
}


int retToken(char * ori[], char * inp)	//함수정의
{
	int i=0,j = 0;
	char * ptr = strtok(inp, " ,=");	// strtok()을 이용하여 문자열을 ''/ ','/'=' 토큰을 기준으로 자름
	
	while (ptr != NULL)	//끝까지 인식
	{
		ori[i] = ptr;	//strtok로 자른 조각을 ori배열에 대입
		ptr = strtok(NULL, " ,=");
		i++;
	}
	
	printf("@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ 레시피가 준비된 음식입니다. @ @ @ @ @ @ @ @ @ @ @ @ @ @ @\n");
	
	for (j = 0; j < 5; j++)	//음식이름들 5만 골라 출력
	{
		printf(" %d. %s", j + 1, ori[0 + j * 9]);
	}
	
	return i;	//ori배열에서 제일 큰 index값을 리턴
}

char Search(char * ori[], int n, char key[])	//함수정의
{
	int j, k;

	for (j = 0, k = 0; j < n; j++)	//ori배열의 index끝까지 비교
	{
		if (strcmp(ori[j], key) == 0)
			return j;	//일치하는 index값 리턴
	}
	return -1;	//배열 안에 없는 값을 입력했을때. return -1
}




