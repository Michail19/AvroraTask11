import QtQuick 2.0

Rectangle {
    width: 264
    height: 200
    property alias value: list.currentIndex
    property alias label: caption.text

    Text {
        id: caption
        text: "Spinner"
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 40;
    }

    Rectangle {
        anchors.top: caption.bottom
        anchors.topMargin: 4
        anchors.horizontalCenter: parent.horizontalCenter
        height: 100
        width: 110
        color: "black"
        ListView {
            id: list
            anchors.fill: parent
            highlightRangeMode: ListView.StrictlyEnforceRange
            preferredHighlightBegin: height/3
            preferredHighlightEnd: height/3
            clip: true
            model: 14
            delegate: Text {
                font.pixelSize: 40;
                color: "white";
                text: index;
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }
}
