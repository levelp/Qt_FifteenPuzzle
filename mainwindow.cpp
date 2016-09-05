#include "mainwindow.h"
#include "ui_mainwindow.h"
// Подключаем 2-ую форму с настройками игры
#include "gamesettings.h"
#include "gamebutton.h"
#include "game.h"
#include <QFileDialog>
#include <QDebug>
#include <QTextCodec>
#include <QTextStream>
#include <string>
#include <QSettings>
// Окно "О программе"
#include "about.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Скрываем кнопку-прототип
    ui->prototypeButton->setVisible(false);

    // Считываем настройки оформления игры из файла
   loadSettings(*(ui->prototypeButton));

    // Поле для игры
    int field[game.SIZE][game.SIZE];
    // Заполняем поле для игры
    game.newGame(field);

    // Создаём кнопки соответствующие клеткам поля
    for(int i = 0; i < game.SIZE; ++i)
        for(int j = 0; j < game.SIZE; ++j) {
            // i - строка 0..3, j - столбец 0..3
            // Для каждой клетки получаем значение
            int value = field[i][j];

            // Пропускаем пустую клетку, у неё значение 0
            if(value == 0)
                continue;

            // Создаём новую кнопку
            game.setCell(i, j,
                         new GameButton(ui->centralWidget,
                                        i, j, value,
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
    game.setCellProperty(*(ui->prototypeButton));

   // Сохраняем настройки оформления игры в файл
    saveSettings(*(ui->prototypeButton));
}

void MainWindow::on_exitAction_triggered()
{
    MainWindow::close();
}

void MainWindow::on_loadGameAction_triggered()
{
    QString str = QFileDialog::getOpenFileName(0, "Загрузка игры", "", "Save game file *.fsg;; All files *.*");
    QFile loadfile(str);
    if (loadfile.open(QIODevice::ReadWrite )) {
        QTextStream inFile(&loadfile);
        QString str = "";
        str = inFile.readLine(); // Читаем первую строчку
        str = inFile.readLine(); // Размер поля
        // Инициализируем игру
        game.intGame(); // Удаляем кнопки
        int field[game.SIZE][game.SIZE];
        game.newGame(field);
        for (int i = 0; i<game.SIZE; i++){
            inFile >> str; // Прочитали имя
            for (int j = 0; j<game.SIZE; j++){
                int value = 0;
                inFile >> value;
                // Пропускаем пустую клетку, у неё значение 0
                if(value == 0){
                    //Установить координаты нуля
                    game.setZeroCoordinates(i,j);
                    continue;
                }
                // Создаём новую кнопку
                game.setCell(i, j,
                             new GameButton(ui->centralWidget,
                                            i, j, value,
                                            ui->prototypeButton,
                                            game));

            }
        }
        loadfile.close();
    }
}


void MainWindow::on_saveGameAction_triggered()
{
    QString str = QFileDialog::getSaveFileName(0, "Сохранение игры", "game_default", "Save game file *.fsg;; All files *.*");
    QFile savefile(str);
    if (savefile.open(QIODevice::WriteOnly)) {
        QTextStream outFile(&savefile);
        outFile << "#Save game for Fiftens-Puzzle#"<< endl;
        outFile << "Game size " << game.SIZE << endl;
        for (int i = 0; i<game.SIZE;i++){
            outFile << "Cells: ";
            for (int j = 0; j<game.SIZE;j++){
                outFile << game.getCell(i,j) << "\t";
            }
            outFile << endl;
        }
        savefile.close();
    }
}

void MainWindow::loadSettings(QPushButton& button){
    QString settPath= QCoreApplication::applicationDirPath() + QDir::separator() + "setting.ini";
    QFile f(settPath);
    if (f.open(QIODevice::ReadOnly))
    {
        f.close();
        QSettings conf(settPath, QSettings::IniFormat);

        QRect tmpRect = conf.value("Geom",tmpRect).toRect();
        QFont tmpFont;
        tmpFont = qvariant_cast<QFont>( conf.value( "Font", tmpFont) );
        QPalette tmpPal;
        tmpPal = qvariant_cast<QPalette>(conf.value("Color",tmpPal));

        button.setFont(tmpFont);
        button.setGeometry(tmpRect);
        button.setPalette(tmpPal);
    }
}

void MainWindow::saveSettings(QPushButton& button){
    QSettings configS(QCoreApplication::applicationDirPath() + QDir::separator() + "setting.ini", QSettings::IniFormat);

    configS.setValue("Font", button.font());
    configS.setValue("Geom", button.geometry());
    configS.setValue("Color", button.palette());
}

void MainWindow::on_aboutAction_triggered() {
  About form(this);
  form.exec();
}
