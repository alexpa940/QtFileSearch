#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDir>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QApplication>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void start(const QDir& dir);

private:
    QLineEdit* Directory;
    QLineEdit* Mask;
    QTextEdit* Result;
    QLabel *labelCount;

public slots:
    void slotFind  ();
    void slotBrowse();
};
#endif // MAINWINDOW_H
