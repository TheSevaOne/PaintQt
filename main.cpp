#include <QtWidgets>
#include <Connectors.h>
#include <QScrollArea>
#include <Canvas.h>
#include <QSize>
int main(int argc, char *argv[])

{
    QApplication app(argc,argv);
    Connectors mainWindow;

    mainWindow.setWindowTitle("PaintQt");

   //QSize D = QSize (1920,1080);
    //mainWindow.setFixedSize(D);






    mainWindow.show();

    return app.exec();


}
