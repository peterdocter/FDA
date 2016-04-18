
import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.1
import QtQuick.Controls 1.2

Item {
    width: 800
    height: 480

    SplitView {
        id: splitView
        anchors.fill: parent

        ListView {
            id: apkInfoList         // apk file message, class, res, or other

            property int columnWidth: splitView.width / 5
            Layout.minimumWidth: splitView.width / 10
        }

        TabView {
            id: decompileTabView

            Layout.minimumWidth: splitView.width / 10

            Tab {
                title: qsTr("Decompile")
            }
        }
    }
}
