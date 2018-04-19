import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.XmlListModel 2.0

Item {
    id: myitem

    ColumnLayout {
        id: columnLayout
        spacing: 5
        anchors.fill: parent
        Rectangle {
            Layout.preferredWidth: columnLayout.width
            height: 40
            color: "#00867d"
            RowLayout {
                id: rowlayout
                Layout.preferredWidth: columnLayout.width
                MyButton {
                    id: back
                    height: 25
                    width: 25
                    Layout.alignment: Qt.AlignLeft

                    color: "transparent"
                    hoverColor: "#82e9de"
                    pressColor: "#82e9de"

                    fontSize: 18
                    borderRadius: 15
                    borderWidth: 0

                    buttonText: "<"
                    onClicked: {
                        stackView.push(startPageStackComponent)
                    }
                }

                Text {
                    id: currencyRate
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                    font.pointSize: 20
                    font.bold: true
                    text: "Курс валюти"
                    color: "#FAFAFA"
                }
            }
        }
        TextField {
            id: findCurrency
            Layout.fillWidth: true
            Layout.leftMargin: 5
            Layout.rightMargin: 5
            font.pointSize: 12
            placeholderText: "Пошук валюти"
            onTextChanged: {
                MyProxyModel.setFilterFixedString(text)
            }
        }
        ListView {
            id: listView
            Layout.fillWidth:  true
            Layout.fillHeight: true
            Layout.leftMargin: 5
            Layout.rightMargin: 5
            clip : true
            spacing: 15

            model: MyProxyModel

            delegate: ItemDelegate {
                Rectangle {
                    id: currency
                    width: listView.width
                    height: 55
                    color: "#26a69a"
                    radius: 7
                    ColumnLayout {
                        id: currencyColumnLayout
                        width: currency.width
                        anchors.fill: parent
                        anchors.leftMargin: 5
                        anchors.rightMargin: 5
                        RowLayout {
                            id: currencyRowLayout
                            anchors.fill: parent
                            width: currency.width
                            height: currency.height
                            Text {
                                font.pointSize: 18
                                font.bold: true
                                text: shortName
                            }
                            Text {
                                anchors.horizontalCenter: currencyRowLayout.horizontalCenter
                                font.pointSize: 18
                                font.bold: true
                                text: rate
                                color: "white"
                            }
                            Text {
                                anchors.right: currencyRowLayout.right
                                font.pointSize: 13
                                text: rateDifference == 0 ? "0" : rateDifference
                                color: rateDifference >= 0 ?(rateDifference == 0 ? "#0000FF" : "#00FF00") : "#FF0000"
                            }
                        }
                        Text {
                            font.pointSize: 13
                            font.bold: true
                            text: name
                            color: "#610B0B"
                        }
                    }
                }
            }
        }
    }
}
