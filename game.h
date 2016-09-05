#ifndef GAME_H
#define GAME_H
#include <QColor>
#include <QFont>
#include <QPushButton>

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
  virtual void setFonts(QFont s_font) = 0;
  virtual void setGeom(QRect s_geom, int row, int col) = 0;
  virtual void setColr(QPalette palette) = 0;
  virtual void setValue(int s_val) = 0;
  virtual void initBtn() = 0;
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
  void newGame(int field[SIZE][SIZE]); //
  // Получить значение в заданной
  // клетке игрового поля
  int getCell(int i, int j);
  // В каком направлении из координат i,j
  // можно двигаться
  void move(int i, int j);
  // Задать клетку игрового поля
  void setCell(int i, int j, GameCell* cell);
  //Копирование свойств прототипа в клетки
  void setCellProperty(QPushButton& prototype);
  void setCellValue(int i, int j, int value);
  // Получение координат нуля
  void setZeroCoordinates(int i, int j);
  // Инициализация самой игры
  void intGame();
  //Перезагрузка игры
  void reLoadGame(int field[SIZE][SIZE]);
  // Головоломка завершена?
  bool isSolved();
 private:
  // Клетки игрового поля. null - пустая клетка
  GameCell* cells[SIZE][SIZE];
  // Храним позицию 0 на поле
  int zeroCol, zeroRow;
};

#endif // GAME_H
