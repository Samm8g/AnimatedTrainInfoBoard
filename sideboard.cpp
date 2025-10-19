#include "sideboard.h"

SideBoard::SideBoard(QWidget *parent) : QWidget(parent) {
    setFixedHeight(50); // Increased height
}

void SideBoard::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.fillRect(rect(), Qt::darkCyan); // Changed to dark turquoise
}
