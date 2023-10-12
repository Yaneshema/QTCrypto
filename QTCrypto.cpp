#include "QTCrypto.h"
#include "ui_QTCrypto.h"

QTCrypto::QTCrypto(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QTCrypto)
{
    ui->setupUi(this);
}

QTCrypto::~QTCrypto()
{
    delete ui;
}

