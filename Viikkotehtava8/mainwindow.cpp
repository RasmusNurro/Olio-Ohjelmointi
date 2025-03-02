#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(new QTimer(this))
    , player1Time(0)
    , player2Time(0)
    , player1Turn(true)
    , gameDuration(0) // Aluksi 0, kunnes pelaaja valitsee ajan
{
    ui->setupUi(this);

    // Yhdistetään painikkeet toimintoihin
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::stopGame);
    connect(ui->switchPlayer1, &QPushButton::clicked, this, &MainWindow::switchPlayer);
    connect(ui->time120sButton, &QPushButton::clicked, this, &MainWindow::setGameTime120s);
    connect(ui->time5minButton, &QPushButton::clicked, this, &MainWindow::setGameTime5min);
    connect(timer, &QTimer::timeout, this, &MainWindow::timeout);

    // Näytetään aloitusohjeet
    setGameInfoText("Select playtime and press START GAME!", 14);
    ui->progressBarPlayer1->setValue(0);
    ui->progressBarPlayer2->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setGameTime120s()
{
    gameDuration = 120;
    setGameInfoText("120 sec selected. Press START GAME!", 14);
}

void MainWindow::setGameTime5min()
{
    gameDuration = 300;
    setGameInfoText("5 min selected. Press START GAME!", 14);
}

void MainWindow::startGame()
{
    if (gameDuration == 0) {
        setGameInfoText("Select playtime first!", 14);
        return;
    }

    player1Time = gameDuration;
    player2Time = gameDuration;
    player1Turn = true;

    ui->progressBarPlayer1->setValue(100);
    ui->progressBarPlayer2->setValue(100);

    setGameInfoText("Game ongoing!", 16);
    timer->start(1000); // Käynnistetään ajastin
}

void MainWindow::stopGame()
{
    timer->stop();
    setGameInfoText("Game stopped. Select playtime to restart.", 14);
}

void MainWindow::switchPlayer()
{
    player1Turn = !player1Turn;
}

void MainWindow::timeout()
{
    if (player1Turn) {
        if (player1Time > 0) player1Time--;
    } else {
        if (player2Time > 0) player2Time--;
    }

    updateProgressBars();

    if (player1Time == 0) {
        timer->stop();
        setGameInfoText("Player 2 WON!!", 16);
    } else if (player2Time == 0) {
        timer->stop();
        setGameInfoText("Player 1 WON!!", 16);
    }
}

void MainWindow::updateProgressBars()
{
    ui->progressBarPlayer1->setValue((player1Time * 100) / gameDuration);
    ui->progressBarPlayer2->setValue((player2Time * 100) / gameDuration);
}

void MainWindow::setGameInfoText(const QString &text, short fontSize)
{
    ui->statusLabel->setText(text);
    ui->statusLabel->setStyleSheet(QString("font-size: %1px; font-weight: bold;").arg(fontSize));
}
