#include "main_notepad.h"

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
                       SLOT(SLoad()),
                       QKeySequence("CTRL+SHIFT+S")
                       );
    pmuFile->addSeparator();

    pmuFile->addAction("&Quit",
                       qApp,
                       SLOT(quit()),
                       QKeySequence("CTRL+Q")
                       );
    pmuFile->addAction("&About",
                       this,
                       SLOT(SAbout()),
                       Qt::Key_F1
                       );

    menuBar()->addMenu(pmuFile);
    menuBar()->addMenu(pmuHelp);

    setCentralWidget(pnotepad);
    connect(pnotepad,SIGNAL(changeWindowTitle(QString)),SLOT(SChangeWindowTitle()));

    statusBar()->showMessage("Ready", 2000);

}
