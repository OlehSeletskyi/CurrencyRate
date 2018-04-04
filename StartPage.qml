import QtQuick 2.0
import QtQuick.Layouts 1.3

Item {
    ColumnLayout {
        id: columnLayout
        spacing: 10
        anchors.fill: parent
        anchors.margins: 5
        Image {
            Layout.alignment: Qt.AlignHCenter
            source: "ico-money.png"
            sourceSize.width: 250
            sourceSize.height: 250
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
            }
        }
    }
}
