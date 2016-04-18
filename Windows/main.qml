import QtQuick 2.5
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.4


ApplicationWindow {
    visible: true
    title: "F8's Dex Analyzer"

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("E&xit")
                shortcut: StandardKey.Quit
                onTriggered: Qt.quit()
            }
        }
    }

    MainForm {
        id: mainForm

        anchors.fill: parent

        Layout.minimumWidth: 800
        Layout.minimumHeight: 480
        Layout.preferredWidth: 768
        Layout.preferredHeight: 480
    }
}
