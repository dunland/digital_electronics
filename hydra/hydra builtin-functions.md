## Source

**noise**
`noise(scale = 10, offset = 0.1)`
- scale: int, smaller numbers result in bigger patches
- offset = movement speed

**voronoi**
`voronoi(scale = 5, speed = 0.3, blending = 0.3)`
- scale: int, number of cells
- speed: movement speed
- blending: color blending between the cells

**osc**
`osc (frequency = 60, sync = 0.1, offset)`
- frequency: stripe density
- sync = scroll speed
- offset: adds color to the pattern
*one cycle of an oscillator in the screen space can be achieved by `osc(Math.PI * 2)`*

**shape**`
`shape(sides = 3, radius = 0.3, smoothing = 0.01)`
- sides: number of sides of the geometry
- radius: size of the shape
- smoothing: float (0 to 1), *Ausfransen der Seiten*
## Audio

- `a.setBins(8)` – number of bins
- `a.setScale(10)` – amplitude / reaction threshold
- `a.setSmooth(float)` – reaction time
- `a.setCutoff(int)`
- `a.fft[bin]` – use as function: 
``` javaScript
osc(60, 0.1, () => a.fft[2])
```

## Geometry

## Color

## Blend

## Modulate

**modulateRotate**
`modulateRotate( texture, multiple = 1, offset )`

## Math
`Math.sin(time)`