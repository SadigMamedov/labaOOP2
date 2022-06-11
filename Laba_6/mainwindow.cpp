#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

char* MainWindow::QstringToCharArray(QString qstr)
{
    char *str = new char[qstr.size() + 1];
    if (str != NULL) {
        int i;
        for (i = 0; i < qstr.size(); i++)
        {
            str[i] = qstr.at(i).unicode();
        }
        str[i] = 0;
    }
    return str;
}

void MainWindow::on_fileDialog_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "C://");
    ui->fileNameLabel->setText(filename);
    try {
        if (filename.isEmpty())
            throw jsonException("File not found");
    }  catch (jsonException& ex) {
        QMessageBox::warning(this, "Ошибка", ex.what());
    }
}


void MainWindow::on_LoadFile_clicked()
{
    QString filename = ui->fileNameLabel->text();
    try {
        fileManager file;
        string data = file.readFile(QstringToCharArray(filename));
        json.fillData(data);
        QString Qdata;
        for (int i = 0; i < data.size(); i++)
            Qdata.append(QString(data[i]));
        ui->textEdit->clear();
        ui->textEdit->append(Qdata);
    }  catch (jsonException& ex) {
        QMessageBox::warning(this, "Ошибка", ex.what());
    }
}


void MainWindow::on_CheckFile_clicked()
{
    stringHelper formatData;
    try {
        string newData = formatData.deleteSymbol(json.getData(), ' ');
        newData = formatData.deleteSymbol(newData, '\n');
        newData = formatData.deleteSymbol(newData, '\t');
        json.fillData(newData);
        JsonFormatChecker check;
        check.startCheck(json.getData());
        ui->fileCorrect->setText("Correct");
        ui->textEditError->setText("All right");
    }  catch (jsonException& ex) {
        QMessageBox::warning(this, "Ошибка", ex.what());
        ui->fileCorrect->setText("Incorrect");
        ui->textEditError->setText(ex.getDataException().c_str());
    }
}

