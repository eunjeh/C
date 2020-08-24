/* Project 1.c */

#include <stdio.h>

int main(void)
{
	int unit = 0; //단위
	float hei, wei;	//키,몸무게
	float BMI = 0;

	float BMI_level(float BMI);	//함수선언

	printf("@@@@@@@@@@@@@@@이 프로그램은 키와 몸무게를 입력받아BMI지수를 측정하여 건강상태를 알려줍니다.@@@@@@@@@@@@@@@\n\n");
	printf("입력하실 키와 몸무게의 단위가 in/lb 인 경우 1을, m/kg 인 경우 2를 입력해주세요 : ");	//두 가지 방법 선택가능
	scanf_s("%d", &unit);
	if (unit == 1 || unit == 2)
		switch (unit)	//입력받은 단위롸 정보로 BMI계산
		{
		case 1: 
		{
			printf("키를 입력해주세요 : (인치 단위입니다.(in))");
			scanf_s("%f", &hei);
			printf("몸무게를 입력해주세요 : (파운드 단위입니다.(lb))");
			scanf_s("%f", &wei);
			
			BMI = wei * 703 / (hei*hei);
			
			if ((hei > 0 && hei < 110) && (wei < 1300 && wei>0))	 //사람을 위한 BMI측정 프로그램이므로 인간의 한계로 조건제약
			{
				BMI_level((float)BMI);	//함수호출
			}
			else
				printf("잘못 입력하셨습니다.\n 사람의 키 혹은 몸무게가 아닙니다.");
		}
		case 2:
		{
			printf("키를 입력해주세요 : (미터 단위입니다.(m))");
			scanf_s("%f", &hei);
			printf("몸무게를 입력해주세요 : (킬로그램 단위입니다.(kg))");
			scanf_s("%f", &wei);
			
			BMI = wei / (hei*hei);
			
			if ((hei > 0 && hei < 3) && (wei < 600 && wei>0))	//사람을 위한 BMI측정 프로그램이므로 인간의 한계로 조건제약
			{
				BMI_level((float)BMI);	//함수호출
			}
			else
				printf("잘못 입력하셨습니다.\n사람의 키 혹은 몸무게가 아닙니다.");

		}
		}
	else
		printf("잘못 입력하셨습니다. 단위선택을 위해 1과 2로만 입력해주십시오.\n");
}
float BMI_level(float BMI)	/*함수정의-기능:BMI값를 통해 건강상태를 출력해준다.
									  -인자:BMI값*/
{
	if (BMI < 18.5)
		printf("당신은 저체중입니다.\n");
	else if (BMI >= 18.5&&BMI <= 24.9)
		printf("당신은 정상체중입니다.\n");
	else if (BMI>24.9 && BMI <= 29.9)
		printf("당신은 과체중입니다.\n");
	else if (BMI > 29.9)
		printf("당신은 비만입니다.\n");
	return (float)BMI;
}