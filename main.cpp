#include "QTCrypto.h"
#include "HashGestion.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTCrypto w;
    w.show();
    HashGestion* sha = new HashGestion();
    std::cout << sha->CalculateSHA256("jad") << std::endl;


    return a.exec();


}
