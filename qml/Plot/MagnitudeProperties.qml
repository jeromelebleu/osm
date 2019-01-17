/**
 *  OSM
 *  Copyright (C) 2019  Pavel Smokotnin

 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.3

import "../" as Root

Item {
    id: chartProperties
    property var dataObject

    ColumnLayout {
        spacing: 0

    RowLayout {
        spacing: 0

        SpinBox {
            value: dataObject.xmin
            onValueChanged: dataObject.xmin = value
            from: dataObject.xLowLimit
            to: dataObject.xHighLimit
            editable: true
            ToolTip.visible: hovered
            ToolTip.text: qsTr("x from")
        }

        SpinBox {
            value: dataObject.xmax
            onValueChanged: dataObject.xmax = value
            from: dataObject.xLowLimit
            to: dataObject.xHighLimit
            editable: true
            ToolTip.visible: hovered
            ToolTip.text: qsTr("x to")
        }

        SpinBox {
            value: dataObject.ymin
            onValueChanged: dataObject.ymin = value
            from: dataObject.yLowLimit
            to: dataObject.yHighLimit
            editable: true
            ToolTip.visible: hovered
            ToolTip.text: qsTr("y from")
        }

        SpinBox {
            value: dataObject.ymax
            onValueChanged: dataObject.ymax = value
            from: dataObject.yLowLimit
            to: dataObject.yHighLimit
            editable: true
            ToolTip.visible: hovered
            ToolTip.text: qsTr("y to")
        }
    }
    RowLayout {
        spacing: 0

        Root.TitledCombo {
            title: qsTr("ppo")
            model: [3, 6, 12, 24, 48]
            currentIndex: {
                var ppo = dataObject.pointsPerOctave;
                model.indexOf(ppo);
            }
            onCurrentIndexChanged: {
                var ppo = model[currentIndex];
                dataObject.pointsPerOctave = ppo;
            }
        }

        Button {
            text: qsTr("Save Image");
            onClicked: fileDialog.open();
        }

        FileDialog {
            id: fileDialog
            selectExisting: false
            title: "Please choose a file's name"
            folder: shortcuts.home
            defaultSuffix: "png"
            onAccepted: {
                dataObject.parent.grabToImage(function(result) {
                    result.saveToFile(dataObject.parent.urlForGrab(fileDialog.fileUrl));
                });
            }
        }
    }

  }
}
