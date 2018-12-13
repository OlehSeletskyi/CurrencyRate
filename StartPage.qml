import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4


Item {
    ColumnLayout {
        id: columnLayout
        spacing: 10
        anchors.fill: parent
        anchors.margins: 5

        Calendar {
                id: calendar
                Layout.preferredWidth: columnLayout.width
                Layout.preferredHeight: 0.75 * columnLayout.height
                height: 250
                maximumDate: new Date()

                style: CalendarStyle {
                        gridVisible: false
                        dayDelegate: Rectangle {
                            gradient: Gradient {
                                GradientStop {
                                    position: 0.00
                                    color: styleData.selected ? "#111" : (styleData.visibleMonth && styleData.valid ? "#444" : "#666");
                                }
                                GradientStop {
                                    position: 1.00
                                    color: styleData.selected ? "#444" : (styleData.visibleMonth && styleData.valid ? "#111" : "#666");
                                }
                                GradientStop {
                                    position: 1.00
                                    color: styleData.selected ? "#777" : (styleData.visibleMonth && styleData.valid ? "#111" : "#666");
                                }
                            }

                            Label {
                                text: styleData.date.getDate()
                                anchors.centerIn: parent
                                color: styleData.valid ? "white" : "grey"
                            }

                            Rectangle {
                                width: parent.width
                                height: 1
                                color: "#555"
                                anchors.bottom: parent.bottom
                            }

                            Rectangle {
                                width: 1
                                height: parent.height
                                color: "#555"
                                anchors.right: parent.right
                            }
                        }
                    }

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

            buttonText: "OK"
            onClicked:
            {
                myDownloader.selectedDate = calendar.selectedDate
                selectedDate = myDownloader.selectedDate
                stackView.push(mainPageStackComponent)
            }
        }
    }
}
