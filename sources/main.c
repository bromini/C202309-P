#include "clothes.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	Clothes* springClothes, * summerClothes, * fallClothes, * winterClothes;
	int numSpringClothes = 0, numSummerClothes = 0, numFallClothes = 0, numWinterClothes = 0;

	// �� �� ���� �Է�
	getClothes(&springClothes, "��", &numSpringClothes);

	// ���� �� ���� �Է�
	getClothes(&summerClothes, "����", &numSummerClothes);

	// ���� �� ���� �Է�
	getClothes(&fallClothes, "����", &numFallClothes);

	// �ܿ� �� ���� �Է�
	getClothes(&winterClothes, "�ܿ�", &numWinterClothes);

	// �� ������ �� ����Ʈ ��� �� ������ �� Ȯ��
	printTotalClothes(springClothes, numSpringClothes, summerClothes, numSummerClothes,
		fallClothes, numFallClothes, winterClothes, numWinterClothes);

	// �Ҵ�� �޸� ����
	free(springClothes);
	free(summerClothes);
	free(fallClothes);
	free(winterClothes);

	return 0;
}
