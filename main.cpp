#include "QTCrypto.h"
#include "AesGestion.h"

#include <QApplication>
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    QTCrypto w;
    w.show();

    string DB[] = {"DB", "DB/Encrypt", "DB/Decrypt", "DB/Keys", "DB/Encrypt/AES", "DB/Encrypt/RSA", "DB/Decrypt/AES", "DB/Decrypt/RSA", "DB/Keys/AES", "DB/Keys/RSA"};
    int DB_length = sizeof(DB)/sizeof(*DB);

    for (int i = 0; i < DB_length; i++) {

        cout << DB[i] << endl;
        fs::create_directories("C:/Users/SNIR_admin/Documents/QTCrypto/" + DB[i]);
    }

    return a.exec();
}
