#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CLOTHES 5
#define MAX_LENGTH 50

// recommendOutfit 함수를 determineSeason 함수 위에 선언
void recommendOutfit(const char clothes[MAX_CLOTHES][MAX_LENGTH], int numClothes, const char* season);

void getClothes(char clothes[MAX_CLOTHES][MAX_LENGTH], const char* season, int* numClothes) {
    // 사용자에게 옷 입력을 요청하는 함수
    printf("%s 옷차림(룩)을 입력해주세요: (최대 %d가지,띄어쓰기 사용 X) \n예시)검정맨투맨슬랙스단화\n", season, MAX_CLOTHES);
    while (*numClothes < MAX_CLOTHES) {
        printf("옷차림(룩) %d: ", *numClothes + 1);
        scanf_s("%s", clothes[*numClothes], MAX_LENGTH);

        (*numClothes)++; // 옷 개수 증가

        printf("더 입력하시겠습니까? (종료시: n or N/더 입력하려면 아무키나 누르시오): ");
        char choice;
        scanf_s(" %c", &choice, sizeof(choice));

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }
}

// 선택된 계절의 옷 목록을 출력하는 함수
void printClothesForSeason(const char clothes[MAX_CLOTHES][MAX_LENGTH], const char* season, int numClothes) {
    printf("\n%s 옷차림(룩) 목록:\n", season);
    for (int i = 0; i < numClothes; ++i) {
        printf("%d. %s\n", i + 1, clothes[i]);
    }
}

void determineSeason(const char springClothes[MAX_CLOTHES][MAX_LENGTH], int numSpringClothes,
    const char summerClothes[MAX_CLOTHES][MAX_LENGTH], int numSummerClothes,
    const char fallClothes[MAX_CLOTHES][MAX_LENGTH], int numFallClothes,
    const char winterClothes[MAX_CLOTHES][MAX_LENGTH], int numWinterClothes) {
    // 현재 기온을 입력받아 계절을 판별하고 해당 계절에 맞는 옷을 추천해주는 함수
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

void recommendOutfit(const char clothes[MAX_CLOTHES][MAX_LENGTH], int numClothes, const char* season) {
    // 해당 계절의 옷 중에서 랜덤으로 옷을 추천해주는 함수
    if (numClothes == 0) {
        printf("추천할 수 없습니다. %s에 대한 옷차림(룩)이 없습니다.\n", season);
        return;
    }

    srand(time(NULL));
    int randomIndex = rand() % numClothes;

    printf("\n현재 날씨에 따른 옷차림(룩)을 추천합니다: %s - %s\n", season, clothes[randomIndex]);
}

void recommendAdditionalClothes(const int numSpringClothes, const int numSummerClothes,
    const int numFallClothes, const int numWinterClothes) {
    // 부족한 계절의 옷 개수를 알려주는 함수
    printf("\n추가적인 옷을 구매하시길 권장하는 계절:\n");

    if (numSpringClothes < MAX_CLOTHES) {
        printf("- 봄 옷을 %d개 더 구매하십시오.\n", MAX_CLOTHES - numSpringClothes);
    }
    if (numSummerClothes < MAX_CLOTHES) {
        printf("- 여름 옷을 %d개 더 구매하십시오.\n", MAX_CLOTHES - numSummerClothes);
    }
    if (numFallClothes < MAX_CLOTHES) {
        printf("- 가을 옷을 %d개 더 구매하십시오.\n", MAX_CLOTHES - numFallClothes);
    }
    if (numWinterClothes < MAX_CLOTHES) {
        printf("- 겨울 옷을 %d개 더 구매하십시오.\n", MAX_CLOTHES - numWinterClothes);
    }
}

void printTotalClothes(const char springClothes[MAX_CLOTHES][MAX_LENGTH], int numSpringClothes,
    const char summerClothes[MAX_CLOTHES][MAX_LENGTH], int numSummerClothes,
    const char fallClothes[MAX_CLOTHES][MAX_LENGTH], int numFallClothes,
    const char winterClothes[MAX_CLOTHES][MAX_LENGTH], int numWinterClothes) {
    // 모든 계절의 옷 목록을 출력하고, 부족한 옷 개수를 알려주며, 해당 계절의 추천 옷을 보여주는 함수
    printf("\n가진 옷 리스트:\n");
    printClothesForSeason(springClothes, "봄", numSpringClothes);
    printClothesForSeason(summerClothes, "여름", numSummerClothes);
    printClothesForSeason(fallClothes, "가을", numFallClothes);
    printClothesForSeason(winterClothes, "겨울", numWinterClothes);

    recommendAdditionalClothes(numSpringClothes, numSummerClothes, numFallClothes, numWinterClothes);

    determineSeason(springClothes, numSpringClothes, summerClothes, numSummerClothes,
        fallClothes, numFallClothes, winterClothes, numWinterClothes);
}

int main() {
    // 각 계절의 옷을 입력받고, 총 옷 목록을 출력하며, 추천 옷을 결정하는 메인 함수
    char springClothes[MAX_CLOTHES][MAX_LENGTH];
    char summerClothes[MAX_CLOTHES][MAX_LENGTH];
    char fallClothes[MAX_CLOTHES][MAX_LENGTH];
    char winterClothes[MAX_CLOTHES][MAX_LENGTH];

    int numSpringClothes = 0, numSummerClothes = 0, numFallClothes = 0, numWinterClothes = 0;

    getClothes(springClothes, "봄", &numSpringClothes);
    getClothes(summerClothes, "여름", &numSummerClothes);
    getClothes(fallClothes, "가을", &numFallClothes);
    getClothes(winterClothes, "겨울", &numWinterClothes);

    printTotalClothes(springClothes, numSpringClothes, summerClothes, numSummerClothes,
        fallClothes, numFallClothes, winterClothes, numWinterClothes);

    return 0;
}
