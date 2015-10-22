#ifndef DRAGAREA_H
#define DRAGAREA_H

#include <QLabel>


class DragArea : public QLabel
{

    Q_OBJECT

public:
    DragArea(QWidget* parent, const QString& s);
    bool isActive() const { return _success; }
    ~DragArea() =default;

protected:
    void dragEnterEvent(QDragEnterEvent*);
    void dragLeaveEvent(QDragLeaveEvent*);
    void dropEvent(QDropEvent*);

signals:
    void success(QString) const;
    void error() const;

private:
    QString defStyle{"border: 2px dotted #8f8f91; border-radius: 5px; background-color: white"};
    QString validDataStyle{"border: 2px dotted #8f8f91; border-radius: 5px; background-color: #C7C7C7"};

    QString fileSelectedStyle{"border: 2px solid green; border-radius: 5px; background-color: white"};
    QString fileInvalidtyle{"border: 2px solid red; border-radius: 5px; background-color: white"};

    bool _success;
};

#endif // DRAGAREA_H
