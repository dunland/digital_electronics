/*
1. render(o0)
2. render(o1)
3. render(o2)
4. render(o3)
5. output o3->o0, render(o0)

*/


a.setBins(10)
a.setScale(1)
a.show()


shape([ 3, 4, 5, 6, 7, 8, 9 ], () => a.fft[1] * 0.1)
	.colorama(5)
  .out(o0)

src(o0)
.modulateRepeat(noise(2), 3.0, 3.0, 0.5, 0.5)
.out(o1)

src(o1)
.rotate(2, 0.1)
.add(
  shape(3)
    .color(0.98, 0.3, 0.79)

    .rotate(2, 0.2)
    .kaleid()
    .repeat(2, 2)
    .blend(noise(20)
          .color(0.1, 0.3, 0.1)
          //.pixelate(9)
          )
    .kaleid(() => a.fft[0] * 3)
  )
.out(o2)

src(o2)
.scale(3,1,1)
  .diff(
    shape(3)
    .color(() => 0.48 + (Math.sin(time) * 0.18), 0.3, 0.79)
    .colorama(0.1, 0, 0.1)
    .scale(1.5, 1, 1)
    .rotate(Math.sin(time)
  )
  .kaleid()
  .repeat(3,3)
  //.kaleid(() => a.fft[2])
  .modulateRotate(osc(1, 0.11, 0.2))
 )
.out(o3) // .out(o0) // geht ab!


render(o0)
