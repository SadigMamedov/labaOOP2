#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QTextEdit>
#include <QMessageBox>
#include <string>
#include <memory>

#include "jsonException.h"
#include "JsonFile.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_fileDialog_clicked();

    void on_LoadFile_clicked();

    void on_CheckFile_clicked();

private:
    Ui::MainWindow *ui;

    JsonFile json;

    char* QstringToCharArray(QString qstr);
};
#endif // MAINWINDOW_H
