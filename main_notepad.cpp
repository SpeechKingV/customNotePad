#include "main_notepad.h"

#include <QFile>
#include <QTextCodec>

main_notepad::main_notepad(QWidget* parent) : QMainWindow(parent)
{

//    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
//    QTextCodec::setCodecForTr(codec);
//    QTextCodec::setCodecForCStrings(codec);
//    QTextCodec::setCodecForLocale(codec);


//    QSplashScreen splash(QPixmap(":/icon/raibow icon notepad.jpg"));

//    QLabel lbl("<H1><CENTER>Costum Notepad<BR>"
//               "Is ready!</Center></H1>"
//               );

//        splash.finish(&lbl);
//        lbl.resize(250,250);
//        lbl.show();


        QMenu*   pmuFile = new QMenu("&File");
        QMenu*   pmuHelp = new QMenu("&Help");
        notepad* pnotepad = new notepad;

        pmuFile->addAction("&Open",
                           pnotepad,
                           SLOT(SLoad()),
                           QKeySequence("CTRL+O")
                           );
        pmuFile->addAction("&Save",
                           pnotepad,
                           SLOT(SSave()),
                           QKeySequence("CTRL+S")
                           );
        pmuFile->addAction("&Save As",
                           pnotepad,
                           SLOT(SSaveAs()),
                           QKeySequence("CTRL+SHIFT+S")
                           );

        pmuFile->addSeparator();

        pmuFile->addAction("&Close file",
                           pnotepad,
                           SLOT(SCloseFile()),
                           QKeySequence("CTRL+Delet")
                           );

        pmuFile->addAction("&Quit",
                           qApp,
                           SLOT(quit()),
                           QKeySequence("CTRL+Q")
                           );

        pmuHelp->addAction("&About",
                           this,
                           SLOT(SAbout()),
                           Qt::Key_F1
                           );
        pmuHelp->addAction("&Help",
                           this,
                           SLOT(SHelp()),
                           QKeySequence("ctrl+H")
                           );

        menuBar()->addMenu(pmuFile);
        menuBar()->addMenu(pmuHelp);

        setCentralWidget(pnotepad);
        connect(pnotepad,SIGNAL(changeWindowTitle(const QString&)),SLOT(SChangeWindowTitle(const QString&)));

        statusBar()->showMessage("Ready", 4000);

}
