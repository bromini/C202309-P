#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CLOTHES 5 // �� ������ �ִ� �� ��
#define MAX_KEYWORD_LEN 20 // Ư�� Ű���� �ִ� ����

struct ClothingItem {
    char* top[MAX_CLOTHES];
    char* bottom[MAX_CLOTHES];
};

void recommendClothes(int temperature, struct ClothingItem clothes);

int main() {
    struct ClothingItem spring, summer, autumn, winter;

    // �� �� �Է�
    printf("�� ���Ǹ� �Է��ϼ��� (�ִ� %d��): \n", MAX_CLOTHES);
    for (int i = 0; i < MAX_CLOTHES; i++) {
        char tempTop[MAX_KEYWORD_LEN];
        scanf_s("%s", tempTop);
        spring.top[i] = strdup(tempTop);
    }

    printf("�� ���Ǹ� �Է��ϼ��� (�ִ� %d��): \n", MAX_CLOTHES);
    for (int i = 0; i < MAX_CLOTHES; i++) {
        char tempBottom[MAX_KEYWORD_LEN];
        scanf_s("%s", tempBottom);
        spring.bottom[i] = strdup(tempBottom);
    }

    // ����, ����, �ܿ� �� �Է� (���� �����ϰ�)

    int currentTemperature;
    printf("���� ����� �Է��ϼ���: ");
    scanf_s("%d", &currentTemperature);

    // �� �������� ��õ���ִ� �Լ� ȣ��
    recommendClothes(currentTemperature, spring);
    // ����, ����, �ܿ￡ ���ؼ��� �� �Լ��� ȣ��

    return 0;
}

void recommendClothes(int temperature, struct ClothingItem clothes) {
    printf("���� ����� %d�� �Դϴ�.\n", temperature);

    printf("��õ�ϴ� ���� ������ �����ϴ�:\n");
    if (temperature >= 25) {
        // ���� ������ �´� �� ��õ
        printf("����: %s, ����: %s\n", clothes.top[0], clothes.bottom[0]);
    }
    else if (temperature >= 15) {
        // �ÿ��� ������ �´� �� ��õ
        printf("����: %s, ����: %s\n", clothes.top[1], clothes.bottom[1]);
    }
    else {
        // �ҽ��� ������ �´� �� ��õ
        printf("����: %s, ����: %s\n", clothes.top[2], clothes.bottom[2]);
    }
}

