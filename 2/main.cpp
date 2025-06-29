/*
 * Задание #2
 * Основная программа для задачи о черепашке
 */

#include "turtle.h"
#include <iostream>
#include <fstream>

int main() 
{
    int board_size;
    std::string input_filename = "input.txt";
    std::string output_filename = "output.txt";

    // Чтение доски из файла
    auto board = ReadBoardFromFile(input_filename, board_size);

    // Вычисление максимальной суммы
    int max_sum = CalculateMaxPathSum(board, board_size);

    // Запись результата в файл
    std::ofstream output(output_filename);
    if (!output.is_open()) 
    {
        std::cerr << "Ошибка: не удалось создать файл " << output_filename << std::endl;
        return 1;
    }
    
    output << max_sum;
    output.close();

    std::cout << "Максимальная сумма пути: " << max_sum << std::endl;
    std::cout << "Результат записан в файл " << output_filename << std::endl;

    return 0;
}