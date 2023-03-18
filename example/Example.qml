import QtQuick 2.15
import QtQuick.Window 2.15

Window { id: root;
    width: 640;
    height: 480;
    visible: true;
    color: "gray";
    Component.onCompleted: showMaximized();
    DebugConsole {

    }
}
