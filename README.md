# Homework on High Performance and Parallel Computing

## Introduction

The midpoint rule is one technique for numerical
evaluation of definite integrals of the form

$$
  I = int^b_a f(x) dx \, .
$$

A C++ implementation is provided in `midpoint.cc` and can be compiled
using `g++ -O3 midpoint.cc -o midpoint`.

## Problem 1.

Adjust the given program to  estimate the number of GFLOP/S your machine
achieves for this problem for $n = 10^{i}, \, i = 1, 2, \ldots 7$.  You will
likely need to loop over the operation multiple times for small $n$ to 
get good results.

Repeat this using $f(x) = 1.2345 + 2.3456*x + 3.4567*x*x + 4.5678*x*x*x$.  Be careful when estimating the number of operations since the compiler will often
turn the apparent 7 FLOPs of

```
a + b*a*a + c*a*a*a
```

into the smaller 5 FLOPs of

```
a2 = a*a
a3 = a2*a
a + b*a2 + c*a3 
```

Is there any difference between this new function and the original `squared_x`?

## Problem 2

Parallelize this code using OpenMP or MPI.  Alternatively, implement the same program in Python and parallelize it with `mpi4py` (or feel free to try out the `multithread` and `multiprocess` modules.

In particular, for `n = 10**7`, show the speedup as a function of the number of threads or processes.  If you need to, use Beocat.  I recommend first executing `module load SciPy-bundle` to get `mpi4py` and other things.  To use a compute node interactively, you may try something like 

```
srun --nodes=1 --cpus-per-task=8  --time=0:30:00 --mem=16G --pty bash 
```

However, I've had issues getting this to work with MPI.  Rather, you can create a short shell script like

```
#!/bin/sh 
mpirun -np 1 python ./exercise_7.py                                                                            
mpirun -np 2 python ./exercise_7.py                                                                            
mpirun -np 4 python ./exercise_7.py                                                                            
mpirun -np 8 python ./exercise_7.py 
```

where the file being run is this ME 701 [demo file](https://github.com/robertsj/me701/blob/f2020/examples/mpi/exercise_7.py).

Then, submit the script via

```
sbatch --nodes=1 --ntasks-per-node=8 --time=0:30:00 --mem=16G ./myscript.sh       
```


Adjust times and resources needed according to what you will run. 


