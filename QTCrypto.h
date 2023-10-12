#ifndef QTCRYPTO_H
#define QTCRYPTO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class QTCrypto; }
QT_END_NAMESPACE

class QTCrypto : public QMainWindow
{
    Q_OBJECT

public:
    QTCrypto(QWidget *parent = nullptr);
    ~QTCrypto();

private:
    Ui::QTCrypto *ui;
};
#endif // QTCRYPTO_H
