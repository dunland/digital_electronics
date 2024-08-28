``` python
for alg in QgsApplication.processingRegistry().algorithms():
        print(alg.id(), "->", alg.displayName())
```

3d:tessellate -> Tessellate
gdal:aspect -> Aspect
gdal:assignprojection -> Assign projection
gdal:buffervectors -> Buffer vectors
gdal:buildvirtualraster -> Build virtual raster
gdal:buildvirtualvector -> Build virtual vector
gdal:cliprasterbyextent -> Clip raster by extent
gdal:cliprasterbymasklayer -> Clip raster by mask layer
gdal:clipvectorbyextent -> Clip vector by extent
gdal:clipvectorbypolygon -> Clip vector by mask layer
gdal:colorrelief -> Color relief
gdal:contour -> Contour
gdal:contour_polygon -> Contour Polygons
gdal:convertformat -> Convert format
gdal:dissolve -> Dissolve
gdal:executesql -> Execute SQL
gdal:extractprojection -> Extract projection
gdal:fillnodata -> Fill nodata
gdal:gdal2tiles -> gdal2tiles
gdal:gdal2xyz -> gdal2xyz
gdal:gdalinfo -> Raster information
gdal:gridaverage -> Grid (Moving average)
gdal:griddatametrics -> Grid (Data metrics)
gdal:gridinversedistance -> Grid (Inverse distance to a power)
gdal:gridinversedistancenearestneighbor -> Grid (IDW with nearest neighbor searching)
gdal:gridlinear -> Grid (Linear)
gdal:gridnearestneighbor -> Grid (Nearest neighbor)
gdal:hillshade -> Hillshade
gdal:importvectorintopostgisdatabaseavailableconnections -> Export to PostgreSQL (available connections)
gdal:importvectorintopostgisdatabasenewconnection -> Export to PostgreSQL (new connection)
gdal:merge -> Merge
gdal:nearblack -> Near black
gdal:offsetcurve -> Offset curve
gdal:ogrinfo -> Vector information
gdal:onesidebuffer -> One side buffer
gdal:overviews -> Build overviews (pyramids)
gdal:pansharp -> Pansharpening
gdal:pcttorgb -> PCT to RGB
gdal:pointsalonglines -> Points along lines
gdal:polygonize -> Polygonize (raster to vector)
gdal:proximity -> Proximity (raster distance)
gdal:rastercalculator -> Raster calculator
gdal:rasterize -> Rasterize (vector to raster)
gdal:rasterize_over -> Rasterize (overwrite with attribute)
gdal:rasterize_over_fixed_value -> Rasterize (overwrite with fixed value)
gdal:rearrange_bands -> Rearrange bands
gdal:retile -> Retile
gdal:rgbtopct -> RGB to PCT
gdal:roughness -> Roughness
gdal:sieve -> Sieve
gdal:slope -> Slope
gdal:tileindex -> Tile index
gdal:tpitopographicpositionindex -> Topographic Position Index (TPI)
gdal:translate -> Translate (convert format)
gdal:triterrainruggednessindex -> Terrain Ruggedness Index (TRI)
gdal:viewshed -> Viewshed
gdal:warpreproject -> Warp (reproject)
grass7:i.albedo -> i.albedo
grass7:i.aster.toar -> i.aster.toar
grass7:i.atcorr -> i.atcorr
grass7:i.biomass -> i.biomass
grass7:i.cca -> i.cca
grass7:i.cluster -> i.cluster
grass7:i.colors.enhance -> i.colors.enhance
grass7:i.eb.eta -> i.eb.eta
grass7:i.eb.evapfr -> i.eb.evapfr
grass7:i.eb.hsebal01.coords -> i.eb.hsebal01.coords
grass7:i.eb.netrad -> i.eb.netrad
grass7:i.eb.soilheatflux -> i.eb.soilheatflux
grass7:i.emissivity -> i.emissivity
grass7:i.evapo.mh -> i.evapo.mh
grass7:i.evapo.pm -> i.evapo.pm
grass7:i.evapo.pt -> i.evapo.pt
grass7:i.evapo.time -> i.evapo.time
grass7:i.fft -> i.fft
grass7:i.gensig -> i.gensig
grass7:i.gensigset -> i.gensigset
grass7:i.group -> i.group
grass7:i.his.rgb -> i.his.rgb
grass7:i.ifft -> i.ifft
grass7:i.image.mosaic -> i.image.mosaic
grass7:i.in.spotvgt -> i.in.spotvgt
grass7:i.landsat.acca -> i.landsat.acca
grass7:i.landsat.toar -> i.landsat.toar
grass7:i.maxlik -> i.maxlik
grass7:i.modis.qc -> i.modis.qc
grass7:i.oif -> i.oif
grass7:i.pansharpen -> i.pansharpen
grass7:i.pca -> i.pca
grass7:i.rgb.his -> i.rgb.his
grass7:i.segment -> i.segment
grass7:i.smap -> i.smap
grass7:i.tasscap -> i.tasscap
grass7:i.topo.coor.ill -> i.topo.coor.ill
grass7:i.topo.corr -> i.topo.corr
grass7:i.vi -> i.vi
grass7:i.zc -> i.zc
grass7:m.cogo -> m.cogo
grass7:nviz -> nviz
grass7:r.basins.fill -> r.basins.fill
grass7:r.blend.combine -> r.blend.combine
grass7:r.blend.rgb -> r.blend.rgb
grass7:r.buffer -> r.buffer
grass7:r.buffer.lowmem -> r.buffer.lowmem
grass7:r.carve -> r.carve
grass7:r.category -> r.category
grass7:r.category.out -> r.category.out
grass7:r.circle -> r.circle
grass7:r.clump -> r.clump
grass7:r.coin -> r.coin
grass7:r.colors -> r.colors
grass7:r.colors.out -> r.colors.out
grass7:r.colors.stddev -> r.colors.stddev
grass7:r.composite -> r.composite
grass7:r.contour -> r.contour
grass7:r.cost -> r.cost
grass7:r.covar -> r.covar
grass7:r.cross -> r.cross
grass7:r.describe -> r.describe
grass7:r.distance -> r.distance
grass7:r.drain -> r.drain
grass7:r.fill.dir -> r.fill.dir
grass7:r.fill.stats -> r.fill.stats
grass7:r.fillnulls -> r.fillnulls
grass7:r.flow -> r.flow
grass7:r.geomorphon -> r.geomorphon
grass7:r.grow -> r.grow
grass7:r.grow.distance -> r.grow.distance
grass7:r.gwflow -> r.gwflow
grass7:r.his -> r.his
grass7:r.horizon -> r.horizon
grass7:r.horizon.height -> r.horizon.height
grass7:r.in.lidar -> r.in.lidar
grass7:r.in.lidar.info -> r.in.lidar.info
grass7:r.info -> r.info
grass7:r.kappa -> r.kappa
grass7:r.lake -> r.lake
grass7:r.latlong -> r.latlong
grass7:r.li.cwed -> r.li.cwed
grass7:r.li.cwed.ascii -> r.li.cwed.ascii
grass7:r.li.dominance -> r.li.dominance
grass7:r.li.dominance.ascii -> r.li.dominance.ascii
grass7:r.li.edgedensity -> r.li.edgedensity
grass7:r.li.edgedensity.ascii -> r.li.edgedensity.ascii
grass7:r.li.mpa -> r.li.mpa
grass7:r.li.mpa.ascii -> r.li.mpa.ascii
grass7:r.li.mps -> r.li.mps
grass7:r.li.mps.ascii -> r.li.mps.ascii
grass7:r.li.padcv -> r.li.padcv
grass7:r.li.padcv.ascii -> r.li.padcv.ascii
grass7:r.li.padrange -> r.li.padrange
grass7:r.li.padrange.ascii -> r.li.padrange.ascii
grass7:r.li.padsd -> r.li.padsd
grass7:r.li.padsd.ascii -> r.li.padsd.ascii
grass7:r.li.patchdensity -> r.li.patchdensity
grass7:r.li.patchdensity.ascii -> r.li.patchdensity.ascii
grass7:r.li.patchnum -> r.li.patchnum
grass7:r.li.patchnum.ascii -> r.li.patchnum.ascii
grass7:r.li.pielou -> r.li.pielou
grass7:r.li.pielou.ascii -> r.li.pielou.ascii
grass7:r.li.renyi -> r.li.renyi
grass7:r.li.renyi.ascii -> r.li.renyi.ascii
grass7:r.li.richness -> r.li.richness
grass7:r.li.richness.ascii -> r.li.richness.ascii
grass7:r.li.shannon -> r.li.shannon
grass7:r.li.shannon.ascii -> r.li.shannon.ascii
grass7:r.li.shape -> r.li.shape
grass7:r.li.shape.ascii -> r.li.shape.ascii
grass7:r.li.simpson -> r.li.simpson
grass7:r.li.simpson.ascii -> r.li.simpson.ascii
grass7:r.mapcalc.simple -> r.mapcalc.simple
grass7:r.mask.rast -> r.mask.rast
grass7:r.mask.vect -> r.mask.vect
grass7:r.mfilter -> r.mfilter
grass7:r.mode -> r.mode
grass7:r.neighbors -> r.neighbors
grass7:r.null -> r.null
grass7:r.out.ascii -> r.out.ascii
grass7:r.out.gridatb -> r.out.gridatb
grass7:r.out.mat -> r.out.mat
grass7:r.out.mpeg -> r.out.mpeg
grass7:r.out.png -> r.out.png
grass7:r.out.pov -> r.out.pov
grass7:r.out.ppm -> r.out.ppm
grass7:r.out.ppm3 -> r.out.ppm3
grass7:r.out.vrml -> r.out.vrml
grass7:r.out.vtk -> r.out.vtk
grass7:r.out.xyz -> r.out.xyz
grass7:r.param.scale -> r.param.scale
grass7:r.patch -> r.patch
grass7:r.path -> r.path
grass7:r.path.coordinate.txt -> r.path.coordinate.txt
grass7:r.plane -> r.plane
grass7:r.profile -> r.profile
grass7:r.proj -> r.proj
grass7:r.quant -> r.quant
grass7:r.quantile -> r.quantile
grass7:r.quantile.plain -> r.quantile.plain
grass7:r.random -> r.random
grass7:r.random.cells -> r.random.cells
grass7:r.random.surface -> r.random.surface
grass7:r.reclass -> r.reclass
grass7:r.reclass.area -> r.reclass.area
grass7:r.recode -> r.recode
grass7:r.regression.line -> r.regression.line
grass7:r.regression.multi -> r.regression.multi
grass7:r.relief -> r.relief
grass7:r.relief.scaling -> r.relief.scaling
grass7:r.report -> r.report
grass7:r.resamp.bspline -> r.resamp.bspline
grass7:r.resamp.filter -> r.resamp.filter
grass7:r.resamp.interp -> r.resamp.interp
grass7:r.resamp.rst -> r.resamp.rst
grass7:r.resamp.stats -> r.resamp.stats
grass7:r.resample -> r.resample
grass7:r.rescale -> r.rescale
grass7:r.rescale.eq -> r.rescale.eq
grass7:r.rgb -> r.rgb
grass7:r.ros -> r.ros
grass7:r.series -> r.series
grass7:r.series.accumulate -> r.series.accumulate
grass7:r.series.interp -> r.series.interp
grass7:r.shade -> r.shade
grass7:r.sim.sediment -> r.sim.sediment
grass7:r.sim.water -> r.sim.water
grass7:r.slope.aspect -> r.slope.aspect
grass7:r.solute.transport -> r.solute.transport
grass7:r.spread -> r.spread
grass7:r.spreadpath -> r.spreadpath
grass7:r.statistics -> r.statistics
grass7:r.stats -> r.stats
grass7:r.stats.quantile.out -> r.stats.quantile.out
grass7:r.stats.quantile.rast -> r.stats.quantile.rast
grass7:r.stats.zonal -> r.stats.zonal
grass7:r.stream.extract -> r.stream.extract
grass7:r.sun.incidout -> r.sun.incidout
grass7:r.sun.insoltime -> r.sun.insoltime
grass7:r.sunhours -> r.sunhours
grass7:r.sunmask.datetime -> r.sunmask.datetime
grass7:r.sunmask.position -> r.sunmask.position
grass7:r.surf.area -> r.surf.area
grass7:r.surf.contour -> r.surf.contour
grass7:r.surf.fractal -> r.surf.fractal
grass7:r.surf.gauss -> r.surf.gauss
grass7:r.surf.idw -> r.surf.idw
grass7:r.surf.random -> r.surf.random
grass7:r.terraflow -> r.terraflow
grass7:r.texture -> r.texture
grass7:r.thin -> r.thin
grass7:r.tile -> r.tile
grass7:r.tileset -> r.tileset
grass7:r.to.vect -> r.to.vect
grass7:r.topidx -> r.topidx
grass7:r.topmodel -> r.topmodel
grass7:r.topmodel.topidxstats -> r.topmodel.topidxstats
grass7:r.transect -> r.transect
grass7:r.univar -> r.univar
grass7:r.uslek -> r.uslek
grass7:r.usler -> r.usler
grass7:r.viewshed -> r.viewshed
grass7:r.volume -> r.volume
grass7:r.walk.coords -> r.walk.coords
grass7:r.walk.points -> r.walk.points
grass7:r.walk.rast -> r.walk.rast
grass7:r.water.outlet -> r.water.outlet
grass7:r.watershed -> r.watershed
grass7:r.what.color -> r.what.color
grass7:r.what.coords -> r.what.coords
grass7:r.what.points -> r.what.points
grass7:v.buffer -> v.buffer
grass7:v.build.check -> v.build.check
grass7:v.build.polylines -> v.build.polylines
grass7:v.class -> v.class
grass7:v.clean -> v.clean
grass7:v.cluster -> v.cluster
grass7:v.db.select -> v.db.select
grass7:v.decimate -> v.decimate
grass7:v.delaunay -> v.delaunay
grass7:v.dissolve -> v.dissolve
grass7:v.distance -> v.distance
grass7:v.drape -> v.drape
grass7:v.edit -> v.edit
grass7:v.extract -> v.extract
grass7:v.extrude -> v.extrude
grass7:v.generalize -> v.generalize
grass7:v.hull -> v.hull
grass7:v.in.ascii -> v.in.ascii
grass7:v.in.dxf -> v.in.dxf
grass7:v.in.e00 -> v.in.e00
grass7:v.in.geonames -> v.in.geonames
grass7:v.in.lidar -> v.in.lidar
grass7:v.in.lines -> v.in.lines
grass7:v.in.mapgen -> v.in.mapgen
grass7:v.in.wfs -> v.in.wfs
grass7:v.info -> v.info
grass7:v.kcv -> v.kcv
grass7:v.kernel.rast -> v.kernel.rast
grass7:v.kernel.vector -> v.kernel.vector
grass7:v.lidar.correction -> v.lidar.correction
grass7:v.lidar.edgedetection -> v.lidar.edgedetection
grass7:v.lidar.growing -> v.lidar.growing
grass7:v.mkgrid -> v.mkgrid
grass7:v.neighbors -> v.neighbors
grass7:v.net -> v.net
grass7:v.net.alloc -> v.net.alloc
grass7:v.net.allpairs -> v.net.allpairs
grass7:v.net.bridge -> v.net.bridge
grass7:v.net.centrality -> v.net.centrality
grass7:v.net.components -> v.net.components
grass7:v.net.connectivity -> v.net.connectivity
grass7:v.net.distance -> v.net.distance
grass7:v.net.flow -> v.net.flow
grass7:v.net.iso -> v.net.iso
grass7:v.net.nreport -> v.net.nreport
grass7:v.net.path -> v.net.path
grass7:v.net.report -> v.net.report
grass7:v.net.salesman -> v.net.salesman
grass7:v.net.spanningtree -> v.net.spanningtree
grass7:v.net.steiner -> v.net.steiner
grass7:v.net.timetable -> v.net.timetable
grass7:v.net.visibility -> v.net.visibility
grass7:v.normal -> v.normal
grass7:v.out.ascii -> v.out.ascii
grass7:v.out.dxf -> v.out.dxf
grass7:v.out.postgis -> v.out.postgis
grass7:v.out.pov -> v.out.pov
grass7:v.out.svg -> v.out.svg
grass7:v.out.vtk -> v.out.vtk
grass7:v.outlier -> v.outlier
grass7:v.overlay -> v.overlay
grass7:v.pack -> v.pack
grass7:v.parallel -> v.parallel
grass7:v.patch -> v.patch
grass7:v.perturb -> v.perturb
grass7:v.proj -> v.proj
grass7:v.qcount -> v.qcount
grass7:v.random -> v.random
grass7:v.rast.stats -> v.rast.stats
grass7:v.reclass -> v.reclass
grass7:v.rectify -> v.rectify
grass7:v.report -> v.report
grass7:v.sample -> v.sample
grass7:v.segment -> v.segment
grass7:v.select -> v.select
grass7:v.split -> v.split
grass7:v.surf.bspline -> v.surf.bspline
grass7:v.surf.idw -> v.surf.idw
grass7:v.surf.rst -> v.surf.rst
grass7:v.surf.rst.cvdev -> v.surf.rst.cvdev
grass7:v.to.3d -> v.to.3d
grass7:v.to.lines -> v.to.lines
grass7:v.to.points -> v.to.points
grass7:v.to.rast -> v.to.rast
grass7:v.transform -> v.transform
grass7:v.type -> v.type
grass7:v.univar -> v.univar
grass7:v.vect.stats -> v.vect.stats
grass7:v.voronoi -> v.voronoi
grass7:v.voronoi.skeleton -> v.voronoi.skeleton
grass7:v.what.rast -> v.what.rast
grass7:v.what.vect -> v.what.vect
native:addautoincrementalfield -> Add autoincremental field
native:addfieldtoattributestable -> Add field to attributes table
native:adduniquevalueindexfield -> Add unique value index field
native:addxyfields -> Add X/Y fields to layer
native:affinetransform -> Affine transform
native:aggregate -> Aggregate
native:angletonearest -> Align points to features
native:antimeridiansplit -> Geodesic line split at antimeridian
native:arrayoffsetlines -> Array of offset (parallel) lines
native:arraytranslatedfeatures -> Array of translated features
native:aspect -> Aspect
native:assignprojection -> Assign projection
native:atlaslayouttoimage -> Export atlas layout as image
native:atlaslayouttopdf -> Export atlas layout as PDF
native:batchnominatimgeocoder -> Batch Nominatim geocoder
native:bookmarkstolayer -> Convert spatial bookmarks to layer
native:boundary -> Boundary
native:boundingboxes -> Bounding boxes
native:buffer -> Buffer
native:bufferbym -> Variable width buffer (by M value)
native:calculatevectoroverlaps -> Overlap analysis
native:categorizeusingstyle -> Create categorized renderer from styles
native:cellstackpercentile -> Cell stack percentile
native:cellstackpercentrankfromrasterlayer -> Cell stack percentrank from raster layer
native:cellstackpercentrankfromvalue -> Cell stack percent rank from value
native:cellstatistics -> Cell statistics
native:centroids -> Centroids
native:clip -> Clip
native:collect -> Collect geometries
native:combinestyles -> Combine style databases
native:condition -> Conditional branch
native:convertgpsdata -> Convert GPS data
native:convertgpxfeaturetype -> Convert GPX feature type
native:converttocurves -> Convert to curved geometries
native:convexhull -> Convex hull
native:countpointsinpolygon -> Count points in polygon
native:createattributeindex -> Create attribute index
native:createconstantrasterlayer -> Create constant raster layer
native:createdirectory -> Create directory
native:creategrid -> Create grid
native:createpointslayerfromtable -> Create points layer from table
native:createrandombinomialrasterlayer -> Create random raster layer (binomial distribution)
native:createrandomexponentialrasterlayer -> Create random raster layer (exponential distribution)
native:createrandomgammarasterlayer -> Create random raster layer (gamma distribution)
native:createrandomgeometricrasterlayer -> Create random raster layer (geometric distribution)
native:createrandomnegativebinomialrasterlayer -> Create random raster layer (negative binomial distribution)
native:createrandomnormalrasterlayer -> Create random raster layer (normal distribution)
native:createrandompoissonrasterlayer -> Create random raster layer (poisson distribution)
native:createrandomuniformrasterlayer -> Create random raster layer (uniform distribution)
native:createspatialindex -> Create spatial index
native:dbscanclustering -> DBSCAN clustering
native:deletecolumn -> Drop field(s)
native:deleteduplicategeometries -> Delete duplicate geometries
native:deleteholes -> Delete holes
native:densifygeometries -> Densify by count
native:densifygeometriesgivenaninterval -> Densify by interval
native:detectvectorchanges -> Detect dataset changes
native:difference -> Difference
native:dissolve -> Dissolve
native:downloadgpsdata -> Download GPS data from device
native:dropgeometries -> Drop geometries
native:dropmzvalues -> Drop M/Z values
native:dxfexport -> Export layers to DXF
native:equaltofrequency -> Equal to frequency
native:explodehstorefield -> Explode HStore Field
native:explodelines -> Explode lines
native:exportlayersinformation -> Export layer(s) information
native:exportmeshedges -> Export mesh edges
native:exportmeshfaces -> Export mesh faces
native:exportmeshongrid -> Export mesh on grid
native:exportmeshvertices -> Export mesh vertices
native:exporttospreadsheet -> Export to spreadsheet
native:extendlines -> Extend lines
native:extenttolayer -> Create layer from extent
native:extractbinary -> Extract binary field
native:extractbyattribute -> Extract by attribute
native:extractbyexpression -> Extract by expression
native:extractbyextent -> Extract/clip by extent
native:extractbylocation -> Extract by location
native:extractmvalues -> Extract M values
native:extractspecificvertices -> Extract specific vertices
native:extractvertices -> Extract vertices
native:extractwithindistance -> Extract within distance
native:extractzvalues -> Extract Z values
native:fieldcalculator -> Field calculator
native:filedownloader -> Download file
native:fillnodata -> Fill NoData cells
native:filter -> Feature filter
native:filterbygeometry -> Filter by geometry type
native:filterlayersbytype -> Filter layers by type
native:filterverticesbym -> Filter vertices by M value
native:filterverticesbyz -> Filter vertices by Z value
native:fixgeometries -> Fix geometries
native:flattenrelationships -> Flatten relationship
native:forcerhr -> Force right-hand-rule
native:fuzzifyrastergaussianmembership -> Fuzzify raster (gaussian membership)
native:fuzzifyrasterlargemembership -> Fuzzify raster (large membership)
native:fuzzifyrasterlinearmembership -> Fuzzify raster (linear membership)
native:fuzzifyrasternearmembership -> Fuzzify raster (near membership)
native:fuzzifyrasterpowermembership -> Fuzzify raster (power membership)
native:fuzzifyrastersmallmembership -> Fuzzify raster (small membership)
native:generatepointspixelcentroidsinsidepolygons -> Generate points (pixel centroids) inside polygons
native:geometrybyexpression -> Geometry by expression
native:greaterthanfrequency -> Greater than frequency
native:highestpositioninrasterstack -> Highest position in raster stack
native:hillshade -> Hillshade
native:hublines -> Join by lines (hub lines)
native:importphotos -> Import geotagged photos
native:interpolatepoint -> Interpolate point on line
native:intersection -> Intersection
native:joinattributesbylocation -> Join attributes by location
native:joinattributestable -> Join attributes by field value
native:joinbynearest -> Join attributes by nearest
native:kmeansclustering -> K-means clustering
native:layertobookmarks -> Convert layer to spatial bookmarks
native:lessthanfrequency -> Less than frequency
native:linedensity -> Line density
native:lineintersections -> Line intersections
native:linesubstring -> Line substring
native:loadlayer -> Load layer into project
native:lowestpositioninrasterstack -> Lowest position in raster stack
native:meancoordinates -> Mean coordinate(s)
native:mergelines -> Merge lines
native:mergevectorlayers -> Merge vector layers
native:meshcontours -> Export contours
native:meshexportcrosssection -> Export cross section dataset values on lines from mesh
native:meshexporttimeseries -> Export time series values from points of a mesh dataset
native:meshrasterize -> Rasterize mesh dataset
native:minimumenclosingcircle -> Minimum enclosing circles
native:multiparttosingleparts -> Multipart to singleparts
native:multiringconstantbuffer -> Multi-ring buffer (constant distance)
native:nearestneighbouranalysis -> Nearest neighbour analysis
native:offsetline -> Offset lines
native:orderbyexpression -> Order by expression
native:orientedminimumboundingbox -> Oriented minimum bounding box
native:orthogonalize -> Orthogonalize
native:package -> Package layers
native:pixelstopoints -> Raster pixels to points
native:pixelstopolygons -> Raster pixels to polygons
native:pointonsurface -> Point on surface
native:pointsalonglines -> Points along geometry
native:pointstopath -> Points to path
native:pointtolayer -> Create layer from point
native:poleofinaccessibility -> Pole of inaccessibility
native:polygonfromlayerextent -> Extract layer extent
native:polygonize -> Polygonize
native:polygonstolines -> Polygons to lines
native:postgisexecutesql -> PostgreSQL execute SQL
native:printlayoutmapextenttolayer -> Print layout map extent to layer
native:printlayouttoimage -> Export print layout as image
native:printlayouttopdf -> Export print layout as PDF
native:projectpointcartesian -> Project points (Cartesian)
native:promotetomulti -> Promote to multipart
native:raiseexception -> Raise exception
native:raisewarning -> Raise warning
native:randomextract -> Random extract
native:randompointsinextent -> Random points in extent
native:randompointsinpolygons -> Random points in polygons
native:randompointsonlines -> Random points on lines
native:rasterbooleanand -> Raster boolean AND
native:rasterize -> Convert map to raster
native:rasterlayerproperties -> Raster layer properties
native:rasterlayerstatistics -> Raster layer statistics
native:rasterlayeruniquevaluesreport -> Raster layer unique values report
native:rasterlayerzonalstats -> Raster layer zonal statistics
native:rasterlogicalor -> Raster boolean OR
native:rastersampling -> Sample raster values
native:rastersurfacevolume -> Raster surface volume
native:reclassifybylayer -> Reclassify by layer
native:reclassifybytable -> Reclassify by table
native:rectanglesovalsdiamonds -> Rectangles, ovals, diamonds
native:refactorfields -> Refactor fields
native:removeduplicatesbyattribute -> Delete duplicates by attribute
native:removeduplicatevertices -> Remove duplicate vertices
native:removenullgeometries -> Remove null geometries
native:renamelayer -> Rename layer
native:renametablefield -> Rename field
native:repairshapefile -> Repair Shapefile
native:reprojectlayer -> Reproject layer
native:rescaleraster -> Rescale raster
native:retainfields -> Retain fields
native:reverselinedirection -> Reverse line direction
native:rotatefeatures -> Rotate
native:roundrastervalues -> Round raster
native:ruggednessindex -> Ruggedness index
native:savefeatures -> Save vector features to file
native:savelog -> Save log to file
native:saveselectedfeatures -> Extract selected features
native:segmentizebymaxangle -> Segmentize by maximum angle
native:segmentizebymaxdistance -> Segmentize by maximum distance
native:selectbylocation -> Select by location
native:selectwithindistance -> Select within distance
native:serviceareafromlayer -> Service area (from layer)
native:serviceareafrompoint -> Service area (from point)
native:setlayerencoding -> Set layer encoding
native:setlayerstyle -> Set layer style
native:setmfromraster -> Set M value from raster
native:setmvalue -> Set M value
native:setprojectvariable -> Set project variable
native:setzfromraster -> Drape (set Z value from raster)
native:setzvalue -> Set Z value
native:shortestpathlayertopoint -> Shortest path (layer to point)
native:shortestpathpointtolayer -> Shortest path (point to layer)
native:shortestpathpointtopoint -> Shortest path (point to point)
native:shpencodinginfo -> Extract Shapefile encoding
native:simplifygeometries -> Simplify
native:singlesidedbuffer -> Single sided buffer
native:slope -> Slope
native:smoothgeometry -> Smooth
native:snapgeometries -> Snap geometries to layer
native:snappointstogrid -> Snap points to grid
native:spatialiteexecutesql -> SpatiaLite execute SQL
native:spatialiteexecutesqlregistered -> SpatiaLite execute SQL (registered DB)
native:splitfeaturesbycharacter -> Split features by character
native:splitlinesbylength -> Split lines by maximum length
native:splitvectorlayer -> Split vector layer
native:splitwithlines -> Split with lines
native:stdbscanclustering -> ST-DBSCAN clustering
native:stringconcatenation -> String concatenation
native:stylefromproject -> Create style database from project
native:subdivide -> Subdivide
native:sumlinelengths -> Sum line lengths
native:swapxy -> Swap X and Y coordinates
native:symmetricaldifference -> Symmetrical difference
native:taperedbuffer -> Tapered buffers
native:tinmeshcreation -> TIN Mesh Creation
native:transect -> Transect
native:transferannotationsfrommain -> Transfer annotations from main layer
native:translategeometry -> Translate
native:truncatetable -> Truncate table
native:union -> Union
native:uploadgpsdata -> Upload GPS data to device
native:wedgebuffers -> Create wedge buffers
native:writevectortiles_mbtiles -> Write Vector Tiles (MBTiles)
native:writevectortiles_xyz -> Write Vector Tiles (XYZ)
native:zonalhistogram -> Zonal histogram
native:zonalstatistics -> Zonal statistics (in place)
native:zonalstatisticsfb -> Zonal statistics
qgis:advancedpythonfieldcalculator -> Advanced Python field calculator
qgis:barplot -> Bar plot
qgis:basicstatisticsforfields -> Basic statistics for fields
qgis:boxplot -> Box plot
qgis:checkvalidity -> Check validity
qgis:climbalongline -> Climb along line
qgis:concavehull -> Concave hull (alpha shapes)
qgis:convertgeometrytype -> Convert geometry type
qgis:definecurrentprojection -> Define Shapefile projection
qgis:delaunaytriangulation -> Delaunay triangulation
qgis:distancematrix -> Distance matrix
qgis:distancetonearesthublinetohub -> Distance to nearest hub (line to hub)
qgis:distancetonearesthubpoints -> Distance to nearest hub (points)
qgis:eliminateselectedpolygons -> Eliminate selected polygons
qgis:executesql -> Execute SQL
qgis:exportaddgeometrycolumns -> Add geometry attributes
qgis:findprojection -> Find projection
qgis:generatepointspixelcentroidsalongline -> Generate points (pixel centroids) along line
qgis:heatmapkerneldensityestimation -> Heatmap (Kernel Density Estimation)
qgis:hypsometriccurves -> Hypsometric curves
qgis:idwinterpolation -> IDW interpolation
qgis:importintopostgis -> Export to PostgreSQL
qgis:importintospatialite -> Export to SpatiaLite
qgis:joinbylocationsummary -> Join attributes by location (summary)
qgis:keepnbiggestparts -> Keep N biggest parts
qgis:knearestconcavehull -> Concave hull (k-nearest neighbor)
qgis:linestopolygons -> Lines to polygons
qgis:listuniquevalues -> List unique values
qgis:meanandstandarddeviationplot -> Mean and standard deviation plot
qgis:minimumboundinggeometry -> Minimum bounding geometry
qgis:pointsdisplacement -> Points displacement
qgis:polarplot -> Polar plot
qgis:postgisexecuteandloadsql -> PostgreSQL execute and load SQL
qgis:randomextractwithinsubsets -> Random extract within subsets
qgis:randompointsalongline -> Random points along line
qgis:randompointsinlayerbounds -> Random points in layer bounds
qgis:randompointsinsidepolygons -> Random points inside polygons
qgis:randomselection -> Random selection
qgis:randomselectionwithinsubsets -> Random selection within subsets
qgis:rastercalculator -> Raster calculator
qgis:rasterlayerhistogram -> Raster layer histogram
qgis:rectanglesovalsdiamondsvariable -> Rectangles, ovals, diamonds (variable)
qgis:regularpoints -> Regular points
qgis:relief -> Relief
qgis:scatter3dplot -> Vector layer scatterplot 3D
qgis:selectbyattribute -> Select by attribute
qgis:selectbyexpression -> Select by expression
qgis:setstyleforrasterlayer -> Set style for raster layer
qgis:setstyleforvectorlayer -> Set style for vector layer
qgis:statisticsbycategories -> Statistics by categories
qgis:texttofloat -> Text to float
qgis:tilesxyzdirectory -> Generate XYZ tiles (Directory)
qgis:tilesxyzmbtiles -> Generate XYZ tiles (MBTiles)
qgis:tininterpolation -> TIN interpolation
qgis:topologicalcoloring -> Topological coloring
qgis:variabledistancebuffer -> Variable distance buffer
qgis:vectorlayerhistogram -> Vector layer histogram
qgis:vectorlayerscatterplot -> Vector layer scatterplot
qgis:voronoipolygons -> Voronoi polygons
script:myscript -> My Script
script:processmapping -> Kartierdaten sortieren