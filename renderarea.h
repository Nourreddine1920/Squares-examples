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
    enum Shapes {Astroid , Cicloid , HuygensCicloid , HypoCicloid };
    void setBackgroundColor(QColor color){
        mBackgroundColor=  color ; //setter
    }
    QColor getBackground() const{
        return mBackgroundColor ;
    } //getter

protected:
    void paintEvent(QPaintEvent *event ) Q_DECL_OVERRIDE ;

private:
    QColor mBackgroundColor ;
    QColor mShapeColor ;


signals:



};

#endif // RENDERAREA_H
