#include "clothes.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	Clothes* springClothes, * summerClothes, * fallClothes, * winterClothes;
	int numSpringClothes = 0, numSummerClothes = 0, numFallClothes = 0, numWinterClothes = 0;

	// 봄 옷 정보 입력
	getClothes(&springClothes, "봄", &numSpringClothes);

	// 여름 옷 정보 입력
	getClothes(&summerClothes, "여름", &numSummerClothes);

	// 가을 옷 정보 입력
	getClothes(&fallClothes, "가을", &numFallClothes);

	// 겨울 옷 정보 입력
	getClothes(&winterClothes, "겨울", &numWinterClothes);

	// 각 계절별 옷 리스트 출력 및 부족한 옷 확인
	printTotalClothes(springClothes, numSpringClothes, summerClothes, numSummerClothes,
		fallClothes, numFallClothes, winterClothes, numWinterClothes);

	// 할당된 메모리 해제
	free(springClothes);
	free(summerClothes);
	free(fallClothes);
	free(winterClothes);

	return 0;
}
