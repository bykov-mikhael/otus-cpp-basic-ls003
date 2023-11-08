// 
// Домашнее задание #3
//

#include "user_input/user_input.h"
#include "game/game.h"

#include <chrono>
#include <iostream>


int main(int argc, char *argv[]) {

  int iMenuIndex = 0;
  int iVal = 0;
  int &rVal = iVal;

  initResult();

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
      startGame(rVal);
      break;
    
    case 2:
      getResult();
      break;

    case 3:
      break;

    default:
      break;
    } //switch
    
  } while (iMenuIndex != 3);

return 0;
}