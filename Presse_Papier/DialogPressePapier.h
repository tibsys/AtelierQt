#ifndef DIALOGPRESSEPAPIER_H
#define DIALOGPRESSEPAPIER_H

#include <QDialog>

namespace Ui {
class DialogPressePapier;
}

class DialogPressePapier : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPressePapier(QWidget *parent = 0);
    ~DialogPressePapier();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::DialogPressePapier *ui;
};

#endif // DIALOGPRESSEPAPIER_H
