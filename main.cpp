#include"main_notepad.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    main_notepad w;
    w.setWindowTitle("Costom Notepad");
    w.setWindowIcon(QIcon(":/icon/raibow icon notepad.jpg"));
    w.show();
    return a.exec();
}
