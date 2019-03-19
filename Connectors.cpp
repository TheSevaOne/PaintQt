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
Connectors::Connectors()
{
    resize(500,500);

    drawEnable = 0;
    rectangleEnable = 0;
    cercleEnable = 0;
    LineEnable = 0;
    Slider= 1;





    Canvas *canvas = new Canvas(this);
    Canvassize *fenetretaille = new Canvassize(canvas);

// QScrollArea * scr = new QScrollArea(canvas);
//QWidget *d = new QWidget();

    QMenu *menuFichier = menuBar()->addMenu("Файл");

    QAction *actionNouveau = new QAction("Размер",this);
    menuFichier->addAction(actionNouveau);
    QAction *SavePic = new QAction("Сохранить",this);
    menuFichier->addAction(SavePic);
    d = new QScrollArea();
 d->setWidget(canvas);

 d->setWidgetResizable(true);
setCentralWidget(d);








    connect(actionNouveau,SIGNAL(triggered(bool)),fenetretaille,SLOT(good()));
    connect(SavePic,SIGNAL(triggered(bool)),canvas,SLOT(SavePic()));







    QMenu *menuOptions = menuBar()->addMenu("Еще...");


    QAction *actionRetour = new QAction("Отмена действия",this);
    actionRetour->setShortcut(QKeySequence("Ctrl+Z"));
    menuOptions->addAction(actionRetour);


    connect(actionRetour,SIGNAL(triggered(bool)),canvas,SLOT(Backcanvas()));

    QToolBar *toolBar2=addToolBar("Цвет");
     toolBar2->setOrientation(Qt::Vertical);
    addToolBar(Qt::TopToolBarArea, toolBar2);
    QPushButton *buttonClolor = new QPushButton;
    buttonClolor->setText("Цвет");


    colorselect = new QColorDialog;

    toolBar2->addWidget(buttonClolor);

    QToolBar *toolBar = addToolBar("Цвет");
    toolBar->setOrientation(Qt::Vertical);
    addToolBar(Qt::LeftToolBarArea, toolBar);


    QSize size =QSize(50,50);
    QPushButton *button6 = new QPushButton;
    b6=button6;
    button6-> setStyleSheet( "QPushButton { border-image: url(:zal2.png);}");

 button6->move(20,0);
    button6->setFixedSize(size);

    toolBar->addWidget(button6);
   connect(button6,SIGNAL(clicked(bool)),this,SLOT(slotFill()));




   QPushButton *button2 = new QPushButton;
    QPushButton *button3=new QPushButton;


//    button3->move(20,0);
    button3->setFixedSize(size);
    button3-> setStyleSheet( "QPushButton { border-image: url(:k.png);} ");
    toolBar->addWidget(button3);

   button2->setFixedSize(size);
   button2-> setStyleSheet( "QPushButton { border-image: url(:KVAD.png);}");

  toolBar->addWidget(button2);
  QPushButton *button4=new QPushButton;
  button4->setFixedSize(size);
  button4-> setStyleSheet( "QPushButton { border-image: url(:Krug.png);}");
  b4=button4;

  toolBar->addWidget(button4);

  QPushButton *button5= new QPushButton;
  button5->setFixedSize(size);
  button5-> setStyleSheet( "QPushButton { border-image: url(:line.png);} ");
  toolBar->addWidget(button5);

    connect(button3,SIGNAL(clicked(bool)),this,SLOT(slotDraw()));
    connect(button2,SIGNAL(clicked(bool)),this,SLOT(slotRectangle()));
    connect(button4,SIGNAL(clicked(bool)),this,SLOT(slotCercle()));
    connect(button5,SIGNAL(clicked(bool)),this,SLOT(slotLine()));
    b5=button5;
    b3=button3;
    b2=button2;
    QSlider *slider = new QSlider(Qt::Horizontal);

        QVBoxLayout* vbox = new QVBoxLayout();
        QSize sli =  QSize( 150,100);
        QHBoxLayout *layout = new QHBoxLayout;
        QWidget* widget = new QWidget();
     layout->addWidget(slider);
    slider->setMaximumSize(sli);
    slider->setRange(1,5);

          vbox->addWidget(slider);

          widget->setLayout(vbox);
        toolBar2->addWidget(widget);
        buttond=buttonClolor;

        buttond->setStyleSheet( " background-color: " +colour.name() );

    //connect(buttonClolor,SIGNAL(clicked(bool)),this,SLOT(slotColour()) );
     connect(buttonClolor,SIGNAL(clicked(bool)),this,SLOT( changeColor()) );

    connect(slider,SIGNAL(valueChanged(int)) ,this,SLOT(slotSlider(int)));

}




void Connectors::updateColor()
{
   buttond->setStyleSheet( " background-color: " + colour.name() );
}

void Connectors::changeColor()
{

    QColor newColor = QColorDialog::getColor(colour,parentWidget());
    if ( newColor != colour )
    {
        setColor( newColor);
    }
}

void Connectors::setColor(const QColor& colour )
{
    this->colour = colour;

    updateColor();
}




bool Connectors::getDrawEnable()
{
    return drawEnable;
}
bool Connectors::getRectangleEnable()
{
    return rectangleEnable;
}
bool Connectors::getCercleEnable()
{
    return cercleEnable;
}
bool Connectors::getLineEnable()
{
    return LineEnable;
}

bool Connectors::getFillEnable()
{
    return FillEnable;
}

QColor Connectors::getColour()
{
    return colour;
}
int Connectors::getVeleurSlider()
{
    return Slider;
}

//SLOTS
void Connectors::slotDraw()
{

    drawEnable = 1;
    rectangleEnable = 0;
    cercleEnable = 0;
    FillEnable = 0;
    LineEnable = 0;

    int state = b3->property("currentState").toInt();
   if(state == 0 && drawEnable == 0)
           {
             b3->setStyleSheet( "QPushButton { border-image: url(:k.png); }");
               b4->setProperty("currentState", 0);
           }
            else
           {

       b4->setStyleSheet( "QPushButton { border-image: url(:Krug.png); }");

 b3->setStyleSheet( "QPushButton { border-image: url(:k2.png); }");
    b2->setStyleSheet( "QPushButton { border-image: url(:KVAD.png); }");
                  b5->setStyleSheet( "QPushButton { border-image: url(:line.png); }");
                  b6->setStyleSheet( "QPushButton { border-image: url(:zal.png); }");
               b4->setProperty("currentState", 1);
           }



}
void Connectors::slotRectangle()
{
    drawEnable = 0;
    rectangleEnable = 1;
    cercleEnable = 0;
    FillEnable = 0;
    LineEnable = 0;
int state = b2->property("currentState").toInt();
       if(state == 0 && rectangleEnable == 0)
               {
                 b2->setStyleSheet( "QPushButton { border-image: url(:KVAD.png); }");
                   b2->setProperty("currentState", 0);
               } else
               {

                      b4->setStyleSheet( "QPushButton { border-image: url(:Krug.png); }");
                       b2->setStyleSheet( "QPushButton { border-image: url(:KVAD2.png); }");
                      b3->setStyleSheet( "QPushButton { border-image: url(:k.png); }");
                      b5->setStyleSheet( "QPushButton { border-image: url(:line.png); }");
                      b6->setStyleSheet( "QPushButton { border-image: url(:zal.png); }");
                   b2->setProperty("currentState", 1);
               }



    }


void Connectors::slotCercle()
{
    drawEnable = 0;
    rectangleEnable = 0;
    cercleEnable = 1;
    FillEnable = 0;
    LineEnable = 0;



    int state = b4->property("currentState").toInt();
    state=1;
   if(state == 0 && cercleEnable == 0)
           {
             b4->setStyleSheet( "QPushButton { border-image: url(:Krug.png); }");
               b4->setProperty("currentState", 0);
           } else
           {
                 b4->setStyleSheet( "QPushButton { border-image: url(:Krug2.png); }");
   b2->setStyleSheet( "QPushButton { border-image: url(:KVAD.png); }");
    b3->setStyleSheet( "QPushButton { border-image: url(:k.png); }");
                  b5->setStyleSheet( "QPushButton { border-image: url(:line.png); }");
                  b6->setStyleSheet( "QPushButton { border-image: url(:zal.png); }");
               b4->setProperty("currentState", 1);
           }
}
void Connectors::slotFill()
{
    drawEnable = 0;
    rectangleEnable = 0;
    cercleEnable = 0;
    FillEnable = 1;
    LineEnable = 0;



    int state = b6->property("currentState").toInt();

   if(state == 0 && FillEnable == 0)
           {
             b6->setStyleSheet( "QPushButton { border-image: url(:zal.png); }");
               b6->setProperty("currentState", 0);
           } else
           {
           b3->setStyleSheet( "QPushButton { border-image: url(:k.png); }");
                 b6->setStyleSheet( "QPushButton { border-image: url(:zal2.png); }");
                  b5->setStyleSheet( "QPushButton { border-image: url(:line.png); }");
                     b2->setStyleSheet( "QPushButton { border-image: url(:KVAD.png); }");
                   b4->setStyleSheet( "QPushButton { border-image: url(:Krug.png); }");
                    b6->setProperty("currentState", 1);
           }






}

void Connectors::slotLine()
{
    drawEnable = 0;
    rectangleEnable = 0;
    cercleEnable = 0;
    FillEnable = 0;
    LineEnable = 1;



    int state = b5->property("currentState").toInt();
   if(state == 0 && LineEnable== 0)
           {
             b5->setStyleSheet( "QPushButton { border-image: url(:line.png); }");
               b5->setProperty("currentState", 0);
           } else
           {           b2->setStyleSheet( "QPushButton { border-image: url(:KVAD.png); }");
                  b3->setStyleSheet( "QPushButton { border-image: url(:k.png); }");
                  b5->setStyleSheet( "QPushButton { border-image: url(:line2.png); }");
                  b4->setStyleSheet( "QPushButton { border-image: url(:Krug.png); }");
                  b6->setStyleSheet( "QPushButton { border-image: url(:zal.png); }");
                  b5->setProperty("currentState", 1);
           }







}

void Connectors::slotColour()
 {

    colour = colorselect->getColor();



}

void Connectors::slotSlider(int x)
{
    Slider = x;
}


