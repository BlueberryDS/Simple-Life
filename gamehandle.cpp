#include "gamehandle.h"
#include "graphicssquare.h"

GameHandle::GameHandle(QGraphicsScene & setScene, QObject *parent) :
    QObject(parent),
    scene(setScene),
    xNum(35),
    yNum(35),
    map(xNum, QVector<bool>(yNum, false)),
    items(xNum, QVector<GraphicsSquare>(yNum))
{
    for(int i = 0; i < xNum; i++){
        for(int j = 0; j < yNum; j++){
            items[i][j].setPos(10.0 * i, 10.0 * j);
            scene.addItem(&items[i][j]);
        }
    }
}

void clear(QVector <QVector <bool> > & map){
    int s1 = map.size();
    for(int i = 0; i < s1; i++){
        int s2 = map[i].size();
        for(int j = 0; j < s2; j++){
            map [i][j] = false;
        }
    }
}

void clear(QVector <QVector <GraphicsSquare> > & items){
    int s1 = items.size();
    for(int i = 0; i < s1; i++){
        int s2 = items[i].size();
        for(int j = 0; j < s2; j++){
            items [i][j].setState(false);
        }
    }
}

void transfer(QVector <QVector <bool> > & map, QVector <QVector <GraphicsSquare> > & items){
    int s1 = map.size();
    for(int i = 0; i < s1; i++){
        int s2 = map[i].size();
        for(int j = 0; j < s2; j++){
            items[i][j].setState(map [i][j]);
        }
    }
}

bool ruleCheck(bool mm, bool tl, bool tm, bool tr, bool ml, bool mr, bool bl, bool bm, bool br){
    int total = 0;
    if(tl){
        total++;
    }
    if(tm){
        total++;
    }
    if(tr){
        total++;
    }
    if(ml){
        total++;
    }
    if(mr){
        total++;
    }
    if(bl){
        total++;
    }
    if(bm){
        total++;
    }
    if(br){
        total++;
    }

    if(total < 2){
        return false;
    }
    else if(total <= 3 && mm){
        return true;
    }
    else if (total == 3){
        return true;
    }
    return false;
}

void GameHandle::update(){
    clear(map);

    int s1 = items.size();
    for(int i = 0; i < s1; i++){
        int s2 = items[i].size();
        for(int j = 0; j < s2; j++){
            map[i][j] = ruleCheck(items[i][j].getState(),                         //careful here of incorrect map error
                                  i == 0 || j == 0 ? false : items[i - 1][j-1].getState(),
                                  i == 0 ? false : items[i - 1][j].getState(),
                                  i == 0 || j == s2 - 1 ? false : items[i - 1][j + 1].getState(),
                                  j == 0 ? false : items[i][j - 1].getState(),
                                  j == s2 - 1 ? false : items [i][j + 1].getState(),
                                  i == s1 - 1 || j == 0 ? false : items[i + 1][j - 1].getState(),
                                  i == s1 - 1 ? false : items[i + 1][j].getState(),
                                  i == s1 - 1 || j == s2 - 1 ? false : items[i + 1][j + 1].getState());
        }
    }

    clear(items);//inefficient?
    transfer(map, items);
}

void GameHandle::clean()
{
    clear(items);
}
