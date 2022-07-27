# Packages Cheat Sheets
Collection of small applications I have used the packages for.

## json
### load json from file:
``` python
import json
f = open('data.json')
json.load(f)
```

---
## Shapely
get points from polygon:
``` python
polygon = some_polygon
pol_list = list(polygon.exterior.coords)
pol_df = pd.DataFrame(pol_list, columns=['long', 'lat'])
```

---
## Numpy  
`np.array(python_list)` creates numpy-array from python list  
`np.shape` returns (rows, columns)  
`array_B = array_A < 5` returns an array of booleans..  
  `array_A[array_B]` will then return only the values where B = True  
`array[0,1]` row 0, col 1  
`array[:,5]` all rows, col 5 (complete column 5)  
`array[2:5, 3:10]` row 2-5, col 3-10  

![python lists vs numpy arrays](img\python\lists_vs_nparrays.png)

## Excel / csv:
`hour_factors = pd.read_csv(file, index_col=0)`
