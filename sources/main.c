#include "clothes.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Clothes* springClothes, * summerClothes, * fallClothes, * winterClothes;
    int numSpringClothes = 0, numSummerClothes = 0, numFallClothes = 0, numWinterClothes = 0;

    getClothes(&springClothes, "��", &numSpringClothes);
    getClothes(&summerClothes, "����", &numSummerClothes);
    getClothes(&fallClothes, "����", &numFallClothes);
    getClothes(&winterClothes, "�ܿ�", &numWinterClothes);

    printTotalClothes(springClothes, numSpringClothes, summerClothes, numSummerClothes,
        fallClothes, numFallClothes, winterClothes, numWinterClothes);

    free(springClothes);
    free(summerClothes);
    free(fallClothes);
    free(winterClothes);

    return 0;

}
