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

bool startGame(int iMaxVal, std::string &sName) {
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

  setResult(sName, iAttemps);

  return 0;
}

int setResult(std::string &sName, int iValue) {

  std::cout << "insert to result table" << std::endl;
  
  ResultTable.insert(std::make_pair(iValue, sName));

  getResult();  

  return 0;
}

// вывод на печать таблицы резульататов
bool getResult() {

  std::cout << "getResult" << std::endl;

  std::cout << std::endl << "Таблица результатов:" << std::endl;
  for (auto &[name, val] : ResultTable) {
    std::cout << "name: " << name << "\t" << "val: " << val << std::endl;
  }
  
  std::cout << std::endl;

  return 0;
}

int saveResult(std::string &sName, int iScore) {
  // // Write new high score to the records table
	// {
	// 	// We should open the output file in the append mode - we don't want
	// 	// to erase previous results.
	// 	std::ofstream out_file{fileResultTable, std::ios_base::app};
	// 	if (!out_file.is_open()) {
	// 		std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
	// 		return -1;
	// 	}

	// 	// Append new results to the table:
	// 	out_file << user_name << ' ';
	// 	out_file << attempts_count;
	// 	out_file << std::endl;
	// } // end of score here just to mark end of the logic block of code
  
  // return 0;
}

int loadResult(std::string &sName, int iScore) {
  return 0;
}