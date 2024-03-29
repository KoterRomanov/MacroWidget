#-------------------------------------------------
#
# Project created by QtCreator 2019-11-19T22:32:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MacroWidget
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += qscintilla2

SOURCES += \
        macro.cpp \
        macro_editor.cpp \
        macro_enable_condition.cpp \
        macro_manage.cpp \
        main.cpp \
        dialog.cpp

HEADERS += \
        dialog.h \
        macro.h \
        macro_editor.h \
        macro_enable_condition.h \
        macro_manage.h

FORMS += \
        dialog.ui \
        macroeditor.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lqscintilla2_qt5
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lqscintilla2_qt5d
else:unix: LIBS += -L$$PWD/lib/ -lqscintilla2_qt5

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
