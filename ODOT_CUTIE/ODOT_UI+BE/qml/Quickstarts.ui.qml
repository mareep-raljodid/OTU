

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
import QtQuick.Timeline 1.0

Item {
    id: quickstarts
    width: 480
    height: 272
    property alias textInput: textInput
    property alias image: image

    property int runDuration: 0
    signal detailsClicked
    signal applied


    Bigbutton {
        id: quickstartgo
        width: 121
        height: 130
        opacity: 0.177
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 100
        anchors.horizontalCenter: parent.horizontalCenter
        presetlabelText: "GO"

        Connections {
            target: quickstartgo
            onClicked: {
                ros.startRecord(textInput.text);
                applied()
            }
        }
    }

    Flatbackground {
        id: backgroundfull
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0

        Image {
            id: image2
            x: 284
            y: 79
            width: 111
            height: 115
            opacity: 0.287
            source: "assets/aa.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: image
            x: 279
            y: 73
            width: 120
            height: 127
            source: "assets/washdrumoutlne 2.png"
            fillMode: Image.PreserveAspectFit

            Text {
                id: text2
                x: 39
                y: 46
                color: "#d7eab2"
                text: qsTr("GO")
                font.pixelSize: 30
                styleColor: "#ffffff"
                font.family: "Maven Pro"
            }
        }

        Rectangle {
            id: rectangle1
            x: 8
            y: 114
            width: 219
            height: 63
            opacity: 1
            color: "#91babf"
        }

        Rectangle {
            id: rectangle
            x: 16
            y: 141
            width: 201
            height: 29
            opacity: 0.482
            color: "#ffffff"

            TextInput {
                id: textInput
                objectName:"inputText"
                x: 8
                y: 5
                width: 185
                height: 20
                text: qsTr("latest")
                font.pixelSize: 15
                font.family: "Times New Roman"
                renderType: Text.QtRendering
            }
        }


        Text {
            id: text1
            x: 16
            y: 116
            width: 83
            height: 15
            color: "#100e0e"
            text: qsTr("Custom Name:")
            font.pixelSize: 15
            font.family: "Maven Pro"
        }






    }











    Text {
        id: quickstrartlabel
        y: 37
        width: 323
        height: 46
        color: "#ffffff"
        text: "Start Recording?"
        font.pixelSize: 30
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenterOffset: -120
        anchors.horizontalCenter: parent.horizontalCenter
        font.family: "Maven Pro"
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.25}
}
##^##*/
