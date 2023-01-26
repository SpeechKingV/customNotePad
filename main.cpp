#include"main_notepad.h"

#include <QApplication>
#include <QThread>

void load_Window(QSplashScreen* psplash)
{

    int i;
    for(i = 0; i < 100; i++)
    {

        QThread::msleep(600);

        psplash->showMessage("Loading : "
                            + QString::number(i)+ "%",
                             Qt::AlignHCenter | Qt::AlignBottom,
                             Qt::black
                             );
        qApp->processEvents();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen splash(QPixmap(":/icon/raibow icon notepad.jpg"));

    main_notepad w;
    w.setWindowTitle("Costom Notepad");
    w.setWindowIcon(QIcon(":/icon/raibow icon notepad.jpg"));
    w.resize(800,600);

    splash.finish(&w);

    w.show();

    return a.exec();
}
