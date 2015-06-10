#ifndef HEALTH
#define HEALTH
#include <QGraphicsTextItem>
#include <QString>
#include <QLabel>
#include <QPixmap>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem* parent = 0);
    void decrease(); //decrese lives
    int getHealth();
private:

    int health;
};

#endif // HEALTH

