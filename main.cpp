
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <cstdio>


int main(){
    
    int Ni,Nj,i,j;
    double r,a,b,m,k,l,delta_t;
    
    double**N = NULL;
    double**P = NULL;
    double**H = NULL;
    
    //FILE *fp = NULL; //Declare a variable for files
    
    Ni= 2002; //horizontal size of landscape
    Nj = 2002; //vertical size of landscape
    
    r= 0.08; //hare birth rate
    a = 0.04; //predation rate
    b = 0.02; //birth rate puma per hare eaten
    m = 0.06; //puma mortality rate
    k = 0.02; //hare diffusion rate
    l = 0.02; //puma diffusion rate
    delta_t=0.4; //time step
    
    //Create the landscape Ni*Nj
    
    for (i=0; i<= Ni; i++)
        for (j=0; j<= Ni; j++){
            if (i==0 || j==0)
                N[i][j]=0;
            else if (i==2002 || j==2002)
                N[i][j]=0;
            else
                N[i][j]= rand()%1;
        }
    
    //Create the P[2002*2002] and H[2002*2002] with the density of Pumas and Hares with initial values
    
    for (i=0; i<= Ni; i++)
        for (j=0; j<= Ni; j++){
            if (N[i][j]!=0)
                P[i][j]=rand()%5;
                H[i][j]=rand()%5;
            if (N[i][j]==0)
                P[i][j]=0;
                H[i][j]=0;
        }
    
    
    //Open folder to print the results of P,H
  //  fp=fopen("results.txt", "w");
    
    //Create the new H,P as the densities change
    
    for (i=0; i<= Ni; i++)
        for (j=0; j<= Ni; j++){
            P[i][j]=P[i][j]+delta_t*(b*H[i][j]*P[i][j]-m*P[i][j]+l*((P[i-1][j]+P[i+1][j]+P[i][j-1]+P[i][j+1])-N[i][j]*P[i][j]));
            H[i][j]=H[i][j]+delta_t*(r*H[i][j]-a*H[i][j]*P[i][j]+k*((H[i-1][j]+H[i+1][j]+H[i][j-1]+H[i][j+1])-N[i][j]*H[i][j]));
            
           // printf(fp,"%le\n", P[i][j]);
           // printf("%5f",P[i][j]);
            }
    

   return(0);
    
    
}