# fillit @ 42

Group project with [mmatime](https://github.com/Marvel2002)

The purpose is to make the smallest possible "square" (which can contain holes) with a given list of
tetriminos, but the disposition must be as such that it returns the first
possible solution when placing them recursively from the top left.

## Compiling
Run `make`, an executable called `fillit` should compile directly. Please submit
an issue if you run into any.

## Usage
`./fillit [file]`

Example:
```
./fillit examples/test_7

AACCDD
ABECDG
ABECDG
.BEFFG
.BEF.G
...F..
```
