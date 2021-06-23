#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>

#include "roscli.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterType<rosCLI>("RosCLI", 1, 0, "RosCLI");
    QQuickView view;
    view.engine()->addImportPath("qrc:/qml/imports");
    view.setSource(QUrl("qrc:/qml/washingMachineUI.qml"));

    if (!view.errors().isEmpty())
        return -1;
    view.show();

    app.exec();
}

/*

#include <QtGui/QGuiApplication>
#include <QtQuick>
#include "qtquick2applicationviewer.h"
#include "hellocpp.h"

int main(int argc, char *argv[])
{
QGuiApplication app(argc, argv);

qmlRegisterType<HelloCpp>("HelloCpp", 1, 0, "HelloCpp");

QtQuick2ApplicationViewer viewer;
viewer.setMainQmlFile&#40;QStringLiteral("qml/QMLTest/main.qml"&#41;);
viewer.showExpanded();

return app.exec();
}

*/
