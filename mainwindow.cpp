#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "compressor.hpp"
#include "QFileDialog"
#include "QString"
#include "QFileInfo"
#include <cmath>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }
}

void MainWindow::on_pushButton_2_clicked()
{

    QString input_file_name = QFileDialog::getOpenFileName(this, tr("Open Directory"), "/home", tr("application/octet-stream"));
    QFileInfo info_for(input_file_name);

    std::ifstream fin(info_for.absoluteFilePath().toStdString());
    std::ofstream fout(input_file_name.toStdString()+"_compressed");

    Compressor comp(std::move(fin),std::move(fout));
    comp.compress(pow(2, compressionRatio));
}

void MainWindow::on_pushButton_clicked()
{

    QString input_file_name = QFileDialog::getOpenFileName(this, tr("Open Directory"), "/home", tr("application/octet-stream"));
    QFileInfo info_for(input_file_name);

    std::ifstream fin(info_for.absoluteFilePath().toStdString());
    std::ofstream fout(input_file_name.toStdString()+"_decompressed");

    Compressor decomp(std::move(fin),std::move(fout));
    decomp.decompress();
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    compressionRatio = arg1;
}
