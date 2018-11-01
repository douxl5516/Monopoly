///======================================================================
///  Project:   Richer03
/// FileName:	outdevice.h
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#ifndef OUTDEVICE_H
#define OUTDEVICE_H
#include <iostream>
using namespace std;

class OutDevice
{
public:
    static OutDevice& getConsole();
    static OutDevice& getTabConsole();
    static OutDevice& createStreamDevice();
    static OutDevice& createPrinterDevice();
    static OutDevice& createWindowDevice();
public:
    OutDevice() {}
    virtual ~OutDevice() {}
    virtual const OutDevice& draw(const char* str) const = 0;
    virtual const OutDevice& drawLn(const char* str = "") const = 0;
protected:

private:
};

class StreamDevice: public OutDevice
{
public:
    StreamDevice(ostream& ss = cout): stream(ss) {}
    virtual ~StreamDevice() {}
    virtual const OutDevice& draw(const char* str) const override;
    virtual const OutDevice& drawLn(const char* str = "") const override;
private:
    ostream& stream;
};

class PrinterDevice: public OutDevice
{
public:
    PrinterDevice();
    virtual ~PrinterDevice();
    virtual const OutDevice& draw(const char* str) const override;
    virtual const OutDevice& drawLn(const char* str = "") const override;
};

class WindowDevice: public OutDevice
{
public:
    WindowDevice();
    virtual ~WindowDevice();
    virtual const OutDevice& draw(const char* str) const override;
    virtual const OutDevice& drawLn(const char* str = "") const override;
};

///-----------------------------------------
///
///-----------------------------------------
class DeviceDecorator: public OutDevice
{
public:
    DeviceDecorator(OutDevice& comp): component(comp) {}
    virtual ~DeviceDecorator() {}
    virtual const OutDevice& draw(const char* str) const;
    virtual const OutDevice& drawLn(const char* str = "") const ;
protected:
    OutDevice& component;
};

class TabDeviceDecorator: public DeviceDecorator
{
public:
    TabDeviceDecorator(OutDevice& comp): DeviceDecorator(comp) {}
    virtual ~TabDeviceDecorator() {}
    virtual const OutDevice& draw(const char* str) const;
    virtual const OutDevice& drawLn(const char* str = "") const ;
};

#endif // OUTDEVICE_H
