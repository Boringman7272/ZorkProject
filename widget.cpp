#include "widget.h"

widget::widget(QWidget *parent)
    : QWidget(parent),
     ui(new Ui::Widget)
{
    ui ->setupUi(this);
}
void widget::Widget()

Widget:~Widget()
{
    delete ui;
}
