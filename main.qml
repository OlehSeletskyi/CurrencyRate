import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2


Window {
    visible: true
    width: 300
    height: 380
    minimumWidth: 300
    minimumHeight: 380
    title: qsTr("Currency Rate")
    color: "#e0e0e0"

//    property var tempDate: new Date();


    StackView {
        id: stackView
        anchors.fill: parent
        focus: true
        initialItem: startPageStackComponent

        Component {
            id: startPageStackComponent

            StartPage {
                id:startPage
            }
        }

        Component {
            id: mainPageStackComponent

            MainPage {
                id: mainPage
            }
        }
    }
}

