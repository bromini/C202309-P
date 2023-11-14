#include <stdio.h>
#include <string.h>


// 고민해봤는데 너무 어려워서 계절별 상의, 하의를 입력받고 그 중에서 기온에 따라 옷을 추천해주는 방식으로 프로그램을 짜는걸 고려해봐야겠음
//예를 들어 아래 처럼 4가지 계절하고 기온에 따라 범위를 쥐어주고 그 옷들 중에서 추천해주는 식이 낫지 않을까 싶다
//여름 상의를 배열로 입력받는다
//여름 하의를 배열로 입력받는다

// 입었던 옷을 어떻게 제외할지도 고민이다. 특정 키워드가 들어가면 제외하도록 할수 있나















struct ClothingItem {
    char top[20];
    char bottom[20];
    char shoes[20];
};

struct WornOutfit {
    char top[20];
    char bottom[20];
    char shoes[20];
};

int main() {
    struct ClothingItem wardrobe[10]; // 최대 10개의 옷 아이템을 저장할 수 있는 배열
    int clothesCount = 0; // 현재 옷장에 저장된 옷 아이템 수

    while (clothesCount < 10) {
        printf("상의를 입력하세요: ");
        scanf_s("%s", wardrobe[clothesCount].top, sizeof(wardrobe[clothesCount].top));
        printf("하의를 입력하세요: ");
        scanf_s("%s", wardrobe[clothesCount].bottom, sizeof(wardrobe[clothesCount].bottom));
        printf("신발을 입력하세요: ");
        scanf_s("%s", wardrobe[clothesCount].shoes, sizeof(wardrobe[clothesCount].shoes));
        clothesCount++;

        char choice;
        printf("더 입력하시겠습니까? 최대 10세트까지 입력할 수 있습니다. (y/n): ");
        scanf_s(" %c", &choice);

        if (choice != 'y' && choice != 'Y') { // 대소문자 구별하지 않으려는 조건문
            break;
        }
    }

    // 사용자가 최소 3일 전에 이미 입은 옷 저장
    struct WornOutfit wornOutfits[3];

    for (int i = 0; i < 3; i++) {
        printf("최소 3일 전에 이미 입은 옷 정보를 입력하세요 \n");
        printf("상의를 입력하세요: ");
        scanf_s("%s", wornOutfits[i].top, sizeof(wornOutfits[i].top));
        printf("하의를 입력하세요: ");
        scanf_s("%s", wornOutfits[i].bottom, sizeof(wornOutfits[i].bottom));
        printf("신발을 입력하세요: ");
        scanf_s("%s", wornOutfits[i].shoes, sizeof(wornOutfits[i].shoes));
    }

    printf("이미 입은 옷 정보를 출력합니다:\n");
    for (int i = 0; i < 3; i++) {
        printf("상의: %s, 하의: %s, 신발: %s\n", wornOutfits[i].top, wornOutfits[i].bottom, wornOutfits[i].shoes);
    }
    return 0;
}