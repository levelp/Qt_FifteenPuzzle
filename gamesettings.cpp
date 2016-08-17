#include "gamesettings.h"
#include "ui_gamesettings.h"
#include <QColorDialog>

GameSettings::GameSettings(QWidget* parent) :
  QDialog(parent),
  ui(new Ui::GameSettings) {
  ui->setupUi(this);
}

GameSettings::~GameSettings() {
  delete ui;
}

void GameSettings::on_buttonSizeEdit_valueChanged(int size) {
  // Получаем изменённый размер
  int buttonSize = ui->buttonSizeEdit->value();
  // Применяем его к кнопке-примеру
  ui->sampleButton->setMaximumWidth(buttonSize);
  ui->sampleButton->setMinimumWidth(buttonSize);
  ui->sampleButton->setMaximumHeight(buttonSize);
  ui->sampleButton->setMinimumHeight(buttonSize);
}

void GameSettings::on_fontComboBox_currentFontChanged(const QFont& f) {
  ui->sampleButton->setFont(f);
}

void GameSettings::saveTo(QPushButton& button) {
  QFont font = ui->sampleButton->font();
  font.setPointSize(
    ui->sampleButton->font().pointSize());
  button.setFont(font);

  int size = ui->sampleButton->minimumWidth();
  button.setMaximumHeight(size);
  button.setMinimumHeight(size);
  button.setMaximumWidth(size);
  button.setMinimumWidth(size);
  // TODO: Сохранять цвет кнопки
}

void GameSettings::on_chooseColorButton_clicked() {
  auto b = ui->sampleButton;
  b->setFlat(true);
  b->setAutoFillBackground(true);

  // Получаем палитру для кнопки
  QPalette palette = b->palette();
  // Вызываем диалог выбора цвета
  QColor color = QColorDialog::getColor(palette.color(QPalette::Button),
                                        this,
                                        "Выберите цвет кнопки");
  // Меняем цвет в палитре
  palette.setColor(QPalette::Button, color);
  // Заменяем палитру
  b->setPalette(palette);
  b->update();

  //  ui->sampleButton->setStyleSheet("background-color:" + color.name() +  ";");
}
