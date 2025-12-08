#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <QObject>
#include <QQuickPaintedItem>
#include <QPainter>
#include "renderthread.h"

class Mandelbrot : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(double centerX READ centerX WRITE setCenterX NOTIFY centerXChanged)
    Q_PROPERTY(double centerY READ centerY WRITE setCenterY NOTIFY centerYChanged)
    Q_PROPERTY(double scale READ scale WRITE setScale NOTIFY scaleChanged)

public:
    Mandelbrot();
    void paint(QPainter *painter);

    Q_INVOKABLE void moveUp();
    Q_INVOKABLE void moveDown();
    Q_INVOKABLE void moveLeft();
    Q_INVOKABLE void moveRight();
    Q_INVOKABLE void zoomIn();
    Q_INVOKABLE void zoomOut();

    double centerX() const { return m_centerX; }
    double centerY() const { return m_centerY; }
    double scale() const { return m_curScale; }

    void setCenterX(double x);
    void setCenterY(double y);
    void setScale(double scale);

signals:
    void centerXChanged();
    void centerYChanged();
    void scaleChanged();

private slots:
    void updatePixmap(const QImage &image, double scaleFactor);

private:
    void zoom(double zoomFactor);
    void scroll(int deltaX, int deltaY);
    void renderImage();

    RenderThread m_thread;
    QPixmap m_pixmap;
    QPoint m_pixmapOffset;
    QPoint m_lastDragPos;
    double m_centerX;
    double m_centerY;
    double m_pixmapScale;
    double m_curScale;
};

#endif // MANDELBROT_H
