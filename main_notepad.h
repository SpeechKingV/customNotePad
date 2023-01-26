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
#include <QApplication>
#include <QSplashScreen>
#include <QLabel>
#include <QTime>

//void load_Window(QSplashScreen* psplash)
//{

//    int i;
//    for(i = 0; i < 100;);
//    {
//        _sleep(30);

//        psplash->showMessage("Loading : "
//                            + QString::number(i)+ "%",
//                             Qt::AlignHCenter | Qt::AlignBottom,
//                             Qt::black
//                             );
//        qApp->processEvents();
//    }


//}

class main_notepad : public QMainWindow
{
    Q_OBJECT

public:

    main_notepad(QWidget* parent = nullptr);

public slots:

    void SAbout()
    {
        statusBar()->showMessage("Abouting");


        QMessageBox::about(this,"About","(c)SpeechKingV | <a href=\"https://github.com/SpeechKingV/customNotePad\">Я в GitHub</a>");
    }

    void SHelp()
    {
        statusBar()->showMessage("Helping");

        QMessageBox::about(this,"Help","this is my first Qt project that I posted on GitHub.\n And it's the same notebook, but the one I created is nothing special.\n Maximum rainbow notepad icon");
    }

    void SChangeWindowTitle(const QString& str)
    {
        statusBar()->showMessage("ready", 4000);


        QString Titel = "Costom Notepad :   "+ str;

        setWindowTitle(Titel);
    }

};

#endif // MAIN_NOTEPAD_H
