#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
int A=50,B=50,ini=1,X=50;
int f,g,x,r1=0,r2=0,fl=0,br=0,temp,temp1,ord;
int map[A][B];int dir[X];int mark[X];
int U=0,D=0,L=0,R=0,eat=0,lo;
while(br==0){
  for(x=1;x<50;x++)
        mark[x]=0;
if (ini==1){
	for(f=0;f<A;f++)
	{map[f][0]=-1;
	 map[f][B-1]=-1;
	}
	for(g=0;g<B;g++)
	{map[0][g]=-1;
	 map[A-1][g]=-1;
	}
	for(f=1;f<A-1;f++)
	for(g=1;g<B-1;g++)
	map[f][g]=0;
	for(x=1;x<=10;x++)
	{
		map[x][5]=11-x;
		dir[x]=2;
	}
	
	lo=10;
	ini=0;
}
    while(fl==0)
	{srand((unsigned)time(NULL));
    r1 = rand()%50+1;
    r2 = rand()%50+1;
    if(map[r1][r2]==0){
    	map[r1][r2]=-2;
    	fl=1;
	}}
    scanf("%d%d%d%d",&U,&D,&L,&R);
    for(ord=1;ord<=lo;ord++)
    for(f=0;f<A;f++)
	for(g=0;g<B;g++)
	{   
	    if(mark[map[f][g]]==1)continue;
		if(map[f][g]==1&&mark[1]==0){
			mark[1]=1;
			if(U==1&&(dir[1]==3||dir[1]==4)){
				if(map[f-1][g]!=0&&map[f-1][g]!=-2){ini=0;br=1;}
				if(map[f-1][g]==0){
					map[f-1][g]=1;
					dir[1]=1;
				}
				if(map[f-1][g]==-2){
					map[f-1][g]=1;
					dir[1]=1;
					eat=1;
					lo++;
				}
			}
			else if(D==1&&(dir[1]==3||dir[1]==4)){
				if(map[f+1][g]!=0&&map[f+1][g]!=-2){ini=0;br=1;}
				if(map[f+1][g]==0){
					map[f+1][g]=1;
					dir[1]=2;
				}
				if(map[f+1][g]==-2){
					map[f+1][g]=1;
					dir[1]=2;
					eat=1;
					lo++;
				}
			}
			else if(L==1&&(dir[1]==1||dir[1]==2)){
				if(map[f][g-1]!=0&&map[f][g-1]!=-2){ini=0;br=1;}
				if(map[f][g-1]==0){
					map[f][g-1]=1;
					dir[1]=3;
				}
				if(map[f][g-1]==-2){
					map[f][g-1]=1;
					dir[1]=3;
					eat=1;
					lo++;
				}
			}
			else if(R==1&&(dir[1]==1||dir[1]==2)){
				if(map[f][g+1]!=0&&map[f][g+1]!=-2){ini=0;br=1;}
				if(map[f][g+1]==0){
					map[f][g+1]=1;
					dir[1]=4;
				}
				if(map[f][g+1]==-2){
					map[f][g+1]=1;
					dir[1]=4;
					eat=1;
					lo++;
				}
			}
			else {
				if(dir[1]==1){
				   if(map[f-1][g]!=0&&map[f-1][g]!=-2){ini=0;br=1;}
				   if(map[f-1][g]==0){
					map[f-1][g]=1;
					dir[1]=1;
				    }
				    if(map[f-1][g]==-2){
					map[f-1][g]=1;
					dir[1]=1;
					eat=1;
					lo++;
				    }
				}
				if(dir[1]==2){
				   if(map[f+1][g]!=0&&map[f+1][g]!=-2){ini=0;br=1;}
				   if(map[f+1][g]==0){
					map[f+1][g]=1;
					dir[1]=2;
				    }
				    if(map[f+1][g]==-2){
					map[f+1][g]=1;
					dir[1]=2;
					eat=1;
					lo++;
				    }
				}
				if(dir[1]==3){
				   if(map[f][g-1]!=0&&map[f][g-1]!=-2){ini=0;br=1;}
				   if(map[f][g-1]==0){
					map[f][g-1]=1;
					dir[1]=3;
				    }
				    if(map[f][g-1]==-2){
					map[f][g-1]=1;
					dir[1]=3;
					eat=1;
					lo++;
				    }
				}
				if(dir[1]==4){
				   if(map[f][g+1]!=0&&map[f][g+1]!=-2){ini=0;br=1;}
				   if(map[f][g+1]==0){
					map[f][g+1]=1;
					dir[1]=4;
				    }
				    if(map[f][g+1]==-2){
					map[f][g+1]=1;
					dir[1]=4;
					eat=1;
					lo++;
				    }
				}
				
			}
		    temp=dir[1];
		}
	   
	   
	        if(map[f][g]==ord&&mark[ord]==0&&ord>=2){
	    	    mark[ord]=1;
	    	    if(dir[ord]==1){
	    		    map[f-1][g]=ord;
	    		    temp1=temp;
	    		    temp=dir[ord];
	    		    dir[ord]=temp1;
			    }
			    else if(dir[ord]==2){
	    		    map[f+1][g]=ord;
	    		    temp1=temp;
	    		    temp=dir[ord];
	    		    dir[ord]=temp1;
			    }
			    else if(dir[ord]==3){
	    		    map[f][g-1]=ord;
	    		    temp1=temp;
	    		    temp=dir[ord];
	    		    dir[ord]=temp1;
			    }
			    else if(dir[ord]==4){
	    		    map[f][g+1]=ord;
	    		    temp1=temp;
	    		    temp=dir[ord];
	    		    dir[ord]=temp1;
			    }
			    
			    if(eat==0&&ord==lo)map[f][g]=0;
			    if(eat==1&&ord==lo-1){
			    	map[f][g]=lo-1;
			    	if(dir[lo-1]==1)map[f+1][g]=lo;
			    	if(dir[lo-1]==2)map[f-1][g]=lo;
			    	if(dir[lo-1]==3)map[f][g+1]=lo;
			    	if(dir[lo-1]==4)map[f][g-1]=lo;
			    	dir[lo]=dir[lo-1];
			    	fl=0;
			    	eat=0;
			    	mark[ord]=1;
				}
				
		    }
		
		
	    
	    
	}






    for(f=0;f<A;f++)
	for(g=0;g<B;g++) 
	{
	printf("%2d",map[f][g]);
	if(g==B-1)printf("\n");}
}

}


