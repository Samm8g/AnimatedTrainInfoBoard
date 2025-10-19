#ifndef MAINDISPLAYBOARD_H
#define MAINDISPLAYBOARD_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QStringList>
#include <QPropertyAnimation>
#include <QEasingCurve>

class MainDisplayBoard : public QWidget {
    Q_OBJECT

public:
    explicit MainDisplayBoard(QWidget *parent = nullptr);

    enum DisplayState { Cycling, Approaching, AtPlatform, Terminus }; // Added Terminus
    void setDisplayState(DisplayState state);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void nextMessage();

private:
    DisplayState currentDisplayState;

    QTimer *timer;
    QStringList messages;
    QStringList bottomMessages;
    int currentMessageIndex;
    int currentBottomMessageIndex;

    QStringList atPlatformMessagesTop;
    QStringList atPlatformMessagesBottom;
    int currentAtPlatformMessageIndex;

    QStringList terminusMessagesTop;
    QStringList terminusMessagesBottom;
    int currentTerminusMessageIndex;

    QStringList approachingMessagesTop;
    QStringList approachingMessagesBottom;
    int currentApproachingMessageIndex;

    friend class MainWindow; // Allow MainWindow to access private members for simplicity
};

#endif // MAINDISPLAYBOARD_H
