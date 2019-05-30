#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);



private slots:
    void on_spinBox_valueChanged(int arg1);

private slots:
    void on_pushButton_clicked();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    int compressionRatio = 14;
};

#endif // MAINWINDOW_HPP
