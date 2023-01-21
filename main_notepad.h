#ifndef MAIN_NOTEPAD_H
#define MAIN_NOTEPAD_H

#include "notepad_window.h"

#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QMainWindow>
#include <QMessageBox>
#include <QApplication>
#include <QStatusBar>
#include <QAction>

class main_notepad : public QMainWindow
{
    Q_OBJECT

public:

    main_notepad(QWidget* parent = nullptr);


public slots:

    void SAbout()
    {
        QMessageBox::about(this,"Application","SDI Example");
    }

    void SChangeWindowTitle(const QString& str)
    {
        setWindowTitle("Costom Notepad :"+ str);
    }

};

#endif // MAIN_NOTEPAD_H
