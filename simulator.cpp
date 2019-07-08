#include"mouse.cpp"

struct file
{
 int fmem[1024],fdel[1024],fpc;
}fee;
int a,b,c,d,e,h,l,w,z,sp,pc,flag,lo,hi,data,A,B,C,D,L,index,fag=0,ind,de,ret[10];
int mem[1024],ram[512],re,ml1,ml2,S,Z,P,CY,opcode=0,ad,st,del[1024],sou=-1,des=-1,cy,p,c1,z1;
int delet[2],q,CWR,portA,portB,portCu,portCl,cl1,cl2,cl3,cl4;
long temp,key=0;
char in[5],so[5],name[15];
const char *path;
int sta(int);
FILE *np;

void add(int h,int l);
void addsp();
void pop();
void run();
void logic(int b);
void display();
void dad();
void dis();
void disy();
void delett();
void reload();
void datashow();
void click();
void regclick();
void hexclick();
void jumpclick();
void callclick();
void retclick();
void lable();
void lable1();
void dis1();
void instdisplay();
void link();
void setting();
void dis2();

struct node
{
  int i;
  char lab[5];
}
arr[20],acr[30];


void lable()
{
	sou++;
	arr[sou].i=del[ml1-1];
   mouse m;
   m.hidemouseptr();
   for(int x=150,a=300;x<=250;x++,a--)
    for(int n=130;n<200;n++)
	 {
     putpixel(x,n,1);
     putpixel(a,n,1);
    }
    delay(300);
  for(x=211,a=209;a<=290;x--,a++)
   {
    for(n=140;n<190;n++)
    {
     putpixel(x,n,2);
     putpixel(a,n,2);
    }
    if(x<160)
    x++;
   }
gotoxy(53,16);
cout<<"Lable:- ";
cin>>arr[sou].lab;
m.showmouseptr();
}

void lable1()
{
mouse m;
m.hidemouseptr();
des++;
ind=ind-200;
acr[des].i=del[CY+ind];
   for(int x=150,a=300;x<=250;x++,a--)
    for(int n=130;n<200;n++)
    {
     putpixel(x,n,1);
     putpixel(a,n,1);
    }
    delay(300);
  for(x=211,a=209;a<=290;x--,a++)
   {
    for(n=140;n<190;n++)
    {
     putpixel(x,n,2);
     putpixel(a,n,2);
    }
    if(x<160)
    x++;
   }
gotoxy(53,16);
cout<<"Lable:- ";
cin>>acr[des].lab;
m.showmouseptr();
}

void delett()
{
int tempi,temp1,temp2;
ind=ind-200;
tempi=del[CY+ind];
temp1=del[CY+ind+1];
if(temp1>tempi)
{
	temp2=temp1-tempi;
	for(tempi=del[CY+ind];tempi<pc;tempi++,temp1++)
	{
	 mem[tempi]=mem[temp1];
	}
	for(tempi=(CY+ind+1);tempi<ml1-12;tempi++)
	 {
	   del[tempi]=del[tempi+1]-temp2;
	}
	datashow();
	pc=pc-temp2;
	ml1--;
}
}
void link()
{
 int che=-1;
 for(a=0;a<=des;a++)
 {
    for(int x1=0;x1<=sou;x1++)
   {
    if(strcmp(acr[a].lab,arr[x1].lab)==0)
    {
      int bin[16];
      che++;
      w=acr[a].i;
	for(int x=0;x<16;x++)
	 {
	  bin[x]=w%2;
	  if(w!=0)
	   w=w/2;
	 }
	 w=0;
	 z=0;
	if(bin[0]==1)
	 w=w+1;
	if(bin[1]==1)
	 w=w+2;
	if(bin[2]==1)
	 w=w+4;
	if(bin[3]==1)
	 w=w+8;
	if(bin[4]==1)
	 w=w+16;
	if(bin[5]==1)
	 w=w+32;
	if(bin[6]==1)
	 w=w+64;
	if(bin[7]==1)
	 w=w+128;

	if(bin[8]==1)
	 z=z+1;
	if(bin[9]==1)
	 z=z+2;
	if(bin[10]==1)
	 z=z+4;
	if(bin[11]==1)
	 z=z+8;
	if(bin[12]==1)
	 z=z+16;
	if(bin[13]==1)
	 z=z+32;
	if(bin[14]==1)
	 z=z+64;
	if(bin[15]==1)
	 z=z+128;

	 mem[arr[x1].i+1]=w;
	 mem[arr[x1].i+2]=z;
       }
     }
    }
    for(int x=50,a=360;x<=210;x++,a--)
    for(int n=40;n<160;n++)
    {
     putpixel(x,n,7);
     putpixel(a,n,7);
    }

    delay(300);
  for(x=211,a=209;x>=60;x--)
   {
    for(n=50;n<150;n++)
    {
     putpixel(x,n,1);
     putpixel(a,n,1);
    }
    if(a<350)
    a++;
  }
    setcolor(15);
    if(che!=sou)
    {
    moveto(60,60);
    outtext("    Error");
    moveto(60,80);
    outtext("    Please Check LABLES ");
    moveto(60,100);
    outtext(" *** PRESS ENTER ***  ");
    opcode=0;
    }
    else
    {
    moveto(60,60);
    outtext("   No Error Detected");
    moveto(60,80);
    outtext(" *** PRESS ENTER *** ");
    opcode=99;
    }
    setcolor(0);
//   getch();
 }

void display()
{
   cleardevice();

 settextstyle(0,0,1);
 setbkcolor(BLACK);
 setfillstyle(1,cl1);
 bar(0,13,215,60);
 bar(0,82,215,256);
 bar(0,278,215,348);
 bar(0,365,215,450);
 if(cl1==0)
 {
 setfillstyle(1,1);
 bar(0,365,215,450);
 }
 setcolor(WHITE);
 setfillstyle(1,cl2);
 for(B=20,C=35;B<45;B+=20,C+=20)
   for(A=10;A<170;A+=50)
    {
   bar(A,B,A+40,C);
   rectangle(A,B,A+40,C);
   }
 for(B=90,C=105;B<240;B+=20,C+=20)
   for(A=10;A<170;A+=50)
    {
    bar(A,B,A+40,C);
    rectangle(A,B,A+40,C);
    }
 for(B=285,C=300;B<335;B+=20,C+=20)
   for(A=10;A<170;A+=50)
    {
    bar(A,B,A+40,C);
    rectangle(A,B,A+40,C);
    }
 bar(10,375,205,440);



setcolor(cl3);
moveto(2,24);
    outtext("  MOV   MVI    LXI  XCHG");
moveto(2,44);
    outtext("  LDAX  STAX  LHLD  SHLD");
moveto(2,94);
    outtext("  ADD   ADI    ADC   ADI");
moveto(2,114);
    outtext("  SUB   SBB    SBC   SBI");
moveto(2,134);
    outtext("  INR   INX    DCR   DCX");
moveto(2,154);
    outtext("  DAD                OUT");


setcolor(cl4);
moveto(2,174);
    outtext("  ANA   ANI    XRA   XRI");
moveto(2,194);
    outtext("  ORA   ORI    CMP   CPI");
moveto(2,214);
    outtext("  CMA   CMC    STC");
moveto(2,234);
    outtext("  RLC   RRC    RAL   RAR");


setcolor(cl3);
moveto(2,289);
    outtext(" JUMP   CALL  RET   REST");
moveto(2,309);
    outtext("  PUSH  POP   XTHL  SPHL");
moveto(2,329);
    outtext("  HLT   NOP");
 moveto(5,385);
 outtext(" 8255 port address :");
 moveto(20,400);
 outtext("CWR    :-> 83 hex");
 moveto(20,410);
 outtext("port A :-> 80 hex");
 moveto(20,420);
 outtext("port B :-> 81 hex");
 moveto(20,430);
 outtext("port C :-> 82 hex");
 if(cl1!=1)
 {
 setfillstyle(1,1);
 bar(0,0,130,10);
 bar(0,67,185,80);
 bar(0,262,200,275);
 }
 else
 {
 setfillstyle(1,12);
 bar(0,0,130,10);
 bar(0,67,185,80);
 bar(0,262,200,275);
 }

 setcolor(YELLOW);
 moveto(0,0);
 outtext(" Data transfer :");
 moveto(0,70);
 outtext(" Arithmatic & Logical :");
 moveto(0,265);
 outtext(" Branch &other control :");

setcolor(RED);
 rectangle(0,13,215,60);
 rectangle(0,82,215,256);
 rectangle(0,278,215,348);
 rectangle(240,52,620,87);

setfillstyle(1,1);
bar(440,0,623,20);

setfillstyle(1,2);
bar(445,3,485,16);
bar(500,3,565,16);
bar(580,3,620,16);

gotoxy(45,3);
cout<<"[ EDIT WINDOW ]";

setcolor(WHITE);

rectangle(237,39,623,470);
rectangle(235,37,625,472);
setcolor(YELLOW);

moveto(225,7);
  outtext("Program Add.:-");
rectangle(365,0,430,20);
setlinestyle(2,3,3);
line(630,180,630,450);
setcolor(RED);
setlinestyle(0,1,1);
line(314,53,314,86);
line(415,51,415,86);
line(465,51,465,86);

setfillstyle(1,14);
bar(625,180,640,200);
bar(625,450,640,470);

setcolor(BLACK);

moveto(450,6);
  outtext("FILE   COMPILE   EXIT ");

settextstyle(0,0,1);

//moveto(628,185);
// outtext("^");
//moveto(628,189);
// outtext("^");
moveto(628,193);
 outtext("");
//moveto(628,197);
// outtext("^");

moveto(628,451);
 outtext("");

setcolor(WHITE);
moveto(2,329);
    outtext("              STA    LDA");

settextstyle(0,0,1);

moveto(244,57);
 outtext(" Memory");
moveto(244,68);
 outtext(" address");
moveto(314,64);
 outtext("   Opcode    Lable    Mnumonics");
moveto(2,154);
    outtext("               RAM");

moveto(20,460);
     outtext("by:- NIKHIL PINGLE");
gotoxy(45,3);
cout<<"[ EDIT WINDOW ]";

}


void click()
{
 mouse m;
 int button,x,y,flag=0;
 int t,i;
 int strptx,strpty,endptx,endpty;
 while(1)
 {
 button=0;
 index=-1;
 if(D==17)
  D=0;
 m.getmousepos(button,x,y);
 switch(D)
 {
  case 0:
   A=20;
   B=35;
   L=0;
   break;
  case 1:
   A=40;
   B=55;
   L=4;
   break;
  case 2:
   A=90;
   B=105;
   L=8;
   break;
  case 3:
   A=110;
   B=125;
   L=12;
   break;
  case 4:
   A=130;
   B=145;
   L=16;
   break;
  case 5:
   A=150;
   B=165;
   L=20;
   break;
  case 6:
   A=170;
   B=185;
   L=24;
   break;
  case 7:
   A=190;
   B=205;
   L=28;
   break;
  case 8:
   A=210;
   B=225;
   L=32;
   break;
  case 9:
   A=230;
   B=245;
   L=36;
   break;
  case 10:
   A=285;
   B=300;
   L=40;
   break;
  case 11:
   A=305;
   B=320;
   L=44;
   break;
  case 12:
   A=325;
   B=340;
   L=48;
   break;

 case 13:   //FILE
     A=445;
     B=485;
     break;
  case 14:   //COMPILE
     A=500;
     B=565;
     break;
 case 15:    //EXIT
     A=580;
     B=620;
     break;
 case 16:
     A=365;
     B=430;
     break;
 }
 if(((button&1)==1)&&(flag==0))
 {
 for(t=10,i=L;t<=160;t+=50,i++)
  {
   if(x>=t&&x<=t+40&&y>=A&&y<=B)
   {
   index=i;
   flag=1;
  // cout<<i;
   break;
   }
  }
 }
 if(((button&1)==1)&&(flag==0))
 {
   if(x>=A&&x<=B&&y>=3&&y<=16)
   {
   index=100+D;
   flag=1;
   break;
   }
  }
  for(t=96,i=200;t<480;t+=16,i++)
  {
    if(((button&1)==1)&&(flag==0))
    {
     if(x>=315&&x<=347||x>=415&&x<=466&&y>=t&&y<=t+15)
     {
      index=i;
      flag=1;
      break;
     }
    }
   }
 D++;
 flag=0;
    if(((button&1)==1)&&(flag==0))
    {
     if(x>=625&&x<=640&&y>=180&&y<=200)
     {
      if(CY>3)
       CY-=3;
//     datashow();
     index=99;
     }
     if(x>=625&&x<=640&&y>=450&&y<=470)
     {
      if(CY<ml1)
       CY+=3;
 //    datashow();
     index=99;
     }

    }
    if(index!=-1)
    break;

}
if(116==index)
 {
	   m.hidemouseptr();
	   refill:
	   for(int x=150,a=300;x<=250;x++,a--)
	    for(int n=130;n<200;n++)
		 {
		 putpixel(x,n,1);
		putpixel(a,n,1);
	    }
	    delay(300);
	  for(x=211,a=209;a<=290;x--,a++)
	   {
	    for(n=140;n<190;n++)
	    {
	     putpixel(x,n,2);
	     putpixel(a,n,2);
	    }
	    if(x<160)
	    x++;
	   }
	gotoxy(53,16);
	cout<<"PC:- ";
	cin>>hex>>pc;
	b=1024;
	if(pc>b||pc<0)
	{
	 gotoxy(40,20);
	 cout<<"Over the Limit (pc< 03ff hex)";
	  goto refill;
	 }
	ml1--;
	del[ml1]=pc;
	ml1++;
	m.showmouseptr();
 }
if(index==113)
{
  setviewport(0,0,639,479,1);
  setfillstyle(1,7);
  bar(430,25,530,100);
 setfillstyle(1,2);
  bar(440,30,520,90);
  setcolor(BLACK);
  rectangle(440,30,520,60);
  rectangle(440,60,520,90);
  settextstyle(0,0,0);
  moveto(445,38);
   outtext("Open/Save");
  moveto(445,72);
   outtext(" NEW ");
  settextstyle(0,0,1);
 delay(350);
 int index,button,x,y,flag=0;
 int t,i,D=0;
 int strptx,strpty,endptx,endpty;
 while(1)
 {
 button=0;
 index=-1;
 flag=0;
 m.getmousepos(button,x,y);
 switch(D)
 {
 case 0:
     A=30;
     B=59;
     break;
  case 1:
     A=61;
     B=89;
     break;
 }
 if(((button&1)==1)&&(flag==0))
 {
   if(x>=440&&x<=520&&y>=A&&y<=B)
   {
   index=300+D;
   flag=1;
   break;
   }
  }
  D++;
  if(D==2)
   D=0;
  if(index!=-1)
   break;
 }
  setviewport(238,88,620,468,1);
 if(index==301)
 {  sou=-1;
   for(D=0;D<=pc;D++)
    mem[D]=-1;
   pc=0;
   for(D=0;D<ml1;D++)
    del[D]=0;
   ml1=0;
 }
 if(300==index)
 {
    for(x=50,a=360;x<=210;x++,a--)
    for(int n=40;n<160;n++)
    {
     putpixel(x,n,7);
     putpixel(a,n,7);
    }

    delay(300);
  for(x=211,a=209;x>=60;x--)
   {
    for(n=50;n<150;n++)
    {
     putpixel(x,n,1);
     putpixel(a,n,1);
    }
    if(a<350)
    a++;
  }
      setcolor(WHITE);
      moveto(70,55);
       outtext(" Enter File Name With  --.$$$ : ");
     setfillstyle(1,0);
     bar(90,80,300,110);
     rectangle(92,82,298,108);
     gotoxy(43,12);
     cout<<"Name : ";
     cin>>name;
     path=name;
     setfillstyle(1,4);
     bar(62,125,120,140);
     rectangle(62,125,120,140);
     rectangle(130,125,220,140);
     rectangle(230,125,320,140);
       moveto(68,130);
       outtext("Cancel");
       moveto(135,130);
       outtext("Save");
       moveto(235,130);
       outtext("Open");
      setcolor(0);
      rectangle(55,45,355,155);
      rectangle(56,46,354,154);
// getch();
	    m.showmouseptr();
 index=-1;
 while(1)
 {
 button=0;
 index=-1;
 flag=0;
 m.getmousepos(button,x,y);

 if(((button&1)==1)&&(flag==0))
  {
   if(x>=370&&x<=460&&y>=213&&y<=228)
      {
      index=996;
      flag=1;
      break;
      }
     if(x>=470&&x<=560&&y>=213&&y<=228)
      {
      index=997;
      flag=1;
      break;
      }
     if(x>=300&&x<=360&&y>=213&&228)
     {
      index=999;
      flag=1;
      break;
     }
  }
 }

  if(index==996)
  {
    np=fopen(path,"a+");
  for(i=0;i<1024;i++)
  {
   fee.fmem[i]=mem[i];
   fee.fdel[i]=del[i];
  }
  fee.fpc=pc;
  fwrite(&fee,sizeof(fee),1,np);
  fclose(np);
  free(np);
  }
 else if(index==997)
 {
    np=fopen(path,"a+");
  fread(&fee,sizeof(fee),1,np);
  for(i=0;i<1024;i++)
  {
   mem[i]=fee.fmem[i];
   del[i]=fee.fdel[i];
  }
  pc=fee.fpc;
 fclose(np);
 free(np);
 }
 }
  setviewport(0,0,639,479,1);
  m.hidemouseptr();
 display();
 m.showmouseptr();
  setviewport(238,88,620,468,1);
 datashow();

}
if(index==114)
{
  setviewport(0,0,639,479,1);
  setfillstyle(1,7);
  bar(490,25,590,130);
 setfillstyle(1,2);
  bar(500,30,580,120);
  setcolor(BLACK);
  rectangle(500,30,580,60);
  rectangle(500,60,580,90);
  rectangle(500,90,580,120);
  settextstyle(1,0,1);
  moveto(505,31);
   outtext("LINK");
  moveto(505,64);
   outtext("RUN");
  moveto(505,92);
   outtext("COLOR");
  settextstyle(0,0,1);
	setviewport(238,88,620,468,1);
 delay(350);
 int index,button,x,y,flag=0;
 int t,i,D=0;
 int strptx,strpty,endptx,endpty;
 while(1)
 {
 button=0;
 index=-1;
 flag=0;
 m.getmousepos(button,x,y);
 switch(D)
 {
 case 0:
     A=30;
     B=59;
     break;
  case 1:
     A=61;
     B=89;
     break;
 case  2:
     A=91;
     B=120;
     break;
 }
 if(((button&1)==1)&&(flag==0))
 {
   if(x>=500&&x<=580&&y>=A&&y<=B)
   {
   index=100+D;
   flag=1;
   break;
   }
//  else if(D==2)
//   break;
  }
  D++;
  if(D==3)
   D=0;
  if(index!=-1)
   break;
 }
  if(index==100)
  {
	link();
	getch();
   }
  if(index==101)
  {
	if(opcode==99)
	  opcode=1;

   }
  if(index==102)
  {
	setting();
	display();
	setviewport(238,88,620,468,1);
  }
  setviewport(0,0,639,479,1);
  m.hidemouseptr();
 display();
 m.showmouseptr();
  setviewport(238,88,620,468,1);
 datashow();


}

if(index>=200)
{
   m.hidemouseptr();
   ind=index;
   for(x=50,a=360;x<=210;x++,a--)
    for(int n=80;n<260;n++)
    {
     putpixel(x,n,5);
     putpixel(a,n,5);
    }

    delay(300);
  for(x=211,a=209;x>=60;x--)
   {
    for(n=90;n<250;n++)
    {
     putpixel(x,n,13);
     putpixel(a,n,13);
    }
    if(a<350)
    a++;
  }
      moveto(85,161);
       outtext(" FOR DELETE  CLICK  ON DELETE");
       moveto(85,181);
       outtext(" FOR LABLE CLICK ON LABLE ");
     rectangle(130,125,220,140);
     rectangle(230,125,320,140);
       moveto(135,130);
       outtext(" DELETE");
       moveto(235,130);
       outtext(" LABLE ");
//getch();
	    m.showmouseptr();
 index=-1;
 while(1)
 {
 button=0;
 index=-1;
 flag=0;
 m.getmousepos(button,x,y);

 if(((button&1)==1)&&(flag==0))
  {   if(x>=370&&x<=460&&y>=213&&y<=228)
      {
      index=116;
      flag=1;
      break;
     }
     if(x>=470&&x<=560&&y>=213&&y<=228)
      {
      index=117;
      flag=1;
      break;
     }
    else
   break;

    }
}
}

}

void regclick()
{
 S=0;
 if(index==4||index==5)
  S=1;
 if(index==2||index==20||index==19||index==17||index==44||index==45)
  S=2;
 mouse m;
 int button,x,y,flag=0;
 int t,i,n;
 int strptx,strpty,endptx,endpty;
    m.hidemouseptr();

   for(x=60,a=300;x<=190;x++,a--)
    for(n=140;n<210;n++)
    {
     putpixel(x,n,1);
     putpixel(a,n,1);
    }

    delay(300);
  for(x=211,a=209;x>=70;x--)
   {
    for(n=150;n<200;n++)
    {
     putpixel(x,n,9);
     putpixel(a,n,9);
    }
    if(a<290)
    a++;

  }
   setfillstyle(1,4);
   bar(80,130,178,142);
    moveto(82,132);
    outtext("Registers :-");
  if(S==2)
   {
     for(A=82;A<242;A+=50)
    bar(A,177,A+40,192);
 moveto(85,161);
    outtext(" B      D     H    M/SP ");
 }
 else
 {
 moveto(85,161);
    outtext(" A      B     C     D");
moveto(85,181);
    outtext(" E      H     L     M");
 }

 for(B=157,C=172;B<182;B+=20,C+=20)
   for(A=82;A<242;A+=50)
    rectangle(A,B,A+40,C);
if(S==1)
{
   bar(82,157,122,172);
   bar(182,157,222,172);
   for(A=82;A<242;A+=50)
    bar(A,177,A+40,192);
}

 m.showmouseptr();

 while(1)
 {
 button=0;
 index=-1;
  m.getmousepos(button,x,y);


 if(((button&1)==1)&&(flag==0))
 {
 for(t=320,i=0;t<=480;t+=50,i++)
  {
   if(x>=t&&x<=t+40&&y>=245&&y<=260)
   {
   index=i;
   flag=1;
   break;
   }
  }
 }
 if(((button&1)==1)&&(flag==0))
 {
 for(t=320,i=4;t<=480;t+=50,i++)
  {
   if(x>=t&&x<=t+40&&y>=265&&y<=280)
   {
   index=i;
   flag=1;
   break;
   }
  }
 }
  if(S==2&&index!=-1&&index<4)
    break;
  if(index!=-1&&S==0)
   break;
  else if (index==1||index==3)
   break;
 }
}


void hexclick()
{
 mouse m;
 m.hidemouseptr();
       setfillstyle(1,4);
   bar(94,46,235,150);
     setfillstyle(1,5);
   bar(104,56,225,140);
     setfillstyle(1,1);
   bar(100,32,195,45);

 setcolor(WHITE);
 for(B=60,C=75;B<140;B+=20,C+=20)
   for(A=110;A<205;A+=30)
    rectangle(A,B,A+20,C);
   rectangle(104,56,225,140);
   rectangle(94,46,235,150);
   rectangle(93,45,236,151);

moveto(104,34);
  outtext("HEX digit:-");
moveto(113,63);
    outtext("0   1   2   3");
moveto(113,83);
    outtext("4   5   6   7");
moveto(113,103);
    outtext("8   9   A   B");
moveto(113,123);
    outtext("C   D   E   F");


 int button,x,y,flag=0;
 int t,i;
 int strptx,strpty,endptx,endpty;
 ind=0;
 button=0;
 delay(300);
 m.showmouseptr();

	 while(1)
	 {
	 button=0;
	 index=-1;
	 m.getmousepos(button,x,y);

	 if((button==1)&&(flag==0))
	 {
	  for(t=350,i=0;t<=445;t+=30,i++)
	  {
	   if(x>=t&&x<=t+20&&y>=147&&y<=162)
	   {
	   index=i;
	   flag=1;
	   break;
	   }
	  }
	 }

	 if((button==1)&&(flag==0))
	 {
	 for(t=350,i=4;t<=445;t+=30,i++)
	  {
	   if(x>=t&&x<=t+20&&y>=167&&y<=182)
	   {
	   index=i;
	   flag=1;
	   break;
	   }
	  }
	 }

	 if((button==1)&&(flag==0))
	 {
	 for(t=350,i=8;t<=445;t+=30,i++)
	  {
	   if(x>=t&&x<=t+20&&y>=187&&y<=202)
	   {
	   index=i;
	   flag=1;
	   break;
	   }
	  }
	 }

	 if((button==1)&&(flag==0))
	 {
	 for(t=350,i=12;t<=445;t+=30,i++)
	  {
	   if(x>=t&&x<=t+20&&y>=207&&y<=222)
	   {
	   index=i;
	   flag=1;
	   break;
	   }
	  }
	 }
	  if(index!=-1)
	    {
	    ind=index*16;
	    break;
	    }
	   }
 m.hidemouseptr();


   flag=0;
   button=0;
   delay(300);

 m.showmouseptr();

   while(1)
	 {
	 button=0;
	 index=-1;
	 m.getmousepos(button,x,y);

	  if((button==1)&&(flag==0))
	 {
	 for(t=350,i=0;t<=445;t+=30,i++)
	  {
	   if(x>=t&&x<=t+20&&y>=147&&y<=162)
	   {
	   index=i;
	   flag=1;
	   break;
	   }
	  }
	 }

	 if((button==1)&&(flag==0))
	 {
	 for(t=350,i=4;t<=445;t+=30,i++)
	  {
	   if(x>=t&&x<=t+20&&y>=167&&y<=182)
	   {
	   index=i;
	   flag=1;
	   break;
	   }
	  }
	 }

	 if((button==1)&&(flag==0))
	 {
	 for(t=350,i=8;t<=445;t+=30,i++)
	  {
	   if(x>=t&&x<=t+20&&y>=187&&y<=202)
	   {
	   index=i;
	   flag=1;
	   break;
	   }
	  }
	 }

	 if((button==1)&&(flag==0))
	 {
	 for(t=350,i=12;t<=445;t+=30,i++)
	  {
	   if(x>=t&&x<=t+20&&y>=207&&y<=222)
	   {
	   index=i;
	   flag=1;
	   break;
	   }
	  }
	 }
	   if(index!=-1)
	    {
	    ind=ind+index;
	   break;
	    }
	 }
	}
void jumpclick()
{
     mouse m;
     m.hidemouseptr();
     int x,n,a;

  for(x=50,a=360;x<=210;x++,a--)
    for(n=80;n<230;n++)
    {
     putpixel(x,n,9);
     putpixel(a,n,9);
    }

    delay(300);
  for(x=211,a=209;x>=60;x--)
   {
    for(n=90;n<220;n++)
    {
     putpixel(x,n,1);
     putpixel(a,n,1);
    }
    if(a<350)
    a++;

  }
  settextstyle(0,0,1);
  setcolor(YELLOW);
  moveto(65,100);
     outtext(" Jump & jump Conditionally instr.:");
  moveto(195,130);
    outtext(" JMP ");
  moveto(133,160);
    outtext(" JNZ    JZ    JNC    JC");
  moveto(133,190);
    outtext(" JPO   JPE    JP     JM");


  setcolor(WHITE);
     rectangle(130,125,320,140);
   for(B=155,C=170;B<190;B+=30,C+=30)
     for(A=130;A<320;A+=50)
      rectangle(A,B,A+40,C);
 int button,y,flag=0;
 int t,i;
 int strptx,strpty,endptx,endpty;
 m.showmouseptr();

 while(1)
 {
 button=0;
 index=-1;
 m.getmousepos(button,x,y);

 if(((button&1)==1)&&(flag==0))
     if(x>=370&&x<=560&&y>=213&&y<=228)
      {
      index=0;
      flag=1;
      break;
     }


 if(((button&1)==1)&&(flag==0))
 {
 for(t=370,i=1;t<525;t+=50,i++)
  {
   if(x>=t&&x<=t+40&&y>=243&&y<=258)
   {
   index=i;
   flag=1;
   break;
   }
  }
 }
 if(((button&1)==1)&&(flag==0))
 {
 for(t=370,i=5;t<525;t+=50,i++)
  {
   if(x>=t&&x<=t+40&&y>=273&&y<=288)
   {
   index=i;
   flag=1;
   break;
   }
  }
 }
  if(index!=-1)
  break;
 }
}




void callclick()
{
 mouse m;
 m.hidemouseptr();
    int x,n,a;

  for(x=50,a=360;x<=210;x++,a--)
    for(n=80;n<230;n++)
    {
     putpixel(x,n,5);
     putpixel(a,n,5);
    }

    delay(300);
  for(x=211,a=209;x>=60;x--)
   {
    for(n=90;n<220;n++)
    {
     putpixel(x,n,13);
     putpixel(a,n,13);
    }
    if(a<350)
    a++;

  }
  settextstyle(0,0,1);
  setcolor(YELLOW);
  moveto(65,100);
     outtext(" Call & Call Conditionally instr.:");
  moveto(195,130);
    outtext(" CALL ");
  moveto(133,160);
    outtext(" CNZ    CZ    CNC    CC");
moveto(133,190);
    outtext(" CPO   CPE    CP     CM");

  setcolor(WHITE);
     rectangle(130,125,320,140);
   for(B=155,C=170;B<190;B+=30,C+=30)
     for(A=130;A<320;A+=50)
      rectangle(A,B,A+40,C);

 int button,y,flag=0;
 int t,i;
 int strptx,strpty,endptx,endpty;
  m.showmouseptr();

 while(1)
 {
 button=0;
 index=-1;
 m.getmousepos(button,x,y);


 if(((button&1)==1)&&(flag==0))
     if(x>=370&&x<=560&&y>=213&&y<=228)
      {
      index=0;
      flag=1;
      break;
     }


 if(((button&1)==1)&&(flag==0))
 {
 for(t=370,i=1;t<525;t+=50,i++)
  {
   if(x>=t&&x<=t+40&&y>=243&&y<=258)
   {
   index=i;
   flag=1;
   break;
   }
  }
 }
 if(((button&1)==1)&&(flag==0))
 {
 for(t=370,i=5;t<525;t+=50,i++)
  {
   if(x>=t&&x<=t+40&&y>=273&&y<=288)
   {
   index=i;
   flag=1;
   break;
   }
  }
 }
  if(index!=-1)
  break;
 }
}





void retclick()
{
	int x,n,a;
	mouse m;

 m.hidemouseptr();


  for(x=50,a=360;x<=210;x++,a--)
    for(n=80;n<230;n++)
    {
     putpixel(x,n,12);
     putpixel(a,n,12);
    }

    delay(300);
  for(x=211,a=209;x>=60;x--)
   {
    for(n=90;n<220;n++)
    {
     putpixel(x,n,5);
     putpixel(a,n,5);
    }
    if(a<350)
    a++;

  }
  settextstyle(0,0,1);
  setcolor(YELLOW);
  moveto(65,100);
     outtext(" Return & Ret Conditionally :-");
  moveto(195,130);
    outtext(" RET ");
  moveto(133,160);
    outtext(" RNZ    RZ    RNC    RC");
moveto(133,190);
    outtext(" RPO   RPE    RP     RM");


  setcolor(WHITE);
     rectangle(130,125,320,140);
   for(B=155,C=170;B<190;B+=30,C+=30)
     for(A=130;A<320;A+=50)
      rectangle(A,B,A+40,C);

 int button,y,flag=0;
 int t,i;
 int strptx,strpty,endptx,endpty;
m.showmouseptr();
 while(1)
 {
 button=0;
 index=-1;
 m.getmousepos(button,x,y);


 if(((button&1)==1)&&(flag==0))
     if(x>=370&&x<=560&&y>=213&&y<=228)
      {
      index=0;
      flag=1;
      break;
     }

 if(((button&1)==1)&&(flag==0))
 {
 for(t=370,i=1;t<525;t+=50,i++)
  {
   if(x>=t&&x<=t+40&&y>=243&&y<=258)
   {
   index=i;
   flag=1;
   break;
   }
  }
 }
 if(((button&1)==1)&&(flag==0))
 {
 for(t=370,i=5;t<525;t+=50,i++)
  {
   if(x>=t&&x<=t+40&&y>=273&&y<=288)
   {
   index=i;
   flag=1;
   break;
   }
  }
 }
  if(index!=-1)
  break;
 }
}


void main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"c:\\8085\\bgi");
 for(a=100;a<500;a+=10)
  for(z=100;z<108;z++)
   for(c=a;c<a+3;c++)
    putpixel(c,z,2);
// rectangle(90,108,500,200);
 for(a=90;a<500;a++)
  for(z=108;z<204;z++)
    putpixel(a,z,8);
 for(a=100;a<500;a+=10)
  for(z=202;z<210;z++)
   for(c=a;c<a+3;c++)
    putpixel(c,z,2);
 settextstyle(10,0,4);
 moveto(225,110);
 outtext("8085");
 settextstyle(4,0,8);
 setcolor(WHITE);
 moveto(100,200);
 outtext("kit  on  ");
 settextstyle(10,0,8);
 moveto(400,180);
 outtext("pc");
 settextstyle(1,0,2);
 moveto(30,400);
 setcolor(LIGHTGREEN);
 outtext("By : NIKHIL  PINGLE");
  settextstyle(1,0,2);
 setcolor(5);
 moveto(3,3);
 outtext("THE 8085 SIMULATOR WITH 8255 ");
 moveto(20,30);
 outtext(" IN  MODE :: 0 (output) ");
  for(a=90;a<500;a++)
   for(z=108;z<200;z++)
    putpixel(a,z,8);
    setcolor(WHITE);
    settextstyle(10,0,4);
    moveto(225,110);
    outtext("8085");
      setcolor(5);
 settextstyle(4,0,4);
 moveto(400,420);
 outtext("Press Enter");
 getch();


 mouse m;
 m.initmouse();
 cl1=0;cl2=0;
 cl3=10;
 cl4=LIGHTRED;
 pc=p=0;
 a=0;
 ml1=0;
 de=20;
 start:
 initgraph(&gd,&gm,"c:\\8085\\bgi");
 gd=9;
 gm=2;
 opcode=0;
 delay(1000);
 display();
// display();
 delay(1000);

 setviewport(238,88,620,468,1);
 datashow();
do
{
 gotoxy(48,1);
 cout<<hex<<pc;
  del[ml1]=pc;
  ml1++;
  if(ml1>400)
  {
    cleardevice();
    cout<<" RE-ENTER THE PROGRAM ADDRESS IN ABOVE BLOCK:";
    getch();
    ml1=0;
   }
  click();
  if(opcode==1)
      index=115;
  else
  {
      switch(index)
 {
      default:
	ml1--;
	break;
      case 117:
	lable1();
	ml1--;
	break;
      case 116:
	delett();
	ml1--;
	break;

      case 0:

	   regclick();
	   switch(index)
	   {
	    case 0:
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=127;
		     break;
		case 1:
		     mem[pc]=120;
		     break;
		case 2:
		     mem[pc]=121;
		     break;
		case 3:
		     mem[pc]=122;
		     break;
		case 4:
		     mem[pc]=123;
		     break;
		case 5:
		     mem[pc]=124;
		     break;
		case 6:
		     mem[pc]=125;
		     break;
		case 7:
		     mem[pc]=126;
		     break;
		 }
	       break;
	   case 1:
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=71;
		     break;
		case 1:
		     mem[pc]=64;
		     break;
		case 2:
		     mem[pc]=65;
		     break;
		case 3:
		     mem[pc]=66;
		     break;
		case 4:
		     mem[pc]=67;
		     break;
		case 5:
		     mem[pc]=68;
		     break;
		case 6:
		     mem[pc]=69;
		     break;
		case 7:
		     mem[pc]=70;
		     break;
		 }
		break;
	   case 2:
	       index=0;
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=79;
		     break;
		case 1:
		     mem[pc]=72;
		     break;
		case 2:
		     mem[pc]=73;
		     break;
		case 3:
		     mem[pc]=74;
		     break;
		case 4:
		     mem[pc]=75;
		     break;
		case 5:
		     mem[pc]=76;
		     break;
		case 6:
		     mem[pc]=77;
		     break;
		case 7:
		     mem[pc]=78;
		     break;
		 }
	     break;
	   case 3:
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=87;
		     break;
		case 1:
		     mem[pc]=80;
		     break;
		case 2:
		     mem[pc]=81;
		     break;
		case 3:
		     mem[pc]=82;
		     break;
		case 4:
		     mem[pc]=83;
		     break;
		case 5:
		     mem[pc]=84;
		     break;
		case 6:
		     mem[pc]=85;
		     break;
		case 7:
		     mem[pc]=86;
		     break;
		 }
	     break;
	   case 4:
	       index=0;
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=95;
		     break;
		case 1:
		     mem[pc]=88;
		     break;
		case 2:
		     mem[pc]=89;
		     break;
		case 3:
		     mem[pc]=90;
		     break;
		case 4:
		     mem[pc]=91;
		     break;
		case 5:
		     mem[pc]=92;
		     break;
		case 6:
		     mem[pc]=93;
		     break;
		case 7:
		     mem[pc]=94;
		     break;
		 }
	     break;
	   case 5:
	       index=0;
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=103;
		     break;
		case 1:
		     mem[pc]=96;
		     break;
		case 2:
		     mem[pc]=97;
		     break;
		case 3:
		     mem[pc]=98;
		     break;
		case 4:
		     mem[pc]=99;
		     break;
		case 5:
		     mem[pc]=100;
		     break;
		case 6:
		     mem[pc]=101;
		     break;
		case 7:
		     mem[pc]=102;
		     break;
		 }
	     break;
	   case 6:
	       index=0;
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=111;
		     break;
		case 1:
		     mem[pc]=104;
		     break;
		case 2:
		     mem[pc]=105;
		     break;
		case 3:
		     mem[pc]=106;
		     break;
		case 4:
		     mem[pc]=107;
		     break;
		case 5:
		     mem[pc]=108;
		     break;
		case 6:
		     mem[pc]=109;
		     break;
		case 7:
		     mem[pc]=110;
		     break;
		 }
	     break;
	   case 7:
	       index=0;
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=119;
		     break;
		case 1:
		     mem[pc]=112;
		     break;
		case 2:
		     mem[pc]=113;
		     break;
		case 3:
		     mem[pc]=114;
		     break;
		case 4:
		     mem[pc]=115;
		     break;
		case 5:
		     mem[pc]=116;
		     break;
		case 6:
		     mem[pc]=117;
		     break;
		case 7:
		     mem[pc]=118;
		     break;
		 }
	     break;
	    }
	    pc++;
	    break;
   case 1:
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=62;
		     pc++;
		     hexclick();
		     mem[pc]=ind;
		     break;
		case 1:
		     mem[pc]=6;
		     pc++;
		     hexclick();
		     mem[pc]=ind;
		     break;
		case 2:
		     mem[pc]=14;
		     pc++;
		     hexclick();
		     mem[pc]=ind;
		     break;
		case 3:
		     mem[pc]=22;
		     pc++;
		     hexclick();
		     mem[pc]=ind;
		     break;
		case 4:
		     mem[pc]=30;
		     pc++;
		     hexclick();
		     mem[pc]=ind;
		     break;
		case 5:
		     mem[pc]=38;
		     pc++;
		     hexclick();
		     mem[pc]=ind;
		     break;
		case 6:
		     mem[pc]=46;
		     pc++;
		     hexclick();
		     mem[pc]=ind;
		     break;
		 case 7:
		     mem[pc]=54;
		     pc++;
		     hexclick();
		     mem[pc]=ind;
		     break;
		 }
	     pc++;
	     break;
   case 2:
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=1;
		     pc++;
		     hexclick();
		     mem[pc+1]=ind;
		     pc++;
		     hexclick();
		     mem[pc-1]=ind;
		     break;
		case 1:
		     mem[pc]=17;
		     pc++;
		     hexclick();
		     mem[pc+1]=ind;
		     pc++;
		     hexclick();
		     mem[pc-1]=ind;
		     break;
		case 2:
		     mem[pc]=33;
		     pc++;
		     hexclick();
		     mem[pc+1]=ind;
		     pc++;
		     hexclick();
		     mem[pc-1]=ind;
		     break;
		case 3:
		     mem[pc]=49;
		     pc++;
		     hexclick();
		     mem[pc+1]=ind;
		     pc++;
		     hexclick();
		     mem[pc-1]=ind;
		     break;
		 }
	       pc++;
	       break;
      case 3:
	   mem[pc]=235;
	   pc++;
	   break;
   case 4:
	     regclick();
	     switch(index)
	     {
	      case 1:
	       mem[pc]=10;
	       break;
	      case 3:
	       mem[pc]=26;
	       break;
	      }
	      pc++;
	      break;
    case 5:
	     regclick();
	     switch(index)
	     {
	      case 1:
	       mem[pc]=2;
	       break;
	      case 3:
	       mem[pc]=18;
	       break;
	      }
	      pc++;
	      break;
     case 6:
	      mem[pc]=42;
	      pc++;
	      hexclick();
	      mem[pc+1]=ind;
	      pc++;
	      hexclick();
	      mem[pc-1]=ind;
	      pc++;
	      break;
      case 7:
	      mem[pc]=34;
	      pc++;
	      hexclick();
	      mem[pc+1]=ind;
	      pc++;
	      hexclick();
	      mem[pc-1]=ind;
	      pc++;
	      break;

  case 8:
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=135;
		     break;
		case 1:
		     mem[pc]=128;
		     break;
		case 2:
		     mem[pc]=129;
		     break;
		case 3:
		     mem[pc]=130;
		     break;
		case 4:
		     mem[pc]=131;
		     break;
		case 5:
		     mem[pc]=132;
		     break;
		case 6:
		     mem[pc]=133;
		     break;
		case 7:
		     mem[pc]=134;
		     break;
		}
		pc++;
		break;
      case 9:
	   mem[pc]=198;
	   pc++;
	   hexclick();
	   mem[pc]=ind;
	   pc++;
	   break;

      case 10:
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=143;
		     break;
		case 1:
		     mem[pc]=136;
		     break;
		case 2:
		     mem[pc]=137;
		     break;
		case 3:
		     mem[pc]=138;
		     break;
		case 4:
		     mem[pc]=139;
		     break;
		case 5:
		     mem[pc]=140;
		     break;
		case 6:
		     mem[pc]=141;
		     break;
		case 7:
		     mem[pc]=142;
		     break;
		}
		pc++;
		break;
      case 11:
	   mem[pc]=206;
	   pc++;
	   hexclick();
	   mem[pc]=ind;
	   pc++;
	   break;

   case 12:
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=151;
		     break;
		case 1:
		     mem[pc]=144;
		     break;
		case 2:
		     mem[pc]=145;
		     break;
		case 3:
		     mem[pc]=146;
		     break;
		case 4:
		     mem[pc]=147;
		     break;
		case 5:
		     mem[pc]=148;
		     break;
		case 6:
		     mem[pc]=149;
		     break;
		case 7:
		     mem[pc]=150;
		     break;
		}
		pc++;
		break;
   case 13:
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=159;
		     break;
		case 1:
		     mem[pc]=152;
		     break;
		case 2:
		     mem[pc]=153;
		     break;
		case 3:
		     mem[pc]=154;
		     break;
		case 4:
		     mem[pc]=155;
		     break;
		case 5:
		     mem[pc]=156;
		     break;
		case 6:
		     mem[pc]=157;
		     break;
		case 7:
		     mem[pc]=158;
		     break;
		}
		pc++;
		break;
      case 14:
	   mem[pc]=214;
	   pc++;
	   hexclick();
	   mem[pc]=ind;
	   pc++;
	   break;
      case 15:
	   mem[pc]=222;
	   pc++;
	   hexclick();
	   mem[pc]=ind;
	   pc++;
	   break;



   case 16:
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=60;
		     break;
		case 1:
		     mem[pc]=4;
		     break;
		case 2:
		     mem[pc]=12;
		     break;
		case 3:
		     mem[pc]=20;
		     break;
		case 4:
		     mem[pc]=28;
		     break;
		case 5:
		     mem[pc]=36;
		     break;
		case 6:
		     mem[pc]=44;
		     break;
		case 7:
		     mem[pc]=52;
		     break;
		}
		pc++;
		break;
    case 17:
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=3;
		     break;
		case 1:
		     mem[pc]=19;
		     break;
		case 2:
		     mem[pc]=35;
		     break;
		case 3:
		     mem[pc]=51;
		     break;
		 }
	       pc++;
	       break;
 case 18:
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=61;
		     break;
		case 1:
		     mem[pc]=5;
		     break;
		case 2:
		     mem[pc]=13;
		     break;
		case 3:
		     mem[pc]=21;
		     break;
		case 4:
		     mem[pc]=29;
		     break;
		case 5:
		     mem[pc]=37;
		     break;
		case 6:
		     mem[pc]=45;
		     break;
		case 7:
		     mem[pc]=53;
		     break;
		}
		pc++;
		break;
    case 19:
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=8;
		     break;
		case 1:
		     mem[pc]=27;
		     break;
		case 2:
		     mem[pc]=43;
		     break;
		case 3:
		     mem[pc]=59;
		     break;
		 }
	       pc++;
	       break;
	case 20:
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=9;
		     break;
		case 1:
		     mem[pc]=25;
		     break;
		case 2:
		     mem[pc]=41;
		     break;
		case 3:
		     mem[pc]=57;
		     break;
		 }
	       pc++;
	       break;
	case 22:
		reset:
		clearviewport();
		gotoxy(33,12);
		cout<<"(00 h  to  0400 h)";
		gotoxy(33,11);
		cout<<"Enter memory address :-";
		cin>>hex>>temp;
		if(temp>1020 && temp>0)
		goto reset;
		for(w=0;w<10;w++)
		{
		gotoxy(53,13+w);
		cout<<hex<<temp<<":-  ";
		cin>>ram[temp];
		temp++;
		}
		break;

	case 23:
	      mem[pc]=211;
	      pc++;
	      hexclick();
	      mem[pc]=ind;
	      pc++;
	      break;

	case 24:
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=167;
		     break;
		case 1:
		     mem[pc]=160;
		     break;
		case 2:
		     mem[pc]=161;
		     break;
		case 3:
		     mem[pc]=162;
		     break;
		case 4:
		     mem[pc]=163;
		     break;
		case 5:
		     mem[pc]=164;
		     break;
		case 6:
		     mem[pc]=165;
		     break;
		case 7:
		     mem[pc]=166;
		     break;
		}
		pc++;
		break;
	 case 25:
	   mem[pc]=230;
	   pc++;
	   hexclick();
	   mem[pc]=ind;
	   pc++;
	   break;
	 case 26:
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=175;
		     break;
		case 1:
		     mem[pc]=168;
		     break;
		case 2:
		     mem[pc]=169;
		     break;
		case 3:
		     mem[pc]=170;
		     break;
		case 4:
		     mem[pc]=171;
		     break;
		case 5:
		     mem[pc]=172;
		     break;
		case 6:
		     mem[pc]=173;
		     break;
		case 7:
		     mem[pc]=174;
		     break;
		}
		pc++;
		break;
	case 27:
	   mem[pc]=238;
	   pc++;
	   hexclick();
	   mem[pc]=ind;
	   pc++;
	   break;
	case 28:
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=183;
		     break;
		case 1:
		     mem[pc]=176;
		     break;
		case 2:
		     mem[pc]=177;
		     break;
		case 3:
		     mem[pc]=178;
		     break;
		case 4:
		     mem[pc]=179;
		     break;
		case 5:
		     mem[pc]=180;
		     break;
		case 6:
		     mem[pc]=181;
		     break;
		case 7:
		     mem[pc]=182;
		     break;
		}
		pc++;
		break;


      case 29:
	   mem[pc]=246;
	   pc++;
	   hexclick();
	   mem[pc]=ind;
	   pc++;
	   break;

      case 30:
	       regclick();
	       switch(index)
	       {
		case 0:
		     mem[pc]=191;
		     break;
		case 1:
		     mem[pc]=184;
		     break;
		case 2:
		     mem[pc]=185;
		     break;
		case 3:
		     mem[pc]=186;
		     break;
		case 4:
		     mem[pc]=187;
		     break;
		case 5:
		     mem[pc]=188;
		     break;
		case 6:
		     mem[pc]=189;
		     break;
		case 7:
		     mem[pc]=190;
		     break;
		}
		pc++;
		break;
      case 31:
	   mem[pc]=254;
	   pc++;
	   hexclick();
	   mem[pc]=ind;
	   pc++;
	   break;
      case 32:
	   mem[pc]=47;
	   pc++;
	   break;
      case 33:
	   mem[pc]=55;
	   pc++;
	   break;
      case 34:
	   mem[pc]=63;
	   pc++;
	   break;

      case 36:
	     mem[pc]=7;
	     pc++;
	     break;
      case 37:
	     mem[pc]=15;
	     pc++;
	     break;
      case 38:
	     mem[pc]=23;
	     pc++;
	     break;
      case 39:
	     mem[pc]=31;
	     pc++;
	     break;
case 40:
	     jumpclick();
	     switch(index)
	     {
	      case 0:
	       mem[pc]=195;
	       pc++;
	       pc++;
	       lable();
	       break;
	      case 1:
	       mem[pc]=194;
	       pc++;
	       pc++;
	       lable();
	       break;
	      case 2:
	       mem[pc]=202;
	       pc++;
	       pc++;
	       lable();
	       break;
	      case 3:
	       mem[pc]=210;
	       pc++;
	       pc++;
	       lable();
	       break;
	      case 4:
	       mem[pc]=218;
	       pc++;
	       pc++;
	       lable();
	       break;
	      case 5:
	       mem[pc]=226;
	       pc++;
	       pc++;
	       lable();
	       break;
	      case 6:
	       mem[pc]=234;
	       pc++;
	       pc++;
	       lable();
	       break;
	      case 7:
	       mem[pc]=242;
	       pc++;
	       pc++;
	       lable();
	       break;
	      case 8:
	       mem[pc]=250;
	       pc++;
	       pc++;
	       lable();
	       break;
	      }
	      pc++;
	      break;
case 41:
	     callclick();
	     switch(index)
	     {
	      case 0:
	       mem[pc]=205;
	       pc++;
	       pc++;
	       lable();
	       break;
	      case 1:
	       mem[pc]=196;
	       pc++;
	       pc++;
	       lable();
	       break;
	      case 2:
	       mem[pc]=204;
	       pc++;
	       pc++;
	       lable();
	       break;
	      case 3:
	       mem[pc]=212;
	       pc++;
	       pc++;
	       lable();
	       break;
	      case 4:
	       mem[pc]=220;
	       pc++;
	       pc++;
	       lable();
	       break;
	      case 5:
	       mem[pc]=228;
	       pc++;
	       pc++;
	       lable();
	       break;
	      case 6:
	       mem[pc]=236;
	       pc++;
	       pc++;
	       lable();
	       break;
	      case 7:
	       mem[pc]=244;
	       pc++;
	       pc++;
	       lable();
	       break;
	      case 8:
	       mem[pc]=252;
	       pc++;
	       pc++;
	       lable();
	       break;

	      }
	      pc++;
	      break;
    case 42:
	     retclick();
	     switch(index)
	     {
	      case 0:
	       mem[pc]=201;
	       break;
	      case 1:
	       mem[pc]=192;
	       break;
	      case 2:
	       mem[pc]=200;
	       break;
	      case 3:
	       mem[pc]=208;
	       break;
	      case 4:
	       mem[pc]=216;
	       break;
	      case 5:
	       mem[pc]=224;
	       break;
	      case 6:
	       mem[pc]=232;
	       break;
	      case 7:
	       mem[pc]=240;
	       break;
	      case 8:
	       mem[pc]=248;
	       break;
	      }
	      pc++;
	      break;
       case 44:
	   regclick();
	   switch(index)
	   {
	    case 0:
	     mem[pc]=197;
	     break;
	    case 1:
	     mem[pc]=213;
	     break;
	    case 2:
	     mem[pc]=229;
	     break;
	    case 3:
	     mem[pc]=245;
	     break;
	   }
	   pc++;
	   break;
       case 45:
	   regclick();
	   switch(index)
	   {
	    case 0:
	     mem[pc]=193;
	     break;
	    case 1:
	     mem[pc]=209;
	     break;
	    case 2:
	     mem[pc]=225;
	     break;
	    case 3:
	     mem[pc]=241;
	     break;
	   }
	   pc++;
	   break;
       case 47:
	   mem[pc]=249;
	   pc++;
	   break;
       case 48:
	   mem[pc]=118;
	   pc++;
	   break;

      case 49:
	   mem[pc]=0;
	   pc++;
	   break;

      case 50:
	      mem[pc]=50;
	      pc++;
	      break;

      case 51:
	      mem[pc]=58;
	      pc++;
	      break;

  }
  datashow();
}
} while(index!=115);
  if(opcode==1)
  {
  run();
  dis2();
  getch();
  goto start;
  }
}

void datashow()
{
 mouse m;
 m.hidemouseptr();
 clearviewport();
 setfillstyle(1,9);
 bar(229,1,620,390);

gotoxy(32,10);
if(ml1<20)
CY=P=0;
if(de<ml1)
{
P=CY=ml1-10;
de+=12;
}
else
P=CY;
Z=0;
for(lo=0,P=P;lo<22;lo++,P++)
{
    re=del[P];
    gotoxy(33,lo+7);
    C=42;
    if(re<16)
     cout<<"000";
    else if(re<255)
     cout<<"00";
    else if(re<4096)
     cout<<"0";
   cout<<hex<<re;
   for(a=0,st=re=del[P];re!=pc;re++,a++)
   {
    if(a==3)
      break;
    if(re==del[P+1])
     break;
    for(w=0;w<=sou;w++)
    {
     if(re==arr[w].i)
     {
      gotoxy(67,lo+7);
      cout<<arr[w].lab;
      }
     }
    for(w=0;w<=des;w++)
    {
     if(re==acr[w].i)
     {
      gotoxy(55,lo+7);
      cout<<acr[w].lab;
      }
     }
    gotoxy(C,lo+7);
     if(mem[re]<16)
     cout<<"0";

    cout<<hex<<mem[re];//<<"  "<<del[lo];
    C+=4;
   }

Z+=16;
if(lo==19)
Z-=2;

setcolor(YELLOW);
line(76,0,76,390);
line(177,0,177,390);
line(228,0,228,390);

setlinestyle(1,1,1);
line(110,0,110,390);
line(143,0,143,390);
setlinestyle(0,1,1);

for(hi=24;hi<300;hi+=16)
 line(0,hi,390,hi);
for(hi=295;hi<360;hi+=16)
 line(0,hi,390,hi);


setcolor(BLACK);


moveto(250,Z);
if(st==re)
outtext("    NOP");

else
{
instdisplay();
}
}
delay(150);
m.showmouseptr();
}

void instdisplay()
{
switch(mem[st])
{
 case 205:
   outtext("CALL");
   break;
 case 196:
   outtext("CNZ");
   break;
 case 204:
   outtext("CZ");
   break;
 case 212:
   outtext("CNC");
   break;
 case 220:
   outtext("CC");
   break;
 case 228:
   outtext("CPO");
   break;
 case 236:
   outtext("CPE");
   break;
 case 244:
   outtext("CP");
   break;
 case 252:
   outtext("CM");
   break;
 case 195:
   outtext("JMP");
   break;
 case 194:
   outtext("JNZ");
   break;
 case 202:
   outtext("JZ");
   break;
 case 210:
   outtext("JNC");
   break;
 case 218:
   outtext("JC");
   break;
 case 226:
   outtext("JPO");
   break;
 case 234:
   outtext("JPE");
   break;
 case 242:
   outtext("JP");
   break;
 case 250:
   outtext("JM");
   break;

 case 64:
  outtext("MOV B,B");
  break;
 case 65:
  outtext("MOV B,C");
  break;
 case 66:
  outtext("MOV B,D");
  break;
 case 67:
  outtext("MOV B,E");
  break;
 case 68:
  outtext("MOV B,H");
  break;
 case 69:
  outtext("MOV B,L");
  break;
 case 70:
  outtext("MOV B,M");
  break;
 case 71:
  outtext("MOV B,A");
  break;
 case 72:
  outtext("MOV C,B");
  break;
 case 73:
  outtext("MOV C,C");
  break;
 case 74:
  outtext("MOV C,D");
  break;
 case 75:
  outtext("MOV C,E");
  break;
 case 76:
  outtext("MOV C,H");
  break;
 case 77:
  outtext("MOV C,L");
  break;
 case 78:
  outtext("MOV C,M");
  break;
 case 79:
  outtext("MOV C,A");
  break;
 case 80:
  outtext("MOV D,B");
  break;
 case 81:
  outtext("MOV D,C");
  break;
 case 82:
  outtext("MOV D,D");
  break;
 case 83:
  outtext("MOV D,E");
  break;
 case 84:
  outtext("MOV D,H");
  break;
 case 85:
  outtext("MOV D,L");
  break;
 case 86:
  outtext("MOV D,M");
  break;
 case 87:
  outtext("MOV D,A");
  break;
 case 88:
  outtext("MOV E,B");
  break;
 case 89:
  outtext("MOV E,C");
  break;
 case 90:
  outtext("MOV E,D");
  break;
 case 91:
  outtext("MOV E,E");
  break;
 case 92:
  outtext("MOV E,H");
  break;
 case 93:
  outtext("MOV E,L");
  break;
 case 94:
  outtext("MOV E,M");
  break;
 case 95:
  outtext("MOV E,A");
  break;
 case 96:
  outtext("MOV H,B");
  break;
 case 97:
  outtext("MOV H,C");
  break;
 case 98:
  outtext("MOV H,D");
  break;
 case 99:
  outtext("MOV H,E");
  break;
 case 100:
  outtext("MOV H,H");
  break;
 case 101:
  outtext("MOV H,L");
  break;
 case 102:
  outtext("MOV H,M");
  break;
 case 103:
  outtext("MOV H,A");
  break;
 case 104:
  outtext("MOV L,B");
  break;
 case 105:
  outtext("MOV L,C");
  break;
 case 106:
  outtext("MOV L,D");
  break;
 case 107:
  outtext("MOV L,E");
  break;
 case 108:
  outtext("MOV L,H");
  break;
 case 109:
  outtext("MOV L,L");
  break;
 case 110:
  outtext("MOV L,M");
  break;
 case 111:
  outtext("MOV L,A");
  break;
 case 112:
  outtext("MOV M,B");
  break;
 case 113:
  outtext("MOV M,C");
  break;
 case 114:
  outtext("MOV M,D");
  break;
 case 115:
  outtext("MOV M,E");
  break;
 case 116:
  outtext("MOV M,H");
  break;
 case 117:
  outtext("MOV M,L");
  break;
// case 118:
//  outtext("MOV M,M");
//  break;
 case 119:
  outtext("MOV M,A");
  break;
 case 120:
  outtext("MOV A,B");
  break;
 case 121:
  outtext("MOV A,C");
  break;
 case 122:
  outtext("MOV A,D");
  break;
 case 123:
  outtext("MOV A,E");
  break;
 case 124:
  outtext("MOV A,H");
  break;
 case 125:
  outtext("MOV A,L");
  break;
 case 126:
  outtext("MOV A,M");
  break;
 case 127:
  outtext("MOV A,A");
  break;


 case 128:
  outtext("ADD B");
  break;
 case 129:
  outtext("ADD C");
  break;
 case 130:
  outtext("ADD D");
  break;
 case 131:
  outtext("ADD E");
  break;
 case 132:
  outtext("ADD H");
  break;
 case 133:
  outtext("ADD L");
  break;
 case 134:
  outtext("ADD M");
  break;
 case 135:
  outtext("ADD A");
  break;

 case 136:
  outtext("ADC B");
  break;
 case 137:
  outtext("ADC C");
  break;
 case 138:
  outtext("ADC D");
  break;
 case 139:
  outtext("ADC E");
  break;
 case 140:
  outtext("ADC H");
  break;
 case 141:
  outtext("ADC L");
  break;
 case 142:
  outtext("ADC M");
  break;
 case 143:
  outtext("ADC A");
  break;

 case 144:
  outtext("SUB B");
  break;
 case 145:
  outtext("SUB C");
  break;
 case 146:
  outtext("SUB D");
  break;
 case 147:
  outtext("SUB E");
  break;
 case 148:
  outtext("SUB H");
  break;
 case 149:
  outtext("SUB L");
  break;
 case 150:
  outtext("SUB M");
  break;
 case 151:
  outtext("SUB A");
  break;


 case 152:
  outtext("SBB B");
  break;
 case 153:
  outtext("SBB C");
  break;
 case 154:
  outtext("SBB D");
  break;
 case 155:
  outtext("SBB E");
  break;
 case 156:
  outtext("SBB H");
  break;
 case 157:
  outtext("SBB L");
  break;
 case 158:
  outtext("SBB M");
  break;
 case 159:
  outtext("SBB A");
  break;


 case 160:
  outtext("ANA B");
  break;
 case 161:
  outtext("ANA C");
  break;
 case 162:
  outtext("ANA D");
  break;
 case 163:
  outtext("ANA E");
  break;
 case 164:
  outtext("ANA H");
  break;
 case 165:
  outtext("ANA L");
  break;
 case 166:
  outtext("ANA M");
  break;
 case 167:
  outtext("ANA A");
  break;


 case 168:
  outtext("XRA B");
  break;
 case 169:
  outtext("XRA C");
  break;
 case 170:
  outtext("XRA D");
  break;
 case 171:
  outtext("XRA E");
  break;
 case 172:
  outtext("XRA H");
  break;
 case 173:
  outtext("XRA L");
  break;
 case 174:
  outtext("XRA M");
  break;
 case 175:
  outtext("XRA A");
  break;


 case 176:
  outtext("ORA B");
  break;
 case 177:
  outtext("ORA C");
  break;
 case 178:
  outtext("ORA D");
  break;
 case 179:
  outtext("ORA E");
  break;
 case 180:
  outtext("ORA H");
  break;
 case 181:
  outtext("ORA L");
  break;
 case 182:
  outtext("ORA M");
  break;
 case 183:
  outtext("ORA A");
  break;


 case 184:
  outtext("CMP B");
  break;
 case 185:
  outtext("CMP C");
  break;
 case 186:
  outtext("CMP D");
  break;
 case 187:
  outtext("CMP E");
  break;
 case 188:
  outtext("CMP H");
  break;
 case 189:
  outtext("CMP L");
  break;
 case 190:
  outtext("CMP M");
  break;
 case 191:
  outtext("CMP A");
  break;


 case 62:
  outtext("MVI A,");
  break;
 case 6:
  outtext("MVI B,");
  break;
 case 14:
  outtext("MVI C,");
  break;
 case 22:
  outtext("MVI D,");
  break;
 case 30:
  outtext("MVI E,");
  break;
 case 38:
  outtext("MVI H,");
  break;
 case 46:
  outtext("MVI L,");
  break;
 case 54:
  outtext("MVI M,");
  break;


 case 1:
  outtext("LXI B");
  break;
 case 17:
  outtext("LXI D");
  break;
 case 33:
  outtext("LXI H");
  break;
 case 49:
  outtext("LXI SP");
  break;

 case 9:
  outtext("DAD B");
  break;
 case 25:
  outtext("DAD D");
  break;
 case 41:
  outtext("DAD H");
  break;
 case 57:
  outtext("DAD SP");
  break;


 case 4:
  outtext("INR B");
  break;
 case 5:
  outtext("DCR B");
  break;
 case 12:
  outtext("INR C");
  break;
 case 13:
  outtext("DCR C");
  break;
 case 20:
  outtext("INR D");
  break;
 case 21:
  outtext("DCR D");
  break;
 case 28:
  outtext("INR E");
  break;
 case 29:
  outtext("DCR E");
  break;
 case 36:
  outtext("INR H");
  break;
 case 37:
  outtext("DCR H");
  break;
 case 44:
  outtext("INR L");
  break;
 case 45:
  outtext("DCR L");
  break;
 case 60:
  outtext("INR A");
  break;
 case 61:
  outtext("DCR A");
  break;
 case 52:
  outtext("INR M");
  break;
 case 53:
  outtext("DCR M");
  break;


 case 3:
  outtext("INX B");
  break;
 case 19:
  outtext("INX D");
  break;
 case 35:
  outtext("INX H");
  break;
 case 51:
  outtext("INX M");
  break;


 case 8:
  outtext("DCX B");
  break;
 case 27:
  outtext("DCX D");
  break;
 case 43:
  outtext("DCX H");
  break;
 case 59:
  outtext("DCX M");
  break;


 case 198:
  outtext("ADI ");
  break;
 case 206:
  outtext("ACI ");
  break;
 case 214:
  outtext("SUI ");
  break;
 case 222:
  outtext("SBI ");
  break;
 case 230:
  outtext("ANI ");
  break;
 case 238:
  outtext("XRI ");
  break;
 case 246:
  outtext("ORI ");
  break;
 case 254:
  outtext("CPI ");
  break;



 case 233:
  outtext("PCHL");
  break;
 case 118:
  outtext("HLT");
  break;
 case 249:
  outtext("SPHL");
  break;
 case 0:
  outtext("NOP");
  break;
 case 7:
  outtext("RLC");
  break;
 case 15:
  outtext("RRC");
  break;
 case 23:
  outtext("RAL");
  break;
 case 31:
  outtext("RAR");
  break;
 case 47:
  outtext("CMA");
  break;
 case 55:
  outtext("CMC");
  break;
 case 63:
  outtext("STC");
  break;

 case 197:
  outtext("PUSH B");
  break;
 case 213:
  outtext("PUSH D");
  break;
 case 229:
  outtext("PUSH H");
  break;
 case 245:
  outtext("PUSH SP");
  break;


 case 193:
  outtext("POP B");
  break;
 case 209:
  outtext("POP D");
  break;
 case 225:
  outtext("POP H");
  break;
 case 241:
  outtext("POP SP");
  break;

 case 235:
  outtext("XCHG");
  break;

 case 10:
  outtext("LDAX B");
  break;
 case 26:
  outtext("LDAX D");
  break;
 case 2:
  outtext("STAX B");
  break;
 case 18:
  outtext("STAX D");
  break;

 case 42:
  outtext("LHLD");
  break;
 case 34:
  outtext("SHLD");
  break;

 case 50:
  outtext("STA");
  break;
 case 58:
  outtext("LDA");
  break;

}
}


void run()
{
  int x,y,button;
  mouse m;
    for(x=50,a=360;x<=210;x++,a--)
    for(int n=40;n<160;n++)
    {
     putpixel(x,n,7);
     putpixel(a,n,7);
    }

    delay(300);
  for(x=211,a=209;x>=60;x--)
   {
    for(n=50;n<150;n++)
    {
     putpixel(x,n,1);
     putpixel(a,n,1);
    }
    if(a<350)
    a++;
  }
      setcolor(WHITE);
      moveto(70,55);
       outtext(" Enter File Name With  --.$$$ : ");
     setfillstyle(1,4);
     bar(62,125,120,140);
     rectangle(62,125,120,140);
     rectangle(130,125,220,140);
     rectangle(230,125,320,140);
       moveto(68,130);
       outtext("Cancel");
       moveto(135,130);
       outtext(" RUN ");
       moveto(235,130);
       outtext(" Step RUN ");
      setcolor(0);
      rectangle(55,45,355,155);
      rectangle(56,46,354,154);
	    m.showmouseptr();
 index=-1;
 while(1)
 {
 button=0;
 index=-1;
 flag=0;
 m.getmousepos(button,x,y);

 if(((button&1)==1)&&(flag==0))
  {
   if(x>=370&&x<=460&&y>=213&&y<=228)
      {
      index=1;
      flag=2;
      break;
      }
     if(x>=470&&x<=560&&y>=213&&y<=228)
      {
      index=1;
      flag=1;
      break;
      }
     if(x>=300&&x<=360&&y>=213&&228)
     {
      index=999;
      flag=1;
      break;
     }
  }
 }
st=index;
if(st!=999)
{
cleardevice();

for(a=pc+1;a<pc+10;a++)
mem[a]=118;

pc=-1;
a=0;
b=0;
c=0;
d=0;
e=0;
h=0;
l=0;
w=0;
z=0;
re=-1;
a=sta(a);
int brea=0;
for(;;)
{
pc++;
//st=pc;
opcode=mem[pc];
if(opcode==0)
brea++;
if(brea>300)
{
opcode=118;
pc=-1;
}
if(opcode!=118)
{
switch(opcode)
{
   case 235:
     w=h;
     z=l;
     h=d;
     l=e;
     d=w;
     e=z;
     break;
   case 60:
     a++;
     a=sta(a);
   break;
   case 4:
     b++;
     b=sta(b);
   break;
   case 12:
     c++;
     c=sta(c);
   break;
   case 28:
     e++;
     e=sta(e);
   break;
   case 36:
     h++;
     h=sta(h);
   break;
   case 44:
     l++;
     l=sta(l);
   break;
   case 20:
     d++;
     d=sta(d);
   break;
   case 52:
     add(h,l);
     ram[temp]++;
     ram[temp]=sta(ram[temp]);
   break;

  case   5:
    b--;
    b=sta(b);
  break;
  case   13:
    c--;
    c=sta(c);
  break;
  case   21:
    d--;
    d=sta(d);
  break;
  case   29:
    e--;
    e=sta(e);
  break;
  case   37:
    h--;
    h=sta(h);
  break;
  case   45:
    l--;
    l=sta(l);
  break;
  case   61:
    a--;
    a=sta(a);
  break;
  case   53:
    add(h,l);
    ram[temp]--;
    ram[temp]=sta(ram[temp]);
  break;


  case  35:
    l++;
    if(l>255)
    {
    h++;
    l=l-256;
    }
  break;
  case  3:
   c++;
   if(c>255)
   {
    b++;
    c=c-256;
    }
  break;
  case  19:
   e++;
   if(e>255)
   {
    d++;
    e=e-256;
   }
   break;
  case  51:
    sp++;
    break;


  case  43:
   l--;
   if(l<0)
   {
    h--;
    l=l+256;
   }
  break;
  case  8:
   c--;
   if(c<0)
   {
    b--;
    c=c+256;
   }
  break;
  case  27:
   e--;
   if(e<0)
   {
    d--;
    e=e+256;
   }
  break;
  case  59:
   sp--;
   break;

  case  47:
   a=sta(a);
   logic(a);
  break;

  case 55:
     if(CY==1)
      CY=0;
     else
      CY=1;
  break;

  case 63:
      CY=1;
   break;

  case 7:
   logic(a);
   break;

  case 15:
   logic(a);
   break;

  case 23:
   logic(a);
   break;

  case 31:
   logic(a);
   break;

  case 10:
   add(b,c);
   a=ram[temp];
   break;

  case 26:
   add(d,e);
   a=ram[temp];
   break;

  case 2:
   add(b,c);
   ram[temp]=a;
   break;

   case 18:
    add(d,e);
    ram[temp]=a;
    break;

  case 42:
   pc++;
   w=mem[pc];
   pc++;
   z=mem[pc];
   add(z,w);
   l=ram[temp];
   h=ram[temp+1];
   break;

  case  34:
      pc++;
     w=mem[pc];
     pc++;
     z=mem[pc];
     add(z,w);
     ram[temp]=l;
     ram[temp+1]=h;
   break;

  case 58:
      add(h,l);
      a=ram[temp];
  break;

  case  50:
      add(h,l);
      ram[temp]=a;
  break;

  case 9:
    w=0;
    l=l+c;
    if(l>255)
    w=l-256;
    h=h+b+w;
    if(h>255)
    h=h-256;
  break;

  case 25:
    w=0;
    l=l+e;
    if(l>255)
    w=l-256;
    h=h+d+w;
    if(h>255)
    h=h-256;

   break;


  case 41:
    w=0;
    l=l+l;
    if(l>255)
    w=l-256;
    h=h+h+w;
    if(h>255)
    h=h-256;

   break;

  case 57:
   add(h,l);
   w=temp;
   z=w+sp;
   dad();
   break;

  case  62:
    pc++;
    a=mem[pc];
    break;
  case  6:
    pc++;
    b=mem[pc];
    break;
  case  14:
    pc++;
    c=mem[pc];
    break;
  case  22:
    pc++;
    d=mem[pc];
    break;
  case  30:
    pc++;
    e=mem[pc];
    break;
  case  38:
    pc++;
    h=mem[pc];
    break;
  case  46:
    pc++;
    l=mem[pc];
    break;
  case  54:
    pc++;
    add(h,l);
    ram[temp]=mem[pc];
    break;


  case  1:
   pc++;
   c=mem[pc];
   pc++;
   b=mem[pc];
   break;
  case  17:
   pc++;
   e=mem[pc];
   pc++;
   d=mem[pc];
   break;
  case  33:
   pc++;
   l=mem[pc];
   pc++;
   h=mem[pc];
   break;
  case  49:
   pc++;
   add(mem[pc+1],mem[pc]);
   sp=temp;
   break;


  case 64:
   b=b;
   break;
  case 65:
   b=c;
   break;
 case 66:
   b=d;
   break;
 case 67:
   b=e;
   break;
 case 68:
   b=h;
   break;
 case 69:
   b=l;
   break;
 case 70:
   add(h,l);
   b=ram[temp];
   break;
 case 71:
   b=a;
   break;
 case 72:
   c=b;
   break;
 case 73:
   c=c;
   break;
 case 74:
   c=d;
   break;
 case 75:
   c=e;
   break;
 case 76:
   c=h;
   break;
 case 77:
   c=l;
   break;
 case 78:
   add(h,l);
   c=ram[temp];
   break;
 case 79:
   c=a;
   break;
 case 80:
   d=b;
   break;
 case 81:
   d=c;
   break;
 case 82:
   d=d;
   break;
 case 83:
   d=e;
   break;
 case 84:
   d=h;
   break;
 case 85:
   d=l;
   break;
 case 86:
   add(h,l);
   d=ram[temp];
   break;
 case 87:
   d=a;
   break;
 case 88:
   e=b;
   break;
 case 89:
   e=c;
   break;
 case 90:
   e=d;
   break;
 case 91:
   e=e;
   break;
 case 92:
   e=h;
   break;
 case 93:
   e=l;
   break;
 case 94:
   add(h,l);
   e=ram[temp];
   break;
 case 95:
   e=a;
   break;
 case 96:
   h=b;
   break;
 case 97:
   h=c;
   break;
 case 98:
   h=d;
   break;
 case 99:
   h=e;
   break;
 case 100:
   h=h;
   break;
 case 101:
   h=l;
   break;
 case 102:
   add(h,l);
   h=ram[temp];
   break;
 case 103:
   h=a;
   break;
 case 104:
   l=b;
   break;
 case 105:
   l=c;
   break;
 case 106:
   l=d;
   break;
 case 107:
   l=e;
   break;
 case 108:
   l=h;
   break;
 case 109:
   l=l;
   break;
 case 110:
   add(h,l);
   l=ram[temp];
   break;
 case 111:
   l=a;
   break;
 case 112:
   add(h,l);
   ram[temp]=b;
   break;
 case 113:
   add(h,l);
   ram[temp]=c;
   break;
 case 114:
   add(h,l);
   ram[temp]=d;
   break;
  case 115:
   add(h,l);
   ram[temp]=e;
   break;
 case 116:
   add(h,l);
   ram[temp]=h;
   break;
 case 117:
   add(h,l);
   ram[temp]=l;
   break;
 case 119:
   add(h,l);
   ram[temp]=a;
   break;
 case 120:
   a=b;
   break;
 case 121:
   a=c;
   break;
 case 122:
   a=d;
   break;
 case 123:
   a=e;
   break;
 case 124:
   a=h;
   break;
 case 125:
   a=l;
   break;
 case 126:
   add(h,l);
   a=ram[temp];
   break;
 case 127:
   a=b;
   break;

 case 128:
  a=a+b;
  a=sta(a);
  break;
 case 129:
  a=a+c;
  a=sta(a);
  break;
 case 130:
  a=a+d;
  a=sta(a);
  break;
 case 131:
  a=a=a+e;
  sta(a);
  break;
 case 132:
  a=a+h;
  a=sta(a);
  break;
 case 133:
  a=a+l;
  a=sta(a);
  break;
 case 134:
  add(h,l);
  a=a+ram[temp];
  a=sta(a);
  break;
 case 135:
  a=a+a;
  a=sta(a);
  break;

 case 136:
  a=a+b+CY;
  a=sta(a);
  break;
 case 137:
  a=a+c+CY;
  a=sta(a);
  break;
 case 138:
  a=a+d+CY;
  a=sta(a);
  break;
 case 139:
  a=a+e+CY;
  a=sta(a);
  break;
 case 140:
  a=a+h+CY;
  a=sta(a);
  break;
 case 141:
  a=a+l+CY;
  a=sta(a);
  break;
 case 142:
  add(h,l);
  a=a+ram[temp]+CY;
  a=sta(a);
  break;
 case 143:
  a=a+a+CY;
  a=sta(a);
  break;

 case 144:
  a=a-b;
  a=sta(a);
  break;
 case 145:
  a=a-c;
  a=sta(a);
  break;
 case 146:
  a=a-d;
  a=sta(a);
  break;
 case 147:
  a=a-e;
  a=sta(a);
  break;
 case 148:
  a=a-h;
  a=sta(a);
  break;
 case 149:
  a=a-l;
  a=sta(a);
  break;
 case 150:
  add(h,l);
  a=a-ram[temp];
  a=sta(a);
  break;
 case 151:
  a=a-a;
  a=sta(a);
  break;

 case 152:
  a=a-b-CY;
  a=sta(a);
  break;
 case 153:
  a=a-c-CY;
  a=sta(a);
  break;
 case 154:
  a=a-d-CY;
  a=sta(a);
  break;
 case 155:
  a=a-e-CY;
  a=sta(a);
  break;
 case 156:
  a=a-h-CY;
  sta(a);
  break;
 case 157:
  a=a-l-CY;
  a=sta(a);
  break;
 case 158:
  add(h,l);
  a=a-ram[temp]-CY;
  a=sta(a);
  break;
 case 159:
  a=a-a-CY;
  a=sta(a);
  break;


 case 160:
  logic(b);
   b=sta(b);
  break;
 case 161:
  logic(c);
   c=sta(c);
  break;
 case 162:
  logic(d);
   d=sta(d);
  break;
 case 163:
  logic(e);
   e=sta(e);
  break;
 case 164:
  logic(h);
   h=sta(h);
  break;
 case 165:
  logic(l);
   l=sta(l);
  break;
 case 166:
  add(h,l);
  logic(ram[temp]);
   ram[temp]=sta(ram[temp]);
  break;
 case 167:
  logic(a);
   a=sta(a);
  break;

 case 168:
  logic(b);
   b=sta(b);
  break;
 case 169:
  logic(c);
   c=sta(c);
  break;
 case 170:
  logic(d);
   d=sta(d);
  break;
 case 171:
  logic(e);
   e=sta(e);
  break;
 case 172:
  logic(h);
   h=sta(h);
  break;
 case 173:
  logic(l);
   l=sta(l);
  break;
 case 174:
  add(h,l);
  logic(ram[temp]);
   ram[temp]=sta(ram[temp]);
  break;
 case 175:
  logic(a);
   a=sta(a);
  break;

 case 176:
  logic(b);
   b=sta(b);
  break;
 case 177:
  logic(c);
   c=sta(c);
  break;
 case 178:
  logic(d);
   d=sta(d);
  break;
 case 179:
  logic(e);
   e=sta(e);
  break;
 case 180:
  logic(h);
   h=sta(h);
  break;
 case 181:
  logic(l);
   l=sta(l);
  break;
 case 182:
  add(h,l);
  logic(ram[temp]);
   ram[temp]=sta(ram[temp]);
  break;
 case 183:
  logic(a);
   a=sta(a);
  break;
 case 184:
  w=a;
  a=a-b;
  a=sta(a);
  a=w;
  break;
 case 185:
  w=a;
  a=a-c;
  a=sta(a);
  a=w;
  break;
 case 186:
  w=a;
  a=a-d;
  a=sta(a);
  a=w;
  break;
 case 187:
  w=a;
  a=a-e;
  a=sta(a);
  a=w;
  break;
 case 188:
  w=a;
  a=a-h;
  a=sta(a);
  a=w;
  break;
 case 189:
  w=a;
  a=a-l;
  a=sta(a);
  a=w;
  break;
 case 190:
  add(h,l);
  w=a;
  a=a-ram[temp];
  a=sta(a);
  a=w;
  break;
 case 191:
  w=a;
  a=a-a;
  a=sta(a);
  w=a;
  break;

case 195:
  add(mem[pc+2],mem[pc+1]);
  pc=temp-1;
  break;
case 194:
  if(Z!=1)
  {
  add(mem[pc+2],mem[pc+1]);
  pc=temp-1;
  }
  else
  pc=pc+2;
  break;
case 202:
  if(Z==1)
  {
  add(mem[pc+2],mem[pc+1]);
  pc=temp-1;
 }
  else
  pc=pc+2;
  break;
case 210:
  if(CY!=1)
  {
  add(mem[pc+2],mem[pc+1]);
  pc=temp-1;
  }
  else
  pc=pc+2;
  break;

case 211:
   pc++;
   if(mem[pc]==131)
    CWR=a;
   if(mem[pc]==128)
    {
     if(CWR==128||CWR==129||CWR==130||CWR==131||CWR==136||CWR==137||CWR==138||CWR==139)
      portA=a;
    }
   if(mem[pc]==129)
    {
     if(CWR==128||CWR==129||CWR==136||CWR==137||CWR==144||CWR==145||CWR==152||CWR==153)
      portB=a;
    }
   if(mem[pc]==130)
    {
     if(CWR==128||CWR==129||CWR==130||CWR==131||CWR==144||CWR==145||CWR==146||CWR==147)
      portCu=a;
    }
   if(mem[pc]==130)
    {
     if(CWR==128||CWR==130||CWR==136||CWR==138||CWR==144||CWR==146||CWR==152||CWR==154)
      portCl=a;
    }
   break;
case 218:
  if(CY==1)
  {
  add(mem[pc+2],mem[pc+1]);
  pc=temp-1;
   }
  else
  pc=pc+2;
  break;
case 226:
  if(P!=1)
  {
  add(mem[pc+2],mem[pc+1]);
  pc=temp-1;
  }
  else
  pc=pc+2;
  break;
case 234:
  if(P==1)
  {
  add(mem[pc+2],mem[pc+1]);
  pc=temp-1;
  }
  else
  pc=pc+2;
  break;
case 242:
  if(S!=1)
  {
  add(mem[pc+2],mem[pc+1]);
  pc=temp-1;
  }
  else
  pc=pc+2;
  break;
case 250:
  if(S==1)
  {
  add(mem[pc+2],mem[pc+1]);
  pc=temp-1;
  }
  else
  pc=pc+2;
  break;

case 233:
  add(h,l);
  pc=temp-1;
  break;

 case 205:
  addsp();
  add(mem[pc+2],mem[pc+1]);
  pc=temp-1;
  re++;
  ret[re]=pc+2;
  break;
 case 196:
  addsp();
  if(Z!=1)
  {
  add(mem[pc+2],mem[pc+1]);
  pc=temp-1;
  re++;
  ret[re]=pc+2;
  }
  else
  pc=pc+2;
  break;
 case 204:
  addsp();
  if(Z==1)
  {
  add(mem[pc+2],mem[pc+1]);
  pc=temp-1;
    re++;
  ret[re]=pc+2;

  }
  else
  pc=pc+2;
  break;
case 212:
  addsp();
  if(CY!=1)
  {
  add(mem[pc+2],mem[pc+1]);
  pc=temp-1;
    re++;
  ret[re]=pc+2;

  }
  else
  pc=pc+2;
  break;
case 220:
  addsp();
  if(CY==1)
  {
  add(mem[pc+2],mem[pc+1]);
  pc=temp-1;
    re++;
  ret[re]=pc+2;

  }
  else
  pc=pc+2;
  break;
case 228:
  addsp();
  if(P!=1)
  {
  add(mem[pc+2],mem[pc+1]);
  pc=temp-1;
    re++;
  ret[re]=pc+2;

  }
  else
  pc=pc+2;
  break;
case 236:
  addsp();
  if(P==1)
  {
  add(mem[pc+2],mem[pc+1]);
  pc=temp-1;
    re++;
  ret[re]=pc+2;

  }
  else
  pc=pc+2;
  break;
case 244:
  addsp();
  if(S!=1)
  {
  add(mem[pc+2],mem[pc+1]);
  pc=temp-1;
    re++;
  ret[re]=pc+2;

  }
  else
  pc=pc+2;
  break;
case 252:
  addsp();
  if(S==1)
  {
  add(mem[pc+2],mem[pc+1]);
  pc=temp;
    re++;
  ret[re]=pc+2;
  }
  else
  pc=pc+2;
  break;


case 201:
  pop();
  break;
case 192:
  if(Z!=1)
   pop();
  break;
case 200:
  if(Z==1)
    pop();
  break;
case 208:
  if(CY!=1)
    pop();
  break;
case 216:
  if(CY==1)
    pop();
  break;
case 224:
  if(P!=1)
    pop();
  break;
case 232:
  if(P==1)
    pop();
  break;
case 240:
  if(S!=1)
    pop();
  break;
case 248:
  if(S==1)
    pop();
  break;

case 197:
 sp--;
 ram[sp]=b;
 sp--;
 ram[sp]=c;
 break;
case 213:
 sp--;
 ram[sp]=d;
 sp--;
 ram[sp]=e;
 break;
case 229:
 sp--;
 ram[sp]=h;
 sp--;
 ram[sp]=l;
 break;
case 245:
 sp--;
 ram[sp]=a;
 sp--;
 ram[sp]=flag;
 break;
case 193:
 sp++;
 b=ram[sp];
 sp++;
 c=ram[sp];
 break;
case 209:
 sp++;
 d=ram[sp];
 sp++;
 e=ram[sp];
 break;
case 225:
 sp++;
 h=ram[sp];
 sp++;
 l=ram[sp];
 break;
case 241:
 sp++;
 a=ram[sp];
 sp++;
 flag=ram[sp];
 break;
case 198:
   pc++;
   a=a+mem[pc];
   a=sta(a);
   break;
case 206:
   pc++;
   a=a+mem[pc]+CY;
   a=sta(a);
   break;
case 214:
   pc++;
   a=a-mem[pc];
   a=sta(a);
   break;
case 222:
   pc++;
   a=a-mem[pc]-CY;
   a=sta(a);
   break;


case 230:
   pc++;
   logic(mem[pc]);
   mem[pc]=sta(mem[pc]);
   break;
case 238:
   pc++;
   logic(mem[pc]);
   mem[pc]=sta(mem[pc]);
   break;
case 246:
   pc++;
   logic(mem[pc]);
   mem[pc]=sta(mem[pc]);
   break;
case 254:
   pc++;
   w=a;
   a=a-mem[pc];
   a=sta(a);
   a=w;
   break;
}
}
else
break;
if(st==1)
dis();
}
if(brea>300)
{cout<<"\n\tProgram may have error (NOP more used) \n\t TERMINATED\n\n\t PRESS ENTER";
getch();}
P=0;
CY=0;
}
setviewport(0,0,639,479,1);
}

 int sta(int A)
{
 int e,b,c,x,bin1[8],bin2[8];
  e=A;
  if(A<0)
   A=A+256;
  if(A>255)
   A=A-255;
   for(x=0;x<8;x++)
 {
  if(A>0)
  bin1[x]=A%2;
  if(A!=0)
   A=A/2;
  else
  bin1[x]=0;
 }
 if(e==0)
   Z=1;
 else if(e!=0)
 Z=0;
 bin2[6]=Z;
 if(e<0)
 {
  e=e+256;
  S=1;
  CY=1;
 }
else
 S=0;
 bin2[7]=S;
 if(e>255)
 {
  e=e-256;
  CY=1;
 }
else if(S!=1)
  CY=0;
 bin2[0]=CY;
 b=0;
 for(x=0;x<8;x++)
 {
  if(bin1[x]==1)
   b++;
 }
  if(b%2==0)
  P=bin2[2]=1;
  else
  P=bin2[2]=0;
c=0;
if(bin2[0]==1)
 c=c+1;
if(bin2[1]==1)
 c=c+2;
if(bin2[2]==1)
 c=c+4;
if(bin2[3]==1)
 c=c+8;
if(bin2[4]==1)
 c=c+16;
if(bin2[5]==1)
 c=c+32;
if(bin2[6]==1)
 c=c+64;
if(bin2[7]==1)
 c=c+128;
 flag=c;
 return(e);
}


void add(int h,int l)
{
 int a,b,x,bin1[8],bin2[8];
 long c;
 a=l;
 b=h;
    for(x=0;x<8;x++)
 {
  if(a>0)
  bin1[x]=a%2;
  if(a!=0)
   a=a/2;
  else
  bin1[x]=0;
 }
    for(x=0;x<8;x++)
 {
  if(b>0)
  bin2[x]=b%2;
  if(b!=0)
   b=b/2;
  else
  bin2[x]=0;
 }

c=0;
if(bin1[0]==1)
 c=c+1;
if(bin1[1]==1)
 c=c+2;
if(bin1[2]==1)
 c=c+4;
if(bin1[3]==1)
 c=c+8;
if(bin1[4]==1)
 c=c+16;
if(bin1[5]==1)
 c=c+32;
if(bin1[6]==1)
 c=c+64;
if(bin1[7]==1)
 c=c+128;
if(bin2[0]==1)
 c=c+256;
if(bin2[1]==1)
 c=c+512;
if(bin2[2]==1)
 c=c+1024;
if(bin2[3]==1)
 c=c+2048;
if(bin2[4]==1)
 c=c+4096;
if(bin2[5]==1)
 c=c+8192;
if(bin2[6]==1)
 c=c+16384;
if(bin2[7]==1)
 c=c+32768;
 temp=c;
}


void logic(int b)
{
  cleardevice();
  int x,q,bin1[8],bin2[8];
    for(x=0;x<8;x++)
 {
  if(a>0)
  bin1[x]=a%2;
  if(a!=0)
   a=a/2;
  else
  bin1[x]=0;
//  cout<<"   "<<bin1[x];
 }
//  getch();
//  cout<<endl;
   for(x=0;x<8;x++)
 {
  if(b>0)
  bin2[x]=b%2;
  if(b!=0)
   b=b/2;
  else
  bin2[x]=0;
//  cout<<"   "<<bin2[x];
}
//  cout<<endl;
  if(mem[pc]==7)
  {
   CY=bin1[7];
   for(x=7;x>0;x--)
    bin1[x]=bin1[x-1];
   bin1[0]=CY;
 //  CY=bin1[7];
   }
  if(mem[pc]==15)
  {
   CY=bin1[0];
    for(x=0;x<7;x++)
    bin1[x]=bin1[x+1];
   bin1[7]=CY;
   }
  if(mem[pc]==23)
  {
   //bin1[0]=CY;
   for(x=7;x>0;x--)
    bin1[x]=bin1[x-1];
   bin1[0]=CY;
   CY=bin1[7];
   }
   if(mem[pc]==31)
  {
    w=CY;
    CY=bin1[0];
    for(x=0;x<7;x++)
    bin1[x]=bin1[x+1];
    bin1[7]=w;
  }

  if(160<=mem[pc]&&mem[pc]<=167||mem[pc-1]==230)
  {
   for(x=0;x<8;x++)
   {
   bin1[x]=bin1[x]&bin2[x];
//    cout<<"   "<<bin1[x];
//   getch();
  }
  }
  if(168<=mem[pc]&&mem[pc]<=175||mem[pc-1]==238)
  {
   for(x=0;x<8;x++)
   bin1[x]=bin1[x]^bin2[x];
  }
  if(176<=mem[pc]&&mem[pc]<=183||mem[pc-1]==246)
  {
   for(x=0;x<8;x++)
   bin1[x]=bin1[x]|bin2[x];
  }
  if(mem[pc]==47)
   for(x=0;x<8;x++)
   {
    if(bin1[x]==1)
      bin1[x]=0;
     else
      bin1[x]=1;
    }
 q=0;
if(bin1[0]==1)
 q=q+1;
if(bin1[1]==1)
 q=q+2;
if(bin1[2]==1)
 q=q+4;
if(bin1[3]==1)
 q=q+8;
if(bin1[4]==1)
 q=q+16;
if(bin1[5]==1)
 q=q+32;
if(bin1[6]==1)
 q=q+64;
if(bin1[7]==1)
 q=q+128;
a=q;
}

void addsp()
{
re++;
if(re<25)
ret[re]=pc+2;
}
void pop()
{
if(re>-1)
pc=ret[re];
re--;
}


void dad()
{
int bin1[16],x;
  for(x=0;x<16;x++)
 {
  if(z>0)
  bin1[x]=z%2;
  if(z!=0)
   z=z/2;
  else
  bin1[x]=0;
 }
 l=0;
if(bin1[0]==1)
 l=l+1;
if(bin1[1]==1)
 l=l+2;
if(bin1[2]==1)
 l=l+4;
if(bin1[3]==1)
 l=l+8;
if(bin1[4]==1)
 l=l+16;
if(bin1[5]==1)
 l=l+32;
if(bin1[6]==1)
 l=l+64;
if(bin1[7]==1)
 l=l+128;
h=0;
if(bin1[8]==1)
 h=h+1;
if(bin1[9]==1)
 h=h+2;
if(bin1[10]==1)
 h=h+4;
if(bin1[11]==1)
 h=h+8;
if(bin1[12]==1)
 h=h+16;
if(bin1[13]==1)
 h=h+32;
if(bin1[14]==1)
 h=h+64;
if(bin1[15]==1)
 h=h+128;
}
void dis()
{
  int a1,c1,gd,gm;
data=0;
do
{
cleardevice();
dis1();
//moveto(500,200);
//instdisplay();
/*cout<<endl<<endl;
cout<<endl<<hex<<" A:   "<<a;
cout<<endl<<hex<<" B:   "<<b;
cout<<endl<<hex<<" C:   "<<c;
cout<<endl<<hex<<" D:   "<<d;
cout<<endl<<hex<<" E:   "<<e;
cout<<endl<<hex<<" H:   "<<h;
cout<<endl<<hex<<" L:   "<<l;
cout<<endl<<" FLAG reg.";
cout<<endl<<hex<<" Z:   "<<Z;
cout<<endl<<hex<<" S:   "<<S;
cout<<endl<<hex<<" CY:  "<<CY;
cout<<endl<<hex<<" P:   "<<P;
cout<<endl<<hex<<"Flage "<<flag;
cout<<endl;
cout<<endl<<hex<<" pc:  "<<pc;
cout<<endl<<hex<<" sp:   "<<sp;
gotoxy(25,5);
cout<<" Memory add   Data ";
for(gd=a1;gd<a1+11;gd++)
{
 gotoxy(25,++c1);
 cout<<gd<<"    "<<hex<<ram[gd];
}*/
gotoxy(38,4);
cout<<" instruction executed" ;

c1=5;
if(pc>5)
c1=pc-3;
else
c1=0;
gd=5;
for(gm=c1;gm<c1+20;gm++)
{
 if(gm==pc)
 {
  gotoxy(41,++gd);
 cout<<" => " <<hex<<gm<<" - "<<mem[gm]<<endl;
 }
 else
 {
  gotoxy(45,++gd);
 cout<<hex<<gm<<" - "<<mem[gm]<<endl;
 }
}
 gotoxy(25,25);
 cout<<"press 1>: next instruction ";
 gotoxy(25,27);
 cout<<"press 2>: memory adress: - ";
 cin>>hex>>data;
 }
 while(data!=1);
}
void reload()
{
 int c1;
 fag=0;
 for(c1=0;c1<q;c1++)
 {
  mem[pc]=delet[c1];
  pc++;
 }
 }

void dis2()
{
 do
 {
    dis1();
     gotoxy(30,5);
     cout<<"press 1>: EXIT ";
     gotoxy(30,7);
     cout<<"OR enter >: memory adress: - ";
     cin>>hex>>data;
 }
 while(data!=1);
}

void dis1()
{
setviewport(0,0,639,479,1);
cleardevice();
setfillstyle(1,1);
bar(6,6,200,267);
rectangle(15,25,187,149);
rectangle(18,28,92,146);
rectangle(99,28,184,146);
rectangle(15,155,187,195);
rectangle(18,158,184,192);
rectangle(15,200,187,260);
rectangle(18,203,184,257);

bar(6,285,200,479);
setfillstyle(1,0);
bar(19,29,91,145);
bar(100,29,183,145);
bar(19,159,183,191);
bar(19,204,183,256);
bar(19,301,91,464);
bar(103,301,183,464);


settextstyle(1,0,1);
setfillstyle(1,4);
bar(240,0,420,25);
bar(20,8,95,22);
bar(125,8,175,22);
bar(24,205,65,217);
bar(8,278,63,288);

moveto(250,0);
 outtext("OUTPUT  WINDOW");
settextstyle(0,0,1);
moveto(25,12);
 outtext("REGISTER");
moveto(130,12);
 outtext("FLAG");
moveto(12,280);
 outtext("MEMORY");

settextstyle(0,0,1);
setcolor(15);
moveto(30,36);
 outtext("A:>");
moveto(30,52);
 outtext("B:>");
moveto(30,68);
 outtext("C:>");
moveto(30,84);
 outtext("D:>");
moveto(30,100);
 outtext("E:>");
moveto(30,116);
 outtext("H:>");
moveto(30,132);
 outtext("L:>");

moveto(120,36);
 outtext("CY:>");
moveto(120,68);
 outtext("P:>");
moveto(120,100);
 outtext("Z:>");
moveto(120,132);
 outtext("S:>");
moveto(30,165);
 outtext("PC:>");
moveto(30,181);
 outtext("SP:>");
moveto(110,212);
 outtext("CWR:>");
moveto(30,208);
 outtext("8255");
moveto(30,228);
 outtext("A:>");
moveto(30,244);
 outtext("B:>");
moveto(100,228);
 outtext("C-up:>");
moveto(100,244);
 outtext("C-lo:>");

gotoxy(8,3);cout<<hex<<a;
gotoxy(8,4);cout<<hex<<b;
gotoxy(8,5);cout<<hex<<c;
gotoxy(8,6);cout<<hex<<d;
gotoxy(8,7);cout<<hex<<e;
gotoxy(8,8);cout<<hex<<h;
gotoxy(8,9);cout<<hex<<l;
gotoxy(20,3);cout<<hex<<CY;
gotoxy(20,5);cout<<hex<<P;
gotoxy(20,7);cout<<hex<<Z;
gotoxy(20,9);cout<<hex<<S;
gotoxy(10,11);cout<<hex<<pc;
gotoxy(10,12);cout<<hex<<sp;

//gotoxy(4,20);cout<<"<8255>";
gotoxy(9,15);cout<<portA;
gotoxy(9,16);cout<<portB;
gotoxy(20,14);cout<<CWR;
gotoxy(20,15);cout<<portCu;
gotoxy(20,16);cout<<portCl;
L=data;
A=20;
for(C=L;C<L+10;C++,A++)
{
gotoxy(4,A);
    if(C<16)
     cout<<"000";
    else if(C<255)
     cout<<"00";
cout<<hex<<C;
gotoxy(10,A);
cout<<hex<<ram[C];
}
A=20;
for(C=C;C<L+20;C++,A++)
{
gotoxy(14,A);
    if(C<16)
     cout<<"000";
    else if(C<255)
     cout<<"00";
cout<<hex<<C;
gotoxy(21,A);
cout<<hex<<ram[C];
}
rectangle(10,290,194,475);
rectangle(18,300,92,465);
rectangle(102,300,184,465);
  setviewport(238,88,620,468,1);

}


void setting()
{
 for(A=0;A<=3;A++)
 {
  gotoxy(1,1);
  cleardevice();
  setviewport(0,0,639,479,1);
  struct viewporttype vp;
  int color, height, width;
  int x, y, i, j;
  char cnum[5];
  color = 1;
  getviewsettings( &vp );		/* Get the current window size	*/
  width  = 2 * ( (vp.right+1) / 16 );	   /* Get box dimensions	   */
  height = 2 * ( (vp.bottom-10) / 10 );
  x = width / 2;
  y = height / 2;	/* Leave 1/2 box border 	*/
  for( j=0 ; j<3 ; ++j ){		/* Row loop			*/

    for( i=0 ; i<5 ; ++i ){		/* Column loop			*/

      setfillstyle(SOLID_FILL, color);	/* Set to solid fill in color	*/
      setcolor( color );		/* Set the same border color	*/

      bar( x, y, x+width, y+height );	/* Draw the rectangle		*/
      rectangle( x, y, x+width, y+height );  /* outline the rectangle	*/

      if( color == BLACK ){		/* If box was black...		*/
	setcolor( WHITE );		/* Set drawing color to white	*/
	rectangle( x, y, x+width, y+height );  /* Outline black in white*/
      }
      itoa( color, cnum, 10 );		/* Convert # to ASCII		*/
      outtextxy( x+(width/2), y+height+4, cnum );  /* Show color #	*/

      color = ++color ;	/* Advance to the next color	*/
      x += (width / 2) * 3;		/* move the column base 	*/
    }				/* End of Column loop		*/

    y += (height / 2) * 3;		/* move the row base		*/
    x = width / 2;			/* reset column base		*/
  }
  switch(A)
   {
    case 0:
      cout<<" Enter  color No  for outter Rectangle:- ";
      cin>>cl1;
      break;
  case 1:
      cout<<" Enter  color No  for inner Rectangle:- ";
      cin>>cl2;
      break;
  case 2:
      cout<<" Enter  color No  for text> 1 :- ";
      cin>>cl3;
      break;
  case 3:
      cout<<" Enter  color No  for text> 2 :- ";
      cin>>cl4;
      break;
  }
}
//   getch();
}
