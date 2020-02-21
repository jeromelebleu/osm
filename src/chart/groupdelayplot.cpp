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
#include "groupdelayplot.h"
#include "groupdelayseriesrenderer.h"
#include <QtMath>

using namespace Fftchart;

GroupDelayPlot::GroupDelayPlot(Settings *settings, QQuickItem *parent): FrequencyBasedPlot(settings, parent)
{
    x.configure(AxisType::logarithmic, 20.f, 20000.f);
    x.setISOLabels();
    y.configure(AxisType::linear,
                -50.f * static_cast<float>(M_PI) / 500,  //min
                50.f  * static_cast<float>(M_PI) / 500,   //max
                21,     //ticks
                500.f / static_cast<float>(M_PI)    //scale
                );
    y.setMin(-40.f * static_cast<float>(M_PI) / 500);
    y.setMax( 10.f * static_cast<float>(M_PI) / 500);
    setFlag(QQuickItem::ItemHasContents);
}
SeriesFBO* GroupDelayPlot::createSeriesFromSource(Source *source)
{
    return new SeriesFBO(source, [](){return new GroupDelaySeriesRenderer();}, this);
}
void GroupDelayPlot::setSettings(Settings *settings) noexcept
{
    if (settings && (settings->value("type") == "Group Delay")) {
        FrequencyBasedPlot::setSettings(settings);
    }
}
void GroupDelayPlot::storeSettings() noexcept
{
    if (!m_settings)
        return;

    FrequencyBasedPlot::storeSettings();
}