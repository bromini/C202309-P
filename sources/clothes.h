#ifndef CLOTHES_H
#define CLOTHES_H

#define MAX_CLOTHES 5
#define MAX_LENGTH 50

typedef struct {
	char name[MAX_LENGTH];
} Clothes;

// ����ڷκ��� �� ������ �Է¹޴� �Լ�
void getClothes(Clothes** clothes, const char* season, int* numClothes);

// �ش� ������ �� ����Ʈ�� ����ϴ� �Լ�
void printClothesForSeason(const Clothes* clothes, const char* season, int numClothes);

// ���� ������ ���� ���� ��õ�ϴ� �Լ�
void recommendOutfit(const Clothes* clothes, int numClothes, const char* season);

// �߰� �� ���Ÿ� �����ϴ� �Լ�
void recommendAdditionalClothes(int numSpringClothes, int numSummerClothes,
	int numFallClothes, int numWinterClothes);

// ���� ������ �Ǵ��ϰ� ���� ��õ�ϴ� �Լ�
void determineSeason(const Clothes* springClothes, int numSpringClothes,
	const Clothes* summerClothes, int numSummerClothes,
	const Clothes* fallClothes, int numFallClothes,
	const Clothes* winterClothes, int numWinterClothes);

// ��ü �� ����Ʈ�� ����ϰ� ������ ���� Ȯ���ϴ� �Լ�
void printTotalClothes(const Clothes* springClothes, int numSpringClothes,
	const Clothes* summerClothes, int numSummerClothes,
	const Clothes* fallClothes, int numFallClothes,
	const Clothes* winterClothes, int numWinterClothes);

#endif
