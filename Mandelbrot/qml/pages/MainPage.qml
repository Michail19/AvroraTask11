import QtQuick 2.0
import Sailfish.Silica 1.0
import Mandelbrot 1.0

Page {
    id: page

    allowedOrientations: Orientation.All

    Rectangle {
        anchors.fill: parent
        color: "black"
    }

    Mandelbrot {
        id: mandelbrot
        anchors.fill: parent
        anchors.margins: Theme.paddingLarge

        MouseArea {
            anchors.fill: parent
            property point lastMousePos

            onPressed: {
                lastMousePos = Qt.point(mouse.x, mouse.y)
            }

            onPositionChanged: {
                var deltaX = mouse.x - lastMousePos.x
                var deltaY = mouse.y - lastMousePos.y
                lastMousePos = Qt.point(mouse.x, mouse.y)

                mandelbrot.scroll(-deltaX, -deltaY)
            }

            PinchArea {
                anchors.fill: parent

                onPinchUpdated: {
                    if (pinch.scale > 1.0) {
                        mandelbrot.zoomIn()
                    } else if (pinch.scale < 1.0) {
                        mandelbrot.zoomOut()
                    }
                }
            }
        }
    }

    DockedPanel {
        id: controlPanel
        width: parent.width
        height: controlColumn.height + 2 * Theme.paddingLarge
        dock: Dock.Bottom

        Column {
            id: controlColumn
            width: parent.width - 2 * Theme.paddingLarge
            anchors.centerIn: parent
            spacing: Theme.paddingMedium

            // Кнопки масштабирования
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: Theme.paddingLarge

                Button {
                    text: "−"
                    width: Theme.itemSizeMedium
                    onClicked: mandelbrot.zoomOut()
                }

                Button {
                    text: "+"
                    width: Theme.itemSizeMedium
                    onClicked: mandelbrot.zoomIn()
                }
            }

            Grid {
                anchors.horizontalCenter: parent.horizontalCenter
                columns: 3
                spacing: Theme.paddingSmall

                Item { width: Theme.itemSizeMedium; height: Theme.itemSizeSmall }

                Button {
                    text: "/\\"
                    width: Theme.itemSizeMedium
                    onClicked: mandelbrot.moveUp()
                }

                Item { width: Theme.itemSizeMedium; height: Theme.itemSizeSmall }

                Button {
                    text: "<"
                    width: Theme.itemSizeMedium
                    onClicked: mandelbrot.moveLeft()
                }

                Button {
                    text: "#"
                    width: Theme.itemSizeMedium
                    onClicked: {
                        mandelbrot.centerX = -0.637011
                        mandelbrot.centerY = -0.0395159
                        mandelbrot.scale = 0.00403897
                    }
                }

                Button {
                    text: ">"
                    width: Theme.itemSizeMedium
                    onClicked: mandelbrot.moveRight()
                }

                Item { width: Theme.itemSizeMedium; height: Theme.itemSizeSmall }

                Button {
                    text: "\/"
                    width: Theme.itemSizeMedium
                    onClicked: mandelbrot.moveDown()
                }

                Item { width: Theme.itemSizeMedium; height: Theme.itemSizeSmall }
            }

            Row {
                width: parent.width
                spacing: Theme.paddingMedium

                Label {
                    text: "X: " + mandelbrot.centerX.toFixed(6)
                    color: Theme.primaryColor
                    font.pixelSize: Theme.fontSizeExtraSmall
                    horizontalAlignment: Text.AlignHCenter
                    width: parent.width / 3
                }

                Label {
                    text: "Y: " + mandelbrot.centerY.toFixed(6)
                    color: Theme.primaryColor
                    font.pixelSize: Theme.fontSizeExtraSmall
                    horizontalAlignment: Text.AlignHCenter
                    width: parent.width / 3
                }

                Label {
                    text: "Zoom: " + (1/mandelbrot.scale).toFixed(2)
                    color: Theme.primaryColor
                    font.pixelSize: Theme.fontSizeExtraSmall
                    horizontalAlignment: Text.AlignHCenter
                    width: parent.width / 3
                }
            }
        }
    }

    IconButton {
        id: togglePanelButton
        icon.source: controlPanel.open ? "image://theme/icon-m-up" : "image://theme/icon-m-down"
        onClicked: controlPanel.open = !controlPanel.open
        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: controlPanel.top
            bottomMargin: Theme.paddingMedium
        }
    }

    PageHeader {
        title: "Фрактал Мандельброта"
    }
}
