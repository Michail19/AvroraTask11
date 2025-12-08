#include <QPainter>
#include <qmath.h>
#include <QDebug>

#include "mandelbrot.h"

const double DefaultCenterX = -0.637011f;
const double DefaultCenterY = -0.0395159f;
const double DefaultScale = 0.00403897f;

const double ZoomInFactor = 0.8f;
const double ZoomOutFactor = 1 / ZoomInFactor;
const int ScrollStep = 20;

Mandelbrot::Mandelbrot()
    : m_centerX(DefaultCenterX)
    , m_centerY(DefaultCenterY)
    , m_pixmapScale(DefaultScale)
    , m_curScale(DefaultScale)
{
    setAcceptedMouseButtons(Qt::LeftButton);

    connect(&m_thread, &RenderThread::renderedImage,
            this, &Mandelbrot::updatePixmap);
}

void Mandelbrot::paint(QPainter *painter) {
    QRectF r(0,0, width(), height());
    painter->fillRect(r, Qt::black);

    if (m_pixmap.isNull()) {
        painter->setPen(Qt::white);
        painter->drawText(r, Qt::AlignCenter, tr("Rendering initial image, please wait..."));
        renderImage();
        return;
    }

    if (m_curScale == m_pixmapScale) {
        painter->drawPixmap(m_pixmapOffset, m_pixmap);
    } else {
        double scaleFactor = m_pixmapScale / m_curScale;
        int newWidth = int(m_pixmap.width() * scaleFactor);
        int newHeight = int(m_pixmap.height() * scaleFactor);
        int newX = m_pixmapOffset.x() + (m_pixmap.width() - newWidth) / 2;
        int newY = m_pixmapOffset.y() + (m_pixmap.height() - newHeight) / 2;

        painter->save();
        painter->translate(newX, newY);
        painter->scale(scaleFactor, scaleFactor);
        QRectF exposed = painter->matrix().inverted().mapRect(r).adjusted(-1, -1, 1, 1);
        painter->drawPixmap(exposed, m_pixmap, exposed);
        painter->restore();
    }
}

void Mandelbrot::moveUp() {
    scroll(0, -ScrollStep);
}

void Mandelbrot::moveDown() {
    scroll(0, ScrollStep);
}

void Mandelbrot::moveLeft() {
    scroll(-ScrollStep, 0);
}

void Mandelbrot::moveRight() {
    scroll(ScrollStep, 0);
}

void Mandelbrot::zoomIn() {
    zoom(ZoomInFactor);
}

void Mandelbrot::zoomOut() {
    zoom(ZoomOutFactor);
}

// Setters для свойств
void Mandelbrot::setCenterX(double x) {
    if (qFuzzyCompare(m_centerX, x))
        return;

    m_centerX = x;
    renderImage();
    emit centerXChanged();
}

void Mandelbrot::setCenterY(double y) {
    if (qFuzzyCompare(m_centerY, y))
        return;

    m_centerY = y;
    renderImage();
    emit centerYChanged();
}

void Mandelbrot::setScale(double scale) {
    if (qFuzzyCompare(m_curScale, scale))
        return;

    m_curScale = scale;
    renderImage();
    emit scaleChanged();
}

void Mandelbrot::updatePixmap(const QImage &image, double scaleFactor)
{
    m_pixmap = QPixmap::fromImage(image);
    m_pixmapOffset = QPoint();
    m_lastDragPos = QPoint();
    m_pixmapScale = scaleFactor;
    update();
}

void Mandelbrot::zoom(double zoomFactor)
{
    m_curScale *= zoomFactor;
    update();
    renderImage();
    emit scaleChanged();
}

void Mandelbrot::scroll(int deltaX, int deltaY)
{
    m_centerX += deltaX * m_curScale;
    m_centerY += deltaY * m_curScale;
    update();
    renderImage();
    emit centerXChanged();
    emit centerYChanged();
}

void Mandelbrot::renderImage()
{
    QSize size(width(), height());
    m_thread.render(m_centerX, m_centerY, m_curScale, size);
}
