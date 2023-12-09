#include "clothes.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Clothes* springClothes, * summerClothes, * fallClothes, * winterClothes;
    int numSpringClothes = 0, numSummerClothes = 0, numFallClothes = 0, numWinterClothes = 0;

    getClothes(&springClothes, "봄", &numSpringClothes);
    getClothes(&summerClothes, "여름", &numSummerClothes);
    getClothes(&fallClothes, "가을", &numFallClothes);
    getClothes(&winterClothes, "겨울", &numWinterClothes);

    printTotalClothes(springClothes, numSpringClothes, summerClothes, numSummerClothes,
        fallClothes, numFallClothes, winterClothes, numWinterClothes);

    free(springClothes);
    free(summerClothes);
    free(fallClothes);
    free(winterClothes);

    return 0;

}
