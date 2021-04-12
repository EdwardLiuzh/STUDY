#include<stdio.h>
#include<math.h>
int main(){
    double x,y,z;
    scanf("%lf",&x);
    y=x/2.0;
    //z=y*y;
    z=y*y*y;
    while(x){
        double t=fabs(z-x);
        if(t>1e-6){
            if(z>x)
                y=y/2.0;
            else
                y=(y+2*y)/2.0;
            //z=y*y;
            z=y*y*y;
        }
        else
            break;
    }
    printf("%.1f\n",y);
    return 0;
}
