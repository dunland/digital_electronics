# teensy interrupts

## Types
- INTx_vect with CHANGE / RISING / FALLING for pin-monitoring --> **attachInterrupt() function**  
- TIMERx for timed interrupts --> **IntervalTimer library**  

## PIT (Periodic Interrupt Timer)
Can be used with the [IntervalTimer](https://github.com/loglow/IntervalTimer) library.  

#### Overview and usage

> Start a timer by creating a new `IntervalTimer` object and then calling it's `begin()` function, passing it the name of the function you'd like it to execute periodically (this is known as its callback function), as well as its period in microseconds (millionths of a second):

```
IntervalTimer timer0;
timer0.begin(timerCallback0, 5000000); // 5 seconds
```

> Once started, the specified callback function will be called at a regular interval. You can change a callback function simply by stopping the timer and restarting it. Your callback routines should have no return value nor any arguments, and they should contain as little code as necessary. Any external variables they modify should be marked as volatile. For example:

```
volatile uint32_t timerCounter0;
void timerCallback0() {
  timerCounter0++;
}
```

> Stop a timer by calling its `end()` function:

```
timer0.end();
```

#### Details and limitations

> Timers are dynamically allocated to hardware resources. A call to the `begin()` function will return true if the timer was able to be allocated and started, whereas it will return false if all hardware resources are already being used. A resource in use will become available to other timers after the timer using it has been stopped. At present you can have up to three IntervalTimer objects operating at any given time. Further development will increase this number.

> Currently, this library utilizes the PIT (Periodic Interrupt Timer) modules, of which there are four. However, only three are available for general use because one is being used by the built-in `tone()` functionality. The first timer to be allocated to a PIT module will enable the PIT clock and the last timer using a PIT module to be stopped will disable the PIT clock.

> Invalid period values will result in `begin()` returning `false`. Assuming the default bus speed of 48 MHz, any period value greater than `89478485` (slightly less than 89.5 seconds) will be considered invalid. This is because the timer periods are stored internally as a quantity of bus clock cycles, and the register storing this value has 32 bits of precision. A value of `0` is also considered to be invalid.

---

## attachInterrupt() function
[Arduino attachInterrupt() Reference](https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/)

> **Syntax**

> `attachInterrupt(digitalPinToInterrupt(pin), ISR, mode)` (recommended)  
> `attachInterrupt(interrupt, ISR, mode)` (not recommended)  
> `attachInterrupt(pin, ISR, mode)` (Not recommended. Additionally, this syntax only works on Arduino SAMD Boards, Uno WiFi Rev2, Due, and 101.)

> **Parameters**

> `interrupt`: the number of the interrupt. Allowed data types: `int`.  
> `pin`: the Arduino pin number.  
> `ISR`: the ISR to call when the interrupt occurs; this function must take no parameters and return nothing. This function is sometimes referred to as an interrupt service routine.  
> `mode`: defines when the interrupt should be triggered. Four constants are predefined as valid values:  
> 
> -   **LOW** to trigger the interrupt whenever the pin is low,  
>     
> -   **CHANGE** to trigger the interrupt whenever the pin changes value  
>     
> -   **RISING** to trigger when the pin goes from low to high,  
>     
> -   **FALLING** for when the pin goes from high to low.  
>     
> 
> The Due, Zero and MKR1000 boards allow also:  
> 
> -   **HIGH** to trigger the interrupt whenever the pin is high.

Example Code: 
``` C++
const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
}

void loop() {
  digitalWrite(ledPin, state);
}

void blink() {
  state = !state;
}
```
---

## Registers as explained in Teensy manual
**from p. 901 (Chapter 37 on Periodic Interrupt Timers):**  

Register	| Function	| Field | Function	| Value | Effect
----------------|---------------|-------|---------------|-------|-------- 
PIT_MCR		| enables or disables the PIT timer clocks and controls timers when PIT enters Debug mode | 1 MDIS | Module disable: disables module clock. mist be enabled before any other setup is done. | 0 | Clock for PIT timers enabled
-		|-		|-	|-		| 1	| Clock for timers disabled
-		|-		|0 FRZ	| Freeze: Allows the timers to be stopped when device enters Debug mode. | 0 | Timers continue to run in Debug mode
-		|-		|-	|-		|1	| timers are stopped in Debug mode
PIT\_LDVAL_n_	| select the timeout period for the timer interrupts | TSV| timer start value: timer counts down until 0, then triggers interrupt and loads this register value again. writing a new value to this register will not restart the timer; instead the value will be loaded after te timer expires. **to abort the current cycle and start a timer period with the new value, the timer must be disabled and enabled again**. with _IntervalTimer_-library: use timer.begin() instead of timer.update() to achieve this. | - | - 
PIT\_CVAL_n_	| indicate the current timer position | - | - | - | -
PIT\_TCTRL_n_	| contain the control bits for each timer | 2 CHN | Chain Mode: when activated, timer n-1 needs to expire before timer n can decrement by 1. (Timer 0 cannot be changed) | 0 | timer not chained
-		|-		|-	|-		| 1	| Timer is chained to previous timer.
-		|-		|TIE	|Timer Interrupt Enable: When an interrupt is pending, or, TFLGn[TIF] is set, enabling the interrupt will immediately cause an interrupt event. To avoid this, the associated TFLGn[TIF] must be cleared first. | 0 | Interrupt requests from Timer n are disabled.
-		|-		|-	|-		| 1	| Interrupt will be requested whenever TIF is set
-		|-		|0 TEN	| Enables or disables the timer | 0 | Timer n is disabled
-		|-		|-	|-				| 1 | Timer n is enabled
PIT\_TFLG_n_	| Timer flag register: holds the interrupt flags | 0 TIF | Timer interrupt flag: sets to 1 at the end of the timer period. Writing 1 to this flag clears it. Writing 0 has no effect. If enabled, or when TCTRLn[TIE] = 1, TIF causes an interrupt request | 0 | Timeout has not yet occured.
- 		|-		|-	|-		 | 1 | Timeout has occured.



---

## [Using Interrupts on Teensy, with C language](https://www.pjrc.com/teensy/interrupts.html)
(PJRC page on teensy interrupts...)

### Interrupt Basics

> Every interrupt has a flag bit, which is set by hardware when the interrupt trigger condition occurs. The flag's purpose is to remember the interrupt condition has occurred until it has been handled by software. An interrupt is said to be "pending" if the trigger condition has set the flag but the interrupt service routine has not been called yet, which can happen if the main program has disabled interrupts or another interrupt service routine is running.

> The flag bit is set even if interrupts are not used. Software polling can read the flag bit to check if the condition has occured, do whatever is necessary, and then reset the flag.

> Most interrupt flags are automatically reset when the interrupt service routine is called. Some flags must be reset by the software inside the interrupt service routine. Some flags are completely controlled by the peripheral to reflect internal state (such as USART receive) and can only be changed indirectly by manipulating the peripheral.

> Every interrupt also has a mask bit, which enable or disables that individual interrupt. These mask bits allow you to control which of the many interrupts are enabled. See below for a [complete list of mask and flag names](#names).

> There is also a global interrupt enable bit, which allows you to disable all interrupts and enable all interrupts that have their mask bits set. When the global interrupt enable is set, and individual masks are enabled, and interrupt flags are set, the corresponding interrupt vector is called for each flag.

### Interrupt Design Strategy

> The simplest and most common strategy is to keep all interrupt service routines short and simple, so they execute quickly, and to minimize time the main program disables interrupts. Virtually all examples follow this model.

> When the hardware calls an interrupt service routine, it clears the global interrupt flag, so that no other interrupt routine may be called. The return from an interrupt service routine automatically reenables interrupts, and if any other interrupt flags are set, the hardware will call the next pending interrupt routine rather than returning to the main program.

> A less common strategy is called "nested interrupts", where the some interrupt service routines enable the global interrupt with sei(). Usually this is done when an interrupt routine may take a very long time to execute, and some other interrupt routine is considered very urgent and can not be blocked from running. Great caution is needed to make sure the already-in-service interrupt can not trigger again, leading to the hardware calling the interrupt routine over and over until the entire memory is overwritten!

> Generally, it is safest to never use sei() within any interrupt service routine. 


### Interrupt Vector, Mask & Flag Names

**ISR() Name**: The name used with ISR() to define the interrupt service routine.

**Mask**: (byte,bit#) Bit that enables this interrupt. See [accessing a single bit](moz-extension://aed13e24-8afb-496d-9580-ddd851bddc28/pins.html#single_bit) for C syntax to write byte,bit# pairs.

**Flag**: (byte,bit#) Flag indicates if the interrupt is pending. Many flags are reset by writing 1 (yes, that seems horribly backwards, but that's the way the hardware works). Most flags are automatically reset when the interrupt service routine is called.

| ISR() Name | Mask | Flag | Function |
| --- | --- | --- | --- |
| INT0\_vect | EIMSK,IINT0 | EIFR,INTF0 | Interrupt Request, External Signal |
| INT1\_vect | EIMSK,IINT1 | EIFR,INTF1 |
| INT2\_vect | EIMSK,IINT2 | EIFR,INTF2 |
| INT3\_vect | EIMSK,IINT3 | EIFR,INTF3 |
| INT4\_vect | EIMSK,IINT4 | EIFR,INTF4 |
| INT5\_vect | EIMSK,IINT5 | EIFR,INTF5 |
| INT6\_vect | EIMSK,IINT6 | EIFR,INTF6 |
| INT7\_vect | EIMSK,IINT7 | EIFR,INTF7 |
| PCINT0\_vect | PCICR,PCIE0 | PCIFR,PCIF0 | Pin Change |
| PCINT1\_vect | PCICR,PCIE1 | PCIFR,PCIF1 |
| TIMER0\_COMPA\_vect | TIMSK0,OCIE0A | TIFR0,OCF0A | Timer 0 Compare A Match |
| TIMER0\_COMPB\_vect | TIMSK0,OCIE0B | TIFR0,OCF0B | Timer 0 Compare B Match |
| TIMER0\_OVF\_vect | TIMSK0,TOIE0 | TIFR0,TOV0 | Timer 0 Overflow |
| TIMER1\_CAPT\_vect | TIMSK1,ICIE1 | TIFR1,ICF1 | Timer 1 Input Capture |
| TIMER1\_COMPA\_vect | TIMSK1,OCIE1A | TIFR1,OCF1A | Timer 1 Compare A Match |
| TIMER1\_COMPB\_vect | TIMSK1,OCIE1B | TIFR1,OCF1B | Timer 1 Compare B Match |
| TIMER1\_COMPC\_vect | TIMSK1,OCIE1C | TIFR1,OCF1C | Timer 1 Compare C Match |
| TIMER1\_OVF\_vect | TIMSK1,TOIE1 | TIFR1,TOV1 | Timer 1 Overflow |
| WDT\_vect | WDTCSR,WDIE | WDTCSR,WDIF | Watchdog Timer |
| USART1\_RX\_vect | UCSR1B,RXCIE1 | UCSR1A,RXC1 | USART Receive |
| USART1\_TX\_vect | UCSR1B,TXCIE1 | UCSR1A,TXC1 | USART Transmit Complete |
| USART1\_UDRE\_vect | UCSR1B,UDRIE1 | UCSR1A,UDRE1 | USART Transmit Ready |
| SPI\_STC\_vect | SPCR,SPIE | SPSR,SPIF | SPI Transfer Complete |
| ANALOG\_COMP\_vect | ACSR,ACIE | ACSR,ACI | Analog Comparison Change |
| EE\_READY\_vect | EECR,EERIE | (none) | EEPROM Operation Complete |
| USB\_GEN\_vect | (complex) | (complex) | USB Device Event |
| USB\_COM\_vect | (very complex) | (very complex) | USB Communication |

## more stuff on C-programmed interrupts
http://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html
[Interrupts short and simple](https://www.embedded.com/interrupts-short-and-simple-part-1-good-programming-practices/)

