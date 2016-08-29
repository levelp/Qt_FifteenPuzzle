#include <QDebug>
#include "gamebutton.h"

void GameButton::move(int row, int col) {
  // Запоминаем новые координаты кнопки
  this->row = row;
  this->col = col;

  QRect rect = geometry();
  // высота, ширина, координаты
  // высоту и ширину не трогаем
  // а координаты меняем
  int borderSize = 5; // Отступ между клетками
  int x = // x - координата кнопки
    10 + (col * (rect.height() + borderSize));
  // y - координата кнопки
  int y = 10 + (row * (rect.width() + borderSize));
  rect.moveTo(x, y);
  setGeometry(rect);
}

GameButton::GameButton(QWidget* parent,
                       int row,
                       int col,
                       int value,
                       QPushButton* prototype,
                       Game& game)
  : QPushButton(parent), row(row), col(col),
    GameCell(value), game(game) {
  // Текст для кнопки - это число взятое с поля
  setText(QString("%1").arg(value));

  // Шрифт у новой кнопки как у кнопки-прототипа
  setFont(prototype->font());

  // Копируем размеры и координаты с прототипа
  setGeometry(prototype->geometry());

  // Перемещение кнопки в заданную строку и столбец
  move(row, col);

  // Подключаем обработчик событий к кнопке
  connect(this, // Источник сигнала
          SIGNAL(clicked()), // Какой сигнал
          this, // Объект-обработчик
          SLOT(tryMove())); // Слот (метод) обработчик
}

void GameButton::tryMove() {
  qDebug() << row << col;

  game.move(row, col);
}
