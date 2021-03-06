#ifndef GAMEBUTTON_H
#define GAMEBUTTON_H

#include <QPushButton>
#include "game.h"

// Наследуем абстрактный класс GameCell
class GameButton : public QPushButton,
  public GameCell {
  Q_OBJECT

 public:
  GameButton(QWidget* parent,
             int row, int col, int value,
             QPushButton* prototype,
             Game& game);

 private slots:
  void tryMove();

 private:
  // Строка и столбец кнопки
  int row, col;
  // Переместить кнопку в
  // координаты row, col
  // Перегруженный виртуальный метод
  // GameCell
  void move(int row, int col);
  void setFonts(QFont s_font);
  void setGeom(QRect s_geom, int row, int col);
  void setColr(QPalette palette);
  void setValue(int s_val);
  void initBtn();

  Game& game;
};

#endif // GAMEBUTTON_H
