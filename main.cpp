// #include "BoyerMooreAlgorithm.hpp"
// #include "KnuthMorrisPrattAlgorithm.hpp"
#include "Coincidence.hpp"
#include <fstream>

void fileReader(std::string& text, const std::string& fileName);

int main() 
{ 
    std::string text;
    fileReader(text, "text.txt");
    std::map<std::string, std::pair<double, int>> result = Coincidence::searchFuzzy(text, "she", 55.0);

    for (const auto& item: result) {
        std::cout << "Word: " << item.first << " - "
                  << "Precision: " << item.second.first << " - "
                  << "Position: " << item.second.second << std::endl;
        ;
    }

    std::cout << std::endl << "Sorted vector: " << std::endl;
    for (const auto& item: Coincidence::sortResult(result)) {
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