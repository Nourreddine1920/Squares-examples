#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;
    enum ShapeType {Astroid , Cycloid , HuygensCycloid , HypoCycloid , Line , Scale};
    void setBackgroundColor(QColor color){
        mBackgroundColor=  color ; //setter
    }
    QColor getBackground() const{
        return mBackgroundColor ;
    } //getter
    void setShape(ShapeType shape){
        mShape = shape ;
        on_shape_changed();
    } //setter
    ShapeType shape() const {
        return mShape ;
    }
    void setScale(float scale)  {
        mScale = scale ;
        repaint();

    }
    float scale() const {
        return mScale;
    }
    void setInterval(float interval)  {
        mIntervalLength = interval ;
        repaint();

    }
    float interval() const {
        return mIntervalLength;
    }

protected:
    void paintEvent(QPaintEvent *event ) Q_DECL_OVERRIDE ;

private:
    void on_shape_changed();
    QColor mBackgroundColor ;
    QColor mShapeColor ;
    ShapeType mShape;
    QPointF compute(float t); // dispatch function based on shapes type
    QPointF compute_astroid(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_hygens(float t);
    QPointF compute_hypo(float t);
    QPointF compute_line(float t);


    float mIntervalLength ;
    float mStep ;
    int mScale ;
    int mStepCount;


signals:



};

#endif // RENDERAREA_H
