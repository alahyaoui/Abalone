#include "GHexacell.h"

#include <cmath>

#include <QPainter>
#include <QPointF>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

GHexaCell::GHexaCell(double x, double y,
                     std::string value,
                     QGraphicsPolygonItem * parent)
    : QGraphicsPolygonItem (parent),
      _x { x }, _y { y },
      _value { value }
{
    static const double pi_over_6 = atan(1) * 4 / 6;
    // FIXME it'll be better if r is parameter.
    static const double r = 50;

    QPolygonF polygon;
    polygon << QPointF(r * cos(pi_over_6), r * sin(pi_over_6));
    polygon << QPointF(0, r);
    polygon << QPointF(-r * cos(pi_over_6), r * sin(pi_over_6));
    polygon << QPointF(-r * cos(pi_over_6), -r * sin(pi_over_6));
    polygon << QPointF(0, -r);
    polygon << QPointF(r * cos(pi_over_6), -r * sin(pi_over_6));
    setPolygon(polygon);
}


void GHexaCell::paint(QPainter * painter,
                      [[maybe_unused]] const QStyleOptionGraphicsItem * option,
[[maybe_unused]] QWidget * widget)
{
    QPen pen(Qt::black, 1);
    painter->setPen(pen);
    QBrush brush;
    brush.setColor(QColor(101, 56, 24));
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawPolygon(polygon());
}



void GHexaCell::mousePressEvent(QGraphicsSceneMouseEvent * event){
    QGraphicsItem::mousePressEvent(event);

    if(!event->isAccepted()) {
        //  if(event->button() == Qt::RightButton) {
        qDebug() << "receive mouse event on GHexacell, emit signal";
        event->accept();
        emit sendValue(_value);
        //}// else if(event->button() == Qt::LeftButton) {

        //}
    }
}

