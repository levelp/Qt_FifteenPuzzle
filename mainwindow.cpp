#include "mainwindow.h"
#include "ui_mainwindow.h"
// Подключаем 2-ую форму с настройками игры
#include "gamesettings.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Скрываем кнопку прототип
  ui->prototypeButton->setVisible(false);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_gameSettingsAction_triggered() {
  GameSettings form(this);
  form.exec();
  form.saveTo(*(ui->prototypeButton));
}
