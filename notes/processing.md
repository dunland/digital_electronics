# Processing cheatsheet  

## library compendium  

libraries are located in `/home/dav/sketchbook/libraries`

[PixelFlow](https://github.com/diwi/PixelFlow) is A Processing/Java library for high performance GPU-Computing (GLSL).  
> **Features:**  
>+ Fluid Simulation (GLSL)
    - Jos Stam, Real-Time Fluid Dynamics for Games
    - Particle Sytems
    - Flow Field Visualisation
    - Streamlines
    - ...
>+ Flow Field Particles (GLSL)
    - Collision Detection, Particle <-> Particle
    - Collision Detection, Particle <-> Obstacle
    - Cohesion
    - Verlet Integration
    - FlowField/SDF(Signed Distance Field) based
    - Streamlines
    - ...
>+ Softbody Dynamics (CPU, GLSL is coming)
    - 2D and 3D
    - Collision Detection
    - Cloth, Grids, Chains, Rigid Folding ...
    - Particle Systems
    - ...
>+ Skylight Renderer (GLSL)
    - Interactive/Realtime Viewport Renderer
    - Ambient Occlusion
    - Diffuse Shading
    - ShadowMapping
    - ...
>+ PostProcessing Filters (GLSL)
    - Box Blur
    - Binomial Blur
    - Gauss Blur
    - Gauss Blur Pyramid
    - Median
    - Bilateral Filter
    - Custom Convolution Kernel
    - DoG (Difference of Gaussian)
    - BackgroundSubtraction
    - Difference
    - Laplace
    - Sobel
    - Gamma Correction
    - Luminace
    - Thresholding
    - Harris Corner Detection
    - Optical Flow
    - Bloom
    - Depth of Field (DoF)
    - Liquid FX Filter
    - Summed Area Table (SAT)
    - Distance Transform (Jumpflood), Voronoi, Distance Map
    - Min/Max (global)
    - Min/Max (local)
    - Merge Shader
    - FlowField
    - Line Integral Convolution (LIC) / Streamlines
    - ...
>+ AntiAliasing (GLSL)
    - MSAA (Processing Default)
    - FXAA
    - SMAA
    - GBAA/DEAA
>+ Shadertoy (GLSL)
    - Wrapper for running existing Shadertoy sketches inside Processing.
>+ Utils
    - HalfEdge
    - Subdivision Polyhedra
    - Sampling
    - GLSL-Shader PreProcessor (#define, #include)
    - GLSL-Shader Uniform Caching
    - ...



[grafica](https://github.com/jagracar/grafica)  is a simple and configurable plotting library for Processing. With it you can easily create 2D plots that will enjoy the full interactive capabilities of Processing.

> **Main features**  
 >   - Make fancy scatter and linear plots that update in real time.
 >   - Display histograms in the vertical and horizontal directions.
 >   - Add several layers with different properties to the same plot.
 >   - It works both with linear and logarithmic scales.
 >   - Automatic axis tick determination.
 >   - Interactive zooming and panning. Make your data move!
 >   - Add labels to your points and display them with one click.
 >   - You can use svg files and PShapes to represent your points.
 >   - Highly customizable. Defaults are nice, but you can tweak almost everything.
 >   - Processing coding style. If you are used to work with Processing, grafica will be very easy.
 >   - It comes with a good set of examples.
 >   - It's open source. grafica is under the GNU Lesser General Public License. You can find the complete source code here.


## exporting gif animation with gifAnimation:  
http://extrapixel.github.io/gif-animation/
