/**
 * @file expression_parser.cpp
 * @brief Реализация парсера математических выражений
 * 
 * Рекурсивный парсер для вычисления выражений вида:
 * <выражение> ::= <терм> | <выражение> + <терм> | <выражение> - <терм>
 * <терм> ::= <элемент> | <терм> * <элемент>
 * <элемент> ::= <число> | (<выражение>)
 */

#include "expression_parser.h"
#include <string>

namespace {

/**
 * @brief Обрабатывает элемент выражения (число или выражение в скобках)
 * @param str Строка с элементом
 * @return Значение элемента
 */
int ParseElement(const std::string& str) 
{
    // FIX ME: добавлена обработка выражений в скобках
    if (str[0] == '(' && str[str.size() - 1] == ')') 
    {
        return CalculateExpression(str.substr(1, str.size() - 2));
    }
    return std::stoi(str);
}

/**
 * @brief Обрабатывает терм (умножение или одиночный элемент)
 * @param str Строка с термом
 * @return Значение терма
 */
int ParseTerm(const std::string& str) 
{
    int level = 0;
    int operator_pos = -1;
    
    // FIX ME: улучшен поиск оператора умножения с учетом вложенных скобок
    for (int i = str.size() - 1; i >= 0; --i) 
    {
        if (str[i] == ')') level++;
        if (str[i] == '(') level--;
        
        if (level == 0 && str[i] == '*') 
        {
            operator_pos = i;
            break;
        }
    }
    
    if (operator_pos == -1)
        return ParseElement(str);
        
    return ParseTerm(str.substr(0, operator_pos)) * 
           ParseElement(str.substr(operator_pos + 1));
}

} // namespace

int CalculateExpression(const std::string& str) 
{
    int level = 0;
    int operator_pos = -1;
    
    // FIX ME: улучшен поиск операторов + и - с учетом вложенных скобок
    for (int i = str.size() - 1; i >= 0; --i) 
    {
        if (str[i] == ')') level++;
        if (str[i] == '(') level--;
        
        if (level == 0 && (str[i] == '+' || str[i] == '-')) 
        {
            operator_pos = i;
            break;
        }
    }
    
    if (operator_pos == -1)
        return ParseTerm(str);
    
    // FIX ME: улучшена обработка операций + и -
    const char op = str[operator_pos];
    const std::string left = str.substr(0, operator_pos);
    const std::string right = str.substr(operator_pos + 1);
    
    if (op == '+')
        return CalculateExpression(left) + ParseTerm(right);
    if (op == '-')
        return CalculateExpression(left) - ParseTerm(right);
        
    return 0;
}