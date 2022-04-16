#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "GHexacell.h"
#include "GMarble.h"

#include "abalone.observer/Observer.h"
#include "abalone.model/Board.h"
#include "abalone.model/Marble.h"
//#include "abalone.controller/Controller.h"

QT_BEGIN_NAMESPACE
namespace abalone::controller { class Controller; }
QT_END_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

//class Scene;

namespace abalone::view {

class View : public QMainWindow, public nvs::Observer{
    Q_OBJECT

private slots:
    void on_gmarble_clicked(std::string value);
    void on_ghexacell_clicked(std::string value);

private:
    //attribut
    abalone::controller::Controller * _controller;

    QGraphicsScene * _scene;

    QGraphicsView * _view;

    Ui::View * ui;

    std::vector<GHexaCell *> _gHexaCells;

    std::vector<GMarble *> _gMarbles;

    std::array<abalone::model::Marble, 28> _marbles;

    std::vector<abalone::model::Position> _positions;

    //méthodes
    void registerMarble(int x, int y);

    void registerMove(int x, int y);

    void updateMarble();

    void initGHexacells();

    void initMarbles();

public:
    explicit View(QWidget *parent = nullptr);
    ~View();

    void controller(abalone::controller::Controller * controller);

    void displayMessage(const std::string & msg);

    void displayError(const std::string & msg);

    void update(const nvs::Subject * subject) override;

protected:
    void paintEvent(QPaintEvent * event) override;

    void keyPressEvent(QKeyEvent * event) override;

};

}
#endif // VIEW2_H
