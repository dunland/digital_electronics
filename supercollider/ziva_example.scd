Quarks.install("https://github.com/loopier/ziva");
Quarks.install("Bjorklund");
Quarks.install("ddwCommon");
Quarks.install("https://github.com/supercollider/sc3-plugins/");

Ziva.boot;
// Ziva.boot(inputChannels:2, outputChannels:2);
// Ziva.boot(numBuffers:16, memSize:32, maxNodes:32);`

// Supercollider:
TempoClock(130); // BPM

// Ziva:
Ziva.loadSamples(Platform.userAppSupportDir++"/downloaded-quarks/ziva/samples"); // not necessary since the samples are preloaded...
Ziva.sounds; // display all available samples
Ziva.synths; // display available synths
Ziva.rhythms; // give me all the available rhythms

// define samples and synths:
~sample_1 = Psample(\delia);
~sample_2 = Psample(\aewaw, 1);
~synth_1 = Psynth(\reese);

// ---------------------------- basics: ----------------------------
(
[
	~sample_1.dur(1/3).pan(-0.5), // triplet duration with panning 0.5 left
	// ~sample_1.pan(-0.5), // from -1(L) to 1(R)
	~sample_2.ff, //p = piano, pp = pianissimo, ppp = pianississsisisismo; f/ff/fff
	~synth_1.fast; // fast, faster, fastest
].ziva;
)


// ------------------------- polyrhyhtmics: -------------------------
(
[
	// samples:
	~sample_1.pan(-0.5).bj(5,9).faster, // polyrhythm
	~sample_2.pan(1).oct(3).bj(2,5).faster, // panning does not work for synths!

	// synths:
	~synth_1.bj(5,9).faster, // polyrhythm
	~synth_1.oct(3).bj(2,5).faster,
	nil

].ziva;
)

// ----------------------------- scales: -----------------------------

~acid = Psynth(\acid);
~saw = Psynth(\saw);

(
[
	~acid.deg([0,2b,4]).legato(); // play chord

].ziva();
)

// --------------------------- tracks and FX --------------------------
Ziva.track(0, \distort, \reverb); // how to use this?

(
[
	~acid.deg(Pseq([0,2,4],inf)).faster,

	nil
].ziva;
)

// what is this?
Bjorklund(3,5)
[1, r, 1, r, 1 ]
[1, r, 1, r, r ]
Ziva.controls(\acid);