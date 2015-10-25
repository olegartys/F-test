#include "selection.h"

#include <QTextStream>
#include <QDebug>

Selection::Selection(QFile* f, bool rememberData)
{
    average = 0.;
    sum = 0.;
    elementsCount = 0;
    dispersion = 0;

    auto changeOnDot = [](QString&& str) -> QString& { for (int i = 0; i < str.length(); i++) if (str[i] == ',') {str[i] = '.'; return str;} return str;};

    QTextStream str(f);
    QString buf;

    // Counting average, sum and count of elements
    double _s = 0;
    while (!str.atEnd()) {
        buf = changeOnDot(std::move(str.readLine()));
        double d = buf.toDouble();

        elementsCount++;
        sum += d;
        _s += d*d;

        qDebug() << d;
    }

    average = sum / (elementsCount);
    dispersion = _s/(elementsCount) - average*average;

}

