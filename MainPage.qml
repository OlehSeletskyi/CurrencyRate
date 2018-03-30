import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.XmlListModel 2.0
import QListModel 1.0


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
        }

        TextField {
            id: findCurrency
            font.pointSize: 12

            placeholderText: "Пошук валюти"
        }
//        Repeater {
//               model: ListModel {
//                   id: theModel
//                   ListElement { shortName: "PLN"; name: "gray"; rate: "7.71" }
//                   ListElement { shortName: "BRL"; name: "yellow"; rate: "17.88" }
//                   ListElement { shortName: "TJS"; name: "blue"; rate: "5.72" }
//                   ListElement { shortName: "RUB"; name: "orange"; rate: "7.73" }
//                   ListElement { shortName: "RSD"; name: "orange"; rate: "4.62" }
//                   ListElement { shortName: "BYN"; name: "yellow"; rate: "3.12" }
//                   ListElement { shortName: "DZD"; name: "lightBlue"; rate: "2.64" }
//                   ListElement { shortName: "AZN"; name: "lightBlue"; rate: "8.35" }
//               }
//        }

//        XmlListModel {
//            id: xmlModel
//            source: "https://bank.gov.ua/NBUStatService/v1/statdirectory/exchange"
//            query: "/exchange/currency"

//            XmlRole { name: "txt"; query: "txt/string()" }
//            XmlRole { name: "rate"; query: "rate/string()" }
//            XmlRole { name: "cc"; query: "cc/string()" }
//        }

            QListModel{
                id: dataModel

            }

            ListView {
                id: listView
                Layout.preferredWidth: columnLayout.width
                Layout.fillHeight: true
                model: dataModel.data()
                spacing: 15
                delegate: ItemDelegate {
                    Rectangle {
                        id: currency
                        width: columnLayout.width
                        height: 50
                        color: "grey"
                        radius: 10

                        ColumnLayout {
                            id: currencyColumnLayout
                            anchors.fill: parent
                            anchors.leftMargin: 5
                            spacing: -25

                            RowLayout {
                                id: currencyRowLayout
                                anchors.fill: parent
                                width: currency.width
                                Text {
                                    font.pointSize: 18
                                    font.bold: true
                                    text: cc
                                }
                                Text {
                                    anchors.horizontalCenter: currencyRowLayout.horizontalCenter
                                    font.pointSize: 18
                                    font.bold: true
                                    text: rate
                                }
                            }
                            Text {
                                font.pointSize: 12
                                font.bold: true
                                text: txt
                            }
                        }
                    }
                }
            }
    }
}
