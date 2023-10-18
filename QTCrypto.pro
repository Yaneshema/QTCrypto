QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    QTCrypto.cpp

HEADERS += \
    QTCrypto.h

FORMS += \
    QTCrypto.ui

RESOURCES += \
    cb.png \
    fdr.png

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



win32: LIBS += -L$$PWD/libCrypt/cryptopp/x64/Output/Release/ -lcryptlib

INCLUDEPATH += $$PWD/libCrypt/cryptopp
DEPENDPATH += $$PWD/libCrypt/cryptopp

win32-g++: PRE_TARGETDEPS += $$PWD/libCrypt/cryptopp/x64/Output/Release/cryptlib.lib


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libCrypt/x64/release/ -lchiffrement1
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libCrypt/x64/debug/ -lchiffrement1

INCLUDEPATH += $$PWD/libCrypt/chiffrement1
DEPENDPATH += $$PWD/libCrypt/chiffrement1

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/libCrypt/x64/release/chiffrement1.lib
win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/libCrypt/x64/debug/chiffrement1.lib

DISTFILES += \
    fdr.png
