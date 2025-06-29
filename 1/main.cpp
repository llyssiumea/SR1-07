/*
 * Задание #1
 * Основной файл программы для выбора артефактов
 */

#include "artifact.h"
#include <fstream>
#include <vector>

int main()
{
    setlocale(0, "");
    
    // FIX ME: переименовано для ясности
    std::ifstream input_file("f.txt");
    if (!input_file.is_open())
    {
        std::cerr << "Не удалось открыть файл f.txt" << std::endl;
        return 1;
    }

    int n, b;
    input_file >> n >> b;

    std::vector<Artifact> artifacts(n);
    
    // Чтение весов
    for (int i = 0; i < n; i++)
    {
        input_file >> artifacts[i].weight;
        artifacts[i].index = i + 1; // FIX ME: сохраняем исходный номер
    }
    
    // Чтение объемов
    for (int i = 0; i < n; i++)
    {
        input_file >> artifacts[i].volume;
    }

    // FIX ME: вызов вынесенной функции
    ArtifactChoose(artifacts, b);

    return 0;
}