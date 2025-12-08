#include <auroraapp.h>
#include <QtQuick>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>

#include "mandelbrot.h"
#include "renderthread.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> application(Aurora::Application::application(argc, argv));
    application->setOrganizationName(QStringLiteral("ru.template"));
    application->setApplicationName(QStringLiteral("Mandelbrot"));

    qmlRegisterType<Mandelbrot>("Mandelbrot", 1, 0, "Mandelbrot");

    QScopedPointer<QQuickView> view(Aurora::Application::createView());

    view->setSource(Aurora::Application::pathTo(QStringLiteral("qml/Mandelbrot.qml")));
    view->show();

    return application->exec();
}
