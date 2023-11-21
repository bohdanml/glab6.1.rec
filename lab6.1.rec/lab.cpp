#include <iostream>
#include <cstdlib>
#include <ctime>

// Функція для генерації випадкового числа в заданому діапазоні
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}
// Функція для створення масиву з випадковими числами
void createArray(int r[], int size, int min, int max, int i = 0) {
    if (i < size) {
        r[i] = generateRandomNumber(min, max);
        createArray(r, size, min, max, i + 1);
    }
}
// Функція для обчислення кількості та суми додатніх елементів, крім кратних 4
int computePositiveSumAndCount(int r[], int size, int i = 0, int positiveCount = 0, int positiveSum = 0) {
    if (i < size) {
        if (r[i] > 0 && r[i] % 4 != 0) {
            positiveCount++;
            positiveSum += r[i];
        }
        return computePositiveSumAndCount(r, size, i + 1, positiveCount, positiveSum);
    }
    return positiveCount;
}
// Функція для заміни нулями додатніх елементів, крім кратних 4
void replacePositivesWithZero(int r[], int size, int i = 0) {
    if (i < size) {
        if (r[i] > 0 && r[i] % 4 != 0) {
            r[i] = 0;
        }
        replacePositivesWithZero(r, size, i + 1);
    }
}
// Функція для виведення масиву на екран
void printArray(const int r[], int size, int i = 0) {
    if (i < size) {
        std::cout << r[i] << " ";
        printArray(r, size, i + 1);
    }
    else {
        std::cout << std::endl;
    }
}

int main() {
    const int size = 23;
    int r[size];
    int min = -19;
    int max = 25;
    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned>(time(nullptr)));

    createArray(r, size, min, max);
    //масив
    std::cout << "array: ";
    printArray(r, size);
    //Кількість додатніх, крім кратних 4:
    int positiveCount = computePositiveSumAndCount(r, size);
    std::cout << "Count of positive, excluding those divisible by 4: " << positiveCount << std::endl;

    int positiveSum = 0;
    replacePositivesWithZero(r, size);
    for (int i = 0; i < size; ++i) {
        positiveSum += r[i];
    }
    //Сума додатніх, крім кратних 4:
    std::cout << "Sum of positive, excluding those divisible by 4: " << positiveSum << std::endl;
    //модифікований масив
    std::cout << "Modified array: ";
    printArray(r, size);

    return 0;
}
