#ifndef SIDEBOARD_H
#define SIDEBOARD_H

#include <QWidget>
#include <QPainter>

class SideBoard : public QWidget {
public:
    explicit SideBoard(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // SIDEBOARD_H
