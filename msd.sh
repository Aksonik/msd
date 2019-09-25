gcc msd.c -o msd
time ./msd -a 1 -b 20000 -m 100 -n 1000  pro.xyz

### compare if consistent with awk
tail msd.dat test/msd_awk.dat
head msd.dat test/msd_awk.dat
