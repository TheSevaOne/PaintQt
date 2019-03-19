
#ifndef CANVAS
#define CANVAS
#include <QtWidgets>
#include <Connectors.h>


#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QRgb>
class Coord{
public:
    Coord(int a,int b) : x(a),y(b) {}
    ~Coord();
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

private:
    int x;
    int y;
};

class Canvas : public QWidget

{
 Q_OBJECT

public :

    Canvas(Connectors *p);
    Connectors *c;
    void draw();
    void drawRectangle();
    void drawProvisoirRectangle();
    void drawCercle();
    void drawProvisoirCercle();
    void drawLine();
    void drawProvisoirTrait();
    void Back();
    int Algo(int x,int y,QRgb colcible, QRgb colrep);

    void paintEvent(QPaintEvent* event);

    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
public slots:
    void newcanvas();
    void SavePic();
    void Backcanvas();

private :

    int xMove;
    int yMove;
    int xPress;
    int yPress;
    int xRelease;
    int yRelease;

    int pixActual;
    int xMax;
    int yMax;

    QPainter *painter;
    QLabel*label;
    Connectors *pere;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QImage *image;
    QVector<QPixmap*> pixmapList;
    QPainterPath *path;

};

#endif
