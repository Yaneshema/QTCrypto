#ifndef QTCRYPTO_H
#define QTCRYPTO_H

#include <QMainWindow>
#include "AesGestion.h"
#include "RsaGestion.h"
#include "HashGestion.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QTCrypto; }
QT_END_NAMESPACE

class QTCrypto : public QMainWindow
{
    Q_OBJECT

public:
    QTCrypto(QWidget *parent = nullptr);
    ~QTCrypto();
    AesGestion aes;
    RsaGestion rsa;
    HashGestion sha;
    int mode;

private slots:

    void on_aesSave_clicked();

    void on_aesLoad_clicked();

    void on_aesGenerate_clicked();

    void on_encrypt_clicked();

    void on_file_clicked();

    void on_Decrypt_clicked();

    void on_rsaGenerate_clicked();

    void on_rsaLoad_pub_clicked();

    void on_rsaLoad_pri_clicked();

    void on_mode_valueChanged(int value);

    void on_hash_clicked();

    void on_clipboard_clicked();

    void hideLabel();

private:
    Ui::QTCrypto *ui;
};
#endif // QTCRYPTO_H
