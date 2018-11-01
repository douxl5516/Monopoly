///======================================================================
///  Project:   Richer03
/// FileName:	outdevice.cpp
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#include "outdevice.h"

OutDevice& OutDevice::getConsole()
{
    static StreamDevice console;
    return console;
}
OutDevice& OutDevice::getTabConsole()
{
    static TabDeviceDecorator console(OutDevice::getConsole());
    return console;
}

const OutDevice& StreamDevice::draw(const char* str) const
{
    stream << str;
    return *this;

}
const OutDevice& StreamDevice::drawLn(const char* str) const
{
    stream << str << "\n";
    return *this;
}
///-----------------------------------------
///
///-----------------------------------------
const OutDevice& DeviceDecorator::draw(const char* str) const
{
    return component.draw(str);
}
const OutDevice& DeviceDecorator::drawLn(const char* str) const
{
    return component.drawLn(str);
}
///-----------------------------------------
const OutDevice& TabDeviceDecorator::draw(const char* str) const
{
    return component.draw("\t").draw(str);
}
const OutDevice& TabDeviceDecorator::drawLn(const char* str) const
{
    return component.draw("\t").drawLn(str);
}
