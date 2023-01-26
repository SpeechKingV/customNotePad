#include "notepad_window.h"
#include "main_notepad.h"

#include <QWidget>
#include <QFileDialog>
#include <QTextStream>
#include <QStatusBar>
#include <QFileInfo>

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
    QFileInfo fileinfo (file);
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        setPlainText(stream.readAll());
        file.close();

        strFileName = str;
        emit changeWindowTitle(fileinfo.baseName());
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
    QFile file(strFileName);

    if (strFileName.isEmpty())
    {
        file.setFileName("unnamed");
        SSaveAs();
        return;
    }

    QFileInfo fileinfo (file);
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream(&file) << toPlainText();
        file.close();
        emit changeWindowTitle(fileinfo.baseName());
    }
}

void notepad::SCloseFile()
{
    QFile file(strFileName);

    if (strFileName.isEmpty())
    {
        file.setFileName("unsaved(costum Notepad)");
        SSave();
        file.close();
        return;
    }
        file.close();

}
