#ifndef DIALOGTHANHTOAN_H
#define DIALOGTHANHTOAN_H

#include <QDialog>

namespace Ui {
class DialogThanhToan;
}

class DialogThanhToan : public QDialog
{
    Q_OBJECT

public:
    explicit DialogThanhToan(QWidget *parent = nullptr);
    ~DialogThanhToan();
private slots:
private:
    Ui::DialogThanhToan *ui;
};

#endif // DIALOGTHANHTOAN_H
