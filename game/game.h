// Для реализации таблицы рекордов пользователю при старте приложения выводится предложение
// представиться. Введенное значение запоминается в переменную строкового типа. Далее
// приложение считает количество попыток, которое потребовалось пользователю для угадывания
// числа. Это число так же запоминается. Затем имя пользователя и число попыток дописываются в
// файл с таблицей рекордов и выводится полное текущее содержимое таблицы рекордов.

#pragma once

#include <string>

bool newValue(int &iMaxValue);

bool startGame(int iMaxValue, std::string &sName, int iTerminalRecCount);

int setResult(std::string &sName, int iValue, int iTerminalRecCount);

bool getResult(int iRecCount);

int saveResult(std::string &sName, int iScore);

int loadResult();
