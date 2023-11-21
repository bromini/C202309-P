#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CLOTHES 10
#define MAX_LENGTH 50

void recommendOutfit(const char clothes[MAX_CLOTHES][MAX_LENGTH], int numClothes, const char* season) {
    // 옷이 없는 경우 해당 계절에 대한 추천이 불가능함을 알림
    if (numClothes == 0) {
        printf("추천할 수 없습니다. %s에 대한 옷이 없습니다.\n", season);
        return;
    }

    // 시간을 기반으로 난수 생성을 위한 초기화
    srand(time(NULL));

    // 해당 계절의 옷 목록에서 랜덤한 인덱스를 생성하여 추천
    int randomIndex = rand() % numClothes;

    printf("\n현재 날씨에 따른 옷을 추천합니다: %s - %s\n", season, clothes[randomIndex]);
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
    printf("현재 기온을 입력해 주세요: ");
    scanf_s("%d", &temperature);

    const char* season;
    // 기온에 따라 계절 판별
    if (temperature >= 25) {
        season = "여름";
        recommendOutfit(summerClothes, numSummerClothes, season);
    }
    else if (temperature >= 15 && temperature < 25) {
        season = "봄";
        recommendOutfit(springClothes, numSpringClothes, season);
    }
    else if (temperature >= 5 && temperature < 15) {
        season = "가을";
        recommendOutfit(fallClothes, numFallClothes, season);
    }
    else {
        season = "겨울";
        recommendOutfit(winterClothes, numWinterClothes, season);
    }

    return 0;
}