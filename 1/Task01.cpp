// FIX ME: задача не по шаблону
//Археолог нашел N артефактов.Известны веса(сi) и объемы(di) артефактов.Нужно выбрать такое подмножество
//найденных вещей, чтобы суммарный их вес не превысил B кг, но был наиболее близок к B, а количество
//взятых артефактов было как можно больше.Известно, что решение единственно.Укажите порядковые номера
//вещей, которые надо взять.Исходные данные находятся в текстовом файле, в первой строке указаны N и B,
//а во второй строке значения весов(в кг), в третьей объемы находок(в куб.см).Вывести так же суммарный
//вес и суммарный объем результата.

/*
 * Задание #1
 * Археолог нашел N артефактов.Известны веса(сi) и объемы(di) артефактов.Нужно выбрать такое подмножество
 * найденных вещей, чтобы суммарный их вес не превысил B кг, но был наиболее близок к B, а количество
 * взятых артефактов было как можно больше.Известно, что решение единственно.Укажите порядковые номера
 * вещей, которые надо взять.Исходные данные находятся в текстовом файле, в первой строке указаны N и B,
 * а во второй строке значения весов(в кг), в третьей объемы находок(в куб.см).Вывести так же суммарный
 * вес и суммарный объем результата.
*/

// FIX ME: все выполнено в одном файле, лучше разделить на несколько для логичной работы с отдельными функциями

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Artifact
{
	int weight;
	int volume;
};

// bool SortWeight(Artifact a, Artifact b) // FIX ME: некорректное название
bool CompareWeights(Artifact a, Artifact b)
{
	return a.weight < b.weight;
}


void ArtifactChoose(vector<Artifact> artifacts, int n, int b) {
	int weights_sum = 0, volumes_sum = 0, conuter = 0, max_weight = 0, max_volume = 0;
	sort(artifacts.begin(), artifacts.end(), CompareWeights);
	while (conuter < n) //{ FIX ME: скобка не перенесена
	{
		weights_sum = 0;
		volumes_sum = 0;
		for (int j = conuter; j < n; j++) //{ FIX ME: скобка не перенесена
		{
			if (artifacts[j].weight + weights_sum <= b) //{ FIX ME: скобка не перенесена
			{
				weights_sum += artifacts[j].weight;
				volumes_sum += artifacts[j].volume;
				if (max_weight < weights_sum) //{ FIX ME: скобка не перенесена,
                //                           не выведены порядковые номера взятых артефактов
				{
					cout << "Взят " << j + 1 << " артефакт" << endl;
					max_weight = weights_sum;
					max_volume = volumes_sum;
				}
			}
		}
		if (max_weight == b) //{ FIX ME: опять скобка не перенесена
		{
			break;
		}
		else //{ FIX ME: вновь скобка не перенесена
		{
			conuter++;
		}
	}

	//cout << "Максимальный вес артефактов = " << max_weight << "\n" << "Объем взятых артефактов = " << max_volume;
    // FIX ME: некорректное описание вывода
	cout << "Суммарный вес артефактов = " << max_weight << "\n" << "СУммарный объем артефактов = " << max_volume;
}

int main()
{
	setlocale(0, "");
	//ifstream f1; // FIX ME: некорректное название
	ifstream input_file;
	input_file.open("f.txt");
	if (!input_file.is_open()) //{ FIX ME: скобка не перенесена
	{
		cout << "Не удалось открыть файл f.txt(" << endl;
		return 1;
	}
	//int n, b, sumw = 0, sumv = 0, k = 0, maxw = 0, maxv = 0 
    // FIX ME: некорректые названия
	int n, b;   //, weights_sum = 0, volumes_sum = 0, conuter = 0, max_weight = 0, max_volume = 0;
	input_file >> n >> b;

	vector<Artifact> artifacts(n);

	for (int i = 0; i < n; i++) //{ FIX ME: скобка не перенесена
	{
		input_file >> artifacts[i].weight;
	}
	for (int i = 0; i < n; i++) //{ FIX ME: скобка не перенесена
	{
		input_file >> artifacts[i].volume;
	}


	/*sort(artifacts.begin(), artifacts.end(), CompareWeights); 
    // FIX ME: не перенесено в функцию
	while (conuter < n) //{ FIX ME: скобка не перенесена
	{
		weights_sum = 0;
		volumes_sum = 0;
		for (int j = conuter; j < n; j++) //{ FIX ME: скобка не перенесена
		{
			if (artifacts[j].weight + weights_sum <= b) //{ FIX ME: скобка не перенесена
			{
				weights_sum += artifacts[j].weight;
				volumes_sum += artifacts[j].volume;
				if (max_weight < weights_sum) //{ FIX ME: скобка не перенесена, 
                //                              не выведены порядковые номера взятых артефактов
				{
					cout << "Взят " << j + 1 << " артефакт" << endl;
					max_weight = weights_sum;
					max_volume = volumes_sum;
				}
			}
		}
		if (max_weight == b) //{ FIX ME: скобка не перенесена
		{
			break;
		}
		else //{ FIX ME: скобка не перенесена
		{
			conuter++;
		}
	}

	//cout << "Максимальный вес артефактов = " << max_weight << "\n" << "Объем взятых артефактов = " << max_volume;
    // FIX ME: некорректное описание вывода
	cout << "Суммарный вес артефактов = " << max_weight << "\n" << "СУммарный объем артефактов = " << max_volume;*/

	ArtifactChoose(artifacts, n, b);
}