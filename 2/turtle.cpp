/*
 * Задание #2
 * Реализация функций для задачи о черепашке
 */

#include "turtle.h"
#include <fstream>
#include <algorithm>
#include <iostream>

std::vector<std::vector<int>> ReadBoardFromFile(const std::string& filename, int& size) 
{
    std::ifstream input(filename);
    if (!input.is_open()) 
    {
        std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
        exit(1);
    }
    
    input >> size;
    std::vector<std::vector<int>> board(size, std::vector<int>(size));
    
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            input >> board[i][j];
        }
    }
    
    input.close();
    return board;
}

int CalculateMaxPathSum(const std::vector<std::vector<int>>& board, int size) 
{
    std::vector<std::vector<int>> dp(size, std::vector<int>(size, 0));
    dp[0][size - 1] = board[0][size - 1]; // Начальная позиция

    // Заполняем первую строку (движение влево)
    for (int j = size - 2; j >= 0; j--) 
    {
        dp[0][j] = dp[0][j + 1] + board[0][j];
    }

    // Заполняем последний столбец (движение вниз)
    for (int i = 1; i < size; i++) 
    {
        dp[i][size - 1] = dp[i - 1][size - 1] + board[i][size - 1];
    }

    // Заполняем остальную часть матрицы
    for (int i = 1; i < size; i++) 
    {
        for (int j = size - 2; j >= 0; j--) 
        {
            dp[i][j] = board[i][j] + std::max(dp[i - 1][j], dp[i][j + 1]);
        }
    }

    return dp[size - 1][0]; // Результат в левом нижнем углу
}