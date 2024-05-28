#pragma once
#include "Adafruit_GFX.h"
#include "SerialWombat.h"

class SerialWombat18ABVGADriver : public Adafruit_GFX
{
public:
	SerialWombat18ABVGADriver(SerialWombat18ABVGA& vga) ;

	void drawPixel(int16_t x, int16_t y, uint16_t color);
	void fillScreen(uint16_t color);
	virtual void fillRect(int16_t x, int16_t y, int16_t w, int16_t h,
		uint16_t color);

private:
	SerialWombat18ABVGA& _vga;
	uint8_t pixelsSinceYield = 0;
};

