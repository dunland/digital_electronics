a.setBins(10)
a.show()

shape(3) // .diff(noise(2).pixelate(200))
    .color(0.2, 0.5, 0.8)

    .rotate(2, 0.2)
    .kaleid()
    .repeat(2, 2)
    .diff(noise(20).pixelate(9))
    .kaleid(() => a.fft[0])
    .out(o0)

src(o0)
    .diff(shape([ 3, 4, 5, 6, 7, 8, 9 ], () => a.fft[2] * 10)
              .color(0.98, 0.3, 0.79))
    .scrollY(2)
    // .colorama(9)
    .out(o1)

src(o1)
    .blend(voronoi(20)
    .posterize(20)
    .color(() => Math.sin(time) * 0.05, 0.3, 0.6))
    .out(o2)

render(o0)
