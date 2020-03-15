#include "RabinKarpAlgorithm.hpp"

int findRabinKarp(std::string text, std::string pattern) {
    // считаем все степени
    const int maxPower = 31;
    std::vector<int> powers(std::max(text.length(), pattern.length()));
    powers[0] = 1;

    for (int i = 1; i < powers.size(); ++i) {
        powers[i] = powers[i - 1] * maxPower;
    }
    // считаем хэши от всех префиксов строки T
    std::vector<int> hashMap(text.length());
    for (int i = 0; i < text.length(); ++i) {
        hashMap[i] = (text[i] - 'a' + 1) * powers[i];
        if (i) {
            hashMap[i] += hashMap[i - 1];
        }
    }
    // считаем хэш от строки S
    int patternHash = 0;
    for (size_t i = 0; i < pattern.length(); ++i) {
        patternHash += (pattern[i] - 'a' + 1) * powers[i];
    }
    // перебираем все подстроки text длины pattern.length и сравниваем их
    for (size_t i = 0; i + pattern.length() - 1 < text.length(); ++i) {
        int currentHash = hashMap[i + pattern.length() - 1];
        if (i) {
            currentHash -= hashMap[i - 1];
        }
        // приводим хэши к одной степени и сравниваем
        // небольшая переделка даст возможность искать все вхождения
        if (currentHash == patternHash * powers[i]) {
            return i + 1;
        }
    }
    return -1;
}