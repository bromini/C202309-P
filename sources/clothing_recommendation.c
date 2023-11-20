#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CLOTHES 10
#define MAX_LENGTH 50

// ��¿� ���� ������ �Ǵ��ϴ� �Լ�
char* determineSeason(int temperature) {
    char* season;

    if (temperature >= 25) {
        season = "����";
    }
    else if (temperature >= 15) {
        season = "�� �Ǵ� ����";
    }
    else if (temperature >= 0) {
        season = "�ܿ�";
    }
    else {
        season = "�߸��� �µ�";
    }

    return season;
}

// �� ������ ���� �Է��ϴ� �Լ�
void getClothes(char clothes[MAX_CLOTHES][MAX_LENGTH], const char* season, int* numClothes) {
    printf("%s ���� �Է����ּ��� (�ִ� %d����):\n", season, MAX_CLOTHES);
    while (*numClothes < MAX_CLOTHES) {
        printf("�� %d: ", *numClothes + 1);
        scanf_s("%s", clothes[*numClothes], MAX_LENGTH);

        printf("�� �Է��Ͻðڽ��ϱ�? (y/n): ");
        char choice;
        scanf_s(" %c", &choice, sizeof(choice));

        if (choice == 'n' || choice == 'N') {
            break;
        }

        (*numClothes)++;
    }
}

// �� ������ �� ����� ����ϴ� �Լ�
void printAllClothes(const char clothes[MAX_CLOTHES][MAX_LENGTH], const char* season, int numClothes) {
    printf("\n%s �� ���:\n", season);
    for (int i = 0; i < numClothes; ++i) {
        printf("%d. %s\n", i + 1, clothes[i]);
    }
}

// ��� ������ �� ����Ʈ�� ����ϴ� �Լ�
void printTotalClothes(const char springClothes[MAX_CLOTHES][MAX_LENGTH], int numSpringClothes,
    const char summerClothes[MAX_CLOTHES][MAX_LENGTH], int numSummerClothes,
    const char fallClothes[MAX_CLOTHES][MAX_LENGTH], int numFallClothes,
    const char winterClothes[MAX_CLOTHES][MAX_LENGTH], int numWinterClothes) {
    printf("\n���� �� ����Ʈ:\n");
    printf("�� ��:\n");
    printAllClothes(springClothes, "��", numSpringClothes);
    printf("\n���� ��:\n");
    printAllClothes(summerClothes, "����", numSummerClothes);
    printf("\n���� ��:\n");
    printAllClothes(fallClothes, "����", numFallClothes);
    printf("\n�ܿ� ��:\n");
    printAllClothes(winterClothes, "�ܿ�", numWinterClothes);
}

// �ش� ������ ��︮�� ���� �������� ��õ�ϴ� �Լ�
void recommendClothes(const char clothes[MAX_CLOTHES][MAX_LENGTH], int numClothes, const char* season) {
    int suitableClothes[MAX_CLOTHES];
    int numSuitable = 0;

    // �ش� ������ ��︮�� ���� �ε����� ã�� �迭�� ����
    for (int i = 0; i < numClothes; ++i) {
        if (strstr(clothes[i], season) != NULL) {
            suitableClothes[numSuitable++] = i;
        }
    }

    // �ش� ������ ��︮�� ���� ���� ���
    if (numSuitable == 0) {
        printf("�ش� ������ ��︮�� ���� �����ϴ�.\n");
    }
    else { // �ش� ������ ��︮�� �� �߿��� �������� ��õ
        srand(time(NULL));
        int randomIndex = suitableClothes[rand() % numSuitable];
        printf("��õ�ϴ� %s ��: %s\n", season, clothes[randomIndex]);
    }
}

int main() {
    char springClothes[MAX_CLOTHES][MAX_LENGTH];
    char summerClothes[MAX_CLOTHES][MAX_LENGTH];
    char fallClothes[MAX_CLOTHES][MAX_LENGTH];
    char winterClothes[MAX_CLOTHES][MAX_LENGTH];

    int numSpringClothes = 0, numSummerClothes = 0, numFallClothes = 0, numWinterClothes = 0;

    // �� ������ �� �Է� �ޱ�
    getClothes(springClothes, "��", &numSpringClothes);
    getClothes(summerClothes, "����", &numSummerClothes);
    getClothes(fallClothes, "����", &numFallClothes);
    getClothes(winterClothes, "�ܿ�", &numWinterClothes);

    // ��ü �� ����Ʈ ���
    printTotalClothes(springClothes, numSpringClothes, summerClothes, numSummerClothes,
        fallClothes, numFallClothes, winterClothes, numWinterClothes);

    int temperature;
    printf("\n����� �Է��ϼ���: ");
    scanf_s("%d", &temperature);

    char* result = determineSeason(temperature);
    printf("���� ������ %s�Դϴ�.\n", result);

    // �ش� ������ �´� �� ��õ
    if (strcmp(result, "����") == 0 || strcmp(result, "�ܿ�") == 0 || strcmp(result, "�� �Ǵ� ����") == 0) {
        recommendClothes(summerClothes, numSummerClothes, result);
    }
    else {
        printf("�ش� ������ ���� ��õ ���� �����ϴ�.\n");
    }

    return 0;
}
