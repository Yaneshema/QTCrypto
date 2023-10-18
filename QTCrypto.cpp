#include "QTCrypto.h"
#include "ui_QTCrypto.h"
#include "AesGestion.h"
#include "RsaGestion.h"

#include <iostream>
#include <filesystem>

#include <QFileDialog>
#include <QDateTime>
#include <QTimer>
#include <QClipboard>
#include <QDesktopServices>

using namespace std;
namespace fs = filesystem;

QTCrypto::QTCrypto(QWidget *parent) : QMainWindow(parent), ui(new Ui::QTCrypto)
{


    ui->setupUi(this);
    AesGestion aes;
    RsaGestion rsa;
    HashGestion sha;

    ui->mode->setValue(0);
    ui->copy->hide();

    setWindowTitle("Encryption Tool");

}

QTCrypto::~QTCrypto()
{
    delete ui;
}

void QTCrypto::on_aesSave_clicked()
{
    QString input = ui->aesFile->text();
    string file = input.toStdString();
    aes.SaveAESKeyToFile("C:/Users/SNIR_admin/Documents/QTCrypto/DB/Keys/AES/" + file);
}

void QTCrypto::on_aesLoad_clicked()
{
    QString input = ui->aesFile->text();
    string file = input.toStdString();
    aes.LoadAESKeyFromFile("C:/Users/SNIR_admin/Documents/QTCrypto/DB/Keys/AES/" + file);
}

void QTCrypto::on_file_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Select a file to encrypt"),"/home", tr("Any file (*)"));
    ui->encryptInput->setText(path);
}

void QTCrypto::on_aesGenerate_clicked()
{
    aes.GenerateAESKey();
}

void QTCrypto::on_encrypt_clicked()
{



        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString formattedDate = currentDateTime.toString("ddMMyyhhmmss");

        QString input = ui->encryptInput->text();
        string str = input.toStdString();
        size_t file = str.find_last_of("/\\");
        string filename = str.substr(file + 1);

        size_t encryptedPos = filename.find("_encrypted");
        filename = filename.substr(0, encryptedPos);

        switch(this->mode) {

        case 0:

            aes.EncryptFileAES256(str, "C:/Users/SNIR_admin/Documents/QTCrypto/DB/Encrypt/AES/" + filename + "_encrypted_" + formattedDate.toStdString());
            break;

        case 1:

            rsa.chiffrementFichier(str, "C:/Users/SNIR_admin/Documents/QTCrypto/DB/Encrypt/RSA/" + filename + "_encrypted_" + formattedDate.toStdString(), 0);
            break;
        }
}

void QTCrypto::on_Decrypt_clicked()
{

        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString formattedDate = currentDateTime.toString("ddMMyyhhmmss");

        QString input = ui->encryptInput->text();
        string str = input.toStdString();
        size_t file = str.find_last_of("/\\");
        string filename = str.substr(file + 1);

        size_t encryptedPos = filename.find("_encrypted");
        filename = filename.substr(0, encryptedPos);

        switch(this->mode) {

        case 0:

            aes.DecryptFileAES256(str, "C:/Users/SNIR_admin/Documents/QTCrypto/DB/Decrypt/AES/" + filename + "_decrypted_" + formattedDate.toStdString());
            break;

        case 1:

           rsa.dechiffrementFichier(str, "C:/Users/SNIR_admin/Documents/QTCrypto/DB/Decrypt/RSA/" + filename + "_decrypted_" + formattedDate.toStdString(), 0);
           break;
        }
}

/***************************************************/

void QTCrypto::on_rsaGenerate_clicked()
{
    string filename = (ui->rsaFile->text()).toStdString();
    rsa.generationClef("C:/Users/SNIR_admin/Documents/QTCrypto/DB/Keys/RSA/" + filename + "_public", "C:/Users/SNIR_admin/Documents/QTCrypto/DB/Keys/RSA/" + filename + "_private", 1024);
}

void QTCrypto::on_rsaLoad_pub_clicked()
{
    QString input = ui->rsaFile->text();
    string file = input.toStdString();
    cout << "C:/Users/SNIR_admin/Documents/QTCrypto/DB/Keys/RSA/" + file << endl;
    rsa.chargementClefsPublic("C:/Users/SNIR_admin/Documents/QTCrypto/DB/Keys/RSA/" + file);
}

void QTCrypto::on_rsaLoad_pri_clicked()
{
    QString input = ui->rsaFile->text();
    string file = input.toStdString();
    rsa.chargementClefsPrive("C:/Users/SNIR_admin/Documents/QTCrypto/DB/Keys/RSA/" + file);
}

void QTCrypto::on_mode_valueChanged(int value)
{
    this->mode = value;
}

void QTCrypto::on_hash_clicked()
{
    QString input = QFileDialog::getOpenFileName(this, tr("Select a file to calculate hash"),"/home", tr("Any file (*)"));
    string Input = input.toStdString();
    string hash = sha.CalculateFileSHA256(Input);
    QString Hash = QString::fromStdString(hash);

    ui->result->setText(Hash);
}

void QTCrypto::on_clipboard_clicked()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    QString originalText = clipboard->text();

    clipboard->setText(ui->result->text());

    ui->copy->show();

    QTimer::singleShot(1000, this, &QTCrypto::hideLabel);
}

void QTCrypto::hideLabel() {

    ui->copy->hide();
}

void QTCrypto::on_database_clicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/SNIR_admin/Documents/QTCrypto/DB"));
}

