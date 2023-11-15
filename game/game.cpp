#include "game.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <map>

// TKey - кол-во попыток
// TValue - имя игрока
// Сортировка по умолчанию - по возрастанию

std::multimap<int, std::string, std::greater<int>> ResultTable;

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

  std::string usr;

  std::cout << "Введите имя пользователя: ";
  std::cin >> usr;

  setResult(usr, iAttemps);

  return 0;
}
// вывод на печать табилцы резульататов
bool getResult() {

  std::cout << "getResult" << std::endl;

  std::cout << std::endl << "Таблица результатов:" << std::endl;
  for (auto &[name, val] : ResultTable) {
    std::cout << "name: " << name << "\t" << "val: " << val << std::endl;
  }
  
  std::cout << std::endl;

  return 0;
}

int initResult() {
// Key - Value
  ResultTable.insert(std::pair<int, std::string>(101, "empty"));
  ResultTable.insert(std::pair<int, std::string>(110, "empty"));
  ResultTable.insert(std::pair<int, std::string>(99, "empty"));

  return 0;
}

int setResult(std::string &sName, int iValue) {

std::cout << "insert to result table" << std::endl;
  
  // for (auto &[name, val] : ResultTable) {
  //   if (iValue < val) {
  //     // вычисляем позицию для вставки новой записи
  //     auto ans = ResultTable.find(sName);
  //     std::pair<std::string, int> pair = {sName, iValue};
      
  //     ResultTable.insert(pair);
  //     break;
  //   }
  // }

  getResult();  

  return 0;
}