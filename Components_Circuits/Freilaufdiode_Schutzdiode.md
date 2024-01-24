https://electronics.stackexchange.com/questions/242504/how-do-i-actually-put-a-diode-across-a-motor

>What you're talking about is called a "freewheel diode", which gives the inductive voltage spikes a place to go when the motor is stopped. The anode of the diode needs to go on the negative wire and the cathode of the diode (with the stripe) needs to go on the positive wire of the motor. This way the diode will not conduct during normal operation, but when the motor is suddenly stopped a reverse voltage is present, which is able to flow through the diode. This is a very simple explanation, the theory actually is a lot deeper than this, but this should give you an idea.

>The switches and the rest of the circuitry stay right where they are. Just connect the diode backwards between the motor terminals.

![[schutzdiode_schaltplan.png]]