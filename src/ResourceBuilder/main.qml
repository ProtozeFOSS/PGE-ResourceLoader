import QtQuick 2.6
import QtQuick.Window 2.2
import Qt.labs.controls 1.0

ApplicationWindow {
    visible: true
    height:800
    width:600


    Rectangle{
        color:"grey"
        anchors.fill: parent
        border.color: "black"
        border.width: 2
    }
    Rectangle{
        height:60
        width:140
        anchors.left: parent.left
        anchors.top:parent.top
        radius:8
        border.width:1
        Image{
            id:imageIcon
            anchors.top:parent.top
            anchors.bottom: parent.bottom
            anchors.left:parent.left
            anchors.margins: 8
            width:height
            source:"images/builder.png"
        }
        Text{
            anchors.left:imageIcon.right
            anchors.right:parent.right
            anchors.top:parent.top
            anchors.bottom:parent.bottom
            font.pixelSize: parent.height * .7
            text:"File"
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignBottom
        }

        MouseArea{
            anchors.fill: parent
            onClicked:{
                fileMenu.open()
            }
        }

        Menu{
            width:140
            id:fileMenu
            title: "File"
            MenuItem{
                text:"Open Resource"
            }
            MenuItem{
                text:"Close"
                onTriggered: {
                    Qt.quit();
                }
            }
        }

    }
}
