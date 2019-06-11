
#include<stdio.h>
//#include<conio.h>
//#include<dos.h>
//#include<graphics.h>

int initmouse();
void showptr();
void openwindow();
void closewindow();
void hideptr();
void getmousepos(int *,int*,int*);
void restrictptr(int,int,int,int);
int button,x,y,x1,y1,x2,y2,s;
long double num=0,get,num1=0,result=0;
long double addnum(int);
char opr;
int a,b,r,s,i1,count,c,sq,newnum=1,d=0;
union REGS i,o;
void main()
{
  int driver=DETECT,mode;
  int q,p[12];
  char input;
   char *inpu[4][4]={"1","2","3","4",
		  "5","6","7","8",
		  "9","0","+","-" ,
		  "*","/","clr","="};
  char inp[4][4]={'1','2','3','4',
		  '5','6','7','8',
		  '9','0','+','-' ,
		  '*','/','l','='};
  initgraph(&driver,&mode,"c:\\tc\\bgi");
  if(initmouse()==0)
  {
	printf("not");
	getch();
	exit(0);
  }
  openwindow();
  getch();
  cleardevice();
  setfillstyle(CLOSE_DOT_FILL,10);
  bar(260,82,450,320);
  bar(430,70,450,320);
  setfillstyle(1,GREEN);
  bar(236,82,432,300);
  setcolor(GREEN);
  rectangle(238,50,430,80);
  rectangle(237,49,431,81);
  rectangle(236,48,432,82);
  c=240;
  d=100;
  s=0;
   for(a=0;a<4;a++)
  {
	c=240;
	for(b=0;b<4;b++)
	{
	  setfillstyle(1,RED);
	  bar(c,d,c+40,d+40);
	  setcolor(YELLOW);
	  outtextxy(c+10,d+14,inpu[a][b]);
	  c+=50;
	}
	d+=50;
  }
  showptr();
  num=0;
  gotoxy(36,5);
  printf("%18.1Lf",num);
  count=0;
while(!kbhit())
{
  outtextxy(30,20,"Press any key to exit..");
  i1=0;
  c=240;
  d=100;
  rectangle(0,0,638,478);
  getmousepos(&button,&x,&y);
  for(a=0;a<4;a++)
  {
	c=240;
	for(b=0;b<4;b++)
	{
	  if((x>=c&&x<=c+40)&&(y>=d&&y<=d+40))
	  {
	   if((button&1)==1)
	   {
	 while((button&1)==1)
	 {
	   setcolor(10);
	   rectangle(c,d,c+40,d+40);
	   rectangle(c-1,d-1,c+41,d+41);
	   rectangle(c-2,d-2,c+42,d+42);
	   break;
	 }
	 delay(100);
	 setcolor(GREEN);
	 rectangle(c,d,c+40,d+40);
	 rectangle(c-1,d-1,c+41,d+41);
	 rectangle(c-2,d-2,c+42,d+42);
	 input=inp[a][b];
	 switch(input)
	 {
	 case '1':
		 get=addnum(1);
		 gotoxy(36,5);
		 printf("%18.1Lf",get);
		 break;
	 case '2':
		 get=addnum(2);
		 gotoxy(36,5);
		 printf("%18.1Lf",get);
		 break;
	  case '3':
		 get=addnum(3);
		 gotoxy(36,5);
		 printf("%18.1Lf",get);
		 break;
	   case '4':
		 get=addnum(4);
		 gotoxy(36,5);
		 printf("%18.1Lf",get);
		 break;
	 case '5':
		 get=addnum(5);
		 gotoxy(36,5);
		 printf("%18.1Lf",get);
		 break;
	 case '6':
		 get=addnum(6);
		 gotoxy(36,5);
		 printf("%18.1Lf",get);
		 break;
	 case '7':
		 get=addnum(7);
		 gotoxy(36,5);
		 printf("%18.1Lf",get);
		 break;
   case '8':
		 get=addnum(8);
		 gotoxy(36,5);
		 printf("%18.1Lf",get);
		 break;
   case '9':
		 get=addnum(9);
		 gotoxy(36,5);
		 printf("%18.1Lf",get);
		 break;
   case '0':
		 get=addnum(0);
		 gotoxy(36,5);
		 printf("%18.1Lf",get);
		 break;
	case '+':
		 num1=num;
		 num=0;
		 opr='+';
		 gotoxy(36,5);
		 printf("%18.1Lf",num);
		 break;
	 case '-':
		 num1=num;
		 num=0;
		 opr='-';
		 gotoxy(36,5);
		 printf("%18.1Lf",num);
		break;
	 case '*':
		 num1=num;
		 num=0;
		 opr='*';
		 gotoxy(36,5);
		 printf("%18.1Lf",num);
		break;
	 case '/':
		 num1=num;
		 num=0;
		 opr='/';
		 gotoxy(36,5);
		 printf("%18.1Lf",num);
		break;
	 case 'l':
		 num=0;
		 num1=0;
		 result=0;
		 count=0;
		 gotoxy(36,5);
		 printf("%18.1Lf",num);
		 break;
	 case '=':
		 switch(opr)
		 {
		   case '+':
				 if(count<1)
				 {
				   result=num+num1;
				 }
				 else
				 {
				   result=result+num;
				 }
				 gotoxy(36,5);
				 printf("%18.1Lf",result);
				 count+=1;
				 break;
		   case '-':
				 if(count<1)
				 {
				   result=num1-num;
				 }
				 else
				 {
				   result=result-num;
				 }
				 gotoxy(36,5);
				 printf("%18.1Lf",result);
				 count+=1;
				 break;
		   case '*':
				 if(count<1)
				 {
				  result=num1*num;
				 }
				 else
				 {
				  result=result*num;
				 }
				 gotoxy(36,5);
				 printf("%18.1Lf",result);
				 count+=1;
				 break;
		   case '/':
				 if(count<1)
				 {
				  result=num1/num;
				 }
				 else
				 {
				  result=result/num;
				 }
				 gotoxy(36,5);
				 printf("%18.1Lf",result);
				 count+=1;
				 break;
		 }
	 }
	   }
	  }
	  c+=50;
	}
	d+=50;
  }
  setcolor(YELLOW);
  delay(150);
}
  getch();
  closewindow();
  getch();
}
long double addnum(int getnum)
{
	num=num*10+getnum;
	return(num);
}
int initmouse()
{
	i.x.ax=0;
	int86(0x33,&i,&o);
	return(o.x.ax);
}
void showptr()
{
   i.x.ax=1;
   int86(0x33,&i,&o);
}
void hideptr()
{
   i.x.ax=2;
   int86(0x33,&i,&o);
}
void restrictptr(int x1,int y1,int x2,int y2)
{
	i.x.ax=7;
	o.x.cx=x1;
	o.x.dx=x2;
	int86(0x33,&i,&o);
	i.x.ax=8;
	o.x.cx=y1;
	o.x.dx=y2;
	int86(0x33,&i,&o);
}
void getmousepos(int *button,int *x,int *y)
{
  i.x.ax=3;
  int86(0x33,&i,&o);
  *button=o.x.bx;
  *x=o.x.cx;
  *y=o.x.dx;
}
void openwindow()
{
	int aa,bb,cc,dd,maxx,maxy,i=10;
	maxx=getmaxx();
	maxy=getmaxy();
	rectangle(0,0,maxx,maxy);
	aa=250;
	bb=400;
	cc=260;
	for(dd=250;dd<350;dd+=20)
	{
	   setfillstyle(1,2);
	   bar(dd,bb,cc,bb+10);
	   cc+=20;
	}
	aa=250;
	bb=400;
	cc=260;
	while(!kbhit())
	{
	setcolor(i);
	outtextxy(20,20,"Hello, Every body i am ashish chaudhary");
	outtextxy(20,32,"I have created this basic calculator using graphics");
	outtextxy(20,44,"This is a 16 digits calculator, you can use upto 16 digit for claculation");
	outtextxy(20,56,"Don't use more than 16 digit's");
	outtextxy(20,68,"Currently i am doing B.Sc(c.s) ");
	outtextxy(20,80,"If you want to contact to me use my e-mail Id--");
	outtextxy(20,92,".net_programmer_ashish@67.com");
	outtextxy(20,104,"my phone number is 9997796324");
	outtextxy(20,116,"Press any key to continue.......");
	if((aa==350)&&(cc==360))
	{
	  aa=250;
	  cc=260;
	  continue;
	}
	else
	{
	setcolor(10);
	rectangle(aa,bb,cc,bb+10);
	rectangle(aa-1,bb-1,cc+1,bb+11);
	}
	delay(300);
	setcolor(BLACK);
	rectangle(aa,bb,cc,bb+10);
	rectangle(aa-1,bb-1,cc+1,bb+11);
	aa+=20;
	cc+=20;
	}

}
void closewindow()
{
  int i,j,k;
  cleardevice();
  rectangle(0,0,638,478);
  k=0;
  while(!kbhit())
  {
   setcolor(k);
   settextstyle(5,0,8);
  outtextxy(100,200,"THANK YOU");
  line(90,300,600,300);
  delay(200);
  k++;
  }
}
