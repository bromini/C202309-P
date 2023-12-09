#include "clothes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getClothes(Clothes** clothes, const char* season, int* numClothes) {
    printf("%s 옷차림(룩)을 입력해주세요: (최대 %d가지,띄어쓰기 사용 X)\n예시) 검정맨투맨슬랙스단화\n", season, MAX_CLOTHES);

    *clothes = (Clothes*)malloc(MAX_CLOTHES * sizeof(Clothes));
    if (*clothes == NULL) {
        printf("메모리 할당 오류\n");
        exit(1);
    }

    while (*numClothes < MAX_CLOTHES) {
        printf("옷차림(룩) %d: ", *numClothes + 1);
        scanf_s("%s", (*clothes)[*numClothes].name, MAX_LENGTH);

        (*numClothes)++;

        printf("더 입력하시겠습니까? (종료시: n or N/더 입력하려면 아무키나 누르시오): ");
        char choice;
        scanf_s(" %c", &choice, sizeof(choice));

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }
}

void printClothesForSeason(const Clothes* clothes, const char* season, int numClothes) {
    printf("\n%s 옷차림(룩) 목록:\n", season);
    for (int i = 0; i < numClothes; ++i) {
        printf("%d. %s\n", i + 1, clothes[i].name);
    }

}

void recommendOutfit(const Clothes* clothes, int numClothes, const char* season) {
    if (numClothes == 0) {
        printf("추천할 수 없습니다. %s에 대한 옷차림(룩)이 없습니다.\n", season);
        return;
    }

    srand(time(NULL));
    int randomIndex = rand() % numClothes;

    printf("\n현재 날씨에 따른 옷차림(룩)을 추천합니다: %s - %s\n", season, clothes[randomIndex].name);
    const char* fileName = "recommended_outfit.txt";

    FILE* file;
    errno_t err = fopen_s(&file, fileName, "a"); // 파일 열기 시도

    if (err != 0) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    // 결과를 파일에 쓰기
    fprintf(file, "\n현재 날씨에 따른 옷차림(룩)을 추천합니다: %s - %s\n", season, clothes[randomIndex].name);

    // 파일 닫기
    fclose(file);
}

void recommendAdditionalClothes(int numSpringClothes, int numSummerClothes,
    int numFallClothes, int numWinterClothes) {
    printf("\n추가적인 옷을 구매하시길 권장하는 계절:\n");

    // 파일 이름 설정
    const char* fileName = "recommended_clothes.txt";

    FILE* file;
    errno_t err = fopen_s(&file, fileName, "a"); // 파일 열기 시도

    if (err != 0) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    if (numSpringClothes < MAX_CLOTHES) {
        printf("- 봄 옷을 %d개 더 구매하십시오.\n", MAX_CLOTHES - numSpringClothes);
        fprintf(file, "- 봄 옷을 %d개 더 구매하십시오.\n", MAX_CLOTHES - numSpringClothes);
    }
    if (numSummerClothes < MAX_CLOTHES) {
        printf("- 여름 옷을 %d개 더 구매하십시오.\n", MAX_CLOTHES - numSummerClothes);
        fprintf(file, "- 여름 옷을 %d개 더 구매하십시오.\n", MAX_CLOTHES - numSummerClothes);
    }
    if (numFallClothes < MAX_CLOTHES) {
        printf("- 가을 옷을 %d개 더 구매하십시오.\n", MAX_CLOTHES - numFallClothes);
        fprintf(file, "- 가을 옷을 %d개 더 구매하십시오.\n", MAX_CLOTHES - numFallClothes);
    }
    if (numWinterClothes < MAX_CLOTHES) {
        printf("- 겨울 옷을 %d개 더 구매하십시오.\n", MAX_CLOTHES - numWinterClothes);
        fprintf(file, "- 겨울 옷을 %d개 더 구매하십시오.\n", MAX_CLOTHES - numWinterClothes);
    }

    fclose(file); // 파일 닫기
}


void determineSeason(const Clothes* springClothes, int numSpringClothes,
    const Clothes* summerClothes, int numSummerClothes,
    const Clothes* fallClothes, int numFallClothes,
    const Clothes* winterClothes, int numWinterClothes) {
    int temperature;
    printf("\n현재 기온을 입력해 주세요: ");
    scanf_s("%d", &temperature);

    const char* season;
    if (temperature >= 23) {
        season = "여름";
        recommendOutfit(summerClothes, numSummerClothes, season);
    }
    else if (temperature >= 12 && temperature < 23) {
        season = "봄";
        recommendOutfit(springClothes, numSpringClothes, season);
    }
    else if (temperature >= 5 && temperature < 12) {
        season = "가을";
        recommendOutfit(fallClothes, numFallClothes, season);
    }
    else {
        season = "겨울";
        recommendOutfit(winterClothes, numWinterClothes, season);
    }
}

void printTotalClothes(const Clothes* springClothes, int numSpringClothes,
    const Clothes* summerClothes, int numSummerClothes,
    const Clothes* fallClothes, int numFallClothes,
    const Clothes* winterClothes, int numWinterClothes) {
    printf("\n가진 옷 리스트:\n");
    printClothesForSeason(springClothes, "봄", numSpringClothes);
    printClothesForSeason(summerClothes, "여름", numSummerClothes);
    printClothesForSeason(fallClothes, "가을", numFallClothes);
    printClothesForSeason(winterClothes, "겨울", numWinterClothes);

    recommendAdditionalClothes(numSpringClothes, numSummerClothes, numFallClothes, numWinterClothes);

    determineSeason(springClothes, numSpringClothes, summerClothes, numSummerClothes,
        fallClothes, numFallClothes, winterClothes, numWinterClothes);
}