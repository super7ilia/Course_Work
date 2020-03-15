#include "KnuthMorrisPrattAlgorithm.hpp"

int findKMP(std::string text, std::string pattern)
{
    int *prefix = new int[pattern.length()];
    // Рассчет префикс функции
    int i = 0;
    int j = -1;
    prefix[0] = -1;
    while (i < (int)pattern.length() - 1) {
        while ((j >= 0) && (pattern[j] != pattern[i])) {
            j = prefix[j];
        }
        ++i;
        ++j;
        prefix[i] = (pattern[i] == pattern[j]) ? prefix[j] : j;
    }
    // Поиск подстроки в предложенном тексте в соответствии с алгоритмом КМП
    for (i = 0, j = 0; (i <= (int)text.length() - 1) && (j <= (int)pattern.length() - 1); ++i, ++j) {
        while ((j >= 0) && (pattern[j] != text[i])) {
            j = prefix[j];
        }
    }
    delete[] prefix;
    
    // В случае нахождения подстроки - возвращаем позицию - начало подстроки в тесте, в противном случае -1
    return (j == (int)pattern.length()) ? i - j + 1: -1;
}