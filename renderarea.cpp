#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>

RenderArea::RenderArea(QWidget *parent)
    : QWidget{parent} , mBackgroundColor(0 , 0, 255) , mShapeColor(255 , 255 , 255)
{
    this->setStyleSheet("background-color:blue;");

}
QSize RenderArea::minimumSizeHint() const {
    return QSize(100 , 100);

}
QSize RenderArea::sizeHint() const {
    return QSize(400 , 200);

}
void RenderArea::paintEvent(QPaintEvent *event )  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing , true);

    switch (mShape) {
    case Astroid:
        mBackgroundColor = Qt::red;

        break;
    case Cycloid:
        mBackgroundColor = Qt::blue;
        break;
    case HuygensCycloid:
        mBackgroundColor = Qt::green;
        break;
    case HypoCycloid:
        mBackgroundColor = Qt::gray;
        break;
    default:
        break;
    }
    painter.setBrush(mBackgroundColor);
    painter.setPen(mShapeColor);

    painter.drawRect(this->rect());
    int StepCount = 64 ;

    float intervalLength = 2 * M_PI ;
    float step = intervalLength / StepCount ;
    for (float t =0 ; t < intervalLength; t+= step){
        QPoint point = compute_astroid(t);
        QPoint pixel ;
         pixel.setX(point.x());
          pixel.setX(point.y());
    }


}

