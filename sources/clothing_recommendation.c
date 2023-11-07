#include <stdio.h>
#include <string.h>

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