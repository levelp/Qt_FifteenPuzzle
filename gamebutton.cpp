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

void GameButton::setFonts(QFont s_font) {
  setFont(s_font);
}

// Копируем размеры и координаты с прототипа
void GameButton::setGeom(QRect s_geom, int row, int col) {
  setGeometry(s_geom);
  move(row, col);
}

void GameButton::setColr(QPalette palette) {
  setFlat(true);
  setAutoFillBackground(true);
  setPalette(palette);
}

void GameButton::setValue(int s_val) {
  value = s_val;
}

void GameButton::initBtn() {
  hide();
  delete this;
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

  // Устанавливаем цвет прототипа
  setColr(prototype->palette());

  // Подключаем обработчик событий к кнопке
  connect(this, // Источник сигнала
          SIGNAL(clicked()), // Какой сигнал
          this, // Объект-обработчик
          SLOT(tryMove())); // Слот (метод) обработчик

  // Перемещение кнопки в заданную строку и столбец
  move(row, col);
  setHidden(false);
}

void GameButton::tryMove() {
  game.move(row, col);
}
