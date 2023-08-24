from https://thebookofshaders.com/:
GLSL = openGL Shading Language

## [2. Hello World](https://thebookofshaders.com/02/)

change all pixels to one color:
``` C
#ifdef GL_ES // compile for mobile devices
precision mediump float; // set floats to medium precision → faster rendering
// precision lowp float;
// precision highp float;
#endif

uniform float u_time;

void main() {
	gl_FragColor = vec4(1.0,0.0,1.0,1.0); // define pixel color R,G,B,A
	// gl_FragColor = vec4(1,0,0,1);   // ERROR, no floating points used!
}
```

- `vec4` = 4-dimensional vector of floating point precision
- `#...` = preprocessor macro (pre-compilation)

## [3. Uniforms](https://thebookofshaders.com/03/)

> You can picture the uniforms like little bridges between the CPU and the GPU.

```glsl
#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;  // Canvas size (width,height)
uniform vec2 u_mouse;       // mouse position in screen pixels
uniform float u_time;       // Time in seconds since load

void main() {
	vec2 st = (gl_FragCoord.xy/u_resolution) * u_mouse.xy + 0.01;
	gl_FragColor = vec4(st.x,st.y,0.0,abs(sin(u_time)));
}

```

> As you can see GLSL has more surprises. The GPU has hardware accelerated angle, trigonometric and exponential functions. Some of those functions are: [`sin()`](https://thebookofshaders.com/glossary/?search=sin), [`cos()`](https://thebookofshaders.com/glossary/?search=cos), [`tan()`](https://thebookofshaders.com/glossary/?search=tan), [`asin()`](https://thebookofshaders.com/glossary/?search=asin), [`acos()`](https://thebookofshaders.com/glossary/?search=acos), [`atan()`](https://thebookofshaders.com/glossary/?search=atan), [`pow()`](https://thebookofshaders.com/glossary/?search=pow), [`exp()`](https://thebookofshaders.com/glossary/?search=exp), [`log()`](https://thebookofshaders.com/glossary/?search=log), [`sqrt()`](https://thebookofshaders.com/glossary/?search=sqrt), [`abs()`](https://thebookofshaders.com/glossary/?search=abs), [`sign()`](https://thebookofshaders.com/glossary/?search=sign), [`floor()`](https://thebookofshaders.com/glossary/?search=floor), [`ceil()`](https://thebookofshaders.com/glossary/?search=ceil), [`fract()`](https://thebookofshaders.com/glossary/?search=fract), [`mod()`](https://thebookofshaders.com/glossary/?search=mod), [`min()`](https://thebookofshaders.com/glossary/?search=min), [`max()`](https://thebookofshaders.com/glossary/?search=max) and [`clamp()`](https://thebookofshaders.com/glossary/?search=clamp).

## [4. Running your shader](https://thebookofshaders.com/04/)

using **three.js**, **Processing**, **openframeworks**

## Tools

- [glslCanvas](https://github.com/patriciogonzalezvivo/glslCanvas): Simple tool to load GLSL shaders on HTML Canvas using WebGL


## References & Galleries

- https://www.shadertoy.com/
- https://openframe.io: a platform for displaying digital art (using a Raspberry Pi??)