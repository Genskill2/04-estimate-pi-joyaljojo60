#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


float frandom() {
  long int q = random();
  float ret = (float)q/(float)RAND_MAX;
  return ret;
}

int main(void) {
  float pi0;
  float pi1;
  
  pi0 = mc_pi(25000);
  pi1 = mc_pi(25000);
  printf("%f %f\n", pi0, pi1);
  
  if (pi0 == pi1) {
      printf("Two separate estimates of pi are exactly the same. This is unlikely.\n");
      abort();
    }

  if (fabs(pi0 - pi1) > 0.05) {
      printf("Two separate estimates %f and %f are too different.\n", pi0, pi1);
      abort();
  }

    
  for (int i=2000; i<5000; i++) {
    pi0 = mc_pi(i);
    if (!(fabs(pi0 - M_PI) < 0.4)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi0);
      abort();
    }
  }
}

float mc_pi(int iterations)
{

float x=0, y=0;                       //x and y coordinates
int circle_points=0;                  // Declaring points inside the circle                
float d; 
float area;                             // Declaring distance and area

                          
for(int i=0;i<iterations;i++)
{

x=frandom();                        //geting random values of x and y from frandom function
y=frandom();

if(sqrt(x*x+y*y)<=1)               //checking if the points lie inside the circle
if((x*x+y*y)<=1)               //checking if the points lie inside the circle
circle_points+=1; 

}
area = (float)(4*circle_points)/iterations;
return (area);
  
}

