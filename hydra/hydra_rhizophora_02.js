a.setBins(10)

shape(3)
    .rotate(2, 0.1)
    .kaleid(2)
    .repeat(2, 2)
    .kaleid(() => a.fft[3])
    .diff(noise(2).pixelate(2))
    // .diff(noise(2).pixelate(200))
    .out(o0)

src(o0).diff(
  shape([3,4,5,6,7,8,9], () => a.fft[0]))
  .scrollY(2)
  .colorama(10)
.out(o1)
render()

// osc().modulate(noise(2, () => a.fft[0])).out(o2)
// a.show()
// render(o2)

    // render(o0)
