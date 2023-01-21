#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

class notepad : public QMainWindow
{
    Q_OBJECT

public:
    notepad(QWidget *parent = nullptr);
    ~notepad();
};
#endif // NOTEPAD_H
