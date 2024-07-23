QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    UIWidgets/accountcredeswidget.cpp \
    atmsystem.cpp \
    UIWidgets/changepasswordwidget.cpp \
    UIWidgets/depositwidget.cpp \
    UIWidgets/loginwidget.cpp \
    main.cpp \
    UIWidgets/mainwidget.cpp \
    mainwindow.cpp \
    UIWidgets/transferwidget.cpp \
    UIWidgets/withdrawwidget.cpp

HEADERS += \
    account.h \
    UIWidgets/headfile/accountcredeswidget.h \
    atmsystem.h \
    UIWidgets/headfile/changepasswordwidget.h \
    UIWidgets/headfile/depositwidget.h \
    UIWidgets/headfile/loginwidget.h \
    UIWidgets/headfile/mainwidget.h \
    mainwindow.h \
    UIWidgets/headfile/transferwidget.h \
    UIWidgets/headfile/withdrawwidget.h

FORMS += \
    UIWidgets/ui/accountcredeswidget.ui \
    UIWidgets/ui/changepasswordwidget.ui \
    UIWidgets/ui/depositwidget.ui \
    UIWidgets/ui/loginwidget.ui \
    UIWidgets/ui/mainwidget.ui \
    mainwindow.ui \
    UIWidgets/ui/transferwidget.ui \
    UIWidgets/ui/withdrawwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resources.qrc
