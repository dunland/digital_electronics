// licensed with CC BY-NC-SA 4.0
// https://creativecommons.org/licenses/by-nc-sa/4.0/ acid bus seat by Will
// Humphreys https://github.com/TheWispy

// ----------------------------- 1 -------------------------------
// osc(Math.random()*100).out()

// ------------------------     2 ---------------------------------
noise(51).out(o0)

// ------------------------ 3 solid with 3 colors: -----------------
// solid(0.1,.51,1)
//  .out()

// ------------------------------- 4: shape -------------------------
// shape(8, 0.75, 0.5) // will cover 75% of screen with 50% smooth edge
//  .out()

// ------------------------ 5: experimenting with color: ------------
// noise(6,0.05)
// .brightness(-0.5)
// .contrast(0.3,0.5,1)
// .color(0,0.3,0.127362873587325)
// .posterize(3) poster effect
//.colorama(1)
// .out()

// ------------------------ 6 : scroll and scale ---------------------
// noise(6, 0.05)
// 	.scrollX(0.3, 0.5)
// 	.scale(0.3)
//   .out()

// noise(6,0.5)
// .pixelate(10,30)
// .out()

// ------------------------------- oscillators ------------------------
// noise(4).out()
// osc(60, 0.1)
//     // .modulate(noise(4, 0.07)) // by, strength
//     // .modulateScale(noise(4),0.3)
//     .modulateRotate(noise(4), 0.9)
//     .out()

// --------------------------- kalleidoscope ------------------------
// osc(60, 0.1)
// .kaleid(3)
// .modulateKaleid(noise(5), 0.1)
// .out()

// ------------------------------- maths ------------------------
// osc(60, 0.1)
//     .blend(noise(16), 0.2)
//     .add(noise(3))    // add
//     .mult(noise(123)) // multiply
//     .out()

// ------------------------ Camera and sound ----------------------

// Camera:
// s0.initCam()
// osc(60,0.01)
// .diff(src(s0))
//
// // Sound:
// .modulateScale(noise(4), () => a.fft[0])
// .out()
//
// a.show()

// ----------------------------------------------------------------
osc(12.3, 0.1, 0.7) // freq, speed of moving, phase
    .rotate(0.0, 0.2)
    .mult(osc(12.5, 0.1, 0.5, 0.7))
    .contrast([ 1, 1.55 ].smooth().fast(3)) // jumps between parameters by using
                                            // array --> smooth() smooehtes them
    .modulate(src(o0)) //  feedback -------------------------------

    .out(o1)

// render() // --> o0, o1, o2, o3 in different window sections
// render(o1) // -> shows selected output only

src(o1)
    .color(0.6, 0.3, 0.6)
    .modulateRotate(src(o1).posterize(3).scale(0.8), 0.1)
    .out(o1)

render()
