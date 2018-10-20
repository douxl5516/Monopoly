#ifndef OUT_DEVICE_H
#define OUT_DEVICE_H

class OutDevice
{
public:
	virtual ~OutDevice();
	virtual void draw(const char* pstr) = 0;
	virtual void drawLn(const char* pstr) = 0;
};

class PrinterDevice :public OutDevice {
public:
	virtual void draw(const char* pstr);
	virtual void drawLn(const char* pstr);
};

class OnlinePrinterDevice :public PrinterDevice {
public:
	virtual void draw(const char* pstr);
	virtual void drawLn(const char* pstr);
};

class PrinterDeviceProxy :public PrinterDevice {
public:
	virtual void draw(const char* pstr);
	virtual void drawLn(const char* pstr);
};

class StreamDevice :public OutDevice {
public:
	virtual void draw(const char* pstr);
	virtual void drawLn(const char* pstr);
};


class StreamDeviceDecorator :public StreamDevice {
public:
	StreamDeviceDecorator(StreamDevice* d);
	StreamDevice* device;
	virtual void draw(const char* pstr);
	virtual void drawLn(const char* pstr);
};

class StreamDeviceTabDecorator :public StreamDeviceDecorator {
public:
	StreamDeviceTabDecorator(StreamDevice* d);
	virtual void draw(const char* pstr);
	virtual void drawLn(const char* pstr);
private:
	void drawTab();
};

#endif // !OUT_DEVICE_H


