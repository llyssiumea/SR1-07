//К - ичные числа.Среди чисел в системе счисления с основанием K(2≤K≤10) определить сколько			//FIX ME задание не по шаблону
//имеется чисел из N(1 < N < 20, K + N < 26) разрядов таких, что в их записи не содержится 
//два и более подряд идущих нулей.Для того, чтобы избежать переполнения, ответ
//представьте в виде вещественного числа.

/*
 * Задание #3
 * К - ичные числа.Среди чисел в системе счисления с основанием K(2≤K≤10) определить сколько
 * имеется чисел из N(1 < N < 20, K + N < 26) разрядов таких, что в их записи не содержится
 * два и более подряд идущих нулей. Для того, чтобы избежать переполнения, ответ
 * представьте в виде вещественного числа.
*/

# include <iostream>
# include <windows.h>
//# include <vector> //FIX ME не используется
using namespace std;

double FindDoubleZero(int n, int k) {
	double non_zero = k - 1, non_zero_temp, with_zero = 1, with_zero_temp, double_zero = 0, double_zero_temp;
	non_zero = k - 1;
	with_zero = 1;
	double_zero = 0;
	for (double i = 2; i <= n; i++)
	{
		non_zero_temp = non_zero;
		with_zero_temp = with_zero;
		double_zero_temp = double_zero;
		non_zero = non_zero_temp * (k - 1) + with_zero_temp * (k - 1);
		with_zero = non_zero_temp;
		double_zero = double_zero_temp * k + with_zero_temp;
	}
	return non_zero + with_zero;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, k;
	cout << "Среди чисел в системе счисления с основанием K(2 <= K <= 10) определить " << endl;
	cout << "сколько имеется чисел из N(1<N<20, K + N<26) разрядов таких," << endl;
	cout << "что в их записи не содержится два и более подряд идущих нулей." << endl;
	cout << "Вам необходимо ввести  два числа - число разрядов и систему счисления." << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << endl;
	cout << endl;
	cout << "Введите число N - число разрядов в числе: ";
	cin >> n;
	cout << "Введите число K - систему счисления: ";
	cin >> k;

	if (k < 2 || k > 10 || n < 1 || n >= 20 || k + n >= 26) {
		cout << "Некорректные входные данные!" << endl;
		return 1;
	}

	// nz = числа в которых нет двух подряд идущих нулей и они не оканчиваются на 0
	// oz = числа в которых нет двух подряд идущих нулей и они оканчиваются на 0
	// tz = числа в которых есть два подряд идущих нуля
	// из числа класса nz может получиться число либо класса нз либо класса оз
	// из числа класса оз может получиться число либо класса нз либо класса тз
	// их числа класса тз может получиться число класса тз
	// nzn = nzn-1*(k-1) +oz(k-1); ozn = nzn-1; tzn = k*tzn-1+ozn-1;
	//double i, nz, _nz, oz, _oz, tz, _tz;		//FIX ME значние не присвоено сразу, совершенно непонятные названия
	//nz = k - 1;
	//oz = 1;
	//tz = 0;

	//double non_zero = k - 1, non_zero_temp, with_zero = 1, with_zero_temp, double_zero = 0, double_zero_temp;		 //FIX ME логика не вынесена в отдельную функцию
	//non_zero = k - 1;
	//with_zero = 1;
	//double_zero = 0;
	//for (double i = 2; i <= n; i++)
	//{
	//	non_zero_temp = non_zero;
	//	with_zero_temp = with_zero;
	//	double_zero_temp = double_zero;
	//	non_zero = non_zero_temp * (k - 1) + with_zero_temp * (k - 1);
	//	with_zero = non_zero_temp;
	//	double_zero = double_zero_temp * k + with_zero_temp;
	//}

	double result = FindDoubleZero(n, k);
	cout << "Количество чисел, в которых нет два и более подряд идущих нулей: " << result << endl;
	return 0;
}