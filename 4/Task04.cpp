//Во всех заданиях данной подгруппы предполагается, что исходные строки, определяющие выражения, //FIX ME задание не по шаблону
//не содержат пробелов.При выполнении заданий не следует использовать оператор цикла.
//Вывести значение целочисленного выражения, заданного в виде строки S.Выражение
//определяется следующим образом :
//		<выражение> :: = <терм> | <выражение> +<терм> | <выражение> − <терм>
//		<терм> :: = <цифра> | <терм> *<цифра>

/*
 * Задание #3
 * Во всех заданиях данной подгруппы предполагается, что исходные строки, определяющие выражения,
 * не содержат пробелов.При выполнении заданий не следует использовать оператор цикла.
 * Вывести значение целочисленного выражения, заданного в виде строки S.Выражение
 * определяется следующим образом :
 * 		<выражение> :: = <терм> | <выражение> +<терм> | <выражение> − <терм>
 * 		<терм> :: = <цифра> | <терм> *<цифра>
*/

#include <iostream>
#include <string>	//FIX ME остутствуют отступы между блоками кода

using namespace std;

//int calc(string str);	//FIX ME некорректное название
int Calculate(string str);

//int element(string str)	//FIX ME некорректное название
int ExpressionDefinition(string str)
{
	if (str[0] == '(' && str[str.size() - 1] == ')')
		return Calculate(str.substr(1, str.size() - 2));
	return stoi(str);
}

//int term(string str) //FIX ME некорректное название
int TermDefinition(string str)
{
	int i = str.size() - 1;
	int level = 0;
	//int pos1 = -1;	//FIX ME некорректное название
	int position = -1;
	while (i >= 0)
	{
		if (str[i] == ')')
			level++;
		if (str[i] == '(')
			level--;
		if (level == 0 && str[i] == '*')
		{
			position = i;
			break;
		}
		i--;
	}
	if (position == -1)
		return ExpressionDefinition(str);
	return TermDefinition(str.substr(0, position)) * ExpressionDefinition(str.substr(position + 1));
}

int Calculate(string str)
{
	int i = str.size() - 1;
	int level = 0;
	//int pos1 = -1;	//FIX ME некорректное название
	int position = -1;
	while (i >= 0)
	{
		if (str[i] == ')')
			level++;
		if (str[i] == '(')
			level--;
		if (level == 0 && (str[i] == '-' || str[i] == '+'))
		{
			position = i;
			break;
		}
		i--;
	}
	if (position == -1)
		return TermDefinition(str);
	//char ch = str[position]; //FIX ME некорректное название
	char symbol = str[position];
	if (symbol == '+')
		return Calculate(str.substr(0, position)) + TermDefinition(str.substr(position + 1));
	if (symbol == '-')
		return Calculate(str.substr(0, position)) - TermDefinition(str.substr(position + 1));
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string str;
	cout << "Введите выражение: ";
	getline(cin, str);
	//int r = Calculate(str); //FIX ME некорректное название
	int result = Calculate(str);
	cout << "Ответ: " << result << endl;
	return 0;
}
