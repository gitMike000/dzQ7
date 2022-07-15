#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QSharedPointer>

#include "blockscheme.h"
#include "helpwindow.h"

namespace Ui { class Widget; }

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private:
    Ui::Widget *ui;
    QGraphicsScene *scene;

    int fig_index = 2;

private:    
    int next();

signals:
//1    void signal1(QKeyEvent *event);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:

    void on_pushButton_clicked();
};


#endif // WIDGET_H
