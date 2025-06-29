/**
 * @file main.cpp
 * @brief Основная программа для вычисления математических выражений
 * 
 * Принимает выражение от пользователя и выводит результат его вычисления.
 * Выражение должно быть без пробелов и содержать только цифры, +, -, *, (, ).
 */

#include "expression_parser.h"
#include <iostream>
#include <string>

int main() 
{
    std::locale::global(std::locale("")); // FIX ME: правильная установка локали
    
    std::cout << "Введите выражение (без пробелов): ";
    std::string expression;
    std::getline(std::cin, expression);
    
    try 
    {
        int result = CalculateExpression(expression);
        std::cout << "Результат: " << result << std::endl;
    } 
    catch (const std::exception& e) 
    {
        // FIX ME: добавлена обработка ошибок
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}