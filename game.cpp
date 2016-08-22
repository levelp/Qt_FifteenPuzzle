#include <vector>
#include <cstdlib>

#include "game.h"

Game::Game() {
  // Инициализируем игровое поле
  // Расставляем случайным
  // образом числа от 0 до 15
  // 0 означает пустую клетку, всё остальное - цифры на кнопках

  // Создаём vector с цифрами, которые надо
  // расставить на поле
  std::vector<int> numbers;
  for(int n = 0; n <= SIZE * SIZE - 1; ++n)
    numbers.push_back(n);

  // Расставляем их случайным образом на поле
  for(int i = 0; i < SIZE; ++i)
    for(int j = 0; j < SIZE; ++j) {
      // Выбираю из набора случайным образом число
      // Индекс очередного числа из вектора
      int index = rand() % numbers.size();
      // Значение помещаю в клетку поля
      field[i][j] = numbers[index];
      // Удаляю из набора использованное число
      numbers.erase(numbers.begin() + index);
    }
}

// Получить значение клетки игрового поля
int Game::getCell(int i, int j) {
  return field[i][j];
}

// В каком направлении можно двигаться
Direction Game::move(int i, int j) {
  if(i > 0 && field[i - 1][j] == 0) {
    field[i - 1][j] = field[i][j];
    field[i][j] = 0;
    return UP;
  }
  if(i < SIZE - 1 && field[i + 1][j] == 0) {
    field[i + 1][j] = field[i][j];
    field[i][j] = 0;
    return DOWN;
  }
  if(j > 0 && field[i][j - 1] == 0) {
    field[i][j - 1] = field[i][j];
    field[i][j] = 0;
    return LEFT;
  }
  if(j < SIZE - 1 && field[i][j + 1] == 0) {
    field[i][j + 1] = field[i][j];
    field[i][j] = 0;
    return RIGHT;
  }
  return NO;
}
