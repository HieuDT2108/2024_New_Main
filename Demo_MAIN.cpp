#ifndef BOARDGENERATOR_H
#define BOARDGENERATOR_H


#include <QThread>
#include <QTime>
#include "Sudoku.h"


class BoardGenerator : public QThread {

    Q_OBJECT
// cDEM dMEO NO RUN
public:
    BoardGenerator(QObject * parent = NULL) : QThread(parent) { }
    virtual ~BoardGenerator(void) { }

    void QueueBoardGeneration(Board * board, int level = 1);

signals:
    void boardGenerated(int generationTime);

protected:
    void run();

private:
    Board * m_board;
    int m_level;
};

#endif // BOARDGENERATOR_H
