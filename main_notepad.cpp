#include "main_notepad.h"

#include <QFile>

main_notepad::main_notepad(QWidget* parent) : QMainWindow(parent)
{
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
                       QKeySequence("F1+H")
                       );

    menuBar()->addMenu(pmuFile);
    menuBar()->addMenu(pmuHelp);

    setCentralWidget(pnotepad);
    connect(pnotepad,SIGNAL(changeWindowTitle(const QString&)),SLOT(SChangeWindowTitle(const QString&)));

    statusBar()->showMessage("Ready", 4000);

}
