#ifndef CLOTHES_H
#define CLOTHES_H

#define MAX_CLOTHES 5
#define MAX_LENGTH 50

typedef struct {
	char name[MAX_LENGTH];
} Clothes;

// 사용자로부터 옷 정보를 입력받는 함수
void getClothes(Clothes** clothes, const char* season, int* numClothes);

// 해당 계절의 옷 리스트를 출력하는 함수
void printClothesForSeason(const Clothes* clothes, const char* season, int numClothes);

// 현재 날씨에 따라 옷을 추천하는 함수
void recommendOutfit(const Clothes* clothes, int numClothes, const char* season);

// 추가 옷 구매를 권장하는 함수
void recommendAdditionalClothes(int numSpringClothes, int numSummerClothes,
	int numFallClothes, int numWinterClothes);

// 현재 계절을 판단하고 옷을 추천하는 함수
void determineSeason(const Clothes* springClothes, int numSpringClothes,
	const Clothes* summerClothes, int numSummerClothes,
	const Clothes* fallClothes, int numFallClothes,
	const Clothes* winterClothes, int numWinterClothes);

// 전체 옷 리스트를 출력하고 부족한 옷을 확인하는 함수
void printTotalClothes(const Clothes* springClothes, int numSpringClothes,
	const Clothes* summerClothes, int numSummerClothes,
	const Clothes* fallClothes, int numFallClothes,
	const Clothes* winterClothes, int numWinterClothes);

#endif
