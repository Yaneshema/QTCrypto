#include "QTCrypto.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTCrypto w;
    w.show();
    return a.exec();
}
