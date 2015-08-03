#include<stdlib.h>
#include<stdio.h>
#include<string.h>
FILE *f2;
int img[1000][1000],duplicate[1000][1000];
int height=0,width=0,pixel=0;
int top=-1;

struct vertex
{
	int type;
	int i;
	int j;
};

struct vertex hull[10000];

void push(struct vertex v)
{
	//printf("pushed i=%d,j=%d\n",v.i,v.j);
	top++;
	hull[top].type=v.type;
	hull[top].i=v.i;
	hull[top].j=v.j;
}

struct vertex pop()
{
	//printf("in pop top=%d\n",top);
	struct vertex temp;
	temp.type=hull[top].type;
	temp.i=hull[top].i;
	temp.j=hull[top].j;
	//printf("popped i=%d,j=%d\n",temp.i,temp.j);
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
	//printf("1=%d,j=%d\n",v.i,v.j);
	while(top>=5 &&check==0)
	{
		//printf("in makehull top=%d\n",top);
		struct vertex v1,v2,v3,v4,v5;
		v5=pop();
		v4=pop();
		v3=pop();
		v2=pop();
		v1=pop();
		//printf("i=%d,j=%d  i=%d,j=%d  i=%d,j=%d  i=%d,j=%d  i=%d,j=%d \n",v1.i,v1.j,v2.i,v2.j,v3.i,v3.j,v4.i,v4.j,v5.i,v5.j);
		//printf("%d %d %d %d %d\n",v1.type,v2.type,v3.type,v4.type,v5.type);
		char d=direction(v1,v2);
		
		if((v4.type==1) && (v3.type==3) &&(v2.type==3) &&(v1.type==1) )
		{
			//printf("here\n");
		//printf("i=%d,j=%d  i=%d,j=%d  i=%d,j=%d  i=%d,j=%d  i=%d,j=%d\n",v1.i,v1.j,v2.i,v2.j,v3.i,v3.j,v4.i,v4.j,v5.i,v5.j);
			if(d=='d')//down
			{
			
			//printf("i=%d,j=%d  i=%d,j=%d  i=%d,j=%d  i=%d,j=%d  i=%d,j=%d\n",v1.i,v1.j,v2.i,v2.j,v3.i,v3.j,v4.i,v4.j,v5.i,v5.j);
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



		//1333 do this at home
		else if((v4.type==3) && (v3.type==3) &&(v2.type==3) &&(v1.type==1) )
		{
		printf("i am here d=%c\n",d);
			if(d=='d')//down
			{
			printf("i am heredown\n");
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
			{printf("i am here up\n");
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
			printf("i am hereleft\n");
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
			printf("i am here right\n");
			printf("i=%d,j=%d  i=%d,j=%d  i=%d,j=%d  i=%d,j=%d  i=%d,j=%d\n",v1.i,v1.j,v2.i,v2.j,v3.i,v3.j,v4.i,v4.j,v5.i,v5.j);
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
		
		}//end of 1331 till here do at home
		else
		{
		check=1;
		push(v1);
		push(v2);
		push(v3);
		push(v4);
		push(v5);
		}
		//printf("i=%d,j=%d  i=%d,j=%d  i=%d,j=%d  i=%d,j=%d  i=%d,j=%d \n",v1.i,v1.j,v2.i,v2.j,v3.i,v3.j,v4.i,v4.j,v5.i,v5.j);
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
	//printf("i am here\n");
	begi=i;
	begj=j;
	occupy=0;
	occup=0;
	a1=0;a2=0;a3=0;a4=0;a5=0;a6=0;a7=0;a8=0;
	for(x=1;x<=pixel && (j+x)<1000;x++)
	{
		if(img[i][j+x]<scale)
		{
			a2=1;
			occup++;
			break;
		}
	}
	for(x=1;x<=pixel && (i+x)<1000;x++)
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
	//printf("blahblah\n");
		a5=1;
		a7=1;
	}
	if(a8==1)
	{
	//printf("blah\n");
		a1=1;
		a7=1;
	}
	for(x=1;x<=pixel && (j+x)<1000 && (i-x)>=0;x++)
	{
		if(img[i-x][j+x]<scale)
		{
			a1=1;
			break;
		}
	}
	for(x=1;x<=pixel && (i+x)<1000 && (j+x)<1000;x++)
	{
		if(img[i+x][j+x]<scale)
		{
			a3=1;
			break;
		}
	}
	for(x=1;x<=pixel && (i+x)<1000 && (j-x)>=0;x++)
	{
		if(img[i+x][j-x]<scale)
		{
			a5=1;
			break;
		}
	}	
	for(x=1;x<=pixel && (j-x)>=0 && (i-x)>=0;x++)
	{
		if(img[i-x][j-x]<scale)
		{
		//printf("blahblahblah\n");
			a7=1;
			break;
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
	//printf("i=%d,j=%d\n",v.i,v.j);
	makehull(v);
	}
	//printf("a1=%d a2=%d a3=%d a4=%d a5=%d a6=%d a7=%d a8=%d occupy=%d\n",a1,a2,a3,a4,a5,a6,a7,a8,occupy); 
	//printf("occupy =%d occup=%d\n",occupy,occup);
	if(occupy==4)
	{
		break;
	}
	if(occupy==0)
	{
		//printf("i am here\n");
		if(lastj!=begj)
		{
		//printf("i am here1\n");
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
		//printf("i am here2\n");
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
			//printf("occupy =%d occup=%d d=%d t=%d\n",occupy,occup,d,t);
		d=(t+d)%4;
		if(d<0)
		d=d+4;
		//printf("d=%d\n",d);
		if(d==1)
		{//printf("i am in occupy 1\n");
			i=i-pixel;
		}
		if(d==2)
		{//printf("i am in occupy 1\n");
			j=j-pixel;
		}
		if(d==0)
		{//printf("i am in occupy 1\n");
			j=j+pixel;
		}
		if(d==3)
		{//printf("i am in occupy 1\n");
			i=i+pixel;
		}
	}	
	//printf("i=%d\tj=%d occupy=%d\n",i,j,occupy);
	
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
	fprintf(f2,"%d\t%d\n",j,i);
	lasti=begi;
	lastj=begj;
	}while(i!=starti || j!=startj);
	
	v.i=i;
	v.j=j;
	if(occupy==0)
		v.type=1;
	else
		v.type=occupy;
	//printf("i=%d,j=%d\n",v.i,v.j);
	makehull(v);

	fclose(f2);
	//printf("%d\t%d\n",j,i);
}

void printhull()
{
	int k;
	struct vertex v1=pop(),v2;
	while(top!=-1)
	{
	v2=pop();
	//printf("%d\n",v1.type);
	//printf("i1=%d,j1=%d  i2=%d,j2=%d  type=%d\n",v1.i,v1.j,v2.i,v2.j,v1.type);
		
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
	for(x=1;x<=pixel && (j+x)<1000;x++)
	{
		if(img[i][j+x]==scale)
		{
			a2=0;
			occup++;
			break;
		}
	}
	for(x=1;x<=pixel && (i+x)<1000;x++)
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
	for(x=1;x<=pixel && (i+x)<1000;x++)
	{
		for(y=1;y<=pixel && (j+y)<1000;y++)
		{
		if(img[i-x][j+y]==scale)
		{
			a1=0;
			break;
		}
		}
	}
	
	for(x=1;x<=pixel && (i+x)<1000;x++)
	{
		for(y=1;y<=pixel && (j+y)<1000;y++)
		{
		if(img[i+x][j+y]==scale)
		{
			a3=0;
			break;
		}
		}
	}
	for(x=1;x<=pixel && (i+x)<1000;x++)
	{
		for(y=1;y<=pixel && (j+y)<1000;y++)
		{
		if(img[i+x][j-y]==scale)
		{
			a5=0;
			break;
		}
		}
	}	
	for(x=1;x<=pixel && (i+x)<1000;x++)
	{
		for(y=1;y<=pixel && (j+y)<1000;y++)
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


int main()
{

	f2=fopen("cover.txt","w");
	char a[100],filetype[100],ch;
	char s1[10]="P2",s2[10]="P5";
	int scale,i,j,starti,startj,flag=0,dummy,num_dark=0,val_dark=0,avg;
	printf("enter grid size : ");
	scanf("%d",&pixel);
	FILE *f=fopen("source_images/dance.pgm","r"),*f3=fopen("output.pgm","w");//opening files
	
	fgets(a,100,f);
	strcpy(filetype,a);
	fprintf(f3,"%s",a);
	if(filetype[1]=='2')
	{
		fgets(a,100,f);
		fprintf(f3,"%s",a);
	}
	fscanf(f,"%s",a);
	width=atoi(a);
	//fprintf(f3,"%s ",a);
	snprintf(a,100,"%d",width+2+2*pixel);
	fprintf(f3,"%s ",a);
	fscanf(f,"%s",a);
	height=atoi(a);
	//fprintf(f3,"%s\n",a);
	snprintf(a,100,"%d",height+2+2*pixel);
	fprintf(f3,"%s\n",a);
	fscanf(f,"%s",a);
	fprintf(f3,"%s\n",a);
	scale=atoi(a);
	for(i=0;i<1000;i++)
	{
		for(j=0;j<1000;j++)
		{
			img[i][j]=scale;
			duplicate[i][j]=scale;
		}
	}
	//printf("%s   %s\n",filetype,s1);
	if(filetype[1]==s1[1])    //reading from P2(ASCII) files
	{
		//printf("i am here1\n");
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
	
	
	
	//printf("%s   %s\n",filetype,s2);
	
	 
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
	
	
	
	//printing array
	/*for(i=0;i<height+2*pixel+2;i++)
	{
		for(j=0;j<width+2*pixel+2;j++)
		printf("%d ",img[i][j]);
		printf("\n");
	}*/
	
	/*for(i=0;i<height+2*pixel+2;i++)
	{
		for(j=0;j<width+2*pixel+2;j++)
		printf("%d ",img[i][j]);
		printf("\n");
	}*/
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
	printf("%d\t%d\n",val_dark,num_dark);
	avg=val_dark/num_dark+20;//finding average value.the value that is added varies with different images.may vary between 0 and 50.20,10,50 and 0 have been used in different case for testing
	printf("avg=%d\n",avg);
	
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
	
	
	
	
	
	
	
	for(i=pixel;i<pixel+height;i++)//finding the starting point
	{
		for(j=10;j<pixel+width;j++)
		{
			if(img[i+1][j+1]<scale)
			{
				//printf("i=%d j=%d\n",i,j);
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
		for(x=1;x<=pixel && (j+x)<1000;x++)
		{
			if(img[i][j+x]==scale)
			{
			
				a2=0;
				
				break;
			}
		}
		for(x=1;x<=pixel && (i+x)<1000;x++)
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
	for(x=1;x<=pixel && (i+x)<1000;x++)
	{
		for(y=1;y<=pixel && (j+y)<1000;y++)
		{
		if(img[i-x][j+y]==scale)
		{
			a1=0;
			break;
		}
		}
	}
	
	for(x=1;x<=pixel && (i+x)<1000;x++)
	{
		for(y=1;y<=pixel && (j+y)<1000;y++)
		{
		if(img[i+x][j+y]==scale)
		{
			a3=0;
			break;
		}
		}
	}
	for(x=1;x<=pixel && (i+x)<1000;x++)
	{
		for(y=1;y<=pixel && (j+y)<1000;y++)
		{
		if(img[i+x][j-y]==scale)
		{
			a5=0;
			break;
		}
		}
	}	
	for(x=1;x<=pixel && (i+x)<1000;x++)
	{
		for(y=1;y<=pixel && (j+y)<1000;y++)
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
	fprintf(f2,"%d\t%d\n",startj,starti);//writing starting points to file
	
	
	printf("startj=%d\tstarti=%d\n",startj,starti);//printing starting points
	
	
	
	//copying the original image to test.pgm
	/*for(i=pixel;i<=1+pixel+height;i++)
	{
	for(j=pixel;j<=1+pixel+width;j++)
	{
	fprintf(f3,"%d ",img[i][j]);
	}
	fprintf(f3,"\n");
	}*/
	
	duplicate[innerstarti][innerstartj]=500;
	duplicate[starti][startj]=400;
	move(starti,startj,scale);//transfer of control to move() function
	moveinner(innerstarti,innerstartj,scale,d);
	printhull();
	
	
	for(i=0;i<=1+pixel*2+height;i++)  //printing final image to file from array
	{
		for(j=0;j<=1+pixel*2+width;j++)
		{
			if(duplicate[i][j]==400)
				fprintf(f3,"%d\n",0);
			else if(duplicate[i][j]==800)
				fprintf(f3,"%d\n",150);
			else
				fprintf(f3,"%d\n",duplicate[i][j]);
		}
	//fprintf(f3,"\n");
	}
	remove("cover.txt");
	return 0;
}
	
			
