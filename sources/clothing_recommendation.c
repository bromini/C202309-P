#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CLOTHES 5 // 각 계절별 최대 옷 수
#define MAX_KEYWORD_LEN 20 // 특정 키워드 최대 길이

struct ClothingItem {
    char* top[MAX_CLOTHES];
    char* bottom[MAX_CLOTHES];
};

void recommendClothes(int temperature, struct ClothingItem clothes);

int main() {
    struct ClothingItem spring, summer, autumn, winter;

    // 봄 옷 입력
    printf("봄 상의를 입력하세요 (최대 %d개): \n", MAX_CLOTHES);
    for (int i = 0; i < MAX_CLOTHES; i++) {
        char tempTop[MAX_KEYWORD_LEN];
        scanf_s("%s", tempTop);
        spring.top[i] = strdup(tempTop);
    }

    printf("봄 하의를 입력하세요 (최대 %d개): \n", MAX_CLOTHES);
    for (int i = 0; i < MAX_CLOTHES; i++) {
        char tempBottom[MAX_KEYWORD_LEN];
        scanf_s("%s", tempBottom);
        spring.bottom[i] = strdup(tempBottom);
    }

    // 여름, 가을, 겨울 옷 입력 (위와 동일하게)

    int currentTemperature;
    printf("현재 기온을 입력하세요: ");
    scanf_s("%d", &currentTemperature);

    // 각 계절별로 추천해주는 함수 호출
    recommendClothes(currentTemperature, spring);
    // 여름, 가을, 겨울에 대해서도 위 함수를 호출

    return 0;
}

void recommendClothes(int temperature, struct ClothingItem clothes) {
    printf("현재 기온은 %d도 입니다.\n", temperature);

    printf("추천하는 옷은 다음과 같습니다:\n");
    if (temperature >= 25) {
        // 더운 날씨에 맞는 옷 추천
        printf("상의: %s, 하의: %s\n", clothes.top[0], clothes.bottom[0]);
    }
    else if (temperature >= 15) {
        // 시원한 날씨에 맞는 옷 추천
        printf("상의: %s, 하의: %s\n", clothes.top[1], clothes.bottom[1]);
    }
    else {
        // 쌀쌀한 날씨에 맞는 옷 추천
        printf("상의: %s, 하의: %s\n", clothes.top[2], clothes.bottom[2]);
    }
}

