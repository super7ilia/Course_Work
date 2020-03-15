// #include "BoyerMooreAlgorithm.hpp"
// #include "KnuthMorrisPrattAlgorithm.hpp"
#include "Coincidence.hpp"
#include <fstream>

void fileReader(std::string& text, const std::string& fileName);

int main() 
{ 
    std::string text;
    fileReader(text, "text.txt");
    Coincidence obj(text, "she", 75.0);
    obj.searchFuzzy();
    std::map<std::string, std::pair<double, int>> result = obj.getFuzzy();

    for (const auto& item: result) {
        std::cout << "Word: " << item.first << " - "
                  << "Precision: " << item.second.first << " - "
                  << "Position: " << item.second.second << std::endl;
        ;
    }

    std::cout << std::endl << "Sorted vector: " << std::endl;
    obj.sortResult();
    for (const auto& item: obj.getSortedResult()) {
        std::cout << "Word: " << item.first << " - "
                  << "Precision: " << item.second << std::endl;
    } 
    return 0;
}

void fileReader(std::string &text, const std::string& fileName) 
{
    std::fstream fin(fileName);

    while (fin) {
        std::string word;
        fin >> word;
        text += word + ' '; 
    }
    text.pop_back();
    fin.close();
}