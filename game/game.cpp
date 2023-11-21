#include "game.h"
#include "../user_input/user_input.h"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <map>

// TKey - кол-во попыток
// TValue - имя игрока
// Сортировка по умолчанию - по возрастанию

std::multimap<int, std::string, std::greater<int>> ResultTable;
const std::string fileResultTable = "result_table.txt";

bool startGame(int iMaxVal, std::string &sName,int iTerminalRecCount) {
  //число пользователя  
  int iGenericVal = 0;  
  //загаданное число
  int iOriginalVal = 0;
  //кол-во попыток
  int iAttemps = 0;
  
  if (get_RandomVal(iMaxVal, iOriginalVal)) {
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

  setResult(sName, iAttemps, iTerminalRecCount);

  return 0;
}

int setResult(std::string &sName, int iValue, int iTerminalRecCount) {

  std::cout << "insert to result table" << std::endl;
  
  ResultTable.insert(std::make_pair(iValue, sName));

  saveResult(sName, iValue);

  getResult(iTerminalRecCount);  

  return 0;
}

// вывод на печать таблицы резульататов
bool getResult(int iRecCount) {

  std::cout << std::endl << "Таблица результатов:" << std::endl;

  for (auto &[name, val] : ResultTable) {
    if (name <= iRecCount) {
      std::cout << "name: " << name << "\t" << "val: " << val << std::endl;
    }
  }
  
  std::cout << std::endl;

  return 0;
}

int saveResult(std::string &sName, int iScore) {
  std::ofstream out_file{fileResultTable, std::ios_base::app};
  
  if (!out_file.is_open()) {
    std::cout << "Failed to open file for write: " << fileResultTable << "!" << std::endl;
    return -1;
  }

  out_file << sName << '\t' << iScore << std::endl;

  return 0;
}

int loadResult() {
  
  std::ifstream in_file{fileResultTable};
  
  if (!in_file.is_open()) {
    std::cout << "Failed to open file for read: " << fileResultTable << "!" << std::endl;
    return -1;
  }

  std::cout << "High scores table:" << std::endl;

  std::string username;
  int high_score = 0;
  while (true) {
    // Read the username first
    in_file >> username;
    // Read the high score next
    in_file >> high_score;
    // Ignore the end of line symbol
    in_file.ignore();

    if (in_file.fail()) {
      break;
    }

    // Print the information to the screen
    std::cout << username << '\t' << high_score << std::endl;
  }
  
  return 0;
}