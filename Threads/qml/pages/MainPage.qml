import QtQuick 2.0
import Sailfish.Silica 1.0
import "../assets"

Page {
    id: page

    allowedOrientations: Orientation.All

    WorkerScript {
        id: rowWorker
        source: "../assets/workerscript.js"
        onMessage: resultRow.text = "Row result: " + messageObject.result
    }

    WorkerScript {
        id: columnWorker
        source: "../assets/workerscript.js"
        onMessage: resultColumn.text = "Column result: " + messageObject.result
    }

    Component.onCompleted: {
        rowWorker.sendMessage({ n: rowSpinner.value });
        columnWorker.sendMessage({ n: columnSpinner.value });
    }

    Row {
        id: row
        anchors.top: parent.top
        anchors.margins: 25
        spacing: 24
        anchors.horizontalCenter: parent.horizontalCenter

        Spinner {
            id: rowSpinner
            label: "Row"
            onValueChanged: rowWorker.sendMessage({ n: rowSpinner.value })
        }

        Spinner {
            id: columnSpinner
            label: "Column"
            onValueChanged: columnWorker.sendMessage({ n: columnSpinner.value })
        }
    }

    Text {
        id: resultRow
        anchors.top: row.bottom
        anchors.topMargin: 25
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 40
        color: "white"
        text: "Row: -"
    }

    Text {
        id: resultColumn
        anchors.top: resultRow.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 40
        color: "white"
        text: "Column: -"
    }
}
