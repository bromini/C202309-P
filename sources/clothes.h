#ifndef CLOTHES_H
#define CLOTHES_H

#define MAX_CLOTHES 5
#define MAX_LENGTH 50

typedef struct {
	char name[MAX_LENGTH];
} Clothes;

void recommendOutfit(const Clothes* clothes, int numClothes, const char* season);
void getClothes(Clothes** clothes, const char* season, int* numClothes);
void printTotalClothes(const Clothes* springClothes, int numSpringClothes,
	const Clothes* summerClothes, int numSummerClothes,
	const Clothes* fallClothes, int numFallClothes,
	const Clothes* winterClothes, int numWinterClothes);

#endif 