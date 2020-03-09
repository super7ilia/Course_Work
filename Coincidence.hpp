#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

class Coincidence
{    
public: 
    static std::vector<std::string> split(const std::string&, char);
    static double compareWords(std::string, std::string);
    static std::map<std::string, std::pair<double, int>> searchFuzzy(const std::string&, 
                                                                     const std::string&, 
                                                                     double precision);
    static std::vector<std::pair<std::string, double>> sortResult(std::map<std::string, std::pair<double, int>>&);
};