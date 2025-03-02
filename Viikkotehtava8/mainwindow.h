#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startGame();
    void stopGame();
    void switchPlayer();
    void updateProgressBars();
    void timeout();
    void setGameTime120s();
    void setGameTime5min();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int player1Time;
    int player2Time;
    bool player1Turn;
    int gameDuration;

    void setGameInfoText(const QString &text, short fontSize);
};

#endif // MAINWINDOW_H
