#ifndef NOTEPAD_H
#define NOTEPAD_H

#include<QTextEdit>

class notepad : public QTextEdit
{

    Q_OBJECT

public:

//    notepad(QWidget* parent = 0);

private:

    QString strFileName;

public:
signals:

    void changeWindowTitle (const QString&);

public slots:

    void SLoad  ();
    void SSave  ();
    void SSaveAs();

};

#endif // NOTEPAD_H
