/*
 * Задание #3
 * Реализация функций для задачи о K-ичных числах
 */

#include "k_numbers.h"

double countNumbersWithoutDoubleZeros(int n, int k) 
{
    // Переменные для хранения количества чисел:
    // nonZeroEnding - числа, оканчивающиеся не на 0
    // singleZeroEnding - числа, оканчивающиеся на один 0
    // doubleZeroEnding - числа, содержащие два и более нуля подряд
    double nonZeroEnding = k - 1;
    double singleZeroEnding = 1;
    double doubleZeroEnding = 0;

    for (int i = 2; i <= n; i++) 
    {
        double prevNonZero = nonZeroEnding;
        double prevSingleZero = singleZeroEnding;
        double prevDoubleZero = doubleZeroEnding;

        // Числа, оканчивающиеся не на 0:
        // можно добавить любую цифру, кроме 0, к числам, оканчивающимся не на 0
        // или к числам, оканчивающимся на один 0
        nonZeroEnding = (prevNonZero + prevSingleZero) * (k - 1);

        // Числа, оканчивающиеся на один 0:
        // можно добавить только один 0 к числам, оканчивающимся не на 0
        singleZeroEnding = prevNonZero;

        // Числа с двумя и более нулями подряд:
        // можно добавить любую цифру к числам, уже имеющим два нуля подряд
        // или добавить ноль к числам, оканчивающимся на один 0
        doubleZeroEnding = prevDoubleZero * k + prevSingleZero;
    }

    return nonZeroEnding + singleZeroEnding;
}