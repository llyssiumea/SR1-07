/*
 * Задание #2
 * Заголовочный файл для задачи о черепашке
 * Содержит объявления функций для работы с доской
 */

#ifndef TURTLE_H
#define TURTLE_H

#include <vector>
#include <string>

// FIX ME: переименовано для лучшей читаемости
std::vector<std::vector<int>> ReadBoardFromFile(const std::string& filename, int& size);

// FIX ME: добавлена документация
/**
 * @brief Вычисляет максимальную сумму на пути черепашки
 * @param board Игровая доска с числами
 * @param size Размер доски (N x N)
 * @return Максимальная сумма чисел на пути
 */
int CalculateMaxPathSum(const std::vector<std::vector<int>>& board, int size);

#endif // TURTLE_H