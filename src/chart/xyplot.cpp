/**
 *  OSM
 *  Copyright (C) 2018  Pavel Smokotnin

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
#include "xyplot.h"

using namespace Fftchart;

XYPlot::XYPlot(QQuickItem *parent) :
    Plot(parent),
    x(AxisDirection::horizontal, this),
    y(AxisDirection::vertical, this)
{}

qreal XYPlot::x2v(qreal mouseX) const noexcept
{
    return x.coordToValue(mouseX);
}
qreal XYPlot::y2v(qreal mouseY) const noexcept
{
    return y.coordToValue(mouseY);
}
