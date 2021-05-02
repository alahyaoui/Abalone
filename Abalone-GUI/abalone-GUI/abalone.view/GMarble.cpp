#include "GMarble.h"

#include "abalone.model/Color.hpp"

#include <cmath>

#include <QPainter>
#include <QPointF>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

#include <QMouseEvent>

GMarble::GMarble(double x, double y, abalone::model::Color color,
                 std::string value,
                 QGraphicsEllipseItem * parent)
    : QGraphicsEllipseItem (parent),
      _x { x },
      _y { y },
      _color {color},
      _value { value }
{
    setRect(_x -25, _y - 25, 55, 55);
}


void GMarble::paint(QPainter * painter,
                    [[maybe_unused]] const QStyleOptionGraphicsItem * option,
[[maybe_unused]] QWidget * widget)
{
    QPen pen(Qt::black, 1);
    painter->setPen(pen);
    QBrush brush;

    if(_color == abalone::model::Color::WHITE){
        brush.setColor(Qt::white);
    }else{
        brush.setColor(Qt::black);
    }

    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);

    painter->drawEllipse(this->rect());
    //painter->drawEllipse(QPoint (_x, _y), 25, 25);
}

QRectF GMarble::boundingRect () const {
    return this->rect();
}

void GMarble::mousePressEvent(QGraphicsSceneMouseEvent * event){
    QGraphicsItem::mousePressEvent(event);
    if(!event->isAccepted()) {
        if(event->button() == Qt::LeftButton) {
            qDebug() << "receive mouse event on Marble, emit signal";
            event->accept();
            emit sendValue(_value);
        } //else if(event->button() == Qt::RightButton) {

        //}
    }
}

