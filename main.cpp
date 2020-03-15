#include "BoyerMooreAlgorithm.hpp"
#include "KnuthMorrisPrattAlgorithm.hpp"
#include "RabinKarpAlgorithm.hpp"
#include "Coincidence.hpp"
#include "staffFile.hpp"
#include <stdlib.h>

int main()
{
        std::cout << std::endl
                  << "Выберете ввод текста: " << std::endl
                  << "- 1 - С клавиатуры" << std::endl
                  << "- 2 - Файловый" << std::endl;

        std::cout << std::endl
                  << "Ваш выбор: ";
        int input_choice = 0;
        std::cin >> input_choice;

        std::string text;
        std::string fileName;

        switch (input_choice)
        {
        case 1:
            std::cin >> text;
            break;
        case 2:
            std::cout << std::endl
                      << "Введите имя файла: " << std::endl;
            std::cin >> fileName;

            fileReader(text, fileName);
            break;
        default:
            std::cout << std::endl
                      << "Такого типа ввода не существует!" << std::endl;
            return 0;
            break;
        }

        std::cout << std::endl
                  << "Введите паттерн для поиска в тексте: " << std::endl;
        std::string pattern; 
        std::cin >> pattern; 

        std::cout << "Выберете алгоритм для поиска подстроки в строке: " << std::endl
                  << "- 1 - Алгоритм Боера-Мура" << std::endl
                  << "- 2 - Алгоритм Боера-Мура-Хорспула" << std::endl
                  << "- 3 - Алгоритм Кнута-Морриса-Пратта" << std::endl
                  << "- 4 - Алгоритм Рабина-Карпа" << std::endl
                  << "- 5 - Алгоритм частичного поиска" << std::endl;

        std::cout << std::endl
                  << "Ваш выбор: ";
        int choice = 0; 
        std::cin >> choice; 

        int answer = 0;
        std::map<std::string, std::pair<double, int>> result;
        
        switch (choice)
        {
        case 1:
            answer = findBoyerMoore(text, pattern);
            break;
        case 2:
            answer = findBoyerMooreHorspool(text, pattern);
            break;
        case 3:
            answer = findKMP(text, pattern);
            break;
        case 4:
            answer = findRabinKarp(text, pattern);
            break;
        case 5:
            std::cout << std::endl
                      << "Введите точность совпадения: " << std::endl;
            double precision; 
            std::cin >> precision;

            result = Coincidence::searchFuzzy(text, pattern, precision);

            for (const auto &item : result)
            {
                std::cout << "Слово: " << item.first << " - "
                          << "Точность совпадения: " << item.second.first << " - "
                          << "Позиция в тексте: " << item.second.second << std::endl;
            }

            std::cout << std::endl
                      << "Произвести сортировку результатов неявного поиска? (y/n)" << std::endl;
            char ans; 
            std::cin >> ans;
        
            if (ans == 'y') {
                std::cout << std::endl
                          << "Отсортированные значения: " << std::endl;

                for (const auto &item : Coincidence::sortResult(result))
                {
                    std::cout << "Слово: " << item.first << " - "
                              << "Точность: " << item.second << std::endl;
                }
            }

            break;
        default:
            std::cout << "Такого алгоритма не существует!" << std::endl;
            break;
        }
        if (choice >= 1 && choice <= 4) {
            output(answer, pattern);
        }
        std::cin.get();
  
    return 0;
}

