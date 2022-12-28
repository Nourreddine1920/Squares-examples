#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    update_ui();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_ui(){
    this->ui->spinScale->setValue(this->ui->renderArea->scale());
    this->ui->spinInterval->setValue(this->ui->renderArea->interval());
    this->ui->spinStepCount->setValue(this->ui->renderArea->count());



}


void MainWindow::on_btnAstroid_clicked()
{
    // change background color for render area
    // but how to do this ?
    // add a function to change the background .
    this->ui->renderArea->setShape(RenderArea::Astroid);

    this->ui->renderArea->repaint();
    update_ui();



}


void MainWindow::on_btnCycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);

    this->ui->renderArea->repaint();
    update_ui();




}


void MainWindow::on_btnHuygens_clicked()
{
     this->ui->renderArea->setShape(RenderArea::HuygensCycloid);

    this->ui->renderArea->repaint();
    update_ui();




}


void MainWindow::on_btnHypo_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HypoCycloid);

    this->ui->renderArea->repaint();

    update_ui();




}



void MainWindow::on_btnLine_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Line);

    this->ui->renderArea->repaint();

    update_ui();



}


void MainWindow::on_spinScale_valueChanged(double scale)
{
    this->ui->renderArea->setScale(scale);


}


void MainWindow::on_spinInterval_valueChanged(double interval)
{
    this->ui->renderArea->setInterval(interval);

}


void MainWindow::on_spinStepCount_valueChanged(double count)
{
    this->ui->renderArea->setStepCount(count);

}

