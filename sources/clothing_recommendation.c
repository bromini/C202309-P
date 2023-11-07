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
    struct ClothingItem wardrobe[10]; // �ִ� 10���� �� �������� ������ �� �ִ� �迭
    int clothesCount = 0; // ���� ���忡 ����� �� ������ ��

    while (clothesCount < 10) {
        printf("���Ǹ� �Է��ϼ���: ");
        scanf_s("%s", wardrobe[clothesCount].top, sizeof(wardrobe[clothesCount].top));
        printf("���Ǹ� �Է��ϼ���: ");
        scanf_s("%s", wardrobe[clothesCount].bottom, sizeof(wardrobe[clothesCount].bottom));
        printf("�Ź��� �Է��ϼ���: ");
        scanf_s("%s", wardrobe[clothesCount].shoes, sizeof(wardrobe[clothesCount].shoes));
        clothesCount++;

        char choice;
        printf("�� �Է��Ͻðڽ��ϱ�? �ִ� 10��Ʈ���� �Է��� �� �ֽ��ϴ�. (y/n): ");
        scanf_s(" %c", &choice);

        if (choice != 'y' && choice != 'Y') { // ��ҹ��� �������� �������� ���ǹ�
            break;
        }
    }

    // ����ڰ� �ּ� 3�� ���� �̹� ���� �� ����
    struct WornOutfit wornOutfits[3];

    for (int i = 0; i < 3; i++) {
        printf("�ּ� 3�� ���� �̹� ���� �� ������ �Է��ϼ��� \n");
        printf("���Ǹ� �Է��ϼ���: ");
        scanf_s("%s", wornOutfits[i].top, sizeof(wornOutfits[i].top));
        printf("���Ǹ� �Է��ϼ���: ");
        scanf_s("%s", wornOutfits[i].bottom, sizeof(wornOutfits[i].bottom));
        printf("�Ź��� �Է��ϼ���: ");
        scanf_s("%s", wornOutfits[i].shoes, sizeof(wornOutfits[i].shoes));
    }

    printf("�̹� ���� �� ������ ����մϴ�:\n");
    for (int i = 0; i < 3; i++) {
        printf("����: %s, ����: %s, �Ź�: %s\n", wornOutfits[i].top, wornOutfits[i].bottom, wornOutfits[i].shoes);
    }
    return 0;
}