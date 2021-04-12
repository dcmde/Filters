# Filters

This repo contains several headers and CLI allowing to test and add filters in any project.

## Exponential smoothing

### Theory

The recursion is as follow,

```
st = alpha.xt + (1 - alpha).st-1
s0 = x0
```

### How to

In order to use the CLI you can run the following commands,

```
git clone https://github.com/dcmde/Filters.git
cd Filters
mkdir build 
cd build
cmake ..
make
```

Then create file containing a single row of data (double format),

```
./exp_smoothing test.txt 0.9 0
```

The first parameter is the name of the input file, the second parameter is `alpha` and the last one the value to
initialize the filter.

The ouput file is named `exp_smt.txt`.