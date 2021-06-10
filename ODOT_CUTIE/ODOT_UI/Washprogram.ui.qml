/****************************************************************************
**
** Copyright (C) 2021 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Design Studio.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.8

Item {
    id: washprogramScreen
    width: 480
    height: 272

    signal canceled
    signal applied

    signal resetSettings

    property int runDuration: washProgramSettings.timeInt

    Washprogramgrid {
        id: washProgramGrid
        y: 1
        width: 270
        height: 270
        visible: true

        Connections {
            target: washProgramGrid
            onActiveItemChanged: {
                washProgramSettings.activeItem = washProgramGrid.activeItem
            }
        }

        colorLabel: washProgramSettings.colorStr
        soilLabel: washProgramSettings.soilStr
        fabricLabel: washProgramSettings.fabricStr
        timeLabel: washProgramSettings.timeStr
        temperatureLabel: washProgramSettings.temperatureStr
        timerLabel: washProgramSettings.timerStr
        weightLabel: washProgramSettings.weightStr
        spinLabel: washProgramSettings.spinStr
        waterLabel: washProgramSettings.waterStr
    }

    Flatbackground {
        id: backgroundfull
        visible: true
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0


        Rectangle {
            id: rectangle
            x: 15
            y: 13
            width: 407
            height: 98
            opacity: 0.238
            visible: true
            color: "#ffffff"

            Rectangle {
                id: rectangle1
                x: 208
                y: 0
                width: 198
                height: 98
                visible: true
                color: "#99b4fb"
            }
        }
        Text {
            id: text1
            x: 35
            y: 22
            width: 131
            height: 18
            visible: true
            color: "#000000"
            text: qsTr("ROS Launch File Path:")
            font.pixelSize: 13
            font.family: "Maven Pro"
        }

        Rectangle {
            id: rectangle4
            x: 15
            y: 117
            width: 108
            height: 141
            opacity: 0.202
            visible: true
            color: "#b9ca70"


            Rectangle {
                id: rectangle8
                x: 146
                y: 81
                width: 92
                height: 52
                visible: true
                color: "#ffffff"
            }


            Rectangle {
                id: rectangle7
                x: 8
                y: 81
                width: 92
                height: 52
                visible: true
                color: "#ffffff"
            }


        }

        Text {
            id: text2
            x: 35
            y: 52
            width: 131
            height: 18
            visible: true
            color: "#000000"
            text: qsTr("ROS Launch Package Name:")
            font.pixelSize: 13
            font.family: "Maven Pro"

            Rectangle {
                id: rectangle10
                x: 388
                y: -51
                width: 57
                height: 32
                opacity: 0.214
                visible: true
                color: "#1e1111"
            }
        }


        Text {
            id: text3
            x: 35
            y: 86
            width: 131
            height: 18
            visible: true
            color: "#000000"
            text: qsTr("ROS Latest Bag Default Name:")
            font.pixelSize: 13
            font.family: "Maven Pro"
        }


        Rectangle {
            id: rectangle2
            x: 15
            y: 41
            width: 407
            height: 5
            opacity: 0.324
            visible: true
            color: "#353b4f"
        }



        Image {
            id: image
            x: 22
            y: 123
            width: 95
            height: 73
            visible: true
            source: "assets/camera.png"
            fillMode: Image.PreserveAspectFit
        }






        Rectangle {
            id: rectangle5
            x: 153
            y: 117
            width: 108
            height: 141
            opacity: 0.202
            visible: true
            color: "#b9ca70"
        }

        Rectangle {
            id: rectangle6
            x: 288
            y: 117
            width: 177
            height: 85
            opacity: 0.202
            visible: true
            color: "#b9ca70"

            Rectangle {
                id: rectangle9
                x: 91
                y: 16
                width: 78
                height: 61
                visible: true
                color: "#ffffff"
            }
        }

        BorderImage {
            id: borderImage
            x: 304
            y: 216
            width: 32
            height: 33
            opacity: 0.202
            visible: true
            source: "assets/aa.png"
        }

        BorderImage {
            id: borderImage1
            x: 416
            y: 216
            width: 32
            height: 33
            opacity: 0.214
            visible: true
            source: "assets/aa.png"
        }
        Image {
            id: image1
            x: 165
            y: 123
            width: 83
            height: 68
            visible: true
            source: "assets/lidar.png"
            fillMode: Image.PreserveAspectFit
        }
        Image {
            id: image2
            x: 294
            y: 123
            width: 82
            height: 73
            visible: true
            source: "assets/map.png"
            fillMode: Image.PreserveAspectFit
        }

        Rectangle {
            id: rectangle3
            x: 15
            y: 77
            width: 407
            height: 5
            opacity: 0.324
            visible: true
            color: "#353b4f"
        }
    }

    Washprogramsettings {
        id: washProgramSettings
        x: 288
        y: 31
        width: 175
        height: 233
        opacity: 1
        visible: true

        Connections {
            target: washProgramSettings

            onCancelClicked: {
                washprogramScreen.canceled()
            }

            onApplyClicked: {
                washprogramScreen.applied()
            }
        }
    }

    Connections {
        target: washprogramScreen
        onResetSettings: {
            washProgramSettings.resetSettingsScreen()

            washProgramGrid.activeItem = 4
        }
    }
}


/*##^##
Designer {
    D{i:0;formeditorZoom:1.5;height:272;width:480}D{i:22}
}
##^##*/
