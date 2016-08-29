#include "mainwindow.h"
#include "ui_mainwindow.h"
// Подключаем 2-ую форму с настройками игры
#include "gamesettings.h"
#include "gamebutton.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Скрываем кнопку прототип
  ui->prototypeButton->setVisible(false);

  // Создаём кнопки соответствующие клеткам поля
  for(int i = 0; i < game.SIZE; ++i)
    for(int j = 0; j < game.SIZE; ++j) {
      // i - строка 0..3, j - столбец 0..3
      // Для каждой клетки получаем значение
      int value = game.getCell(i, j);

      // Пропускаем пустую клетку, у неё значение 0
      if(value == 0)
        continue;

      // Создаём новую кнопку
      game.setCell(i, j,
                   new GameButton(ui->centralWidget,
                                  i, j,
                                  ui->prototypeButton,
                                  game));
    }
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_gameSettingsAction_triggered() {
  GameSettings form(this);
  form.exec();
  form.saveTo(*(ui->prototypeButton));
}
