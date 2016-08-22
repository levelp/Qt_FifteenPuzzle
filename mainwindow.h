#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// Подключаем модуль с "состоянием игры"
#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 private slots:
  void on_gameSettingsAction_triggered();

 private:
  Ui::MainWindow* ui;

  // Состояние игры (игрового поля,
  // выйгрыш/проигрыш и т.д.)
  Game game;
};

#endif // MAINWINDOW_H
