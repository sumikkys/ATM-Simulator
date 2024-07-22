QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    atmsystem.cpp \
    changepasswordwidget.cpp \
    depositwidget.cpp \
    loginwidget.cpp \
    main.cpp \
    mainwidget.cpp \
    mainwindow.cpp \
    withdrawwidget.cpp

HEADERS += \
    account.h \
    atmsystem.h \
    changepasswordwidget.h \
    depositwidget.h \
    loginwidget.h \
    mainwidget.h \
    mainwindow.h \
    withdrawwidget.h

FORMS += \
    changepasswordwidget.ui \
    depositwidget.ui \
    loginwidget.ui \
    mainwidget.ui \
    mainwindow.ui \
    withdrawwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resources.qrc
