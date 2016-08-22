#ifndef GAMEBUTTON_H
#define GAMEBUTTON_H

#include <QPushButton>
#include "game.h"

class GameButton : public QPushButton {
  Q_OBJECT

 public:
  GameButton(QWidget* parent,
             int row, int col,
             QPushButton* prototype,
             Game& game);

 private slots:
  void tryMove();

 private:
  // Строка и столбец кнопки
  int row, col;
  // Переместить кнопку в
  // координаты row, col
  void move(int row, int col);

  Game& game;
};

#endif // GAMEBUTTON_H
