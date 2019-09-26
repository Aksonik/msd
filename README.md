# msd

## Calculates mean squere displacement.

#### Input file format

time x y z

#### Options

*-a* (float) *-b* (float): range of time, e.g. to skip equilibration time.

*-m* (float) *-n* (float): range of time lags, i.e. observation window.

### Remarks

Much slower MSD calculation with *awk* (*test* directory) is for comparison.

Output data are in the same units as input data, e.g. if time and coordinates are in *ns* and *A*
the MSD and time are in *A^2* and *ns*.
