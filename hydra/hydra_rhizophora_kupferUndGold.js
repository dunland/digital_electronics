a.setScale(10)

osc(8,-0.5, 1)
  .color(-1.5, -1.5, -1.5)
  .blend(o0)
  .rotate(-0.5, -0.5)
  .modulate(
  	shape(4)
  	.rotate(0.5, 0.5)
  	.scale(2)
  	.repeatX(2, 2)
  	.modulate(
      o0, () => a.fft[2])
  	.repeatY(2, 2))
  .out(o0)







