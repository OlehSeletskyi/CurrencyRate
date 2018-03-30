import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2


Window {
    visible: true
    width: 250
    height: 380
    maximumWidth: 250
//    maximumHeight: 380
    minimumWidth: 250
    minimumHeight: 380
    title: qsTr("Currency Rate")


    StackView {
            id: stackView
            anchors.fill: parent
            focus: true
            initialItem: startPageStackComponent

            Component {
                id: startPageStackComponent

                StartPage {
                    id:startPage
//                    anchors.fill: parent
//                    enabled: Stack.status === Stack.Active
                }

            }

            Component {
                id: mainPageStackComponent

                MainPage {
                    id: mainPage
//                    anchors.fill: parent
                }


            }
    }





}

