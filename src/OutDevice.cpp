#include "OutDevice.h"
#include <iostream>
using namespace std;

void StreamDevice::draw(const char * pstr)
{
	cout << pstr;
}

void StreamDevice::drawLn(const char * pstr)
{
	cout << pstr << endl;
}

OutDevice::~OutDevice()
{
}

StreamDeviceDecorator::StreamDeviceDecorator(StreamDevice * d):device(d)
{
}

void StreamDeviceDecorator::draw(const char * pstr)
{
	device->draw(pstr);
}

void StreamDeviceDecorator::drawLn(const char * pstr)
{
	device->drawLn(pstr);
}

StreamDeviceTabDecorator::StreamDeviceTabDecorator(StreamDevice * d):StreamDeviceDecorator(d)
{
}

void StreamDeviceTabDecorator::draw(const char * pstr)
{
	drawTab();
	StreamDeviceDecorator::draw(pstr);
}

void StreamDeviceTabDecorator::drawLn(const char * pstr)
{
	drawTab();
	StreamDeviceDecorator::drawLn(pstr);
}

void StreamDeviceTabDecorator::drawTab()
{
	cout << "\t";
}

void PrinterDevice::draw(const char * pstr)
{
	cout << "print " << pstr << "to printer"<<endl;
}

void PrinterDevice::drawLn(const char * pstr)
{
	cout << "print " << pstr << endl << "to printer" << endl;
}

void PrinterDeviceProxy::draw(const char * pstr)
{
	OutDevice* d=new PrinterDevice();
	d->draw(pstr);
	delete d;
}

void PrinterDeviceProxy::drawLn(const char * pstr)
{
	OutDevice* d = new OnlinePrinterDevice();
	d->drawLn(pstr);
	delete d;
}

void OnlinePrinterDevice::draw(const char * pstr)
{
	cout << "print " << pstr << "to online printer" << endl;
}

void OnlinePrinterDevice::drawLn(const char * pstr)
{
	cout << "print " << pstr << endl << "to online printer" << endl;
}
