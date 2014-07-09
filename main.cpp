#include <QApplication>
#include "convert.h"

int main(int argc, char **argv)
{
QApplication app(argc, argv);
convert widget;
widget.show();
return app.exec();
}
