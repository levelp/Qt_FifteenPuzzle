#include "gamesettings.h"
#include "ui_gamesettings.h"
#include <QColorDialog>
#include <QSettings>
#include <QDir>
#include "game.h"
#include <QDebug>

bool saveParam = false; //Сохранять изменения или нет

GameSettings::GameSettings(QWidget* parent) :
  QDialog(parent),
  ui(new Ui::GameSettings) {
  ui->setupUi(this);

  QPushButton* b = ui->sampleButton;
  b->setText("15");

  //примeнение параметров из файла
  QSettings confSet(QCoreApplication::applicationDirPath() + QDir::separator() + "setting.ini", QSettings::IniFormat); //+ QDir::separator()

  QRect tmpRect = confSet.value("Geom", tmpRect).toRect();
  QFont tmpFont;
  tmpFont = qvariant_cast<QFont>(confSet.value( "Font", tmpFont));
  QPalette tmpPal;
  tmpPal = qvariant_cast<QPalette>(confSet.value("Color", tmpPal));

  b->setGeometry(tmpRect);
  b->setFont(tmpFont);
  b->setFlat(true);
  b->setAutoFillBackground(true);
  b->setPalette(tmpPal);
  b->update();

  ui->buttonSizeEdit->setValue(tmpRect.height());
  ui->fontComboBox->setCurrentFont(tmpFont);
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
  // Изменяем размер шрифта при изменении размера кнопки
  QFont b_font = ui->sampleButton->font();
  b_font.setPointSize(10 + 30 * (buttonSize - 30) / 70);
  ui->sampleButton->setFont(b_font);
}

void GameSettings::on_fontComboBox_currentFontChanged(const QFont& f) {
  //Изменение размера при изменении надвания шрифта
  QFont b_font = f;
  b_font.setPointSize(10 + 30 * (ui->buttonSizeEdit->value() - 30) / 70);
  ui->sampleButton->setFont(b_font);
}

void GameSettings::saveTo(QPushButton& button) {
  if (saveParam) {
    QFont font = ui->sampleButton->font();
    font.setPointSize(
      ui->sampleButton->font().pointSize());
    button.setFont(font);

    QRect rect = ui->sampleButton->geometry();
    button.setGeometry(rect);

    button.setFlat(true);
    button.setAutoFillBackground(true);
    button.setPalette(ui->sampleButton->palette());
    button.update();
  }
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
}



void GameSettings::on_GameSettings_accepted() {
  qDebug() << "Ok pressed";
  saveParam = true;
}

void GameSettings::on_buttonBox_rejected() {
  qDebug() << "Cancel pressed";
  saveParam = false;
}
