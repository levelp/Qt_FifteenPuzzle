#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include <QDialog>

namespace Ui {
class GameSettings;
}

class GameSettings : public QDialog {
  Q_OBJECT

 public:
  explicit GameSettings(QWidget* parent = 0);
  ~GameSettings();

  void saveTo(QPushButton& button);

 private slots:
  void on_buttonSizeEdit_valueChanged(int arg1);

  void on_fontComboBox_currentFontChanged(const QFont& f);

  void on_chooseColorButton_clicked();

  void on_GameSettings_accepted();

private:
  Ui::GameSettings* ui;
};

#endif // GAMESETTINGS_H
