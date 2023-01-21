#include "notepad_window.h"

#include <QWidget>
#include <QFileDialog>
#include <QTextStream>

//notepad::notepad(QWidget* parent = 0) : QTextEdit(parent)
//{

//}

void notepad::SLoad()
{
    QString str = QFileDialog::getOpenFileName();
    if (str.isEmpty())
    {
        return;
    }

    QFile file(str);
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        setPlainText(stream.readAll());
        file.close();

        strFileName = str;
        emit changeWindowTitle(strFileName);
    }
}

void notepad::SSaveAs()
{
    QString str = QFileDialog::getSaveFileName(0,strFileName);
    if (!str.isEmpty())
    {
        strFileName = str;
        SSave();
    }
}

void notepad::SSave()
{
    if (strFileName.isEmpty())
    {
        SSaveAs();
        return;
    }

    QFile file(strFileName);
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream(&file) << toPlainText();
        file.close();
        emit changeWindowTitle(strFileName);
    }
}
