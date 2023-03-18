import QtQuick 2.15
import QtQuick.Window 2.15

Window { id: root;
    width: 640;
    height: 480;
    visible: true;
    color: "#1E1e1e";
    Component.onCompleted: showMaximized();
    DebugConsole { id: debugConsole; }
    Item {
        Keys.onPressed: (event) => {
                            if (event.key === Qt.Key_Backslash) {
                                console.log("Toggle console");
                                debugConsole.visible = !debugConsole.visible;
                                debugConsole.enabled = !debugConsole.enabled;
                                event.accepted = true;
                            }
                        }
        Component.onCompleted: forceActiveFocus();
    }
}
