#include "Coincidence.hpp"

Coincidence::Coincidence(const std::string &text, const std::string &pattern, double precision)
{
    _text = text;
    _pattern = pattern;
    _precision = precision;
}
void Coincidence::setText(const std::string &text)
{
    _text = text;
}
void Coincidence::setPattern(const std::string &pattern)
{
    _pattern = pattern;
}
void Coincidence::setPrecision(double precision)
{
    _precision = precision;
}
std::map<std::string, std::pair<double, int>> Coincidence::getFuzzy()
{
    return fuzzy;
}
std::vector<std::pair<std::string, double>> Coincidence::getSortedResult()
{
    return sortedResult;
}
// Функция разбиения text по делителю delimeter
std::vector<std::string> Coincidence::split(const std::string& text, char delimiter)
{
    std::vector<std::string> splittedText;
    std::string word = "";
    for (const auto& symbol: text) {
        if (symbol == delimiter) {
            splittedText.push_back(word);
            word = "";
            continue;           
        }
        word += symbol;
    }
    return splittedText;
}
// Функция сравнения слов в процентном соотношении (Text, testa) дают 75%
double Coincidence::compareWords(std::string firstWord, std::string secondWord)
{
    std::transform(firstWord.begin(), firstWord.end(), firstWord.begin(), tolower);
    std::transform(secondWord.begin(), secondWord.end(), secondWord.begin(), tolower);
    int similarity = 0;
    int minLength = std::min(firstWord.length(), secondWord.length());
    for (int i = 0; i < minLength; ++i) {
        if (firstWord[i] == secondWord[i]) {
            ++similarity; 
        }
    }
    int maxLength = std::max(firstWord.length(), secondWord.length());
    double percent = (double)similarity / maxLength * 100;
    return percent;
}
std::map<std::string, std::pair<double, int>> Coincidence::searchFuzzy(const std::string& text, 
                                                                       const std::string& pattern, 
                                                                       double precision)
{
    std::vector<std::string> wordVector = split(text, ' ');
    std::map<std::string, std::pair<double, int>> resultMap;
    
    for (int i = 0; i < wordVector.size(); ++i) {
        std::string textWord = wordVector[i];
        double result = compareWords(textWord, pattern);
        if (result >= precision) {
            resultMap[textWord].first = result;
            resultMap[textWord].second = i;
        }
    }
    return resultMap;
}

void Coincidence::searchFuzzy()
{
    std::vector<std::string> wordVector = split(_text, ' ');
    std::map<std::string, std::pair<double, int>> resultMap;

    for (int i = 0; i < wordVector.size(); ++i)
    {
        std::string textWord = wordVector[i];
        double result = compareWords(textWord, _pattern);
        if (result >= _precision)
        {
            resultMap[textWord].first = result;
            resultMap[textWord].second = i;
        }
    }
    fuzzy = resultMap;
}

std::vector<std::pair<std::string, double>> Coincidence::sortResult(std::map<std::string, 
                                                                              std::pair<double, int>> &result)
{
    std::vector<std::pair<std::string, double>> sortVector;
    for (const auto& item: result) {
        sortVector.push_back(make_pair(item.first, item.second.first));
    }
    for (int i = 0; i < sortVector.size(); ++i) {
        for (int j = 0; j < sortVector.size(); ++j) {
            if (i != j && sortVector[i].second < sortVector[j].second) {
                std::swap(sortVector[i], sortVector[j]);
            }
        }
    }
    return sortVector;
}

void Coincidence::sortResult() 
{
    std::vector<std::pair<std::string, double>> sortVector;
    for (const auto &item : fuzzy) {
        sortVector.push_back(make_pair(item.first, item.second.first));
    }
    for (int i = 0; i < sortVector.size(); ++i)
    {
        for (int j = 0; j < sortVector.size(); ++j)
        {
            if (i != j && sortVector[i].second < sortVector[j].second)
            {
                std::swap(sortVector[i], sortVector[j]);
            }
        }
    }
    sortedResult = sortVector;
}