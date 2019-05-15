#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>

namespace Ui {
class MainForm;
}

class MainForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = nullptr);
    ~MainForm();

private slots:
    void on_sliderThreads_valueChanged(int value);
    void on_sliderIterations_valueChanged(int value);
    void on_sliderZoom_valueChanged(int value);


private:
    Ui::MainForm *ui;
};

#endif // MAINFORM_H
