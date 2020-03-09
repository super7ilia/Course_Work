#include "BoyerMooreAlgorithm.hpp"

std::map<char, int> makePatternMap(const std::string& pattern) 
{
    std::map<char, int> patternMap = {{'*', pattern.length()},
                                      {pattern[pattern.length() - 1], pattern.length()}};

    int counter = 1;

    for (int i = pattern.length()-2; i >= 0; --i) {
        if (patternMap.count(pattern[i]) == 0) {
            patternMap[pattern[i]] = counter;
        }
        ++counter;
    }
    return patternMap;
}

int findBoyerMoore(const std::string& text, const std::string& pattern)
{
    if (text.length() < pattern.length() || text.length() == 0) {
        return -1;
    }


    std::map <char, int> patternMap = makePatternMap(pattern);

    char lastSymbol = pattern[pattern.length()-1];
    // Обходим введенную строку ориентируясь на длинну паттерна
    for (unsigned int i = pattern.length()-1; i < text.length(); ++i) {
        // Проверяем соответствие последнего символа паттерна и итерируемого символа строки
        if (text[i] == lastSymbol) {
            // В случае истины, начинаем обратный обход в соответствии с алгоритмом
            unsigned int backTrack = pattern.length()-2;
            for (unsigned int j = i-1; j > i-pattern.length(); ++j) {
                
                // Если один из символов не совпадает, то делаем сдвиг в соответствии с алгоритмом
                if (text[j] != pattern[backTrack]) {
                    // Если символ из текста есть в паттерне, то делаем соотвтствующий сдвиг, иначе делаем полный на длинну строки
                    char shiftSymbol = patternMap.count(text[j]) > 0 ? text[j] : '*';

                    if(patternMap[shiftSymbol]+backTrack > text.length()-1) {
                        return -1;
                    }
                    i += patternMap[shiftSymbol];
                    break;
                }
                if (backTrack == 0) {
                    return 1;
                }
                --backTrack;
            }
            // Если условие равно нулю -> мы обошли паттерн, все символы совпали, значит подстрока найдена
            if (backTrack == 0) { 
              return 1;
            }
        }
    }
    return -1;
} 