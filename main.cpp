// 
// Домашнее задание #3
// Суть игры. Приложение «загадывает» некоторое число и ждёт в цикле ввода от пользователя. В
// случае, если пользователь ввёл число, меньшее загаданного, выводится подсказка «less than». В
// случае, если пользователь ввёл число, большее заданного, выводится подсказка «greater than». В
// случае, когда пользователь, наконец, угадывает число, выводится сообщение «you win!», и цикл
// ввода завершается. В качестве примера см пример check_value.cpp из материалов к самостоятельной работе.
//
// Дополнительное задание 1. Задание опциональное и для формальной сдачи работы не
// обязательное.
// Добавить обработку параметра командной строки “-max” с одним числовым аргументом, с
// помощью которого можно задать максимальное значения для загаданного числа. См пример
// argument.cpp. В случае, если параметр не передаётся, ограничением по умолчанию
// выбирается некоторая константа на усмотрение автора (например, 100). Пример запуска
// приложения с этим аргументом:
// > guess_the_number –max 42
// 
// Дополнительное задание 2. Задание опциональное и для формальной сдачи работы не
// обязательное.
// Добавить обработку параметра командной строки “-table” без аргументов, с помощью которого
// можно вывести таблицу рекордов сразу, без необходимости игры. При этом приложение выводит
// текущие значения из таблицы рекордов и сразу завершается. Пример запуска с этим аргументом:
// > guess_the_number -table
// 
// Дополнительное задание 3. Задание опциональное и для формальной сдачи работы не
// обязательное.
// При чтении таблицы рекордов для каждого пользователя определять минимальное значение числа
// попыток и выводить только их.

#include "user_input/user_input.h"
#include "game/game.h"

#include <chrono>
#include <iostream>

int main(int argc, char *argv[]) {
  const int iTerminalRecCount{3};
  int iMenuIndex = 0;
  std::string sName;
  std::string sPrmName;
  int iPrmValue;
  int iMaxVal =10;

  if (argc > 1) {
    sPrmName = argv[1];
    // std::cout << " argv[1] " << argv[1] << " " << " argv[2] " << argv[2] << std::endl;
    iPrmValue = std::stoi(argv[2]);
  }

  if (sPrmName == "- max") {
    iMaxVal = iPrmValue;
  }

  // if (sPrmName == "- table") {
  //   getResult(std::stoi(argv[2]));
  // }   

  std::cout << "Введите имя: ";
  std::cin >> sName;

  do {
    std::cout.clear();
    
    std::cout << "1. запустить игру" << std::endl;
    std::cout << "2. таблица результатов" << std::endl;
    std::cout << "3. выход" << std::endl;
    
    std::cout << std::endl << "выберете пункт меню [1,2,3] ";
    std::cin >> iMenuIndex;

    if (std::cin.fail()) {
      iMenuIndex = 3;
    }
    
    switch (iMenuIndex) {
    case 1:
      startGame(iMaxVal, sName, iTerminalRecCount);
      break;
    
    case 2:
      getResult(iTerminalRecCount);

      loadResult();
      break;

    case 3:
      break;

    default:
      break;
    } //switch
    
  } while (iMenuIndex != 3);

return 0;
}