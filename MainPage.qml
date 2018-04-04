import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.XmlListModel 2.0

Item {

    ColumnLayout {
        id: columnLayout
        spacing: 10
        anchors.fill: parent
        anchors.margins: 5
        Text {
            id: currencyRate
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            font.pointSize: 20
            font.bold: true
            text: "Курс валюти"
            color: "#FAFAFA"
        }

        TextField {
            id: findCurrency
            font.pointSize: 12
            color: "#FAFAFA"
            placeholderText: "Пошук валюти"
            onTextChanged: {
                MyProxyModel.setFilterFixedString(text)
            }
        }
            ListView {
                id: listView
                Layout.preferredWidth: columnLayout.width
                Layout.fillHeight: true
                clip : true
                model: MyProxyModel
                spacing: 15
                delegate: ItemDelegate {
                    Rectangle {
                        id: currency
                        width: columnLayout.width
                        height: 55
                        color: "#424242"
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
                                    color: "#013ADF"
                                }
                                Text {
                                    anchors.horizontalCenter: currencyRowLayout.horizontalCenter
                                    font.pointSize: 18
                                    font.bold: true
                                    text: rate
                                    color: "#E6E6E6"
                                }
                                Text {
                                    anchors.right: currencyRowLayout.right
                                    font.pointSize: 12
                                    text: rateDifference
                                    color: rateDifference >= 0 ? "#00FF00" : "red"
                                }
                            }
                            Text {
                                font.pointSize: 12
                                font.bold: true
                                text: name
                                color: "#0080FF"
                            }
                        }
                    }
                }
            }
    }
}
