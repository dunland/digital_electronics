## 4. Frameworks

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
