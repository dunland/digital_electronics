- [Codecademy: Setting up Go locally](https://www.codecademy.com/article/setting-up-go-locally)
- [Codecademy Go Cheatsheet](https://www.codecademy.com/learn/learn-go/modules/learn-go-introduction/cheatsheet)
- [Go Standard Library](https://pkg.go.dev/std)
- [Tour of Go](https://go.dev/tour/welcome/1)
- [Go: Writing Web Applications](https://go.dev/doc/articles/wiki/)
- [The Go Blog: Go maps in action](https://go.dev/blog/maps)
- [Russ Cox' (Go) Blog](research.swtch.com)
- [Go Dev Blog](https://go.dev/blog/)

``` bash
# build an executable from the go file:
go build main.go 
./main

# run the go file directly:
go run main.go

# read the manual of package fmt:
go doc fmt
go doc fmt.Println # maunal for Println Function
```

**go example code:**
``` go
package main // declare this file to be part of package 'main'

import "fmt" // double quotes necessary

func main() { // will be run upon file execution
	fmt.Println("Hello World")
}
```
- programs start running in package "main"

**misc:**

- standard **GOPATH** is `/home/user/go/`
### variables

>All numeric variables have a value of `0` before assignment. String variables have a default value of `""`. Boolean variables have a default value of `false`.

**declaration and definition**

``` go
const myInt int8 = 4
var myString string = "asdf"
var myOtherInt = 3
var magicNum, powerLevel int32 := 7, 8 // short assignment only valid inside of functions!
```
**short declaration (automatic type declaration)**

``` go
nuclearMeltdownOccurring := true
radiumInGroundWater := 4.521
daysSinceLastWorkplaceCatastrophe := 0
externalMessage := "Everything is normal. Keep calm and carry on.
quote, fact := "Bears, Beets, Battlestar Galactica", true
```
>Floats created in this way are of type `float64`. Integers created in this way are either `int32` or `int64`

**Type conversion:**
``` go
i := 42
f := float64(i)
u := uint(f)
```

Exported variables start with a capital letter!

### flow control
- **loops:**
>The init and post statements can be left out:
``` go
	sum := 1
	for sum < 1000 {
		sum += sum
	}
```

- **conditionals**:
>the `if` statement can start with a short statement to execute before the condition. Variables declared by the statement are only in scope until the end of the `if`. Variables declared inside an `if` short statement are also available inside any of the `else` blocks.
``` go
func pow(x, n, lim float64) float64 {
	if v := math.Pow(x, n); v < lim {
		return v
	}
	return lim
}
```

- **switch**: no `break` needed, not only constants allowed
- **[defer](https://go.dev/blog/defer-panic-and-recover)**: "A defer statement defers the execution of a function until the surrounding function returns. Deferred function calls are pushed onto a stack. When a function returns, its deferred calls are executed in last-in-first-out order."
``` go
func main() {
	defer fmt.Println("world")
	fmt.Println("hello")
}
```
- **[panic](https://go.dev/blog/defer-panic-and-recover)**
- **[recover](https://go.dev/blog/defer-panic-and-recover)**

### arrays

``` go
var a [10]int
```
Arrays cannot be resized! But **slices** can:
``` go
a := make([]int, 5) // len(a)=5
b := make([]int, 0, 5) // len(b)=0, cap(b)=5
r := []bool{true, false, true, true, false, true}

```
>The `make` function allocates a zeroed array and returns a slice that refers to that array.
### pointers
``` go
var p *int
p = &i  // point to i
*p = 21 // change i through p
fmt.Println(*p) // same as fmt.Println(i)
```

### structs

``` go
type Vertext struct{
	X int
	Y int
}
v := Vertex{1,2} // oder: v := Vertext{X:1}
v.X = 4
fmt.Println(v.X) // 4
```
>To access the field `X` of a struct when we have the struct pointer `p` we could write `(*p).X`. However, that notation is cumbersome, so the language permits us instead to write just `p.X`, without the explicit dereference.


----------------
## packages

>By convention, the package name is the same as the last element of the import path. For instance, the `"math/rand"` package comprises files that begin with the statement `package rand`.

- **fmt**: standard library for formats
	- `fmt.Println()`: spaces between arguments, line break at the end
	- `fmt.Print()`: no spaces between arguments, no line break
	- `fmt.Printf("%v is a cool number", 5)` – `%v` is for the *[verb](https://pkg.go.dev/fmt#hdr-Printing)* to be filled in
	- `variable := fmt.Sprint("some text")` – stores printout to be printed later
	- `fmt.Scan(&response)` takes the first value before a space and stores it in `response`
- **strings**: 
- **time**: standard library for time, e.g. `time.Now()`
	- `time.Now().Hour()` returns hour of current time
- **runtime**: contains operations that interact with Go's runtime system,  such as functions to control goroutines
	- `runtime.GOOS`: contains info on operating system

