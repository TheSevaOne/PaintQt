#include "Canvasresize.h"


int Canvassize::l = 500;
int Canvassize::h = 500;

Canvassize::Canvassize(Canvas *canevas) : QWidget()
{

    QVBoxLayout *layout = new QVBoxLayout(this);
    longL= new QLineEdit;
    hl = new QLineEdit;
    QFormLayout *can = new QFormLayout;

    can->addRow("X",longL);
    can->addRow("Y",hl);


    OK = new QPushButton("OK");
    layout->addLayout(can);
    layout->addWidget(OK);
    connect(OK,SIGNAL(clicked(bool)),canevas,SLOT(newcanvas()));
    connect(longL,SIGNAL(textChanged(QString)),this,SLOT(getL(QString)));
    connect(hl,SIGNAL(textChanged(QString)),this,SLOT(getH(QString)));
connect(OK,SIGNAL(clicked(bool)),this,SLOT(close()));
}

void Canvassize::good()
{

    this->show();

}

void Canvassize::getL(QString lLine)
{
    l = lLine.toInt();
}
void Canvassize::getH(QString hLine)
{
    h= hLine.toInt();
}

int Canvassize::getLongueur()
{
    return l;
}

int Canvassize::getHauteur()
{
    return h;
}
