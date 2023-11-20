#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CLOTHES 10
#define MAX_LENGTH 50

// 기온에 따라 계절을 판단하는 함수
char* determineSeason(int temperature) {
    char* season;

    if (temperature >= 25) {
        season = "여름";
    }
    else if (temperature >= 15) {
        season = "봄 또는 가을";
    }
    else if (temperature >= 0) {
        season = "겨울";
    }
    else {
        season = "잘못된 온도";
    }

    return season;
}

// 각 계절의 옷을 입력하는 함수
void getClothes(char clothes[MAX_CLOTHES][MAX_LENGTH], const char* season, int* numClothes) {
    printf("%s 옷을 입력해주세요 (최대 %d가지):\n", season, MAX_CLOTHES);
    while (*numClothes < MAX_CLOTHES) {
        printf("옷 %d: ", *numClothes + 1);
        scanf_s("%s", clothes[*numClothes], MAX_LENGTH);

        printf("더 입력하시겠습니까? (y/n): ");
        char choice;
        scanf_s(" %c", &choice, sizeof(choice));

        if (choice == 'n' || choice == 'N') {
            break;
        }

        (*numClothes)++;
    }
}

// 각 계절의 옷 목록을 출력하는 함수
void printAllClothes(const char clothes[MAX_CLOTHES][MAX_LENGTH], const char* season, int numClothes) {
    printf("\n%s 옷 목록:\n", season);
    for (int i = 0; i < numClothes; ++i) {
        printf("%d. %s\n", i + 1, clothes[i]);
    }
}

// 모든 계절의 옷 리스트를 출력하는 함수
void printTotalClothes(const char springClothes[MAX_CLOTHES][MAX_LENGTH], int numSpringClothes,
    const char summerClothes[MAX_CLOTHES][MAX_LENGTH], int numSummerClothes,
    const char fallClothes[MAX_CLOTHES][MAX_LENGTH], int numFallClothes,
    const char winterClothes[MAX_CLOTHES][MAX_LENGTH], int numWinterClothes) {
    printf("\n가진 옷 리스트:\n");
    printf("봄 옷:\n");
    printAllClothes(springClothes, "봄", numSpringClothes);
    printf("\n여름 옷:\n");
    printAllClothes(summerClothes, "여름", numSummerClothes);
    printf("\n가을 옷:\n");
    printAllClothes(fallClothes, "가을", numFallClothes);
    printf("\n겨울 옷:\n");
    printAllClothes(winterClothes, "겨울", numWinterClothes);
}

// 해당 계절에 어울리는 옷을 랜덤으로 추천하는 함수
void recommendClothes(const char clothes[MAX_CLOTHES][MAX_LENGTH], int numClothes, const char* season) {
    int suitableClothes[MAX_CLOTHES];
    int numSuitable = 0;

    // 해당 계절에 어울리는 옷의 인덱스를 찾아 배열에 저장
    for (int i = 0; i < numClothes; ++i) {
        if (strstr(clothes[i], season) != NULL) {
            suitableClothes[numSuitable++] = i;
        }
    }

    // 해당 계절에 어울리는 옷이 없는 경우
    if (numSuitable == 0) {
        printf("해당 계절에 어울리는 옷이 없습니다.\n");
    }
    else { // 해당 계절에 어울리는 옷 중에서 랜덤으로 추천
        srand(time(NULL));
        int randomIndex = suitableClothes[rand() % numSuitable];
        printf("추천하는 %s 옷: %s\n", season, clothes[randomIndex]);
    }
}

int main() {
    char springClothes[MAX_CLOTHES][MAX_LENGTH];
    char summerClothes[MAX_CLOTHES][MAX_LENGTH];
    char fallClothes[MAX_CLOTHES][MAX_LENGTH];
    char winterClothes[MAX_CLOTHES][MAX_LENGTH];

    int numSpringClothes = 0, numSummerClothes = 0, numFallClothes = 0, numWinterClothes = 0;

    // 각 계절의 옷 입력 받기
    getClothes(springClothes, "봄", &numSpringClothes);
    getClothes(summerClothes, "여름", &numSummerClothes);
    getClothes(fallClothes, "가을", &numFallClothes);
    getClothes(winterClothes, "겨울", &numWinterClothes);

    // 전체 옷 리스트 출력
    printTotalClothes(springClothes, numSpringClothes, summerClothes, numSummerClothes,
        fallClothes, numFallClothes, winterClothes, numWinterClothes);

    int temperature;
    printf("\n기온을 입력하세요: ");
    scanf_s("%d", &temperature);

    char* result = determineSeason(temperature);
    printf("현재 계절은 %s입니다.\n", result);

    // 해당 계절에 맞는 옷 추천
    if (strcmp(result, "여름") == 0 || strcmp(result, "겨울") == 0 || strcmp(result, "봄 또는 가을") == 0) {
        recommendClothes(summerClothes, numSummerClothes, result);
    }
    else {
        printf("해당 계절에 대한 추천 옷은 없습니다.\n");
    }

    return 0;
}
