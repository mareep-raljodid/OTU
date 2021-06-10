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
    id: washprogramitem
    width: 85
    height: 84
    property alias temperatureiconoffSource: temperatureiconoff.source
    property alias washprogramiconSource: washprogramicon.source
    property alias currentvaluelabelText: currentvaluelabel.text

    property bool toggled: false

    signal pressed

    Image {
        id: hoverbackground
        x: 0
        y: 0
        source: "assets/hoverbackground.png"
    }

    Image {
        id: lineseperator
        y: 59
        source: "assets/lineseperator.png"
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: currentvaluelabel
        y: 62
        width: 49
        height: 16
        color: "#B8B8B8"
        text: "LAUNCH"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.family: "Maven Pro"
    }

    Image {
        id: washprogramicon
        anchors.bottom: lineseperator.top
        source: "assets/washprogramicon.png"
        anchors.bottomMargin: 5
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Image {
        id: temperatureiconoff
        y: 10
        anchors.bottom: lineseperator.top
        source: "assets/pluginIcon.png"
        anchors.horizontalCenterOffset: 2
        anchors.bottomMargin: 4
        anchors.horizontalCenter: parent.horizontalCenter
        fillMode: Image.PreserveAspectFit
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        Connections {
            target: mouseArea
            onClicked: washprogramitem.toggled = true
            onPressed: washprogramitem.pressed()
        }
    }
    states: [
        State {
            name: "default"
            when: !toggled && !mouseArea.pressed

            PropertyChanges {
                target: hoverbackground
                visible: false
            }

            PropertyChanges {
                target: washprogramicon
                visible: false
            }

            PropertyChanges {
                target: temperatureiconoff
                visible: true
            }
        },
        State {
            name: "pressed"
            when: mouseArea.pressed

            PropertyChanges {
                target: hoverbackground
                visible: true
            }

            PropertyChanges {
                target: washprogramicon
                visible: true
            }

            PropertyChanges {
                target: temperatureiconoff
                visible: false
            }
        },
        State {
            name: "active"
            when: toggled

            PropertyChanges {
                target: hoverbackground
                visible: false
            }

            PropertyChanges {
                target: washprogramicon
                visible: true
            }

            PropertyChanges {
                target: temperatureiconoff
                visible: false
            }
        }
    ]
}


/*##^##
Designer {
    D{i:0;height:84;width:85}
}
##^##*/
