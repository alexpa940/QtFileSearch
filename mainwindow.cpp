#include "mainwindow.h"
#include "fileopen.xpm"
uint i;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    Directory    = new QLineEdit(QDir::current().absolutePath());
    Mask   = new QLineEdit("*.cpp *.h");
    Result = new QTextEdit;
    QLabel*      labelDirectory  = new QLabel("&Каталог");
    QLabel*      labelMask = new QLabel("&Маска");
    labelCount = new QLabel("Количество файлов: ");
    QPushButton* ButDirectory  = new QPushButton(QPixmap(fileopen), "");
    QPushButton* ButFind = new QPushButton("&Найти");
    connect(ButDirectory, SIGNAL(clicked()), SLOT(slotBrowse()));
    connect(ButFind, SIGNAL(clicked()), SLOT(slotFind()));
    labelDirectory->setBuddy(Directory);
    labelMask->setBuddy(Mask);
    QGridLayout* pgrdLayout = new QGridLayout;
    pgrdLayout->setMargin(5);
    pgrdLayout->setSpacing(15);
    pgrdLayout->addWidget(labelDirectory, 0, 0);
    pgrdLayout->addWidget(labelMask, 1, 0);
    pgrdLayout->addWidget(Directory, 0, 1);
    pgrdLayout->addWidget(Mask, 1, 1);
    pgrdLayout->addWidget(ButDirectory, 0, 2);
    pgrdLayout->addWidget(ButFind, 1, 2);
    pgrdLayout->addWidget(labelCount, 2, 0, 1, 3);
    pgrdLayout->addWidget(Result, 3, 0, 1, 3);
    setLayout(pgrdLayout);
}

void MainWindow::slotBrowse()
{
    Result->clear();
    QString str = QFileDialog::getExistingDirectory(0,
                                                    "Выбор каталога",
                                                    Directory->text()
                                                   );

    if (!str.isEmpty()) {
       Directory->setText(str);
    }
}


void MainWindow::slotFind()
{
    i=0;
    Result->clear();
    start(QDir(Directory->text()));
    QString stri = QString::number(i);
    labelCount->setText("Количество файлов: "+stri);
}


void MainWindow::start(const QDir& dir)
{
    QApplication::processEvents();

    QStringList listFiles =
        dir.entryList(Mask->text().split(" "), QDir::Files);
     i=i+dir.entryList(Mask->text().split(" "), QDir::Files).count();

    foreach (QString file, listFiles) {
        Result->append(dir.absoluteFilePath(file));
    }

    QStringList listDir = dir.entryList(QDir::Dirs);

    foreach (QString subdir, listDir) {
        if (subdir == "." || subdir == "..") {
            continue;
        }
        start(QDir(dir.absoluteFilePath(subdir)));
    }
}
