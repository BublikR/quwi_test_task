QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    downloadImageRequest.cpp \
    httpRequest.cpp \
    loginRequest.cpp \
    loginView.cpp \
    main.cpp \
    mainwindow.cpp \
    networkManage.cpp \
    projectDataRequest.cpp \
    projectView.cpp \
    projectsListRequest.cpp \
    projectsListView.cpp \
    setProjectNameRequest.cpp

HEADERS += \
    downloadImageRequest.h \
    httpRequest.h \
    loginRequest.h \
    loginView.h \
    mainwindow.h \
    networkManage.h \
    projectDataRequest.h \
    projectView.h \
    projectsListRequest.h \
    projectsListView.h \
    setProjectNameRequest.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    img/check_act.jpeg
