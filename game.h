#ifndef GAME_H
#define GAME_H

enum Direction {
  NO, UP, DOWN, LEFT, RIGHT
};

// Клетка в игре (абстрактный класс)
struct GameCell {
  virtual void move(int row, int col) = 0;
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
  void move(int i, int j);
  // Задать клетку игрового поля
  void setCell(int i, int j, GameCell* cell);
 private:
  // Игровое поле. nullPtr - пустая клетка
  int field[SIZE][SIZE];
  // Клетки игрового поля
  GameCell* cells[SIZE][SIZE];
  // Храним позицию 0 на поле
  int zeroCol, zeroRow;
};

#endif // GAME_H
