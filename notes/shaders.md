# shaders

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

- [glslCanvas](https://github.com/patriciogonzalezvivo/glslCanvas): Simple tool to load GLSL shaders on HTML Canvas using WebGL
- [glslViewer](https://github.com/patriciogonzalezvivo/glslViewer): Console-based GLSL Sandbox for 2D/3D shaders
- [glslEditor](https://github.com/patriciogonzalezvivo/glslEditor): Simple WebGL Fragment Shader Editor - http://editor.thebookofshaders.com/ 
- [glslGallery](https://github.com/patriciogonzalezvivo/glslGallery): a tool to curate your shaders into a gallery that can be embedded on any site

- Three.js
- Processing
- OpenFrameworks
- SFML
- Blender

### openframeworks
will look for shaders in data folder.
```cpp
void ofApp::draw(){
    ofShader shader;
    shader.load("","shader.frag");

    shader.begin();
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofRect(0,0,ofGetWidth(), ofGetHeight());
    shader.end();
}
```

[OpenFrameworks shader tutorial](https://openframeworks.cc/ofBook/chapters/shaders.html)


## 5. Shaping Functions

- Polynomial Shaping Functions: www.flong.com/archive/texts/code/shapers_poly    
- Exponential Shaping Functions: www.flong.com/archive/texts/code/shapers_exp    
- Circular & Elliptical Shaping Functions: www.flong.com/archive/texts/code/shapers_circ
- Bezier and Other Parametric Shaping Functions: www.flong.com/archive/texts/code/shapers_bez
- Inigo Quilez: https://iquilezles.org/articles/functions/
- [GraphToy](http://www.iquilezles.org/apps/graphtoy/): once again [Iñigo Quilez](http://www.iquilezles.org) made a tool to visualize GLSL functions in WebGL.
- [LYGIA Shader Library](https://lygia.xyz/) a shader library of reusable functions that can be include easily on your projects.
- https://easings.net/: Gallery of easing functions! **Easing functions** specify the rate of change of a parameter over time.

## 6. Colors
Another great feature of vector types in GLSL is that the properties can be combined in any order you want, which makes it easy to cast and mix values. This ability is called _swizzle_.

```Cpp
vec3 yellow, magenta, green;

// Making Yellow
yellow.rg = vec2(1.0);  // Assigning 1. to red and green channels
yellow[2] = 0.0;        // Assigning 0. to blue channel

// Making Magenta
magenta = yellow.rbg;   // Assign the channels with green and blue swapped

// Making Green
green.rgb = yellow.bgb; // Assign the blue channel of Yellow (0) to red and blue channels
```

```Cpp
// Mix uses pct (a value from 0-1) to
// mix the two colors
color = mix(colorA, colorB, pct);
```

## Tools

- [glslCanvas](https://github.com/patriciogonzalezvivo/glslCanvas): Simple tool to load GLSL shaders on HTML Canvas using WebGL


## References & Galleries

- https://www.shadertoy.com/
- https://openframe.io: a platform for displaying digital art (using a Raspberry Pi??)
