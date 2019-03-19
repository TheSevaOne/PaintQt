#ifndef HEADER
#define HEADER

#include <QtWidgets>
#include <QPushButton>
#include <QColor>


class Connectors : public QMainWindow
{

   Q_OBJECT

public:

    Connectors();
    bool getDrawEnable();
    bool getRectangleEnable();
    bool getCercleEnable();
    bool getLineEnable();
    bool getFillEnable();
    QColor getColour();
    int getVeleurSlider();

 void setColor(const QColor& color );
public slots :

    void slotDraw();
    void slotRectangle();
    void slotCercle();
    void slotLine();
    void slotFill();
    void slotColour();
    void slotSlider(int x);
    void updateColor();
    void changeColor();
private:
    bool buttonRec;
    bool drawEnable;
    bool rectangleEnable;
    bool cercleEnable;
    bool LineEnable;
    bool FillEnable;
    int Slider;
    QColorDialog *colorselect;
    QColor colour;
    QPushButton *buttond;
    QPushButton *b3;
    QPushButton *b6;
    QPushButton *b5;
     QPushButton *b4;
     QPushButton *b2;
QScrollArea *d;
};

#endif
