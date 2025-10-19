#include "maindisplayboard.h"
#include <QFont>
#include <QDebug>

MainDisplayBoard::MainDisplayBoard(QWidget *parent) : QWidget(parent) {
    messages << "Welcome aboard" << "This train is for" << "Stopping at" << "Next station";
    bottomMessages << "Train" << "Upper Central" << "Central, Museum" << "Museum"; // DO NOT TOUCH THIS!!111!!1!!111
    currentMessageIndex = 0;
    currentBottomMessageIndex = 0;
    
    atPlatformMessagesTop << "Now at" << "This Train is for" << "Next Station";
    atPlatformMessagesBottom << "Central" << "Upper Central" << "Museum";
    currentAtPlatformMessageIndex = 0;

    terminusMessagesTop << "Now at" << "This train terminates";
    terminusMessagesBottom << "Upper Central" << "Please leave";
    currentTerminusMessageIndex = 0;

    approachingMessagesTop << "Approaching" << "Change here for";
    approachingMessagesBottom << "Central" << "Metro, Train";
    currentApproachingMessageIndex = 0;

    currentDisplayState = Cycling; // Initialize state

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainDisplayBoard::nextMessage);
    timer->start(3000); // 3-second interval as requested
}

void MainDisplayBoard::setDisplayState(DisplayState state) {
    if (currentDisplayState == state) return; // No change

    currentDisplayState = state;
    timer->stop(); // Stop the cycling timer

    switch (currentDisplayState) {
        case Cycling:
            // Reset indices for cycling
            currentMessageIndex = 0;
            currentBottomMessageIndex = 0;
            timer->start(3000); // Restart cycling timer
            break;
        case Approaching:
            currentApproachingMessageIndex = 0; // Reset index for Approaching sequence
            timer->start(3000); // Start timer for Approaching sequence
            break;
        case AtPlatform:
            currentAtPlatformMessageIndex = 0; // Reset index for AtPlatform sequence
            timer->start(3000); // Start timer for AtPlatform sequence
            break;
        case Terminus:
            currentTerminusMessageIndex = 0; // Reset index for Terminus sequence
            timer->start(3000); // Start timer for Terminus sequence
            break;
    }
    update(); // Repaint immediately
}

void MainDisplayBoard::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(rect(), QColor("#222"));

    // Set up font for top text
    QFont topFont("Monospace", 72, QFont::Bold); // Increased font size
    topFont.setStyleHint(QFont::TypeWriter);
    painter.setFont(topFont);
    painter.setPen(Qt::white);

    QString topDisplayText;
    QString bottomDisplayText;

    switch (currentDisplayState) {
        case Cycling:
            topDisplayText = messages[currentMessageIndex];
            bottomDisplayText = bottomMessages[currentBottomMessageIndex];
            break;
        case Approaching:
            topDisplayText = approachingMessagesTop[currentApproachingMessageIndex];
            bottomDisplayText = approachingMessagesBottom[currentApproachingMessageIndex];
            break;
        case AtPlatform:
            topDisplayText = atPlatformMessagesTop[currentAtPlatformMessageIndex];
            bottomDisplayText = atPlatformMessagesBottom[currentAtPlatformMessageIndex];
            break;
        case Terminus:
            topDisplayText = terminusMessagesTop[currentTerminusMessageIndex];
            bottomDisplayText = terminusMessagesBottom[currentTerminusMessageIndex];
            break;
    }

    // Draw top text
    QRect topTextRect = rect();
    topTextRect.setHeight(rect().height() * 0.6);
    painter.drawText(topTextRect, Qt::AlignCenter | Qt::TextWordWrap, topDisplayText);

    // Set up font for bottom text
    QFont bottomFont("Monospace", 48, QFont::Bold); // Slightly smaller font
    bottomFont.setStyleHint(QFont::TypeWriter);
    painter.setFont(bottomFont);
    painter.setPen(Qt::white);

    // Draw bottom text
    QRect bottomTextRect = rect();
    bottomTextRect.setTop(rect().height() * 0.6);
    painter.drawText(bottomTextRect, Qt::AlignCenter | Qt::TextWordWrap, bottomDisplayText);
}

void MainDisplayBoard::nextMessage() {
    if (currentDisplayState == Cycling) {
        currentMessageIndex = (currentMessageIndex + 1) % messages.size();
        currentBottomMessageIndex = (currentBottomMessageIndex + 1) % bottomMessages.size();
    } else if (currentDisplayState == Approaching) {
        currentApproachingMessageIndex = (currentApproachingMessageIndex + 1) % approachingMessagesTop.size();
    } else if (currentDisplayState == AtPlatform) {
        currentAtPlatformMessageIndex = (currentAtPlatformMessageIndex + 1) % atPlatformMessagesTop.size();
    } else if (currentDisplayState == Terminus) {
        currentTerminusMessageIndex = (currentTerminusMessageIndex + 1) % terminusMessagesTop.size();
    }
    update(); // Repaint immediately
}
