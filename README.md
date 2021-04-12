# Filters

This repo contains several headers and CLI allowing to test and add filters in any project.

## How to

In order to use the CLI you can run the following commands,

```
git clone https://github.com/dcmde/Filters.git
cd Filters
mkdir build
cd build
cmake ..
make
```

## Exponential smoothing

### Theory

The recursion is as follow,

```
Recursion:
    st = alpha.xt + (1 - alpha).st-1 
Initialization:
    s0 = x0
```

### How to

Create file containing a single row of data (double format),

```
./exp_smoothing test.txt 0.9 0
```

The first parameter is the name of the input file, the second parameter is `alpha` and the last one the value to
initialize the filter.

The ouput file is named `exp_smt.txt`.

### Theory

The recursion is as follow,

```
Recursion:
    st = alpha.xt + (1 - alpha)(st-1 + bt-1)
    bt = beta.(st - st-1) + (1 - beta).bt-1 
Initialization:
    s0 = x0 b0 = x1 - x0 
Forecast:
    Ft+m = st + m.bt
```

### How to

Create file containing a single row of data (double format),

```
./double_exp_smoothing test.txt alpha beta x0 x1 m
```

Parameter list:

- file name
- `alpha` data smoothing factor
- `beta` trend smoothing factor
- `x0`, `x1` filter initialization
- `m` number of point to forecast

The output file is `` and it contains `m` rows being the forecasted values, `t t+1 t+... t+m`.

```
0 0 0 
0.5 0.95 1.4 
0.975 1.4475 1.92 
1.22375 1.49487 1.766 
1.24744 1.29587 1.3443 
1.14793 1.06322 0.978515 
```


