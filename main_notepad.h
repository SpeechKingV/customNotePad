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

    void SM(QString str, int t)
    {
        statusBar()->showMessage(str, t);
    }

    main_notepad(QWidget* parent = nullptr);


public slots:

    void SAbout()
    {
        QMessageBox::about(this,"Adout","(c)SpeechKingV | <a href=\"https://github.com/SpeechKingV/customNotePad\">Я в GitHub</a>");
    }

    void SHelp()
    {
        QMessageBox::about(this,"Help","this is my first Qt project that I posted on GitHub.\n And it's the same notebook, but the one I created is nothing special.\n Maximum rainbow notepad icon");
    }

    void SChangeWindowTitle(const QString& str)
    {
        QString Titel = "Costom Notepad :   "+ str;

        setWindowTitle(Titel);
    }

};

#endif // MAIN_NOTEPAD_H
