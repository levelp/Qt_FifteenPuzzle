#ifndef GAME_H
#define GAME_H

enum Direction {
  NO, UP, DOWN, LEFT, RIGHT
};

// Клетка в игре (абстрактный класс)
struct GameCell {
  // Значение клетки
  int value;
  // Конструктор
  GameCell(int value) : value(value) {
  }
  // Абстрактный метод, который класс абстрактным
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
  // Инициализация поля для новой игры
  void newGame(int field[SIZE][SIZE]);
  // Получить значение в заданной
  // клетке игрового поля
  int getCell(int i, int j);
  // В каком направлении из координат i,j
  // можно двигаться
  void move(int i, int j);
  // Задать клетку игрового поля
  void setCell(int i, int j, GameCell* cell);
 private:
  // Клетки игрового поля. null - пустая клетка
  GameCell* cells[SIZE][SIZE];
  // Храним позицию 0 на поле
  int zeroCol, zeroRow;
};

#endif // GAME_H
