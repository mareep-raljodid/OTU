

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
    property alias image3: image3
    property alias quickstartdetails: quickstartdetails

    property int runDuration: 0
    signal detailsClicked
    signal applied


    Flatbackground {
        id: backgroundfull
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0

        Image {
            id: image2
            x: 286
            y: 97
            width: 84
            height: 79
            opacity: 0.287
            source: "assets/aa.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: image3
            x: 108
            y: 97
            width: 84
            height: 79
            opacity: 0.287
            source: "assets/aa.png"
            fillMode: Image.PreserveAspectFit
        }


    }

    Bigbutton {
        id: quickstartgo
        width: 84
        height: 89
        opacity: 1
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 1
        anchors.horizontalCenterOffset: 88
        anchors.horizontalCenter: parent.horizontalCenter
        presetlabelText: "GO"

        Connections {
            target: quickstartgo
            onClicked: {
                applied()
            }
        }
    }






    Bigbutton {
        id: quickstartdetails
        width: 113
        height: 110
        opacity: 1
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: -90
        anchors.horizontalCenter: parent.horizontalCenter
        presetlabelText: "Set Param"

        Connections {
            target: quickstartdetails
            onClicked: {
                detailsClicked()
            }
        }
    }





    Text {
        id: quickstrartlabel
        y: 29
        width: 323
        height: 46
        color: "#ffffff"
        text: "Start Recording?"
        font.pixelSize: 30
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenterOffset: 1
        anchors.horizontalCenter: parent.horizontalCenter
        font.family: "Maven Pro"
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.75}
}
##^##*/
