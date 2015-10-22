#include "dragarea.h"

#include <QDragEnterEvent>
#include <QMimeData>
#include <QDebug>

DragArea::DragArea(QWidget* parent, const QString& s):
    QLabel(parent)
{
    setStyleSheet(defStyle);
    setText(s);
    setAcceptDrops(true);
    setAlignment(Qt::AlignCenter);

    _success = false;
}

void DragArea::dragEnterEvent(QDragEnterEvent *event) {
    if (event->mimeData()->hasFormat("text/uri-list")) {
        event->acceptProposedAction();
        setStyleSheet(validDataStyle);
    } else {
        setStyleSheet(defStyle);
    }
}

void DragArea::dragLeaveEvent(QDragLeaveEvent *event) {
    if (_success)
        setStyleSheet(fileSelectedStyle);
    else
        setStyleSheet(defStyle);
}

void DragArea::dropEvent(QDropEvent *event) {
    _success = true;
    auto urls = event->mimeData()->urls();
    if (urls.isEmpty()) {
        setStyleSheet(fileInvalidtyle);
        _success = false;
        emit error();
        return;
    }

    QString fileName = urls.first().toLocalFile();
    if (fileName.isEmpty()) {
        setStyleSheet(fileInvalidtyle);
        _success = false;
        emit error();
        return;
    }
    setStyleSheet(fileSelectedStyle);
    emit success(fileName);
}
