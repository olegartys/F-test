#ifndef SELECTION_H
#define SELECTION_H

#include <QList>
#include <QFile>

class Selection
{
public:
    Selection(const QList<double>&);
    Selection(QFile*, bool rememberData=false);

    double getAverage() const { return average; }
    double getDispersion() const { return dispersion; }
    double getSum() const { return sum; }
    size_t getElementsCount() const { return elementsCount; }

    QList<double> getData() const;

private:
    QList<double> data;
    double average, dispersion, sum;
    size_t elementsCount;

};

#endif // SELECTION_H
