/**
 * @file expression_parser.h
 * @brief Заголовочный файл для парсера математических выражений
 * 
 * Содержит объявления функций для вычисления целочисленных выражений,
 * заданных в виде строки без пробелов.
 * Поддерживаются операции: +, -, * и скобки ()
 */

#ifndef EXPRESSION_PARSER_H
#define EXPRESSION_PARSER_H

#include <string>

/**
 * @brief Вычисляет значение целочисленного выражения
 * @param str Строка с выражением (без пробелов)
 * @return Результат вычисления выражения
 */
int CalculateExpression(const std::string& str);

#endif // EXPRESSION_PARSER_H