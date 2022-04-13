#include "ui_widget.h"
#include <QtDebug>

widget::widget(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
