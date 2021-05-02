#ifndef GMARBLE_H
#define GMARBLE_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QPushButton>

/*
 * forward declaration.
 * put include in cpp file not in .h file
 */
class QPainter;
class QPointF;
class QStyleOptionGraphicsItem;
class QWidget;
class QGraphicsSceneMouseEvent;

class QMouseEvent;

namespace abalone::model{
enum class Color;
}

class GMarble : public QObject, public QGraphicsEllipseItem {

    Q_OBJECT

protected:
    double _x, _y; // coordinates of center
    abalone::model::Color _color;
    std::string _value; // some value to emit (e.g. abapro position)

public:
    explicit GMarble(double x, double y, abalone::model::Color color,
                     std::string value,
                     QGraphicsEllipseItem * parent = nullptr);

    inline double x() const;
    inline double y() const ;

    inline void value(std::string value);
    inline void color(abalone::model::Color color);

    /*
     * how can I what method rewrite ?
     * first because is in abs poc… and in doc
     * see https://doc.qt.io/qt-5/qgraphicspolygonitem.html#paint
     */
    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option,
               QWidget * widget) override;
//protected:
public:
    /*
   * Capture mouse press event. ghexacell is now clickable.
   * see https://www.learnqt.guide/events/working-with-events/
   */
   void mousePressEvent(QGraphicsSceneMouseEvent * event) override;

   QRectF boundingRect () const override;

    /*
   * #1 add signal to emit when hexagon is clicked.
   * this method must return void and is implemented by Qt.
   * To do this, class must inherit from QObject.
   */
signals:
    void sendValue(std::string value);
};

//
// inline methods
//
double GMarble::x() const{
    return _x;
}

double GMarble::y() const{
    return _y;
}

void GMarble::value(std::string value){
    this->_value = value;
}

void GMarble::color(abalone::model::Color color){
    this->_color = color;
}

#endif // GMARBLE_H
