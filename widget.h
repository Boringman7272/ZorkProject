#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QWidget>

class widget : public QWidget
{
private:
    void Widget();

    Q_OBJECT
public:
    explicit widget(QWidget *parent = nullptr);

signals:

};

#endif // WIDGET_H
