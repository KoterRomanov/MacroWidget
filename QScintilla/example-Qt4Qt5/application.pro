CONFIG      += qscintilla2

HEADERS      = mainwindow.h
SOURCES      = main.cpp mainwindow.cpp
RESOURCES    = application.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Qt4Qt5/release/ -lqscintilla2_qt5
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Qt4Qt5/debug/ -lqscintilla2_qt5

INCLUDEPATH += $$PWD/../Qt4Qt5/release
DEPENDPATH += $$PWD/../Qt4Qt5/release
