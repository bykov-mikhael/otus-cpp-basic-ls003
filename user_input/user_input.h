// Для того, чтобы игра была более интересной, в приложении стоит использовать генератор
// случайных чисел вместо «угадывания» константы. При этом рекомендуется использовать самый
// простой генератор случайных чисел из стандартной библиотеки – std::rand

#pragma once

bool get_RandomVal(int iMaxVal, int iRandomVal);