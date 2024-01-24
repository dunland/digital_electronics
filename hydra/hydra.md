# hydra

## enable developing

1. `public/index.html`: comment line with bundle.min.js, uncomment line with bundle.js
2. `yarn dev`

## enable offline usage

1. 
``` bash
cd github/hydra
npm install --save hydra-synth
npm install p5
```
2. copy `hydra-synth` from `node_js` folder to `public` and import in `index.html`: `<script src="hydra-synth/dist/hydra-synth.js"></script>`
3. copy `p5` from `node_js` folder to `public` and import in `index.html`:  `<script src="p5/p5.min.js" defer></script>`

## hotkeys

- `Ctrl+Shift+H`: view/hide code

## functions

``` javascript
function r(min=0,max=1) { return Math.random()*(max-min)+min; }
 
solid(1,1,1)
  	.diff(shape([4,4,4,24].smooth().fast(.5),r(0.6,0.93),.09).repeat(20,10))
	.modulateScale(osc(8).rotate(r(-.5,.5)),.52)
	.add(
  		src(o0).scale(0.965).rotate(.012*(Math.round(r(-2,1))))
  		.color(r(),r(),r())
    	.modulateRotate(o0,r(0,0.5))
  		.brightness(.15)
  		,.7)
	.out()
```
