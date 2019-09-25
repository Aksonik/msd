#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
calculates mean square displacement
input file format: time x y z
-a/-b (int): range of frames, e.g if want to skip equilibration time
-m/-n (int): range of time lags, i.e. observation window
*/

int main(int argc,char **argv){

 if(argc==1){
  printf("Error: No argument - input file name!\n");
  exit(0);
 }

 int n=100000;	// increase is file is larger

 float time[n];
 float x[n],y[n],z[n];
 float xx[n],yy[n],zz[n];
 int i;
 int t,t1,t2;
 int tl,tl1,tl2;

 FILE *inputFile;
 inputFile=fopen(argv[argc-1],"r");	// input file is always the last argument

 if(inputFile==NULL){
  printf("Error: No input file - not found!\n");
  exit(0);
 }

// read input file

 i=1;	// indexes start from 1

 while(!feof(inputFile)){
  if(fscanf(inputFile,"%f %f %f %f",&time[i],&x[i],&y[i],&z[i])==4){
//  printf("%f %f %f %f\n",time[i],x[i],y[i],z[i]);
   i++;
  }
 }

 fclose(inputFile);

// default time range, i.e max.
 t1=1;
 t2=i-1;

// default time lag range, i.e. max.
 tl1=1;
 tl2=i-2;

// read parameters from the command line instead of default

 int opt;

 while((opt=getopt(argc,argv,"a:b:m:n:")) != -1){
  switch (opt){
  case 'a': t1=atoi(optarg); break;
  case 'b': t2=atoi(optarg); break;
  case 'm': tl1=atoi(optarg); break;
  case 'n': tl2=atoi(optarg); break;
  default:
   fprintf(stderr,"Usage: %s [-abc] [file...]\n", argv[0]);
   exit(EXIT_FAILURE);
  }
 }

// msd

 FILE *outputFile;
 outputFile=fopen("msd.dat","w");

 for(tl=tl1;tl<=tl2;tl++){		// time lag
  float rr=0.0;
  for(t=t1;t<=t2-tl;t++){		// time
   xx[t]=x[t+tl]-x[t];
   yy[t]=y[t+tl]-y[t];
   zz[t]=z[t+tl]-z[t];
   rr=rr+xx[t]*xx[t]+yy[t]*yy[t]+zz[t]*zz[t];
  }
  fprintf(outputFile,"%f %f\n",tl*0.1,rr/t);
 }

 fclose(outputFile);

 return 0;
}
