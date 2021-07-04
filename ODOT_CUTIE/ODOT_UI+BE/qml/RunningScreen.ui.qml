

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
import QtQuick 2.11

Item {
    id: runningScreen
    width: 480
    height: 272
    property alias rectangle: rectangle
    property alias image: image
    property alias running: running
    property alias bigbutton: bigbutton
    state: "RunScreen"

    signal runFinished
    signal startRun

    property int runDuration: 20
    property bool activated: false

    Running {
        id: running
        x: 0
        y: 0


        runDuration: runningScreen.runDuration
        activated: runningScreen.activated

        Flatbackground {
            id: flatbackground
            x: 425
            y: 0
        }

        Connections {
            target: running

            onRunFinished: runningScreen.runFinished()

            onStopRun: runningScreen.state = "CancelScreen"
        }

        Bigbutton {
            id: bigbutton
            x: 50
            y: 107
            presetlabelText: "Camera"
        }

        Image {
            id: image
            x: 55
            y: 120
            width: 73
            height: 53
            source: "assets/camera.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: image1
            x: 55
            y: 112
            width: 73
            height: 74
            opacity: 0.336
            source: "assets/aa.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: image2
            x: 46
            y: 100
            width: 88
            height: 94
            source: "assets/drumcopy_temp.png"
            fillMode: Image.PreserveAspectFit
        }

        Rectangle {
            id: rectangle
            x: 8
            y: 8
            width: 126
            height: 63
            opacity: 0.1
            color: "#2a1a1a"
        }
    }

    RunningCancelation {
        id: cancelationScreen
        x: 0
        y: 0

        visible: false

        Connections {
            target: cancelationScreen
            onCanceled: runningScreen.state = "RunScreen"
        }

        Connections {
            target: cancelationScreen
            onAccepted: running.runFinished()
        }
    }

    Connections {
        target: runningScreen
        onStartRun: {
            runningScreen.state = "RunScreen"
            running.startRun()
        }
    }

    states: [
        State {
            name: "RunScreen"

            PropertyChanges {
                target: running
                visible: true
            }

            PropertyChanges {
                target: cancelationScreen
                visible: false
            }
        },
        State {
            name: "CancelScreen"
            PropertyChanges {
                target: running
                visible: false
            }

            PropertyChanges {
                target: cancelationScreen
                visible: true
            }
        }
    ]
}
