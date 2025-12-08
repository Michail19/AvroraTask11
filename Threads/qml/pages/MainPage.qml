import QtQuick 2.0
import Sailfish.Silica 1.0
import "../assets"

Page {
    id: page

    allowedOrientations: Orientation.All

    WorkerScript {
            id: myWorker
            source: "../assets/workerscript.js"

            onMessage: {
                if (messageObject.row === rowSpinner.value && messageObject.column === columnSpinner.value){
                    if (messageObject.result === -1)
                        resultText.text = "Column must be <= Row";
                    else
                        resultText.text = messageObject.result;
                }
            }
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
                onValueChanged: {
                    resultText.text = "Loading...";
                    myWorker.sendMessage( { row: rowSpinner.value, column: columnSpinner.value } );
                }
            }

            Spinner {
                id: columnSpinner
                label: "Column"
                onValueChanged: {
                    resultText.text = "Loading...";
                    myWorker.sendMessage( { row: rowSpinner.value, column: columnSpinner.value } );
                }
            }
        }

        Text {
            id: resultText
            anchors.top: row.bottom
            anchors.margins: 25
            width: parent.width
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WordWrap
            font.pixelSize: 54
            color: "white"
        }

        Text {
            text: "Pascal's Triangle Calculator"
            anchors { horizontalCenter: parent.horizontalCenter; bottom: parent.bottom; bottomMargin: 50 }
            color: "white"
        }
}
