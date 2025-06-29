/*
 * Задание #1
 * Реализация функций для работы с артефактами
 */

#include "artifact.h"
#include <algorithm>
#include <vector>

// FIX ME: добавлен const и ссылки для избежания копирования
bool CompareWeights(const Artifact& a, const Artifact& b)
{
    return a.weight < b.weight;
}

// FIX ME: полностью переработана функция для правильного выбора артефактов
void ArtifactChoose(const std::vector<Artifact>& artifacts, int max_weight)
{
    std::vector<Artifact> sorted = artifacts;
    std::sort(sorted.begin(), sorted.end(), CompareWeights);

    int current_weight = 0;
    std::vector<Artifact> selected;

    for (const auto& artifact : sorted)
    {
        if (current_weight + artifact.weight <= max_weight)
        {
            selected.push_back(artifact);
            current_weight += artifact.weight;
            std::cout << "Взят артефакт №" << artifact.index << std::endl; // FIX ME: вывод номеров
        }
    }

    int total_volume = 0;
    for (const auto& artifact : selected)
    {
        total_volume += artifact.volume;
    }

    // FIX ME: исправлено описание вывода
    std::cout << "Суммарный вес артефактов: " << current_weight << "\n"
              << "Суммарный объем артефактов: " << total_volume << std::endl;
}