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
    property alias image3: image3
    property alias image5: image5
    property alias bigbutton: bigbutton

    signal canceled
    signal applied
    signal onCamScr
    signal resetSettings

    property int runDuration: washProgramSettings.timeInt

    Washprogramgrid {
        id: washProgramGrid
        x: 0
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
            id: rectangle4
            x: 62
            y: 33
            width: 101
            height: 141
            opacity: 0.202
            visible: true
            color: "#b9ca70"


            Rectangle {
                id: rectangle8
                x: 116
                y: 72
                width: 93
                height: 61
                visible: true
                color: "#ffffff"
            }


            Rectangle {
                id: rectangle7
                x: 10
                y: 72
                width: 83
                height: 61
                visible: true
                color: "#ffffff"
            }


        }





        Image {
            id: image
            x: 93
            y: 33
            width: 52
            height: 73
            visible: true
            source: "assets/camera.png"
            fillMode: Image.PreserveAspectFit
        }






        Rectangle {
            id: rectangle5
            x: 169
            y: 33
            width: 108
            height: 141
            opacity: 0.202
            visible: true
            color: "#b9ca70"
        }

        Rectangle {
            id: rectangle6
            x: 283
            y: 33
            width: 104
            height: 141
            opacity: 0.202
            visible: true
            color: "#b9ca70"

            Rectangle {
                id: rectangle9
                x: 8
                y: 72
                width: 88
                height: 61
                visible: true
                color: "#ffffff"
            }
        }

        BorderImage {
            id: borderImage1
            x: 424
            y: 223
            width: 35
            height: 37
            opacity: 0.494
            visible: true
            source: "assets/aa.png"
        }
        Image {
            id: image1
            x: 193
            y: 43
            width: 61
            height: 54
            visible: true
            source: "assets/lidar.png"
            fillMode: Image.PreserveAspectFit
        }
        Image {
            id: image2
            x: 304
            y: 45
            width: 54
            height: 50
            visible: true
            source: "assets/map.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: image5
            x: 408
            y: 33
            width: 55
            height: 61
            source: "assets/bigbuttoniconarc.png"
            fillMode: Image.PreserveAspectFit
        }

        Rectangle {
            id: rectangle
            x: 62
            y: 189
            width: 325
            height: 37
            opacity: 0.579
            color: "#ffffff"

            Text {
                id: text1
                x: 47
                y: 11
                color: "#000000"
                text: qsTr("IP Adress:")
                font.pixelSize: 12
                font.family: "Maven Pro"
                minimumPixelSize: 16
                renderType: Text.QtRendering
                textFormat: Text.PlainText
            }

            Rectangle {
                id: rectangle1
                x: 108
                y: 8
                width: 209
                height: 21
                color: "#ffffff"
            }
        }

        Image {
            id: image6
            x: 68
            y: 193
            width: 38
            height: 29
            visible: true
            source: "assets/camera.png"
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: text2
            x: 414
            y: 100
            width: 45
            height: 16
            color: "#ff0404"
            text: qsTr("[LIVE] cam")
            font.pixelSize: 9
            styleColor: "#ff2222"
            font.family: "Maven Pro"
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

        Image {
            id: image4
            x: 117
            y: 4
            width: 62
            height: 56
            opacity: 0.2
            source: "assets/aa.png"
            fillMode: Image.PreserveAspectFit

            Rectangle {
                id: rectangle2
                x: 0
                y: -2
                width: 62
                height: 88
                opacity: 0.518
                color: "#110909"
            }
        }

        Connections {
            target: washProgramSettings

            onCancelClicked: {
                presetsScreen.state = "StartScreen"
            }

            onApplyClicked: {
                washprogramScreen.applied()
            }

        }

        Image {
            id: image3
            x: 122
            y: 14
            width: 53
            height: 36
            opacity: 0.567
            source: "assets/camera.png"
            fillMode: Image.PreserveAspectFit
        }

    }

    Connections {
        target: washprogramScreen
        onResetSettings: {
            washProgramSettings.resetSettingsScreen()

            washProgramGrid.activeItem = 4
        }
    }

    Bigbutton {
        id: bigbutton
        x: 396
        y: 21
        opacity: 0
    }
}


/*##^##
Designer {
    D{i:0;formeditorZoom:1.5;height:272;width:480}
}
##^##*/
