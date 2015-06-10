#include "health.h"
#include <QFont>
#include "game.h"

/*Construct lives
 */
Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    //initialize to 0
    health = 5;

    //draw text
    setPlainText(QString("Lives: ") + QString::number(health));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

/* Decrease Lives
 */
void Health::decrease()
{
    health--;
    setPlainText(QString("Lives: ") + QString::number(health));


}

/* Get lives
 */
int Health::getHealth()
{
    return health;
}

