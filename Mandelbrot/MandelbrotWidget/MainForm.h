#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include "ThreadControleur.h"

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
    void on_btnStart_clicked();
    void on_btnStop_clicked();
    //Ici le FractalPoint est copié, on pourrait optimiser cela de plusieurs façons :
    //1 - en passant une référence et non une valeur
    //2 - en utilisant la technique du copy-on-write dans le FractalPoint
    void onNouveauPoint(FractalPoint point);
    void onCalculDemarre();
    void onCalculStoppe();
    void onCalculTermine();

private:
    Ui::MainForm *ui;
    ThreadControleur *threadControleur_ = nullptr;
};

#endif // MAINFORM_H
