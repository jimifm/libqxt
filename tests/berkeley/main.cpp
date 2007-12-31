#include <QxtBdbHash>
#include <QTest>
#include <QDebug>
#include <QStringList>

class Test: public QObject
{
Q_OBJECT 
private slots:
    void begin()
    {
        db.open("test.db");
    }
    void readInvalidIterator()
    {
        QVERIFY(db.begin().value().size()==0);
    }
    void insert()
    {
        QVERIFY(db.insert(454.332,QStringList()<<"hello"<<"how are you?"));
        QVERIFY(db.insert(235,QStringList()<<"hey"<<"how's it going?"));
        QVERIFY(db.insert(234,QStringList()<<"jo"<<"sup?"));
    }
    void contains()
    {
        QVERIFY(db.contains(235));
        QVERIFY(!db.contains(34.24));
    }
    void implicitCopy()
    {
        QxtBdbHash<qreal,QStringList>  d=db;
        QVERIFY(d.contains(235));
        QVERIFY(!d.contains(34.24));
    }
    void read()
    {
        QVERIFY(db[235].at(1)=="how's it going?");
    }
    void readBeginIterator()
    {
        QVERIFY(db.begin().value().at(1)=="sup?");
    }
    void readNextAndPrevIterator()
    {
        QxtBdbHashIterator<qreal,QStringList> it=db.begin();
        ++it;

        QVERIFY(it.value().at(1)=="how's it going?");
        QVERIFY(it.key()==235);

        --it;
        QVERIFY(it.value().at(1)=="sup?");
    }

    void readIteratorOutOfBounds()
    {
        QxtBdbHashIterator<qreal,QStringList> it=db.begin();
        --it;
        it--;
        --it;
        it--;

        QVERIFY(!it.isValid());
        QVERIFY(it.value().count()==0);
        QVERIFY(it.key()==0);

        it+=4;
    }


    void clear()
    {
        QVERIFY(db.contains(235));
        db.clear();
        QVERIFY(!db.contains(235));
    }
    void end()
    {
    }

private:
    QxtBdbHash<qreal,QStringList> db;
};

QTEST_MAIN(Test)
#include "main.moc"