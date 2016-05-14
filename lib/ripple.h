#ifndef RIPPLE_H
#define RIPPLE_H

#include <QObject>
#include <QPoint>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QBrush>

class Ripple : public QObject
{
    Q_OBJECT

    Q_PROPERTY(qreal radius WRITE setRadius READ radius)
    Q_PROPERTY(qreal opacity WRITE setOpacity READ opacity)

public:
    explicit Ripple(const QPoint &center, QObject *parent = 0);
    ~Ripple();

    void setRadius(qreal radius);
    inline qreal radius() const { return _radius; }

    void setOpacity(qreal opacity);
    inline qreal opacity() const { return _opacity; }

    void setColor(const QColor &color);
    inline QColor color() const { return _brush.color(); }

    inline void setBrush(const QBrush &brush) { _brush = brush; }
    inline QBrush brush() const { return _brush; }

    inline const QPoint &center() const { return _center; }

    inline void setDuration(int duration)
    {
        _radiusAnimation->setDuration(duration);
        _opacityAnimation->setDuration(duration);
    }

    inline void setOpacityStartValue(qreal value) { _opacityAnimation->setStartValue(value); }
    inline void setOpacityEndValue(qreal value) { _opacityAnimation->setEndValue(value); }
    inline void setRadiusStartValue(qreal value) { _radiusAnimation->setStartValue(value); }
    inline void setRadiusEndValue(qreal value) { _radiusAnimation->setEndValue(value); }

    inline void startAnimation() { _group.start(); }

signals:
    void changed();
    void finished();

private:
    QPropertyAnimation *animate(const QByteArray &property);

    QParallelAnimationGroup   _group;
    QPropertyAnimation *const _radiusAnimation;
    QPropertyAnimation *const _opacityAnimation;
    qreal                     _radius;
    qreal                     _opacity;
    QPoint                    _center;
    QBrush                    _brush;
};

#endif // RIPPLE_H
