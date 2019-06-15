﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "poissonmatting.h"

#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    canvas = new MattingCanvas(this);
    scrollArea = new QScrollArea(this);
    scrollArea->setWidget(canvas);
    ui->gridLayout->addWidget(scrollArea, 0, 0, 1, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpenForeground_triggered()
{
    filename = QFileDialog::getOpenFileName(this, tr("Open Image"), QString(), tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
    pmat.openFore(filename);
    canvas->setImage(pmat.getImageMat());
}

void MainWindow::on_actionOpenBackground_triggered()
{
    filename = QFileDialog::getOpenFileName(this, tr("Open Image"), QString(), tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
    pmat.openBack(filename);
    cv::Mat background;
    background=pmat.getbackMat();
    cv::imshow("Background", background);
}

void MainWindow::on_actionSelectRegion_triggered()
{

}


void MainWindow::on_actionDraw_Unknown_triggered(bool checked)
{
    ui->actionMark_Foreground->setChecked(false);
    canvas->setFilling(false);
    canvas->clearFilling();
    canvas->setDrawing(checked);
}

void MainWindow::on_actionMark_Foreground_triggered(bool checked)
{
    ui->actionDraw_Unknown->setChecked(false);
    canvas->setDrawing(false);
    canvas->setFilling(checked);
}

void MainWindow::on_actionClear_triggered()
{
    ui->actionMark_Foreground->setChecked(false);
    ui->actionDraw_Unknown->setChecked(false);
    canvas->setDrawing(false);
    canvas->setFilling(false);
    canvas->clearAll();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionMatte_triggered()
{
    cv::Mat foreground, alpha;
    pmat.matting(canvas->getTrimapMat(), foreground, alpha);
    cv::imshow("trimap", canvas->getTrimapMat());
    cv::imshow("fore", foreground);
    cv::imshow("alpha", alpha);
}

void MainWindow::on_actionClear_Mark_triggered()
{
    canvas->clearFilling();
}

void MainWindow::on_action_Add_Pen_Size_triggered()
{
    canvas->setPenSize(canvas->getPenSize() + 5);
}

void MainWindow::on_action_Sub_Pen_Size_triggered()
{
    canvas->setPenSize(canvas->getPenSize() - 5);
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("About me"), tr("This is Poisson Matting Application for my final work of Digital Image Processing Course.\n\nHongxu Xu\n201411212027\n\nComputer Science Major\nCollege of Information Science and Technology\nBeijing Normal University"));
}
