# teensy

## Serial connection

When **Serial connection breaks** (on Linux) after <1s, use Tools->CPU Speed: 72 MHz and set Baud rate to 115200. Port: `/dev/ttyACM0 Serial (Teensy 3.2)`

[Teensy Using USB Serial Communication](https://www.pjrc.com/teensy/td_serial.html)
> Unlike a standard Arduino, the Teensy Serial object always communicates at 12 Mbit/sec USB speed. Many computes, especially older Macs, can not update the serial monitor window if there is no delay to limit the speed!

> **Serial.begin()**  
Initialize the Serial object. The baud rate is ignored and communication always occurs at full USB speed.

## teensy 3.2 ADC / Analog Reads

according to [this video](https://www.youtube.com/watch?v=tZ1hdDT41Yc) the ADC speed results in ~10 microseconds

[Using Analog Inputs Guideline on PJRC.com](https://www.pjrc.com/teensy/adc.html)
Also see the section on **Sampling at free Running Speed**!

### implementation in C

see [analog.c](analog.c) [analog.h](analog.h) for reference

``` C++
// Arduino compatible pin input
int16_t analogRead(uint8_t pin)
{
#if defined(__AVR_ATmega32U4__)
	static const uint8_t PROGMEM pin_to_mux[] = {
		0x00, 0x01, 0x04, 0x05, 0x06, 0x07,
		0x25, 0x24, 0x23, 0x22, 0x21, 0x20};
	if (pin >= 12) return 0;
	return adc_read(pgm_read_byte(pin_to_mux + pin));
#elif defined(__AVR_AT90USB646__) || defined(__AVR_AT90USB1286__)
	if (pin >= 8) return 0;
	return adc_read(pin);
#else
	return 0;
#endif
}

// Mux input
int16_t adc_read(uint8_t mux)
{
#if defined(__AVR_AT90USB162__)
	return 0;
#else
	uint8_t low;

	ADCSRA = (1<<ADEN) | ADC_PRESCALER;		// enable ADC
	ADCSRB = (1<<ADHSM) | (mux & 0x20);		// high speed mode
	ADMUX = aref | (mux & 0x1F);			// configure mux input
	ADCSRA = (1<<ADEN) | ADC_PRESCALER | (1<<ADSC);	// start the conversion
	while (ADCSRA & (1<<ADSC)) ;			// wait for result
	low = ADCL;					// must read LSB first
	return (ADCH << 8) | low;			// must read MSB only once!
#endif
}


```
