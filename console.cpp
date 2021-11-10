// console.cpp
// A text editor component that is designed specifically for Tetra code
// */

#include <QtWidgets>

#include "console.h"
#include "settingsmanager.h"
#include "ui_mainwindow.h"

Console::Console(MainWindow* parent) : QPlainTextEdit(parent) {
    setContentsMargins(50, 50, 50, 50);

    ensureCursorVisible();
    setCenterOnScroll(false);
    setReadOnly(false);
    this->parent = parent;
    inputStart = 0;

    // update all settings for the console */
    updateSettings();
}

void Console::setUpConnections(MainWindow* parent) {
    this->parent = parent;

    // set it up so that console can pass input to main window */
    connect(this, SIGNAL(enterPressed(QString)), parent,
            SLOT(receiveInput(QString)));
}

void Console::clear() {
    inputStart = 0;
}

void Console::updateSettings() {
    // set colors */
    setStyleSheet(
        "QPlainTextEdit {"
        "background-color: " +
        SettingsManager::termBackground().name() +
        ";"
        "color: " +
        SettingsManager::termForeground().name() +
        ";"
        "}");

    // set font */
    QFont font = SettingsManager::font();
    setFont(font);

    // set the cursor to be a block */
    QFontMetrics fm(font);
    setCursorWidth(fm.averageCharWidth());
}

// when keys are pressed in the widget */
void Console::keyPressEvent(QKeyEvent* e) {
    // if we push left or backspace, we can only handle it if there is room */
    if (e->key() == Qt::Key_Left || e->key() == Qt::Key_Backspace) {
        if (textCursor().positionInBlock() > inputStart) {
            QPlainTextEdit::keyPressEvent(e);
        }
    }

    // if we push home, then we go to the original start */
    else if (e->key() == Qt::Key_Home) {
        QTextCursor cursor = textCursor();
        cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::MoveAnchor, 1);
        cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, inputStart);
        setTextCursor(cursor);
    }

    // enter returns the input back to the main window which passes to the program
    else if (e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return) {
        // get the last line of text */
        QString text = textCursor().block().text();

        // remove what was there at start */
        text.remove(0, inputStart);

        // handle the enter so the line break is put in */
        QPlainTextEdit::keyPressEvent(e);

        // go back to start */
        inputStart = 0; 

        // return this back to the program TODO - get the real stuff! */
        emit enterPressed(text);
    }

    // we ignore all of these keys altogether */
    else if (e->key() == Qt::Key_Up || e->key() == Qt::Key_Down ||
             e->key() == Qt::Key_Insert || e->key() == Qt::Key_PageUp ||
             e->key() == Qt::Key_PageDown) {
    }

    // else, just pass it */
    else {
        QPlainTextEdit::keyPressEvent(e);
    }
}

// we must ignore these so the user does not click to a new position */
void Console::mousePressEvent(QMouseEvent*) {
}

void Console::resizeEvent(QResizeEvent* e) {
    QPlainTextEdit::resizeEvent(e);
}

void Console::write(QString text) {
    QTextCursor* cursor = new QTextCursor(document());
    cursor->movePosition(QTextCursor::End);
    cursor->insertText(text);
    inputStart += text.length();
    ensureCursorVisible();
}
