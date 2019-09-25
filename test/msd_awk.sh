### msd - mean squared displacement [nm^2]
### msd(tt) = <dr(tt)^2> = <[r(t+tt)-r(t)]^2>

### D - diffusion coefficient
### D = 1/(2*d)lim(tt->inf)<[r(t+tt)-r(t)]^2>/tt
### d - dimension

awk 'BEGINE{f=0}
{if($1>=0.0)					### first 0 ns is equilibration
  {f=f+1					### frame [fr]
   x[f]=$2;y[f]=$3;z[f]=$4}}			### read coordinates [nm]
   END{for(tt=100;tt<=1000;tt=tt+1)		### 10-100 ns every 100 ps (time lag)
        {rr=0
         for(t=1;t<=f-tt;t=t+1)			### for each frame [fr]
           {xx[t]=x[t+tt]-x[t]			### calculate difference with lag
            yy[t]=y[t+tt]-y[t]
            zz[t]=z[t+tt]-z[t]
            rr=rr+xx[t]^2+yy[t]^2+zz[t]^2	### throw squares to one bin
           }					
           print tt*0.1,rr/t
        }
      }' ../pro.xyz > msd_awk.dat

