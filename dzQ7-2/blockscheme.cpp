#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <math.h>

#include "blockscheme.h"

BlockScheme::BlockScheme(QObject *parent, int _fig_index) : QObject(parent), QGraphicsItem(),
     fig_index(_fig_index)
{
    brush.setColor(QColor(rand() % 256, rand() % 256, rand() % 256));
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    geometry = (Geometry) fig_index;    
}

BlockScheme::~BlockScheme() {}

void BlockScheme::paint(QPainter *painter, const QStyleOptionGraphicsItem
                                               *option, QWidget *widget)
{
    painter->setBrush(brush);
    if (geometry == Geometry::ELLIPS) painter->drawEllipse(dx, dy, 200, 100);
    if (geometry == Geometry::RECTANGLE) painter->drawRect(dx, dy, 200, 100);
    if (geometry == Geometry::STAR)
    {
        QPolygon polygon;

        polygon << QPoint(dx+25,dy+100);
        polygon << QPoint(dx+60,dy+60);
        polygon << QPoint(dx,dy+40);
        polygon << QPoint(dx+70,dy+40);
        polygon << QPoint(dx+100,dy);
        polygon << QPoint(dx+130,dy+40);
        polygon << QPoint(dx+200,dy+40);
        polygon << QPoint(dx+140,dy+60);
        polygon << QPoint(dx+175,dy+100);
        polygon << QPoint(dx+100,dy+75);

        painter->drawPolygon(polygon);
    }
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QRectF BlockScheme::boundingRect() const
{
    return QRectF(dx, dy, 200, 100);
}

void BlockScheme::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        this->setCursor(QCursor(Qt::ClosedHandCursor));
    }
    else if (event->button() == Qt::RightButton)
    {
        this->deleteLater();
    }
}

void BlockScheme::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (!isRotate)
    {   //move
        this->setPos(mapToScene(event->pos()));
    }
    else
    {   //rotate
        auto dx = event->pos().x() - m_previousPosition.x();
        auto dy = event->pos().y() - m_previousPosition.y();

        QPoint center(0,0);
        QTransform trans =  this->transform();
        trans.translate( center.x(), center.y());
        trans.rotateRadians(rotation() + sign(dx*dy)*0.1, Qt::ZAxis);
        trans.translate( -center.x(),  -center.y());
        setTransform(trans);

    }
}

void BlockScheme::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    isRotate = !isRotate;
    setPreviousPosition(event->pos());
};

void BlockScheme::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    isRotate = false;
    Q_UNUSED(event)
};

void BlockScheme::setPreviousPosition(const QPointF previousPosition)
{
    if (m_previousPosition == previousPosition)
        return;

    m_previousPosition = previousPosition;
}

void BlockScheme::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    int degree=sign(event->delta()/8);
    QPoint center(0,0);
    QTransform trans =  this->transform();
    trans.translate( center.x(), center.y());
    trans.scale(1+degree*0.05,1+degree*0.05);
    trans.translate( -center.x(),  -center.y());
    setTransform(trans);
};

//1void BlockScheme::keyPressEvent(QKeyEvent *event)
//{
//    if (event->key() == Qt::Key_Plus)
//    {
//        QPoint center(0,0);
//        QTransform trans =  this->transform();
//        trans.translate( center.x(), center.y());
//        trans.scale(1+0.05,1+0.05);
//        trans.translate( -center.x(),  -center.y());
//        setTransform(trans);
//    }
//    else if (event->key() == Qt::Key_Minus)
//    {
//        QPoint center(0,0);
//        QTransform trans =  this->transform();
//        trans.translate( center.x(), center.y());
//        trans.scale(1-0.05,1-0.05);
//        trans.translate( -center.x(),  -center.y());
//        setTransform(trans);
//    }
//};
