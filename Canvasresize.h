#ifndef  CANVASSIZE
#define CANVASSIZE



#include <QtWidgets>
#include <Canvas.h>
class Canvassize : public QWidget
{
    Q_OBJECT
public:
    Canvassize(Canvas *canvas );
    static int getLongueur();
    static int getHauteur();



public slots:
    void good();
    void getL(QString lLine);
    void getH(QString hLine);

private:
    static int l;
    static int h;
    QLineEdit *longL;
    QLineEdit *hl;
    QPushButton *OK;



};

#endif
