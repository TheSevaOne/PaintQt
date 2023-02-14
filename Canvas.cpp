#include "Connectors.h"
#include "Canvas.h"
#include "Canvasresize.h"
#include <QRadioButton>
#include <QColorDialog>
#include <QtWidgets/QColorDialog>
#include <QtGui/QPainter>
#include <QGridLayout>
#include <QtCore/QMimeData>
#include <QtGui/QDragEnterEvent>
#include <QtGui/QDrag>
#include <QtWidgets/QApplication>
#include <iostream>
#include <QLabel>
#include <QMenu>
#include <QSize>
#include <QLabel>
#include <QIcon>
#include <QHBoxLayout>
#include <QScrollArea>


Canvas::Canvas(Connectors *p) : QWidget()
{xMax = 800;
    yMax = 800;
    pere = p;


    pixmapList.push_back(new QPixmap(xMax,yMax));
    pixActual = pixmapList.size()-1;
    pixmapList[pixActual]->fill();
    painter = new QPainter(pixmapList[pixActual]);
QSize y = QSize(xMax,yMax);


    label = new QLabel(this);

   label->setPixmap(*pixmapList[pixActual]);
  this->setFixedSize(pixmapList[pixActual]->size());




}






void Canvas::paintEvent(QPaintEvent *event)
{


}


void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if(pere->getDrawEnable())
    {
        xMove = event->pos().x();
        yMove = event->pos().y();
        draw();


    }
    if(pere->getRectangleEnable())
    {
        xMove = event->pos().x();
        yMove = event->pos().y();
        drawProvisoirRectangle();
    }
    if(pere->getCercleEnable())
    {
        xMove = event->pos().x();
        yMove = event->pos().y();
        drawProvisoirCercle();
    }
    if(pere->getLineEnable())
    {
        xMove = event->pos().x();
        yMove = event->pos().y();
        drawProvisoirTrait();
    }

}
void Canvas::mousePressEvent(QMouseEvent* event)
{
    if(pere->getRectangleEnable()||pere->getCercleEnable()
            ||pere->getFillEnable()||pere->getLineEnable())
    {
        xPress = event->pos().x();
        yPress = event->pos().y();

    }
    if(pere->getDrawEnable())
    {
        pixmapList.push_back(new QPixmap(xMax,yMax));
        pixActual = pixActual+1;
        pixmapList[pixActual]->operator =(*pixmapList[pixActual-1]);
        painter->end();
        delete painter;
        painter = new QPainter(pixmapList[pixActual]);
    }
    if(pere->getDrawEnable())
    {
        xPress = event->pos().x();
        yPress = event->pos().y();
        path = new QPainterPath(QPointF(xPress,yPress));
        path->moveTo(xPress,yPress);
    }

}
void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    if(pere->getRectangleEnable())
    {
        xRelease = event->pos().x();
        yRelease = event->pos().y();
        drawRectangle();

    }
    if(pere->getCercleEnable())
    {
        xRelease = event->pos().x();
        yRelease = event->pos().y();
        drawCercle();

    }
    if(pere->getLineEnable())
    {
        xRelease = event->pos().x();
        yRelease = event->pos().y();
        drawLine();

    }
    if(pere->getFillEnable())
    {
        xRelease = event->pos().x();
        yRelease = event->pos().y();
        Back();

    }
    if(pere->getDrawEnable())
    {
        delete path;
    }

}
void Canvas::draw()
{
    QPen pen;

    path->lineTo(xMove,yMove);
    pen.setColor(pere->getColour());
    pen.setWidth(pere->getVeleurSlider());
    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawPath(*path);

    label->setPixmap(*pixmapList[pixActual]);
}
void Canvas::drawRectangle()
{
    QPen pen;
    pen.setColor(pere->getColour());
    pen.setWidth(pere->getVeleurSlider());

    pixmapList.push_back(new QPixmap(xMax,yMax));
    pixActual = pixActual+1;
    pixmapList[pixActual]->operator =(*pixmapList[pixActual-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapList[pixActual]);

    painter->setPen(pen);
    painter->drawRect(xPress,yPress,xRelease-xPress,yRelease-yPress);

    label->setPixmap(*pixmapList[pixActual]);
}
void Canvas::drawProvisoirRectangle()
{
    QPen pen;
    pen.setColor(pere->getColour());
    pen.setWidth(pere->getVeleurSlider());

    pixmapList.push_back(new QPixmap(xMax,yMax));
    pixActual = pixActual+1;
    pixmapList[pixActual]->operator =(*pixmapList[pixActual-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapList[pixActual]);

    painter->setPen(pen);
    painter->drawRect(xPress,yPress,xMove-xPress,yMove-yPress);
    label->setPixmap(*pixmapList[pixActual]);
    pixmapList.remove(pixActual);
    pixActual = pixmapList.size()-1;
}

void Canvas::drawCercle()
{
    QPen pen;
    pen.setColor(pere->getColour());
    pen.setWidth(pere->getVeleurSlider());

    pixmapList.push_back(new QPixmap(xMax,yMax));
    pixActual = pixActual+1;
    pixmapList[pixActual]->operator =(*pixmapList[pixActual-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapList[pixActual]);

    painter->setPen(pen);
    painter->drawEllipse(xPress,yPress,xRelease-xPress,yRelease-yPress);
    label->setPixmap(*pixmapList[pixActual]);


}
void Canvas::drawProvisoirCercle()
{
    QPen pen;
    pen.setColor(pere->getColour());
    pen.setWidth(pere->getVeleurSlider());

    pixmapList.push_back(new QPixmap(xMax,yMax));
    pixActual = pixActual+1;
    pixmapList[pixActual]->operator =(*pixmapList[pixActual-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapList[pixActual]);

    painter->setPen(pen);
    painter->drawEllipse(xPress,yPress,xMove-xPress,yMove-yPress);
    label->setPixmap(*pixmapList[pixActual]);
    pixmapList.remove(pixActual);
    pixActual = pixmapList.size()-1;
}

void Canvas::drawLine()
{
    QPen pen;
    pen.setColor(pere->getColour());
    pen.setWidth(pere->getVeleurSlider());

    pixmapList.push_back(new QPixmap(xMax,yMax));
    pixActual = pixActual+1;
    pixmapList[pixActual]->operator =(*pixmapList[pixActual-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapList[pixActual]);

    painter->setPen(pen);
    painter->drawLine(xPress,yPress,xRelease,yRelease);
    label->setPixmap(*pixmapList[pixActual]);

}
void Canvas::drawProvisoirTrait()
{
    QPen pen;
    pen.setColor(pere->getColour());
    pen.setWidth(pere->getVeleurSlider());

    pixmapList.push_back(new QPixmap(xMax,yMax));
    pixActual = pixActual+1;
    pixmapList[pixActual]->operator =(*pixmapList[pixActual-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapList[pixActual]);

    painter->setPen(pen);
    painter->drawLine(xPress,yPress,xMove,yMove);
    label->setPixmap(*pixmapList[pixActual]);
    pixmapList.remove(pixActual);
    pixActual = pixmapList.size()-1;
}
///заливка
void Canvas::Back()
{
    painter->end();
    delete painter;
    QRgb couleurCible,couleurReproduit;
    QColor couleurBuff;

    pixmapList.push_back(new QPixmap(xMax,yMax));
    pixActual = pixActual+1;
    pixmapList[pixActual]->operator =(*pixmapList[pixActual-1]);


    image = new QImage(xMax,yMax,QImage::Format_RGB32);
    *image = pixmapList[pixActual]->toImage();
    couleurCible = image->pixel(xPress,yPress);
    couleurReproduit = pere->getColour().rgb();
    Algo(xPress,yPress,couleurCible,couleurReproduit);




    pixmapList[pixActual]->convertFromImage(*image);
    painter = new QPainter(pixmapList[pixActual]);

    delete image;


    label->setPixmap(*pixmapList[pixActual]);
}
//Алгоритм для рисованя
int Canvas::Algo(int x,int y,QRgb colcible, QRgb colrep)
{
    int a,b,i;
    int lastPosition;
    QVector<Coord*> listPosition;

    if(image->pixel(x,y)!= colcible)
    {
        return 1;
    }
    if(x<0||y<0||x>(xMax-1)||y>(yMax-1)||colcible==colrep)
    {
        return 0;
    }

    listPosition.push_back(new Coord(x,y));

    while(listPosition.empty()==0)
    {


        a = listPosition[listPosition.size()-1]->getX();
        b = listPosition[listPosition.size()-1]->getY();

        if(a==1||b==1||a==(xMax-1)||b==(yMax-1))
        {
            for(i=0;i<xMax;i++)
            {
               image->setPixel(i,0,colrep);
               image->setPixel(i,yMax-1,colrep);
            }
            for(i=0;i<yMax;i++)
            {
               image->setPixel(0,i,colrep);
               image->setPixel(xMax-1,i,colrep);
            }
        }
        lastPosition = listPosition.size()-1;
        listPosition.remove(lastPosition);

        image->setPixel(a,b,colrep);

        if(image->pixel(a,b-1)==colcible)
        {
            listPosition.push_back(new Coord(a,b-1));
        }

        if(image->pixel(a,b+1)==colcible)
        {
            listPosition.push_back(new Coord(a,b+1));
        }
        if(image->pixel(a+1,b)==colcible)
        {
            listPosition.push_back(new Coord(a+1,b));
        }
        if(image->pixel(a-1,b)==colcible)
        {
            listPosition.push_back(new Coord(a-1,b));
        }
    }
    return 1;
}

void Canvas::SavePic()
{
    QString fichier = QFileDialog::getSaveFileName(0, "save", QString(), "Images (*.png)");

    pixmapList[pixActual]->save(fichier);
}



void Canvas::newcanvas()
{
    painter->end();
    delete painter;
    pixmapList.erase(pixmapList.begin(),pixmapList.end());
    delete label;
    xMax = Canvassize::getLongueur();
    yMax = Canvassize::getHauteur();

    pixmapList.push_back(new QPixmap(xMax,yMax));
    pixActual = pixmapList.size()-1;
    pixmapList[pixActual]->fill();

    label = new QLabel(this);
    label->setPixmap(*pixmapList[pixActual]);



    painter = new QPainter(pixmapList[pixActual]);



 label->show();
}
void Canvas::Backcanvas()
{
    if(pixActual ==0) return;
    pixmapList.remove(pixActual);
    pixActual = pixmapList.size()-1;
    painter->end();
    delete painter;
    painter = new QPainter(pixmapList[pixActual]);
    label->setPixmap(*pixmapList[pixActual]);

}
