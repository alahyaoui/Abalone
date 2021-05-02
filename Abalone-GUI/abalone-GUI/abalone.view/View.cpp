#include "View.h"
#include "ui_View.h"

#include <cmath>
#include <iostream>

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QCursor>

#include <QStyle>
#include <QKeyEvent>
#include <QDesktopWidget>

#include "abalone.controller/Controller.h"
#include "abalone.model/Game.h"

namespace abalone::view{

View::View(QWidget *parent) :
    QMainWindow(parent),
    _controller {nullptr},
    _scene {new QGraphicsScene()},
    _view {new QGraphicsView(_scene)},
    ui {new Ui::View},
    _gHexaCells {},
    _gMarbles {},
    _marbles {},
    _positions {},
    _playerMarblesLoss {},
    _turn {}
{
    ui->setupUi((QMainWindow *) this);

    initGHexacells();
    initMarbles();

    for(auto & gHexaCell : _gHexaCells){
        int y = gHexaCell->y();
        int x = gHexaCell->x();
        gHexaCell->setPos(y, x);
        _scene->addItem(gHexaCell);
        QObject::connect(gHexaCell, SIGNAL(sendValue(std::string)),
                         this, SLOT(on_ghexacell_clicked(std::string)));
    }

    for(auto & gMarble : _gMarbles){
        gMarble->setPos(gMarble->x(), gMarble->y());
        _scene->addItem(gMarble);
        QObject::connect(gMarble, SIGNAL(sendValue(std::string)),
                         this, SLOT(on_gmarble_clicked(std::string)));
    }

    //_scene->setSceneRect(QMainWindow::iconSize());
    _view->update();
    //ui->verticalLayout->addWidget(_view);
    //ui->verticalLayout_2->addWidget(_view);
    //_view->setFixedSize(1145, 703);
    //_view->sceneRect();
    //_view->setFixedWidth(710);
    ui->myScene->addWidget(_view);
}

View::~View(){
    delete ui;
}

void View::controller(abalone::controller::Controller * controller){
    this->_controller = controller;
}

void View::paintEvent(QPaintEvent *event){
    updateMarble();
}

void View::keyPressEvent(QKeyEvent * event){
    qDebug() << "Key pressed action";

    QKeyEvent* key = static_cast<QKeyEvent*>(event);
    if((key->key() == Qt::Key_Enter || key->key() == Qt::Key_Escape)){
        ui->label->setText("Mouvement annulé.");
        _positions.clear();
    }
}

void View::registerMarble(int x, int y){
    for(auto & e : _marbles){
        if((e.positionOnBoard().x() == x && e.positionOnBoard().y() == y)){
            if( _positions.size() < 3){
                if(_positions.size() == 0){
                    _positions.push_back(Position(x, y));
                }else{
                    if(_positions.at(0).x() == x){
                        _positions.push_back(Position(x, y));
                    }else{
                        registerMove(x, y);
                    }
                }

            }
        }
    }
}

void View::registerMove(int x, int y){
    if( _positions.size() == 1){
        _positions.push_back(Position(x, y));
        _controller->tryMove(_positions);
        _positions.clear();
    }else if(_positions.size() == 2){
        _positions.push_back(Position(x, y));
        _controller->tryMove(_positions);
        _positions.clear();
    }
}

void View::on_ghexacell_clicked(std::string value){
    qDebug() << "gHexacell action";
    ui->label->setText(value.c_str());

    int x = value[0] - '0';
    int y = value[1] - '0';

    registerMove(x, y);

    std::string s = "receveive value from ghexacell ";
    s.append(value);
    qDebug() << s.c_str();
}

void View::on_gmarble_clicked(std::string value){
    qDebug() << "gMarble action";
    ui->label->setText(value.c_str());

    int x = value[0] - '0';
    int y = value[1] - '0';

    registerMarble(x, y);

    std::string s = "receveive value from gmarble ";
    s.append(value);
    qDebug() << s.c_str();
}

void View::displayMessage(std::string msg){
    ui->label->setText(msg.c_str());
}

void View::displayError(std::string msg){
    ui->label->setText(msg.c_str());
}

void View::updateMarble(){
    int offset = 0;
    for(size_t i = 0; i < _marbles.size(); i++){
        int row = _marbles.at(i).positionOnBoard().x();
        int col = _marbles.at(i).positionOnBoard().y();

        if(row != -1 && col != -1){
            if(row < 4){
                if(row == 0){
                    col -= 4;
                }else if (row == 1){
                    col -= 3;
                }else if(row == 2){
                    col -= 2;
                }else if(row == 3){
                    col -= 1;
                }
            }

            if(row == 0){
                offset = 0;
            }else if (row == 1){
                offset = -45;
            }else if(row == 2){
                offset = -85;
            }else if(row == 3){//FIX
                offset = -130;
            }else if(row == 4){//FIX
                offset = -170;
            }else if (row == 5){//FIX
                offset = -130;
            }else if(row == 6){
                offset = -85;
            }else if(row == 7){
                offset = -45;
            }else if(row == 8){
                offset = 0;
            }

            int pointX = col * 85 + offset /*-25*/;
            int pointY= row * 75;//* 75 /*-25*/;
            _gMarbles.at(i)->setPos(QPoint(pointX, pointY));

            _gMarbles.at(i)->color(_marbles.at(i).color());

            std::string strCoord = std::to_string(row) + "" +
                    std::to_string(_marbles.at(i).positionOnBoard().y());

            _gMarbles.at(i)->value(strCoord);
        }else{
            if(_marbles.at(i).color() == Color::BLACK){
                //_gMarbles.at(i)->setPos(500, 500);
                _scene->removeItem(_gMarbles.at(i));
            }else{
                _scene->removeItem(_gMarbles.at(i));
                //_gMarbles.at(i)->setPos(500, 500);
            }
        }
    }
}

void View::update(const nvs::Subject * subject){
    abalone::model::Game * game = (abalone::model::Game*) subject;

    _turn = game->currentRound();
    for(size_t i = 0; i < _marbles.size(); i++){
        _marbles.at(i) = *game->marbles().at(i);
    }

    _playerMarblesLoss = game->currentPlayerMarblesLoss();

    if(_turn %2 == 0){
        ui->blackMarbleLoss->setNum(_playerMarblesLoss);
    }else{
        ui->whiteMarbleLoss->setNum(_playerMarblesLoss);
    }
}


void View::initMarbles(){
    int offset = 0;
    for(auto marble : _marbles){
        int row = marble.positionOnBoard().y();
        int col = marble.positionOnBoard().x();

        std::string strCoord = std::to_string(row) + "" + std::to_string(col);

        if(row == 0){
            offset = 0;
        }else if (row == 1){
            offset = 45;
        }else if(row == 2){
            offset = 85;
        }else if(row == 3){
            offset = 130;
        }else if(row == 4){
            offset = -170;
        }else if (row == 5){
            offset = -130;
        }else if(row == 6){
            offset = -85;
        }else if(row == 7){
            offset = -45;
        }else if(row == 8){
            offset = 0;
        }

        int pointX = col * 85 + offset;
        int pointY= row * 75;

        _gMarbles.push_back(new GMarble(pointX, pointY, marble.color(), strCoord));
    }
}

void View::initGHexacells(){

    //Ligne 1
    _gHexaCells.push_back(new GHexaCell(0, 0, "04", nullptr));
    _gHexaCells.push_back(new GHexaCell(0, sqrt(3) * 50, "05", nullptr));
    _gHexaCells.push_back(new GHexaCell(0, sqrt(3) * 100, "06", nullptr));
    _gHexaCells.push_back(new GHexaCell(0, sqrt(3) * 150, "07", nullptr));
    _gHexaCells.push_back(new GHexaCell(0, sqrt(3) * 200, "08", nullptr));

    //Ligne 2
    _gHexaCells.push_back(new GHexaCell(2 * 50 * 3 / 4, - sqrt(3) * 50 / 2, "13", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 50 * 3 / 4, sqrt(3) * 50 / 2, "14", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 50 * 3 / 4, sqrt(3) * 150 / 2, "15", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 50 * 3 / 4, sqrt(3) * 250 / 2, "16", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 50 * 3 / 4, sqrt(3) * 350 / 2, "17", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 50 * 3 / 4, sqrt(3) * 450 / 2, "18", nullptr));

    //Ligne 3
    _gHexaCells.push_back(new GHexaCell(2 * 100 * 3 / 4, - sqrt(3) * 50 , "22", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 100 * 3 / 4, - sqrt(3) * 0 , "23", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 100 * 3 / 4, sqrt(3) * 50, "24", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 100 * 3 / 4, sqrt(3) * 100 , "25", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 100 * 3 / 4, sqrt(3) * 150, "26", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 100 * 3 / 4, sqrt(3) * 200 , "27", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 100 * 3 / 4, sqrt(3) * 250 , "28", nullptr));

    //Ligne 4
    _gHexaCells.push_back(new GHexaCell(2 * 150 * 3 / 4, - sqrt(3) * 150 / 2, "31", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 150 * 3 / 4, - sqrt(3) * 50 / 2, "32", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 150 * 3 / 4, sqrt(3) * 50 / 2, "33", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 150 * 3 / 4, sqrt(3) * 150 / 2, "34", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 150 * 3 / 4, sqrt(3) * 250 / 2, "35", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 150 * 3 / 4, sqrt(3) * 350 / 2, "36", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 150 * 3 / 4, sqrt(3) * 450 / 2, "37", nullptr));
    _gHexaCells.push_back(new GHexaCell(2 * 150 * 3 / 4, sqrt(3) * 550 / 2, "38", nullptr));


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

void View::centerAndResize() {

   // get the dimension available on this screen
   QSize availableSize = qApp->desktop()->availableGeometry().size();
   int width = availableSize.width();
   int height = availableSize.height();
   qDebug() << "Available dimensions " << width << "x" << height;
   width *= 0.9; // 90% of the screen size
   height *= 0.9; // 90% of the screen size
   qDebug() << "Computed dimensions " << width << "x" << height;
   QSize newSize( width, height );
   setGeometry(
       QStyle::alignedRect(
           Qt::LeftToRight,
           Qt::AlignCenter,
           newSize,
           qApp->desktop()->availableGeometry()
       )
   );
}

}//namespace abalone::view
