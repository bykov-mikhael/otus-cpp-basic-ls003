#include "game.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <map>

std::multimap<std::string, int> ResultTable;

bool getRndVal(int &iVal) {
  const int max_value = 100;

	std::srand(std::time(nullptr)); // use current time as seed for random generator

  iVal = std::rand() % 100;

	return 0;
}

bool startGame(int &iMaxValue) {
  //число пользователя  
  int iGenericVal = 0;  
  //загаданное число
  int iOriginalVal = 0;
  //кол-во попыток
  int iAttemps = 0;
  
  if (getRndVal(iOriginalVal)) {
    std::cerr << "rnd timer fault" << std::endl;
  }
  
  std::cout << iOriginalVal << std::endl;

  do
  {
    std::cout << std::endl << "Введите угадываемое число: ";
    std::cin >> iGenericVal;
    iAttemps++;

    if (iOriginalVal < iGenericVal) {
      std::cout << std::endl << "меньше" << std::endl;
    }
    
    if (iOriginalVal > iGenericVal) {
      std::cout << std::endl << "больше" << std::endl;
    }

    if (iOriginalVal == iGenericVal) {
      std::cout << std::endl << "угадал" << std::endl;
    }

  } while (iGenericVal != iOriginalVal);
  
  std::cout << std::endl << "Кол-во попыток: " << iAttemps << std::endl;
  
  getResult();

  return 0;
}
// вывод на печать табилцы резульататов
bool getResult() {

  std::cout << std::endl << "Таблица результатов:" << std::endl;
  for (auto &[name, val] : ResultTable) {
    std::cout << "name: " << name << "\t" << "val: " << val << std::endl;
  }
  

  return 0;
}

int initResult() {

  ResultTable.insert(std::pair<std::string, int>("empty", 0));
  ResultTable.insert(std::pair<std::string, int>("empty", 1));
  ResultTable.insert(std::pair<std::string, int>("empty", 2));

  return 0;
}

int setResult(std::string &sName, int iValue) {

  

  return 0;
}