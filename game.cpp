#include <vector>
#include <cstdlib>
#include <algorithm>

#include "game.h"

using namespace std;

Game::Game() {
}

// Инициализация новой игры
void Game::newGame(int field[SIZE][SIZE]) {
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
      int value = numbers[index];
      field[i][j] = value;
      // Если это 0, запоминаем его позицию
      if(value == 0) {
        zeroRow = i;
        zeroCol = j;
      }
      // Удаляю из набора использованное число
      numbers.erase(numbers.begin() + index);
      // Обнуляем клетки поля
      cells[i][j] = nullptr;
    }
}

// Получить значение клетки игрового поля
int Game::getCell(int i, int j) {
  if(cells[i][j] == nullptr)
    return 0;
  return cells[i][j]->value;
}

// В каком направлении можно двигаться
void Game::move(int i, int j) {
  // У нас там не должно быть кнопки
  // но на всякий случай :)
  if(i == zeroRow && j == zeroCol)
    return;
  // Если строка совпадает, то будем двигаться
  // горизонтально
  if(i == zeroRow) {
    if(j < zeroCol) { // Двигаем вправо
      for(int c = zeroCol - 1; c >= j; c--) {
        // Передвинули кнопки
        cells[zeroRow][c]->move(zeroRow, c + 1);
        // Меняем местами данные
        swap(cells[zeroRow][c + 1], cells[zeroRow][c]);
      }
    } else { // Двигаем влево
      for(int c = zeroCol + 1; c <= j; c++) {
        // Передвинули кнопки
        cells[zeroRow][c]->move(zeroRow, c - 1);
        // Меняем местами данные
        swap(cells[zeroRow][c - 1], cells[zeroRow][c]);
      }
    }
    zeroCol = j;
    return;
  }
  // Если столбец совпадает, то будем
  // двигаться вертикально
  if(j == zeroCol) {
    if(i < zeroRow) { // Двигаем вниз
      for(int r = zeroRow - 1; r >= i; r--) {
        // Передвинули кнопки
        cells[r][zeroCol]->move(r + 1, zeroCol);
        // Меняем местами данные
        swap(cells[r + 1][zeroCol], cells[r][zeroCol]);
      }
    } else { // Двигаем вверх
      for(int r = zeroRow + 1; r <= i; r++) {
        // Передвинули кнопки
        cells[r][zeroCol]->move(r - 1, zeroCol);
        // Меняем местами данные
        swap(cells[r - 1][zeroCol], cells[r][zeroCol]);
      }
    }
    zeroRow = i;
  }
}

void Game::setCell(int i, int j, GameCell* cell) {
  cells[i][j] = cell;
}
