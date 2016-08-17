#include "gamesettings.h"
#include "ui_gamesettings.h"

GameSettings::GameSettings(QWidget* parent) :
  QDialog(parent),
  ui(new Ui::GameSettings) {
  ui->setupUi(this);

  // Добавляем палитру цветов
  ui->colorComboBox->addItem("Красный");
  ui->colorComboBox->addItem("Зелёный");
  ui->colorComboBox->addItem("Синий");
  ui->colorComboBox->addItem("Фиолетовый");
  // TODO: добавить остальные цвета
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
