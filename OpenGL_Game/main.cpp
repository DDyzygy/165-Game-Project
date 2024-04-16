#include <QApplication>
#include "window.h"

int main(int argc, char **argv)
{
    // Keep
    QApplication app(argc, argv);

    window w;

    w.show();


    // Keep
    return app.exec();
}
