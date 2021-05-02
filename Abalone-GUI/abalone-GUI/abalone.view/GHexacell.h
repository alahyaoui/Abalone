#ifndef GHEXACELL_H
#define GHEXACELL_H

#include <QGraphicsPolygonItem>
#include <QObject>

/*
 * forward declaration.
 * put include in cpp file not in .h file
 */
class QPainter;
class QPointF;
class QStyleOptionGraphicsItem;
class QWidget;
class QGraphicsSceneMouseEvent;

/**
 * @brief The GHexaCell class.
 * represent an hexagon at position x,y and with a "value". this
 * value is emited on click.
 *
 * inherit from QObject to have capability of sending signal.
 */
class GHexaCell : public QObject, public QGraphicsPolygonItem{

    Q_OBJECT

protected:
    double _x, _y; // coordinates of center
    std::string _value; // some value to emit (e.g. abapro position)

public:
    explicit GHexaCell(double x, double y,
                       std::string value,
                       QGraphicsPolygonItem * parent = nullptr);
    inline double x() const;
    inline double y() const ;

    /*
     * how can I what method rewrite ?
     * first because is in abs poc… and in doc
     * see https://doc.qt.io/qt-5/qgraphicspolygonitem.html#paint
     */
    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option,
               QWidget * widget);

protected:
public:
    /*
     * Capture mouse press event. ghexacell is now clickable.
     * see https://www.learnqt.guide/events/working-with-events/
     */
     void mousePressEvent(QGraphicsSceneMouseEvent * event);

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
double GHexaCell::x() const{
    return _x;
}

double GHexaCell::y() const{
    return _y;
}

#endif // GHEXACELL_H
