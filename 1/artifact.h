/* 
 * Задание #1
 * Заголовочный файл для работы с артефактами
 * Содержит структуру Artifact и объявления функций
 */

#ifndef ARTIFACT_H
#define ARTIFACT_H

#include <vector>
#include <iostream>

struct Artifact
{
    int weight;
    int volume;
    int index; // FIX ME: добавлен индекс для отслеживания исходного порядка артефактов
};

// FIX ME: переименовано для лучшей читаемости
bool CompareWeights(const Artifact& a, const Artifact& b);

// FIX ME: вынесена в отдельную функцию для лучшей структуризации кода
void ArtifactChoose(const std::vector<Artifact>& artifacts, int max_weight);

#endif // ARTIFACT_H