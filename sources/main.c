#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CLOTHES 5
#define MAX_LENGTH 50

// recommendOutfit �Լ��� determineSeason �Լ� ���� ����
void recommendOutfit(const char clothes[MAX_CLOTHES][MAX_LENGTH], int numClothes, const char* season);

void getClothes(char clothes[MAX_CLOTHES][MAX_LENGTH], const char* season, int* numClothes) {
    // ����ڿ��� �� �Է��� ��û�ϴ� �Լ�
    printf("%s ������(��)�� �Է����ּ���: (�ִ� %d����,���� ��� X) \n����)���������ǽ�������ȭ\n", season, MAX_CLOTHES);
    while (*numClothes < MAX_CLOTHES) {
        printf("������(��) %d: ", *numClothes + 1);
        scanf_s("%s", clothes[*numClothes], MAX_LENGTH);

        (*numClothes)++; // �� ���� ����

        printf("�� �Է��Ͻðڽ��ϱ�? (�����: n or N/�� �Է��Ϸ��� �ƹ�Ű�� �����ÿ�): ");
        char choice;
        scanf_s(" %c", &choice, sizeof(choice));

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }
}

// ���õ� ������ �� ����� ����ϴ� �Լ�
void printClothesForSeason(const char clothes[MAX_CLOTHES][MAX_LENGTH], const char* season, int numClothes) {
    printf("\n%s ������(��) ���:\n", season);
    for (int i = 0; i < numClothes; ++i) {
        printf("%d. %s\n", i + 1, clothes[i]);
    }
}

void determineSeason(const char springClothes[MAX_CLOTHES][MAX_LENGTH], int numSpringClothes,
    const char summerClothes[MAX_CLOTHES][MAX_LENGTH], int numSummerClothes,
    const char fallClothes[MAX_CLOTHES][MAX_LENGTH], int numFallClothes,
    const char winterClothes[MAX_CLOTHES][MAX_LENGTH], int numWinterClothes) {
    // ���� ����� �Է¹޾� ������ �Ǻ��ϰ� �ش� ������ �´� ���� ��õ���ִ� �Լ�
    int temperature;
    printf("\n���� ����� �Է��� �ּ���: ");
    scanf_s("%d", &temperature);

    const char* season;
    if (temperature >= 23) {
        season = "����";
        recommendOutfit(summerClothes, numSummerClothes, season);
    }
    else if (temperature >= 12 && temperature < 23) {
        season = "��";
        recommendOutfit(springClothes, numSpringClothes, season);
    }
    else if (temperature >= 5 && temperature < 12) {
        season = "����";
        recommendOutfit(fallClothes, numFallClothes, season);
    }
    else {
        season = "�ܿ�";
        recommendOutfit(winterClothes, numWinterClothes, season);
    }
}

void recommendOutfit(const char clothes[MAX_CLOTHES][MAX_LENGTH], int numClothes, const char* season) {
    // �ش� ������ �� �߿��� �������� ���� ��õ���ִ� �Լ�
    if (numClothes == 0) {
        printf("��õ�� �� �����ϴ�. %s�� ���� ������(��)�� �����ϴ�.\n", season);
        return;
    }

    srand(time(NULL));
    int randomIndex = rand() % numClothes;

    printf("\n���� ������ ���� ������(��)�� ��õ�մϴ�: %s - %s\n", season, clothes[randomIndex]);
}

void recommendAdditionalClothes(const int numSpringClothes, const int numSummerClothes,
    const int numFallClothes, const int numWinterClothes) {
    // ������ ������ �� ������ �˷��ִ� �Լ�
    printf("\n�߰����� ���� �����Ͻñ� �����ϴ� ����:\n");

    if (numSpringClothes < MAX_CLOTHES) {
        printf("- �� ���� %d�� �� �����Ͻʽÿ�.\n", MAX_CLOTHES - numSpringClothes);
    }
    if (numSummerClothes < MAX_CLOTHES) {
        printf("- ���� ���� %d�� �� �����Ͻʽÿ�.\n", MAX_CLOTHES - numSummerClothes);
    }
    if (numFallClothes < MAX_CLOTHES) {
        printf("- ���� ���� %d�� �� �����Ͻʽÿ�.\n", MAX_CLOTHES - numFallClothes);
    }
    if (numWinterClothes < MAX_CLOTHES) {
        printf("- �ܿ� ���� %d�� �� �����Ͻʽÿ�.\n", MAX_CLOTHES - numWinterClothes);
    }
}

void printTotalClothes(const char springClothes[MAX_CLOTHES][MAX_LENGTH], int numSpringClothes,
    const char summerClothes[MAX_CLOTHES][MAX_LENGTH], int numSummerClothes,
    const char fallClothes[MAX_CLOTHES][MAX_LENGTH], int numFallClothes,
    const char winterClothes[MAX_CLOTHES][MAX_LENGTH], int numWinterClothes) {
    // ��� ������ �� ����� ����ϰ�, ������ �� ������ �˷��ָ�, �ش� ������ ��õ ���� �����ִ� �Լ�
    printf("\n���� �� ����Ʈ:\n");
    printClothesForSeason(springClothes, "��", numSpringClothes);
    printClothesForSeason(summerClothes, "����", numSummerClothes);
    printClothesForSeason(fallClothes, "����", numFallClothes);
    printClothesForSeason(winterClothes, "�ܿ�", numWinterClothes);

    recommendAdditionalClothes(numSpringClothes, numSummerClothes, numFallClothes, numWinterClothes);

    determineSeason(springClothes, numSpringClothes, summerClothes, numSummerClothes,
        fallClothes, numFallClothes, winterClothes, numWinterClothes);
}

int main() {
    // �� ������ ���� �Է¹ް�, �� �� ����� ����ϸ�, ��õ ���� �����ϴ� ���� �Լ�
    char springClothes[MAX_CLOTHES][MAX_LENGTH];
    char summerClothes[MAX_CLOTHES][MAX_LENGTH];
    char fallClothes[MAX_CLOTHES][MAX_LENGTH];
    char winterClothes[MAX_CLOTHES][MAX_LENGTH];

    int numSpringClothes = 0, numSummerClothes = 0, numFallClothes = 0, numWinterClothes = 0;

    getClothes(springClothes, "��", &numSpringClothes);
    getClothes(summerClothes, "����", &numSummerClothes);
    getClothes(fallClothes, "����", &numFallClothes);
    getClothes(winterClothes, "�ܿ�", &numWinterClothes);

    printTotalClothes(springClothes, numSpringClothes, summerClothes, numSummerClothes,
        fallClothes, numFallClothes, winterClothes, numWinterClothes);

    return 0;
}
