#include <QMessageBox>
#include <QGraphicsSceneEvent>

#include "widget.h"
#include "ui_widget.h"

#include "blockscheme.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    srand(clock());
    // Косметическая подготовка приложения
    this->resize(840,840);          // Устанавливаем размеры окна приложения
    this->setFixedSize(840,840);

    scene = new QGraphicsScene(this);   // Инициализируем графическую сцену
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов

    ui->graphicsView->resize(800,800);  // Устанавливаем размер graphicsView

    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    scene->setSceneRect(0,0,700,700); // Устанавливаем размер сцены

}
Widget::~Widget() {}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        BlockScheme *newFigure = new BlockScheme(this,next());        // Создаём графический элемент
        newFigure->setPos(event->x()-70,    // Устанавливаем случайную позицию элемента
                          event->y()-90);
        scene->addItem(newFigure);   // Добавляем элемент на графическую сцену

//1        connect(this,&Widget::signal1, newFigure, &BlockScheme::keyPressEvent);

        //setWindowTitle(QString::number(event->x()-70)+ " " + QString::number(event->y()-70));
    }
}


int Widget::next()
{
    if (2 == fig_index) fig_index = 0;
    else ++fig_index;
    return fig_index;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Plus)
    {
        QPoint center(0,0);
        QTransform trans =  ui->graphicsView->transform();
        trans.translate( center.x(), center.y());
        trans.scale(1+0.05,1+0.05);
        trans.translate( -center.x(),  -center.y());
        ui->graphicsView->setTransform(trans);
    }
    else if (event->key() == Qt::Key_Minus)
    {
        QPoint center(0,0);
        QTransform trans =  ui->graphicsView->transform();
        trans.translate( center.x(), center.y());
        trans.scale(1-0.05,1-0.05);
        trans.translate( -center.x(),  -center.y());
        ui->graphicsView->setTransform(trans);
    }
//1    emit signal1(event);
};

void Widget::on_pushButton_clicked()
{
    QSharedPointer<helpWindow> abDialog = QSharedPointer<helpWindow>::create(this);
    abDialog->exec();
}

