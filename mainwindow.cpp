#include "mainwindow.h"
#include "sideboard.h"
#include "maindisplayboard.h"
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Create the central widget and layout
    auto *centralWidget = new QWidget(this);
    auto *layout = new QVBoxLayout(centralWidget);

    // Create top, main, and bottom boards
    auto *topBoard = new SideBoard(this);
    mainDisplayBoard = new MainDisplayBoard(this); // Make it a member to access later
    auto *bottomBoard = new SideBoard(this);

    // Add boards to the layout
    layout->addWidget(topBoard);
    layout->addWidget(mainDisplayBoard, 1); // Give main display stretch factor of 1
    layout->addWidget(bottomBoard);

    // Set the central widget
    setCentralWidget(centralWidget);

    // Set stylesheet for a fully black background
    centralWidget->setStyleSheet("background-color: black;");

    // Make the window fullscreen
    showFullScreen();

    setWindowTitle("Train Information Board");
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space) {
        // Toggle between Cycling and Approaching
        if (mainDisplayBoard->currentDisplayState == MainDisplayBoard::Cycling) {
            mainDisplayBoard->setDisplayState(MainDisplayBoard::Approaching);
        } else {
            mainDisplayBoard->setDisplayState(MainDisplayBoard::Cycling);
        }
    } else if (event->key() == Qt::Key_A) {
        // Toggle between Cycling and AtPlatform
        if (mainDisplayBoard->currentDisplayState == MainDisplayBoard::Cycling) {
            mainDisplayBoard->setDisplayState(MainDisplayBoard::AtPlatform);
        } else {
            mainDisplayBoard->setDisplayState(MainDisplayBoard::Cycling);
        }
    } else if (event->key() == Qt::Key_T) {
        // Toggle between Cycling and Terminus
        if (mainDisplayBoard->currentDisplayState == MainDisplayBoard::Cycling) {
            mainDisplayBoard->setDisplayState(MainDisplayBoard::Terminus);
        } else {
            mainDisplayBoard->setDisplayState(MainDisplayBoard::Cycling);
        }
    } else {
        QMainWindow::keyPressEvent(event);
    }
}
