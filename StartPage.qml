import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4



Item {
    ColumnLayout {
        id: columnLayout
        spacing: 10
        anchors.fill: parent
        anchors.margins: 5
//        Image {
//            Layout.alignment: Qt.AlignHCenter
//            source: "ico-money.png"
//            sourceSize.width: 250
//            sourceSize.height: 250
//        }
        Calendar {
                id: calendar
                Layout.preferredWidth: columnLayout.width
                height: 250
                maximumDate: new Date()

        }
        MyButton
        {
            id: look
            height: 50
            width: 150
            Layout.alignment: Qt.AlignHCenter

            borderWidth: 0
            hoverColor: "#00867d"
            pressColor: "#00867d"
            fontSize: 18

            buttonText: "Гледіти"
            onClicked:
            {
                stackView.push(mainPageStackComponent)
                myDownloader.mSelectedDate = calendar.selectedDate
            }
        }
    }
}
