"hello world".postln()

f = {arg phase;	[SinOsc.ar(freq: 440,phase: 0,mul: 1,add: 0.2), SinOsc.ar(442,phase,0.2)]}.play;
phase.postln;
f.value(1.rand)

(
f = { arg a; a.value + 3 };    // call 'value' on the arg; polymorphism awaits!
f.value(3);            // 3.value = 3, so this returns 3 + 3 = 6
g = { 3.0.rand; };
f.value(g);            // here the arg is a Function. Cool, huh?
f.value(g);            // try it again, different result
)


(
{
  var snare, bdrum, hihat;
  var tempo = 4;

  tempo = Impulse
	.ar(tempo); // for a drunk drummer replace Impulse with Dust !!!
  snare = WhiteNoise.ar(Decay2.ar(PulseDivider.ar(tempo, 4, 2), 0.005, 0.5));
  bdrum = SinOsc.ar(Line.ar(120,60, 1), 0, Decay2.ar(PulseDivider.ar(tempo, 4, 0), 0.005, 0.5));
  hihat = HPF.ar(WhiteNoise.ar(1), 10000) * Decay2.ar(tempo, 0.005, 0.5);

  Out.ar(0, (snare + bdrum + hihat) * 0.4 ! 2)
}.play
)
