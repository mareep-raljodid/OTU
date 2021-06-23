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
    id: quickstarts
    width: 480
    height: 272

    signal canceled
    signal accepted

    Flatbackground {
        id: backgroundfull
        anchors.fill: parent

        Image {
            id: image
            x: 112
            y: 85
            width: 75
            height: 100
            opacity: 0.275
            source: "assets/aa.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: image1
            x: 293
            y: 86
            width: 75
            height: 100
            opacity: 0.275
            source: "assets/aa.png"
            fillMode: Image.PreserveAspectFit
        }
    }

    Bigbutton {
        id: quickstartdetails
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: -90
        anchors.horizontalCenter: parent.horizontalCenter
        presetlabelText: "No"

        Connections {
            target: quickstartdetails
            onClicked: {
                canceled()
            }
        }
    }

    Bigbutton {
        id: quickstartgo
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: 90
        anchors.horizontalCenter: parent.horizontalCenter
        presetlabelText: "Yes"

        Connections {
            target: quickstartgo
            onClicked: {
                ros.stopRecord("ROS CANCELLED");
                accepted()
            }
        }
    }

    Text {
        id: quickstrartlabel
        y: 42
        height: 32
        color: "#ffffff"
        text: "Stop and Save bag file?"
        font.pixelSize: 30
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.family: "Maven Pro"
    }
}


/*##^##
Designer {
    D{i:0;height:272;width:480}
}
##^##*/
