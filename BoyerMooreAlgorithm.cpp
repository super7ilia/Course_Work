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
    int possiblePosition = 0;
    // Обходим введенную строку ориентируясь на длинну паттерна
    for (unsigned int i = pattern.length()-1; i < text.length(); ++i) {
        // Проверяем соответствие последнего символа паттерна и итерируемого символа строки
        if (text[i] == lastSymbol) {
            possiblePosition = i;
            // В случае истины, начинаем обратный обход в соответствии с алгоритмом
            unsigned int backTrack = pattern.length() - 2;
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
                    return possiblePosition + 1;
                }
                --backTrack;
            }
            // Если условие равно нулю -> мы обошли паттерн, все символы совпали, значит подстрока найдена
            if (backTrack == 0) { 
              return possiblePosition + 1;
            }
        }
    }
    return -1;
 
}

int findBoyerMooreHorspool(std::string& text,  std::string& pattern)
{
    std::string stopTable;

    // Построение таблицы стоп-символов
    for (int i = 0; i < 2048; ++i) {
        stopTable.push_back(-1);
    }
    for (int i = 0; i < pattern.size(); ++i) {
        stopTable.at(pattern.at(i)) = i;
    }
    // Процесс поиска
    for (int i_pos = 0; i_pos <= text.size() - pattern.size();) {
        int j_pos = pattern.size() - 1;
        //Проверка на совпадение
        while (pattern.at(j_pos) == text.at(j_pos + i_pos)) {
            if (j_pos == 0) {
                return i_pos + 1;
            }
            --j_pos;
        }
        // если не совпало
        if (stopTable.at(text.at(j_pos + i_pos)) == -1) {
            i_pos += j_pos + 1;
        } else {
            i_pos += j_pos - stopTable.at(text.at(j_pos + i_pos));
        }
    }
    return -1;
}