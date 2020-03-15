#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

class Coincidence
{    
private: 
    std::string _text; 
    std::string _pattern;
    std::map<std::string, std::pair<double, int>> fuzzy;
    std::vector<std::pair<std::string, double>> sortedResult;
    double _precision;

public:
    Coincidence(const std::string&, const std::string&, double);
    void setText(const std::string& text);
    void setPattern(const std::string& pattern);
    void setPrecision(double precision);
    std::map<std::string, std::pair<double, int>> getFuzzy();
    std::vector<std::pair<std::string, double>> getSortedResult(); 
    static std::vector<std::string> split(const std::string &, char);
    static double compareWords(std::string, std::string);
    static std::map<std::string, std::pair<double, int>> searchFuzzy(const std::string&, 
                                                                     const std::string&, 
                                                                     double precision);
    void searchFuzzy();
    static std::vector<std::pair<std::string, double>> sortResult(std::map<std::string, std::pair<double, int>>&);
    void sortResult();
};