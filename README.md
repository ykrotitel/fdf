# FDF
### :white_square_button: ***About***

FdF is a project of ***School 42***. A simple 3D height-map render. It made using the minilibx library. It is possible to rotate the figure, increase the perspective and change the depth of the figure.

### :white_square_button: ***Grade***

***Score 118/125***
```
Mandatory part 100/100

Bonus paty 18/25
```
***Example****

```console
➜  test_maps git:(master) ✗ cat pyramide.fdf
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
0 0 0 0 0 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 3 3 3 3 3 3 3 3 3 3 3 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 4 4 4 4 4 4 4 4 4 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 4 4 4 4 4 4 4 4 4 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 4 4 4 4 4 4 4 4 4 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 4 4 4 4 4 4 4 4 4 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 4 4 4 4 4 4 4 4 4 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 5 5 5 5 5 5 5 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 6 6 6 6 6 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 7 7 7 7 7 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 7 8 8 8 7 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 7 8 8 8 7 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 7 8 8 8 7 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 7 8 8 8 7 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 7 8 9 8 7 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 7 8 8 8 7 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 7 7 7 7 7 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 6 6 6 6 6 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 5 5 5 5 5 5 5 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 4 4 4 4 4 4 4 4 4 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 3 3 3 3 3 3 3 3 3 3 3 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 1 0 0 0 0 0
0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0%  
```

![42.fdf map](/images/image1.png)

# How to install and use

### :white_square_button: ***Installation***

```
git clone https://github.com/ykrotitel/fdf.git fdf

cd fdf

make
```

### :white_square_button: ***Usage***
```
./fdf test_maps/"map name"
```

:three: - more depth

:two: - less depth

***}***, ***{*** :arrow_left:, :arrow_right:, :arrow_up:, :arrow_down: - rotate the figure

***P*** - on/off perspective

:heavy_plus_sign:, :heavy_minus_sign: - handle perspective
