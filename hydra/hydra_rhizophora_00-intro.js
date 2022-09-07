a.setBins(10)
a.show()

shape([ 3, 4, 5, 6, 7, 8, 9 ], () => a.fft[2] * 10)
	.colorama(5)
  .out(o0)

src(o0)
.modulateRepeat(noise(2), 3.0, 3.0, 0.5, 0.5)
.out(o1)

src(o1)
  .add(
  shape(3)
  .color(() => 0.48 + (Math.sin(time) * 0.18), 0.3, 0.79)
  //.colorama(0.1, 0, 0.1)
  .scale(1.5, 1, 1)
  .rotate(
    () => Math.sin(time)
  )
  .kaleid()
  .repeat(3,3)
  .kaleid(3)
	.modulateScale(osc(4,-0.5,0)  )
 )

.out(o2)

src(o2)
.rotate(2, 0.1)
.add(
  shape(3)
    .color(0.98, 0.3, 0.79)

    .rotate(2, 0.2)
    .kaleid()
    .repeat(2, 2)
    .blend(noise(20)
          .color(0.1, 0.3, 0.1)
          .pixelate(9))
    .kaleid(() => a.fft[0] * 3)
  )
.out(o3)

render()
