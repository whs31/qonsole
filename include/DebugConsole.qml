import QtQuick 2.15
import QtQuick.Controls 2.15
import DebugConsoleImpl 1.0

Rectangle { id: control;
    width: 1024;
    height: 891;
    color: "#232323";
    border.width: 0.5;
    border.color: "#343434";
    x: 128;
    y: 64;
    z: 100;

    FontLoader { id: monoFont; source: "qrc:/rc/UbuntuMono.ttf"; }
    Connections
    {
        target: Impl;
        function onAppendSignal(text)
        {
            textArea.append(text);
        }
    }
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
                onClicked: {
                    control.enabled = false;
                    control.visible = false;
                }
            }

            Image {
                source: "qrc:/rc/cross.png";
                anchors.centerIn: parent;
            }
        }
    }

    ScrollView { id: scrollView;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.top: header.bottom;
        anchors.bottom: inputArea.top;
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn;

        TextArea { id: textArea;
            color: "#ECEFF4";
            background: Rectangle{
                color:"#232323";
            }
            text: "[GUI] Console initialized";
            selectByMouse: true;
            readOnly: true;
            selectedTextColor: "#2E3440";
            selectionColor: "#B48EAD";
            textFormat: Text.RichText;
            font.family: monoFont.name;
            font.pixelSize: 13;
            wrapMode: Text.NoWrap;
            function append(strAdd)
            {
                textArea.text = textArea.text + strAdd;
                textArea.cursorPosition = textArea.length - 1;
            }
        }
    }

    Rectangle { id: inputArea;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.bottom: parent.bottom;
        height: 28;
        color: "#000000";
        border.width: 0.5;
        border.color: "#343434";
    }
}
