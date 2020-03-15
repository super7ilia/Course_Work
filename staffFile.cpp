#include "staffFile.hpp"

void fileReader(std::string &text, const std::string &fileName)
{
    std::fstream fin(fileName);

    while (fin)
    {
        std::string word;
        fin >> word;
        text += word + ' ';
    }
    text.pop_back();
    fin.close();
}

void output(int position, std::string pattern)
{

    if(position > 0) {
        std::cout << "Слово: " << pattern << "   "
                  << "Найдено в тексте на позиции: " << position
                  << std::endl;
    } else {
        std::cout << "Слово: " << pattern << "   "
                  << "Не найдено в тексте" 
                  << std::endl;
    }
}