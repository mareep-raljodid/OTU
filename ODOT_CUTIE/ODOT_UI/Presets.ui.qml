

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
    id: presets
    width: 480
    height: 272

    property int duration: 20
    signal presetSelected

    Flatbackground {
        id: backgroundfull
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: -7
        anchors.topMargin: 0

        Rectangle {
            id: rectangle
            x: 95
            y: 8
            width: 324
            height: 79
            color: "#d4fbf3"

            Text {
                id: text1
                x: 8
                y: 8
                width: 135
                height: 15
                color: "#02676d"
                text: qsTr("Last Bag Date/Time:")
                font.pixelSize: 14
                font.family: "Maven Pro"
            }

            Text {
                id: text2
                x: 8
                y: 29
                width: 243
                height: 15
                color: "#02676d"
                text: qsTr("Current Sensors' Status: ")
                font.pixelSize: 14
                font.family: "Maven Pro"
            }

            Text {
                id: text3
                x: 8
                y: 50
                width: 135
                height: 15
                color: "#02676d"
                text: qsTr("Last Bag Location:")
                font.pixelSize: 14
                font.family: "Maven Pro"
            }
        }

        Text {
            id: text4
            x: 18
            y: 118
            width: 304
            height: 36
            color: "#ffffff"
            text: qsTr("ODOT Recording Options:")
            font.pixelSize: 25
            font.family: "Maven Pro"
        }
    }

    Text {
        id: presetlabel
        y: 32
        width: 52
        height: 38
        color: "#ffffff"
        text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:'Titillium Web'; font-size:13pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Current</p>\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Status</p></body></html>"
        font.pixelSize: 17
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignTop
        textFormat: Text.RichText
        anchors.horizontalCenterOffset: -197
        anchors.horizontalCenter: parent.horizontalCenter
        font.family: "Maven Pro"

        Presetscroll {
            id: presetscroll
            x: 52
            y: -10
            width: 19
            height: 59
        }
    }

    Presetsroll {
        id: presetscrollinstance
        width: 480
        height: 95
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 81
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter

        Connections {
            target: presetscrollinstance

            onPresetSelected: {
                presets.duration = presetscrollinstance.duration

                presets.presetSelected()
            }
        }

        Image {
            id: image
            x: 18
            y: 8
            width: 84
            height: 79
            opacity: 0.275
            source: "assets/aa.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: image1
            x: 138
            y: 7
            width: 84
            height: 79
            opacity: 0.275
            source: "assets/aa.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: image2
            x: 258
            y: 7
            width: 84
            height: 79
            opacity: 0.275
            source: "assets/aa.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: image3
            x: 378
            y: 7
            width: 84
            height: 79
            opacity: 0.275
            source: "assets/aa.png"
            fillMode: Image.PreserveAspectFit
        }
    }
}
