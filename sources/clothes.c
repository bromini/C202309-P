#include "clothes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getClothes(Clothes** clothes, const char* season, int* numClothes) {
    printf("%s ������(��)�� �Է����ּ���: (�ִ� %d����,���� ��� X)\n����) ���������ǽ�������ȭ\n", season, MAX_CLOTHES);

    *clothes = (Clothes*)malloc(MAX_CLOTHES * sizeof(Clothes));
    if (*clothes == NULL) {
        printf("�޸� �Ҵ� ����\n");
        exit(1);
    }

    while (*numClothes < MAX_CLOTHES) {
        printf("������(��) %d: ", *numClothes + 1);
        scanf_s("%s", (*clothes)[*numClothes].name, MAX_LENGTH);

        (*numClothes)++;

        printf("�� �Է��Ͻðڽ��ϱ�? (�����: n or N/�� �Է��Ϸ��� �ƹ�Ű�� �����ÿ�): ");
        char choice;
        scanf_s(" %c", &choice, sizeof(choice));

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }
}

void printClothesForSeason(const Clothes* clothes, const char* season, int numClothes) {
    printf("\n%s ������(��) ���:\n", season);
    for (int i = 0; i < numClothes; ++i) {
        printf("%d. %s\n", i + 1, clothes[i].name);
    }

}

void recommendOutfit(const Clothes* clothes, int numClothes, const char* season) {
    if (numClothes == 0) {
        printf("��õ�� �� �����ϴ�. %s�� ���� ������(��)�� �����ϴ�.\n", season);
        return;
    }

    srand(time(NULL));
    int randomIndex = rand() % numClothes;

    printf("\n���� ������ ���� ������(��)�� ��õ�մϴ�: %s - %s\n", season, clothes[randomIndex].name);
    const char* fileName = "recommended_outfit.txt";

    FILE* file;
    errno_t err = fopen_s(&file, fileName, "a"); // ���� ���� �õ�

    if (err != 0) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    // ����� ���Ͽ� ����
    fprintf(file, "\n���� ������ ���� ������(��)�� ��õ�մϴ�: %s - %s\n", season, clothes[randomIndex].name);

    // ���� �ݱ�
    fclose(file);
}

void recommendAdditionalClothes(int numSpringClothes, int numSummerClothes,
    int numFallClothes, int numWinterClothes) {
    printf("\n�߰����� ���� �����Ͻñ� �����ϴ� ����:\n");

    // ���� �̸� ����
    const char* fileName = "recommended_clothes.txt";

    FILE* file;
    errno_t err = fopen_s(&file, fileName, "a"); // ���� ���� �õ�

    if (err != 0) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    if (numSpringClothes < MAX_CLOTHES) {
        printf("- �� ���� %d�� �� �����Ͻʽÿ�.\n", MAX_CLOTHES - numSpringClothes);
        fprintf(file, "- �� ���� %d�� �� �����Ͻʽÿ�.\n", MAX_CLOTHES - numSpringClothes);
    }
    if (numSummerClothes < MAX_CLOTHES) {
        printf("- ���� ���� %d�� �� �����Ͻʽÿ�.\n", MAX_CLOTHES - numSummerClothes);
        fprintf(file, "- ���� ���� %d�� �� �����Ͻʽÿ�.\n", MAX_CLOTHES - numSummerClothes);
    }
    if (numFallClothes < MAX_CLOTHES) {
        printf("- ���� ���� %d�� �� �����Ͻʽÿ�.\n", MAX_CLOTHES - numFallClothes);
        fprintf(file, "- ���� ���� %d�� �� �����Ͻʽÿ�.\n", MAX_CLOTHES - numFallClothes);
    }
    if (numWinterClothes < MAX_CLOTHES) {
        printf("- �ܿ� ���� %d�� �� �����Ͻʽÿ�.\n", MAX_CLOTHES - numWinterClothes);
        fprintf(file, "- �ܿ� ���� %d�� �� �����Ͻʽÿ�.\n", MAX_CLOTHES - numWinterClothes);
    }

    fclose(file); // ���� �ݱ�
}


void determineSeason(const Clothes* springClothes, int numSpringClothes,
    const Clothes* summerClothes, int numSummerClothes,
    const Clothes* fallClothes, int numFallClothes,
    const Clothes* winterClothes, int numWinterClothes) {
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

void printTotalClothes(const Clothes* springClothes, int numSpringClothes,
    const Clothes* summerClothes, int numSummerClothes,
    const Clothes* fallClothes, int numFallClothes,
    const Clothes* winterClothes, int numWinterClothes) {
    printf("\n���� �� ����Ʈ:\n");
    printClothesForSeason(springClothes, "��", numSpringClothes);
    printClothesForSeason(summerClothes, "����", numSummerClothes);
    printClothesForSeason(fallClothes, "����", numFallClothes);
    printClothesForSeason(winterClothes, "�ܿ�", numWinterClothes);

    recommendAdditionalClothes(numSpringClothes, numSummerClothes, numFallClothes, numWinterClothes);

    determineSeason(springClothes, numSpringClothes, summerClothes, numSummerClothes,
        fallClothes, numFallClothes, winterClothes, numWinterClothes);
}