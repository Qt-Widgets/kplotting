/*
    Copyright (C) 2012 Benjamin Port <benjamin.port@ben2367.fr>

    This library is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This library is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to the
    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
    02110-1301, USA.
*/

#include <kplotaxis.h>

#include <QtTest>

class KPlotAxisTest : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void initTestCase()
    {
        m_kPlotAxis = new KPlotAxis(QStringLiteral("label"));
    }

    void cleanupTestCase()
    {
        delete m_kPlotAxis;
    }

    void testVisible()
    {
        m_kPlotAxis->setVisible(true);
        QCOMPARE(m_kPlotAxis->isVisible(), true);

        m_kPlotAxis->setVisible(false);
        QCOMPARE(m_kPlotAxis->isVisible(), false);
    }

    void testTickLabelsShown()
    {
        m_kPlotAxis->setTickLabelsShown(true);
        QCOMPARE(m_kPlotAxis->areTickLabelsShown(), true);

        m_kPlotAxis->setTickLabelsShown(false);
        QCOMPARE(m_kPlotAxis->areTickLabelsShown(), false);
    }

    void testLabel()
    {
        QCOMPARE(m_kPlotAxis->label(), QString::fromLatin1("label"));

        m_kPlotAxis->setLabel(QStringLiteral("newLabel"));
        QCOMPARE(m_kPlotAxis->label(), QString::fromLatin1("newLabel"));
    }

    void testTickLabelFormat()
    {
        m_kPlotAxis->setTickLabelFormat('e', 3, 2);
        QCOMPARE(m_kPlotAxis->tickLabelFormat(), 'e');
        QCOMPARE(m_kPlotAxis->tickLabelWidth(), 3);
        QCOMPARE(m_kPlotAxis->tickLabelPrecision(), 2);
    }

    void testTickMarks()
    {
        m_kPlotAxis->setTickMarks(0.0, 12.0);
        QCOMPARE(m_kPlotAxis->majorTickMarks(), QList<double>() << 0.0 << 4.0 << 8.0 << 12.0);
        QCOMPARE(m_kPlotAxis->minorTickMarks(), QList<double>() << 1.0 << 2.0 << 3.0 << 5.0 << 6.0 << 7.0 << 9.0 << 10.0 << 11.0);

        m_kPlotAxis->setTickMarks(0.0, 120.0);
        QCOMPARE(m_kPlotAxis->majorTickMarks(), QList<double>() << 0.0 << 40.0 << 80.0 << 120.0);
        QCOMPARE(m_kPlotAxis->minorTickMarks(), QList<double>() << 10.0 << 20.0 << 30.0 << 50.0 << 60.0 << 70.0 << 90.0 << 100.0 << 110.0);

        m_kPlotAxis->setTickMarks(4.0, 29.0); // from 4 to 4+29 = 33
        QCOMPARE(m_kPlotAxis->majorTickMarks(), QList<double>() << 5.0 << 10.0 << 15.0 << 20.0 << 25.0 << 30.0);
    }

private:
    KPlotAxis *m_kPlotAxis;
};

QTEST_MAIN(KPlotAxisTest)

#include "kplotaxistest.moc"
