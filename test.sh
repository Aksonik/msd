gcc msd.c -o msd
time ./msd -a 0.1 -b 2000.0 -m 10.0 -n 100.0  pro.xyz

### compare if consistent with awk
tail msd.dat test/msd_awk.dat
head msd.dat test/msd_awk.dat
