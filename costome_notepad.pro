QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

win64:RC_ICONS += myapp.rc

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    main_notepad.cpp \
notepad_window.cpp

HEADERS += \
    main_notepad.h \
notepad_window.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    main_notepad.ui

RESOURCES += \
    qrc.qrc


# txt_Binar easter egg: 11010000 10111111 11010000 10110000 11010001 10000001 11010001 10000101 11010000 10110000 11010000 10111011 11010000 10111010 11010000 10110000 100000 110001
# convert to txt: https://www.duplichecker.com/ru/binary-translator

