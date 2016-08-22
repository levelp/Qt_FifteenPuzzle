#ifndef GAME_H
#define GAME_H

enum Direction {
  NO, UP, DOWN, LEFT, RIGHT
};

// Состояние игры
// Состояние поля + выйгрыш/проигрыш
class Game {
 public:
  // Размер поля игры 4x4
  static const int SIZE = 4;
  // Конструктор
  Game();
  // Получить значение в заданной
  // клетке игрового поля
  int getCell(int i, int j);
  // В каком направлении из координат i,j
  // можно двигаться
  Direction move(int i, int j);
 private:
  // Игровое поле. 0 - пустая клетка
  int field[SIZE][SIZE];
};

#endif // GAME_H
