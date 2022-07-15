#ifndef BLOCKSCHEME_H
#define BLOCKSCHEME_H

#include <QObject>
#include <QGraphicsItem>
#include <QContextMenuEvent>
#include <QBrush>
#include <QCursor>

class BlockScheme : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QBrush brush)

public:
    explicit BlockScheme(QObject *parent = nullptr, int _fig_index = 0);
    ~BlockScheme();

signals:
    void signalMove(QGraphicsItem *item, qreal dx, qreal dy);

public slots:
//1    void keyPressEvent(QKeyEvent *event) override;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget
                                                                                *widget) override;
    QRectF boundingRect() const override;

    void setPreviousPosition(const QPointF previousPosition);

    template<class T>
    T sign(T x)
    {
        return x<0?-1 : 1;
    }

private:
    enum Geometry {RECTANGLE = 0, ELLIPS = 1, STAR = 2};
    int dx=-100;
    int dy=-50;
    int fig_index;
    Geometry geometry;
    QBrush brush;

    bool isRotate = false;
    QPointF m_previousPosition = QPointF(0,0);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

};
#endif // BLOCKSCHEME_H
