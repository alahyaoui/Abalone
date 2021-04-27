#include "View.h"
#include "ui_View.h"

#include <cmath>
#include <iostream>

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "abalone.model/Game.h"
#include "abalone.model/Position.h"


View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View),
    _gHexaCells {},
    _controller {nullptr},
    _board {},
    _marbles {},
    _positions{}
{
    ui->setupUi(this);

    initGHexacells();

    auto scene = new QGraphicsScene();

    std::for_each(begin(_gHexaCells), end(_gHexaCells),
                  [this, scene](GHexaCell * e) {
        e->setPos(e->y(), e->x());
        scene->addItem(e);
        QObject::connect(e,
                         SIGNAL(sendValue(std::string)),
                         this,
                         SLOT(on_ghexacell_clicked(std::string)));
    });
    auto view = new QGraphicsView(scene);
    view->update();
    ui->verticalLayout->addWidget(view);

    /* connect in for_each
    QObject::connect(_gHexaCells[0], SIGNAL(sendValue(std::string)),
                     this, SLOT(on_ghexacell_clicked(std::string)));
    */
}

View::~View(){
    delete ui;
}

void View::on_ghexacell_clicked(std::string value){
    ui->label->setText(value.c_str());

    int x = value[0] - '0';
    int y = value[1] - '0';

    _positions.push_back(Position(x, y));
    if( _positions.size() == 2){
        if(_positions.at(0).x() != _positions.at(1).x()){
            _controller->tryMove(_positions);//tryRegularMove(_positions);
            _positions.clear();
        }
    }else if(_positions.size() == 3){
        _controller->tryMove(_positions);//tryLateralMove(_positions);
        _positions.clear();
    }

    std::string s = "receveive value from ghexacell ";
    s.append(value);
    qDebug() << s.c_str();
}

void View::controller(abalone::controller::Controller * controller){
    this->_controller = controller;
}

void View::update(const nvs::Subject * subject){
    abalone::model::Game * game = (abalone::model::Game*) subject;

    _board = game->board();

    _turn = game->currentRound();

    for(size_t i = 0; i < _marbles.size(); i++){
        _marbles.at(i) = *game->marbles().at(i);
    }

    //_marbles = game->marbles();

    _playerMarblesLoss = game->currentPlayerMarblesLoss();
}

void View::displayMessage(std::string msg){
    ui->label->setText(msg.c_str());
}

void View::displayError(std::string msg){
    ui->label->setText(msg.c_str());
}

void View::initGHexacells(){

    //Ligne 1
    _gHexaCells.push_back(new GHexaCell(0, 0, "00", nullptr));
    _gHexaCells.push_back(new GHexaCell(0, sqrt(3) * 50, "01", nullptr));
    _gHexaCells.push_back(new GHexaCell(0, sqrt(3) * 100, "02", nullptr));
    _gHexaCells.push_back(new GHexaCell(0, sqrt(3) * 150, "03", nullptr));
    _gHexaCells.push_back(new GHexaCell(0, sqrt(3) * 200, "04", nullptr));

    //Ligne 2
    _gHexaCells.push_back(new GHexaCell(2 * 50 * 3 / 4, - sqrt(3) * 50 / 2, "10", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 50 * 3 / 4, sqrt(3) * 50 / 2, "11", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 50 * 3 / 4, sqrt(3) * 150 / 2, "12", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 50 * 3 / 4, sqrt(3) * 250 / 2, "13", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 50 * 3 / 4, sqrt(3) * 350 / 2, "14", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 50 * 3 / 4, sqrt(3) * 450 / 2, "15", nullptr));

    //Ligne 3
    _gHexaCells.push_back(new GHexaCell(2 * 100 * 3 / 4, - sqrt(3) * 50 , "20", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 100 * 3 / 4, - sqrt(3) * 0 , "21", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 100 * 3 / 4, sqrt(3) * 50, "22", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 100 * 3 / 4, sqrt(3) * 100 , "23", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 100 * 3 / 4, sqrt(3) * 150, "24", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 100 * 3 / 4, sqrt(3) * 200 , "25", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 100 * 3 / 4, sqrt(3) * 250 , "26", nullptr));

    //Ligne 4
    _gHexaCells.push_back(new GHexaCell(2 * 150 * 3 / 4, - sqrt(3) * 150 / 2, "30", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 150 * 3 / 4, - sqrt(3) * 50 / 2, "31", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 150 * 3 / 4, sqrt(3) * 50 / 2, "32", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 150 * 3 / 4, sqrt(3) * 150 / 2, "33", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 150 * 3 / 4, sqrt(3) * 250 / 2, "34", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 150 * 3 / 4, sqrt(3) * 350 / 2, "35", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 150 * 3 / 4, sqrt(3) * 450 / 2, "36", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 150 * 3 / 4, sqrt(3) * 550 / 2, "37", nullptr));


    //Ligne 5
    _gHexaCells.push_back(new GHexaCell(2 * 200 * 3 / 4, - sqrt(3) * 100 , "40", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 200 * 3 / 4, - sqrt(3) * 50, "41", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 200 * 3 / 4, sqrt(3) * 0, "42", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 200 * 3 / 4, sqrt(3) * 50, "43", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 200 * 3 / 4, sqrt(3) * 100 , "44", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 200 * 3 / 4, sqrt(3) * 150, "45", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 200 * 3 / 4, sqrt(3) * 200 , "46", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 200 * 3 / 4, sqrt(3) * 250 , "47", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 200 * 3 / 4, sqrt(3) * 300 , "48", nullptr));

    //Ligne 6
    _gHexaCells.push_back(new GHexaCell(2 * 250 * 3 / 4, - sqrt(3) * 150 / 2, "50", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 250 * 3 / 4, - sqrt(3) * 50 / 2, "51", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 250 * 3 / 4, sqrt(3) * 50 / 2, "52", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 250 * 3 / 4, sqrt(3) * 150 / 2, "53", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 250 * 3 / 4, sqrt(3) * 250 / 2, "54", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 250 * 3 / 4, sqrt(3) * 350 / 2, "55", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 250 * 3 / 4, sqrt(3) * 450 / 2, "56", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 250 * 3 / 4, sqrt(3) * 550 / 2, "57", nullptr));

    //Ligne 7
    _gHexaCells.push_back(new GHexaCell(2 * 300 * 3 / 4, - sqrt(3) * 50 , "60", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 300 * 3 / 4, - sqrt(3) * 0 , "61", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 300 * 3 / 4, sqrt(3) * 50, "62", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 300 * 3 / 4, sqrt(3) * 100 , "63", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 300 * 3 / 4, sqrt(3) * 150, "64", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 300 * 3 / 4, sqrt(3) * 200 , "65", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 300 * 3 / 4, sqrt(3) * 250 , "66", nullptr));

    //Ligne 8
    _gHexaCells.push_back(new GHexaCell(2 * 350 * 3 / 4, - sqrt(3) * 50 / 2, "70", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 350 * 3 / 4, sqrt(3) * 50 / 2, "71", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 350 * 3 / 4, sqrt(3) * 150 / 2, "72", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 350 * 3 / 4, sqrt(3) * 250 / 2, "73", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 350 * 3 / 4, sqrt(3) * 350 / 2, "74", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 350 * 3 / 4, sqrt(3) * 450 / 2, "75", nullptr));

    //Ligne 9
    _gHexaCells.push_back(new GHexaCell(2 * 400 * 3 / 4, 0, "80", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 400 * 3 / 4, sqrt(3) * 50, "81", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 400 * 3 / 4, sqrt(3) * 100, "82", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 400 * 3 / 4, sqrt(3) * 150, "83", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 400 * 3 / 4, sqrt(3) * 200, "84", nullptr));
}
