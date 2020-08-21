#include<stdio.h>
struct fushu{
	int x;
	int y;
};
int main(){
	int q=0;
	scanf("%d",&q);
	if(q>=1&&q<=1000){
		int i=0;
		fushu a={0,0};
		for(i=0;i<q;i++){
			int o,xo,yo,xt,yt;
			scanf("%d %d %d",&o,&xo,&yo);
			if(o==1){
				a.x=xo;
				a.y=yo; 
			}
			if(o==2){
				a.x=a.x+xo;
				a.y=a.y+yo;
			}
			if(o==3){
				xt=a.x*xo-a.y*yo;
				yt=a.x*yo+a.y*xo;
				a.x=xt;
				a.y=yt;
			}
			if(a.y>=0)
				printf("%d+%di\n",a.x,a.y);
			else
				printf("%d-%di\n",a.x,-a.y);
		}
	} 
	return 0; 
} 
