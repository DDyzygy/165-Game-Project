#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class window : public QWidget
{
    Q_OBJECT
public:
    explicit window(QWidget *parent = nullptr);

signals:
};

#endif // WINDOW_H
