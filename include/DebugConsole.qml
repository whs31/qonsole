import QtQuick 2.15

Rectangle { id: control;
    width: 1024;
    height: 891;
    color: "#232323";
    border.width: 0.5;
    border.color: "#343434";
    x: 128;
    y: 64;
    z: 100;

    Rectangle { id: header;
        height: 20;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.top: parent.top;
        color: "#343434";

        Image { id: title;
            source: "qrc:/rc/header.png";
            anchors.left: parent.left;
            anchors.leftMargin: 5;
            anchors.verticalCenter: parent.verticalCenter;
        }

        MouseArea { // move window mouse area
            anchors.fill: parent;
            anchors.rightMargin: 20;
            property point offset: Qt.point(0, 0);
            onPressed: {
                parent.color = "#444444";
                offset = Qt.point(mouseX, mouseY);
            }
            onReleased: {
                parent.color = "#343434";
            }
            onPositionChanged: {
                if(pressed) {
                    let global_pos = mapToItem(control.parent, mouseX, mouseY);
                    control.x = global_pos.x - offset.x;
                    control.y = global_pos.y - offset.y;
                    console.log(global_pos, offset, control.x, control.y);
                }
            }
        }

        Rectangle { id: closeButton;
            anchors.right: parent.right;
            anchors.top: parent.top;
            width: 20;
            height: 20;
            color: "#343434";

            MouseArea { // close window mouse area
                anchors.fill: parent;
                hoverEnabled: true;
                onEntered: parent.color = "#563A3D";
                onExited: parent.color = "#343434";
            }

            Image {
                source: "qrc:/rc/cross.png";
                anchors.centerIn: parent;
            }
        }
    }
}
