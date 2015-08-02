#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX_SIZE MAX_SIZE0

int img[MAX_SIZE][MAX_SIZE],duplicate[MAX_SIZE][MAX_SIZE];
int height=0,width=0,pixel=0;
int top=-1;

struct vertex
{
	int type;
	int i;
	int j;
};

struct vertex hull[MAX_SIZE];

void push(struct vertex v)
{
	top++;
	hull[top].type=v.type;
	hull[top].i=v.i;
	hull[top].j=v.j;
}

struct vertex pop()
{
	struct vertex temp;
	temp.type=hull[top].type;
	temp.i=hull[top].i;
	temp.j=hull[top].j;
	top--;
	return temp;
}
		
	
char direction(struct vertex a,struct vertex b)
{
	if(a.i==b.i)//horizontal
	{
		if(a.j<b.j)
			return 'd';
		else
			return 'u';
	}
	if(a.j==b.j)//vertical
	{
		if(a.i<b.i)
			return 'l';
		else
			return 'r';
	}
}
		
	
	
	
void makehull(struct vertex v)
{
	push(v);
	int check=0;
	while(top>=5 &&check==0)
	{
		struct vertex v1,v2,v3,v4,v5;
		v5=pop();
		v4=pop();
		v3=pop();
		v2=pop();
		v1=pop();
		char d=direction(v1,v2);
		
		if((v4.type==1) && (v3.type==3) &&(v2.type==3) &&(v1.type==1) )
		{
			if(d=='d')//down
			{
			
				if(v1.j==v4.j)
				{
					push(v5);
				}
				if(v1.j>v4.j)
				{
					v1.i=v4.i;
					v1.type=3;
					push(v1);
					push(v4);
					push(v5);
				}
				if(v1.j<v4.j)
				{
					push(v1);
					v4.i=v1.i;
					v4.type=3;
					push(v4);
					push(v5);
				}
			}
			
			if(d=='u')//up
			{
				if(v1.j==v4.j)
				{
					push(v5);
				}
				if(v1.j<v4.j)
				{
					v1.i=v4.i;
					v1.type=3;
					push(v1);
					push(v4);
					push(v5);
				}
				if(v1.j>v4.j)
				{
					push(v1);
					v4.i=v1.i;
					v4.type=3;
					push(v4);
					push(v5);
				}
			}
		
		
			if(d=='l')//left
			{
				if(v1.i==v4.i)
				{
					push(v5);
				}
				if(v1.i>v4.i)
				{
					v1.j=v4.j;
					v1.type=3;
					push(v1);
					push(v4);
					push(v5);
				}
				if(v1.i<v4.i)
				{
					push(v1);
					v4.j=v1.j;
					v4.type=3;
					push(v4);
					push(v5);
				}
			}
		
		
			if(d=='r')//right
			{
				if(v1.i==v4.i)
				{
					push(v5);
				}
				if(v1.i<v4.i)
				{
					v1.j=v4.j;
					v1.type=3;
					push(v1);
					push(v4);
					push(v5);
				}
				if(v1.i>v4.i)
				{
					push(v1);
					v4.j=v1.j;
					v4.type=3;
					push(v4);
					push(v5);
				}
			}
			
		}//end of 1331



		//1333
		else if((v4.type==3) && (v3.type==3) &&(v2.type==3) &&(v1.type==1) )
		{
			if(d=='d')//down
			{
				if(v1.j==v4.j)
				{
					v5.type=3;
					push(v5);
				}
				if(v1.j>v4.j)
				{
					v1.i=v4.i;
					v1.type=3;
					push(v1);
					push(v4);
					push(v5);
				}
				if(v1.j<v4.j)
				{
					v5.type=3;
					v2.j=v5.j;
					push(v1);
					push(v2);					
					push(v5);
				}
			}
			
			
			if(d=='u')//up
			{
				if(v1.j==v4.j)
				{
					v5.type=3;
					push(v5);
				}
				if(v1.j<v4.j)
				{
					v1.i=v4.i;
					v1.type=3;
					push(v1);
					push(v4);
					push(v5);
				}
				if(v1.j>v4.j)
				{
					v5.type=3;
					v2.j=v5.j;
					push(v1);
					push(v2);					
					push(v5);
				}
			}
			
		
			if(d=='l')//left
			{
				if(v1.i==v4.i)
				{
					v5.type=3;
					push(v5);
				}
				if(v1.i>v4.i)
				{
					v1.j=v4.j;
					v1.type=3;
					push(v1);
					push(v4);
					push(v5);
				}
				if(v1.i<v4.i)
				{
					v5.type=3;
					v2.i=v5.i;
					push(v1);
					push(v2);					
					push(v5);
				}
			}
		
		
			if(d=='r')//right
			{
				if(v1.i==v4.i)
				{
					
					v5.type=3;
					push(v5);
				}
				if(v1.i<v4.i)
				{
					v1.j=v4.j;
					v1.type=3;
					push(v1);
					push(v4);
					push(v5);
				}
				if(v1.i>v4.i)
				{
					
					v5.type=3;
					v2.i=v5.i;
					push(v1);
					push(v2);					
					push(v5);
				}
			}
		
		}//end of 1331 
		else
		{
		check=1;
		push(v1);
		push(v2);
		push(v3);
		push(v4);
		push(v5);
		}
	}
}



	

void move(int starti,int startj,int scale)
{
	struct vertex v;
	v.i=starti;
	v.j=startj;
	v.type=1;
	makehull(v);
	int a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,i=starti,j=startj,x,y,occupy,occup,begi,begj,lasti,lastj,d=2,t;
	do
	{
	begi=i;
	begj=j;
	occupy=0;
	occup=0;
	a1=0;a2=0;a3=0;a4=0;a5=0;a6=0;a7=0;a8=0;
	for(x=1;x<=pixel && (j+x)<MAX_SIZE0;x++)
	{
		if(img[i][j+x]<scale)
		{
			a2=1;
			occup++;
			break;
		}
	}
	for(x=1;x<=pixel && (i+x)<MAX_SIZE0;x++)
	{
		if(img[i+x][j]<scale)
		{
			a4=1;
			occup++;
			break;
		}
	}
	for(x=1;x<=pixel && (j-x)>=0;x++)
	{
		if(img[i][j-x]<scale)
		{
			a6=1;
			occup++;
			break;
		}
	}
	for(x=1;x<=pixel && (i-x)>=0;x++)
	{
		if(img[i-x][j]<scale)
		{
			a8=1;
			occup++;
			break;
		}
	}

	if(a2==1)
	{
		a1=1;
		a3=1;
	}
	if(a4==1)
	{
		a5=1;
		a3=1;
	}
	if(a6==1)
	{
		a5=1;
		a7=1;
	}
	if(a8==1)
	{
		a1=1;
		a7=1;
	}
	for(x=1;x<=pixel && (i+x)<MAX_SIZE0;x++)
	{
		for(y=1;y<=pixel && (j+y)<MAX_SIZE0;y++)
		{
		if(img[i-x][j+y]<scale)
		{
			a1=1;
			break;
		}
		}
	}
	
	for(x=1;x<=pixel && (i+x)<MAX_SIZE0;x++)
	{
		for(y=1;y<=pixel && (j+y)<MAX_SIZE0;y++)
		{
		if(img[i+x][j+y]<scale)
		{
			a3=1;
			break;
		}
		}
	}
	for(x=1;x<=pixel && (i+x)<MAX_SIZE0;x++)
	{
		for(y=1;y<=pixel && (j+y)<MAX_SIZE0;y++)
		{
		if(img[i+x][j-y]<scale)
		{
			a5=1;
			break;
		}
		}
	}	
	for(x=1;x<=pixel && (i+x)<MAX_SIZE0;x++)
	{
		for(y=1;y<=pixel && (j+y)<MAX_SIZE0;y++)
		{
		if(img[i-x][j-y]<scale)
		{
			a7=1;
			break;
		}
		}
	}	
	if(a1==1)
	{
		occupy++;
	}
	if(a3==1)
	{
		occupy++;
	}
	if(a5==1)
	{
		occupy++;
	}
	if(a7==1)
	{
		occupy++;
	}
	if(occupy!=2)
	{
	v.i=i;
	v.j=j;
	if(occupy==0)
		v.type=1;
	else
		v.type=occupy;
	makehull(v);
	}
	if(occupy==4)
	{
		break;
	}
	if(occupy==0)
	{
		if(lastj!=begj)
		{
			if(lastj<begj)
			{
				i=i-pixel;
				d=1;
			}
			else
			{
				d=3;
				i=i+pixel;
			}
		}
		if(lasti!=begi)
		{
			if(lasti<begi)
			{
				d=0;
				j=j+pixel;
			}
			else
			{
				d=2;
				j=j-pixel;
			}
		}
	}
	else
	{
		if(occupy==1)
			t=1;
		if(occupy==2)
		{
			if((a1==1 && a3==1) || (a3==1 && a5==1) || (a5==1 && a7==1) || (a1==1 && a7==1))
			t=0;
			else
			t=-1;
		}
		if(occupy==3)
			t=-1;
			d=(t+d)%4;
		if(d<0)
		d=d+4;
		if(d==1)
		{	i=i-pixel;
		}
		if(d==2)
		{	j=j-pixel;
		}
		if(d==0)
		{	j=j+pixel;
		}
		if(d==3)
		{	i=i+pixel;
		}
	}	
	
	if(i!=begi)
	{
		if(begi<i)
		{
			for(x=begi;x<=i;x++)
				duplicate[x][j]=400;
		}
		else
		{
			for(x=begi;x>=i;x--)
				duplicate[x][j]=400;
		}
	}
	if(j!=begj)
	{
		if(begj<j)
		{
			for(x=begj;x<=j;x++)
				duplicate[i][x]=400;
		}
		else
		{
			for(x=begj;x>=j;x--)
				duplicate[i][x]=400;
		}
	}
	
	lasti=begi;
	lastj=begj;
	}while(i!=starti || j!=startj);
	
	v.i=i;
	v.j=j;
	if(occupy==0)
		v.type=1;
	else
		v.type=occupy;
	makehull(v);
}



void moveinner(int starti,int startj,int scale,int d)
{
	
	int a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,i=starti,j=startj,x,y,occupy,occup,begi,begj,lasti,lastj,t;
	do
	{
	begi=i;
	begj=j;
	occupy=0;
	occup=0;
	a1=1;a2=1;a3=1;a4=1;a5=1;a6=1;a7=1;a8=1;
	for(x=1;x<=pixel && (j+x)<MAX_SIZE0;x++)
	{
		if(img[i][j+x]==scale)
		{
			a2=0;
			occup++;
			break;
		}
	}
	for(x=1;x<=pixel && (i+x)<MAX_SIZE0;x++)
	{
		if(img[i+x][j]==scale)
		{
			a4=0;
			occup++;
			break;
		}
	}
	for(x=1;x<=pixel && (j-x)>=0;x++)
	{
		if(img[i][j-x]==scale)
		{
			a6=0;
			occup++;
			break;
		}
	}
	for(x=1;x<=pixel && (i-x)>=0;x++)
	{
		if(img[i-x][j]==scale)
		{
			a8=0;
			occup++;
			break;
		}
	}

	if(a2==0)
	{
		a1=0;
		a3=0;
	}
	if(a4==0)
	{
		a5=0;
		a3=0;
	}
	if(a6==0)
	{
		a5=0;
		a7=0;
	}
	if(a8==0)
	{
		a1=0;
		a7=0;
	}
	for(x=1;x<=pixel && (i+x)<MAX_SIZE0;x++)
	{
		for(y=1;y<=pixel && (j+y)<MAX_SIZE0;y++)
		{
		if(img[i-x][j+y]==scale)
		{
			a1=0;
			break;
		}
		}
	}
	
	for(x=1;x<=pixel && (i+x)<MAX_SIZE0;x++)
	{
		for(y=1;y<=pixel && (j+y)<MAX_SIZE0;y++)
		{
		if(img[i+x][j+y]==scale)
		{
			a3=0;
			break;
		}
		}
	}
	for(x=1;x<=pixel && (i+x)<MAX_SIZE0;x++)
	{
		for(y=1;y<=pixel && (j+y)<MAX_SIZE0;y++)
		{
		if(img[i+x][j-y]==scale)
		{
			a5=0;
			break;
		}
		}
	}	
	for(x=1;x<=pixel && (i+x)<MAX_SIZE0;x++)
	{
		for(y=1;y<=pixel && (j+y)<MAX_SIZE0;y++)
		{
		if(img[i-x][j-y]==scale)
		{
			a7=0;
			break;
		}
		}
	}
	printf("a1=%d a3=%d a5=%d a7=%d ",a1,a3,a5,a7); 
	if(a1==0)
	{
		occupy++;
	}
	if(a3==0)
	{
		occupy++;
	}
	if(a5==0)
	{
		occupy++;
	}
	if(a7==0)
	{
		occupy++;
	}
	
	if(occupy==4)
	{
		break;
	}
	if(occupy==0)
	{
		if(lastj!=begj)
		{
			if(lastj<begj)
			{
				i=i-pixel;
				d=1;
			}
			else
			{
				d=3;
				i=i+pixel;
			}
		}
		if(lasti!=begi)
		{
			if(lasti<begi)
			{
				d=0;
				j=j+pixel;
			}
			else
			{
				d=2;
				j=j-pixel;
			}
		}
	}
	else
	{
		if(occupy==1)
			t=-1;
		if(occupy==2)
		{
			if((a1==1 && a3==1) || (a3==1 && a5==1) || (a5==1 && a7==1) || (a1==1 && a7==1))
			t=0;
			else
			t=1;
		}
		if(occupy==3)
			t=1;
		printf("d=%d t=%d\n",d,t);
		d=(t+d)%4;
		if(d<0)
		d=d+4;
		if(d==1)
		{	i=i-pixel;
		}
		if(d==2)
		{	j=j-pixel;
		}
		if(d==0)
		{	j=j+pixel;
		}
		if(d==3)
		{	i=i+pixel;
		}
	}	
	
	if(i!=begi)
	{
		if(begi<i)
		{
			for(x=begi;x<=i;x++)
				duplicate[x][j]=500;
		}
		else
		{
			for(x=begi;x>=i;x--)
				duplicate[x][j]=500;
		}
	}
	if(j!=begj)
	{
		if(begj<j)
		{
			for(x=begj;x<=j;x++)
				duplicate[i][x]=500;
		}
		else
		{
			for(x=begj;x>=j;x--)
				duplicate[i][x]=500;
		}
	}
	
	lasti=begi;
	lastj=begj;
	}while(i!=starti || j!=startj);
}

void printhull()
{
	int k;
	struct vertex v1=pop(),v2;
	while(top!=-1)
	{
	v2=pop();
		
		if(v1.i==v2.i)
		{
			if(v1.j<v2.j)
			{
				for(k=v1.j;k<=v2.j;k++)
					duplicate[v1.i][k]=800;
			}
			if(v1.j>v2.j)
			{
				for(k=v2.j;k<=v1.j;k++)
					duplicate[v1.i][k]=800;
			}
		}
		
		if(v1.j==v2.j)
		{
			if(v1.i<v2.i)
			{
				for(k=v1.i;k<=v2.i;k++)
					duplicate[k][v1.j]=800;
			}
			if(v1.i>v2.i)
			{
				for(k=v2.i;k<=v1.i;k++)
					duplicate[k][v1.j]=800;
			}
		}
		
				
		v1=v2;
		
	}
}	
		
		
			


int main()//driver program
{

	
	char a[MAX_SIZE],filetype[MAX_SIZE],ch;
	char s1[10]="P2",s2[10]="P5";
	int scale,i,j,starti,startj,flag=0,dummy,num_dark=0,val_dark=0,avg;
	printf("enter grid size : ");
	scanf("%d",&pixel);
	FILE *f=fopen("p2/dance.pgm","r"),*f3=fopen("test.pgm","w");//opening files
	
	fgets(a,MAX_SIZE,f);
	strcpy(filetype,a);
	fprintf(f3,"%s",a);
	if(filetype[1]=='2')
	{
		fgets(a,MAX_SIZE,f);
		fprintf(f3,"%s",a);
	}
	fscanf(f,"%s",a);
	width=atoi(a);
	//fprintf(f3,"%s ",a);
	snprintf(a,MAX_SIZE,"%d",width+2+2*pixel);
	fprintf(f3,"%s ",a);
	fscanf(f,"%s",a);
	height=atoi(a);
	//fprintf(f3,"%s\n",a);
	snprintf(a,MAX_SIZE,"%d",height+2+2*pixel);
	fprintf(f3,"%s\n",a);
	fscanf(f,"%s",a);
	fprintf(f3,"%s\n",a);
	scale=atoi(a);
	for(i=0;i<MAX_SIZE0;i++)
	{
		for(j=0;j<MAX_SIZE0;j++)
		{
			img[i][j]=scale;
			duplicate[i][j]=scale;
		}
	}
	
	if(filetype[1]==s1[1])    //reading from P2(ASCII) files
	{
		
		for(i=1+pixel;i<1+pixel+height;i++)
		{
			for(j=1+pixel;j<1+pixel+width;j++)
			{
				fscanf(f,"%s",a);
				img[i][j]=atoi(a);
				duplicate[i][j]=atoi(a);
			}
		}
	}
	
	
	
	
	
	 
	if(filetype[1]==s2[1])//reading from P5(RAW) files
	{
		for(i=0;i<height;i++)
		{
			printf("i am here2\n");
			fread((void *)(&duplicate[i][0]),2,width,f);
			fwrite((void *)(&duplicate[i][0]),2,width,f3);
			fread((void *)(&img[i][0]),2,width,f);
			
		}
	}
	
	
	
	
	for(i=1+pixel;i<1+pixel+height;i++)
	{
		for(j=1+pixel;j<1+pixel+width;j++)
		{
			if(img[i][j]<scale)
			{
			num_dark++;
			val_dark +=img[i][j];
			}
			
		}
	}
	
	avg=val_dark/num_dark+20;//finding average value.the value that is added varies with different images.may vary between 0 and 50.20,10,50 and 0 have been used in different case for testing
	printf("tot=%d avg=%d num=%d",val_dark,avg,num_dark);
	
	for(i=1+pixel;i<1+pixel+height;i++)
	{
		for(j=1+pixel;j<1+pixel+width;j++)
		{
			
			
			if(img[i][j]<avg)
			{
				img[i][j]=avg;
				duplicate[i][j]=avg;
			}
			else
			{
				img[i][j]=scale;
				duplicate[i][j]=scale;
			}
		}
	}
	
	
	
	
	
	
	
	for(i=pixel;i<pixel+height;i=i+1)//finding the starting point for outer cover
	{
		for(j=pixel;j<pixel+width;j=j+1)
		{
			if(img[i+1][j+1]<scale)
			{
				
				starti=i;
				startj=j;
				flag=1;
				break;
			}
		}
		if(flag==1)
			break;
	}
	int count=0,a1=1,a3=1,a5=1,a7=1,d=0,a2,a4,a6,a8,innerstarti=0,innerstartj=0,x,y,ki,kj;
	for(i=pixel+(starti%pixel);i<height;i=i+pixel)//finding the starting point for inner cover
	{
		
		for(j=pixel+(startj%pixel);j<width;j=j+pixel)
		{
		count=0;
		
		a1=1;a2=1;a3=1;a4=1;a5=1;a6=1;a7=1;a8=1;
		for(x=1;x<=pixel && (j+x)<MAX_SIZE0;x++)
		{
			if(img[i][j+x]==scale)
			{
			
				a2=0;
				
				break;
			}
		}
		for(x=1;x<=pixel && (i+x)<MAX_SIZE0;x++)
		{
			if(img[i+x][j]==scale)
			{
				a4=0;
				
				break;
			}
		}
		for(x=1;x<=pixel && (j-x)>=0;x++)
		{
			if(img[i][j-x]==scale)
			{
				a6=0;
				break;
			}
		}
		for(x=1;x<=pixel && (i-x)>=0;x++)
		{
			if(img[i-x][j]==scale)
			{
			
				a8=0;
			
				break;
			}
		}
	
		if(a2==0)
		{
			a1=0;
			a3=0;
			
		}
		if(a4==0)
		{
			a5=0;
			a3=0;
		}
		if(a6==0)
		{
		
			a5=0;
			a7=0;
		}
		if(a8==0)
		{
			
			a1=0;
			a7=0;
		}
	for(x=1;x<=pixel && (i+x)<MAX_SIZE0;x++)
	{
		for(y=1;y<=pixel && (j+y)<MAX_SIZE0;y++)
		{
		if(img[i-x][j+y]==scale)
		{
			a1=0;
			break;
		}
		}
	}
	
	for(x=1;x<=pixel && (i+x)<MAX_SIZE0;x++)
	{
		for(y=1;y<=pixel && (j+y)<MAX_SIZE0;y++)
		{
		if(img[i+x][j+y]==scale)
		{
			a3=0;
			break;
		}
		}
	}
	for(x=1;x<=pixel && (i+x)<MAX_SIZE0;x++)
	{
		for(y=1;y<=pixel && (j+y)<MAX_SIZE0;y++)
		{
		if(img[i+x][j-y]==scale)
		{
			a5=0;
			break;
		}
		}
	}	
	for(x=1;x<=pixel && (i+x)<MAX_SIZE0;x++)
	{
		for(y=1;y<=pixel && (j+y)<MAX_SIZE0;y++)
		{
		if(img[i-x][j-y]==scale)
		{
			a7=0;
			break;
		}
		}
	}
		if(a1==0) count++;
		if(a3==0) count++;
		if(a5==0) count++;
		if(a7==0) count++;
		if(count==1)
		break;
	}
	if(count==1)
	{
	printf("a1=%d a3=%d a5=%d a7=%d\n",a1,a3,a5,a7);
		if(a1==0) d=2;
		if(a3==0) d=1;
		if(a5==0) d=4;
		if(a7==0) d=3;
		break;
	}
}
if(count==1)
{
		innerstarti=i;
		innerstartj=j;
}	
		
	
	
	
	
	printf("startj=%d\tstarti=%d d=%d\n",innerstartj,innerstarti,d);//printing starting points
	
	
	
	//duplicate[innerstarti][innerstartj]=500;
	//duplicate[starti][startj]=400;
	//move(starti,startj,scale);//transfer of control to move() function
	//printhull();
	//moveinner(innerstarti,innerstartj,scale,d);
	ki=starti%pixel;
	kj=startj%pixel;
	
	for(i=1+pixel;i<1+pixel+height;i++)
	{
		for(j=1+pixel;j<1+pixel+width;j++)
		{
	if(((i%(pixel)==ki) ||(j%(pixel)==kj))&&(duplicate[i][j]==scale))
	duplicate[i][j]=700;
	}
	}
	
	
	
	for(i=0;i<=1+pixel*2+height;i++)  //printing final image to file from array
	{
		for(j=0;j<=1+pixel*2+width;j++)
		{
			
			if(duplicate[i][j]==400)
				fprintf(f3,"%d\n",0);
			else if(duplicate[i][j]==800)
				fprintf(f3,"%d\n",150);
				else if(duplicate[i][j]==500)
				fprintf(f3,"%d\n",scale);
			else if(duplicate[i][j]==avg)
				fprintf(f3,"%d\n",duplicate[i][j]);	
			else
			{
			if(duplicate[i][j]==700)
				fprintf(f3,"%d\n",230);
				else
				fprintf(f3,"%d\n",duplicate[i][j]);
				}
		}
	
	}
	
	return 0;
}
	
			
