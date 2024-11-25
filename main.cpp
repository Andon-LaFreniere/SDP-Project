#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
void Start();
char Move(int *,char,int, int, char *);
char Arrow(int *,int *, int *, char, char *, int, int);
char Amove(int *,int *,char *, char *);
char Aboost(int *,int *,char *, char *,char *);
char Acounter(char *);
char Ammo(int *, char *);
char TrailFix(int *,int *, char *,int *);
int Border(int *);
char BoostCheck(int *, char *, char *);
char HitCheck(int *,int *,int *,int *);
char Win(char);


/*
    SDP Training Minigame #1
  
    Make the shapes race across the ​screen.​
    Change their colors when they reach​ the finish line.​
*/
void Start() {

    int i;
    LCD.SetFontColor(GREEN);
    LCD.FillRectangle(5, 5, 209, 209);
    LCD.SetFontColor(GOLDENROD);
    LCD.FillRectangle(95, 95, 30, 30);

    LCD.SetFontColor(SILVER);
    LCD.FillRectangle(160, 40, 18, 18);
    LCD.SetFontColor(BURLYWOOD);
    LCD.FillRectangle(40, 160, 18, 18);


    LCD.SetFontColor(DARKGREEN);
    for (i=1;i<35;i++)
    {
    LCD.DrawLine(5,4+6*i,214,4+6*i);
    LCD.DrawLine(4+6*i,5,4+6*i,214);
    LCD.Update();
    Sleep(10);
    }

    LCD.SetFontColor(DARKGRAY);
    LCD.FillRectangle(237, 15, 60, 25);
    LCD.SetFontColor(SIENNA);
    LCD.FillCircle(267, 180, 35);

    LCD.SetFontColor(GRAY);
    LCD.DrawRectangle(237, 15, 60, 25);
    LCD.DrawCircle(267, 180, 35);
    LCD.WriteAt("SHOOT",236,173);

    LCD.SetFontColor(DARKGRAY);
    LCD.FillCircle(267, 60, 10);
    LCD.FillCircle(247, 75, 10);
    LCD.FillCircle(287, 75, 10);
    LCD.FillCircle(267, 90, 10);
    LCD.SetFontColor(GRAY);
    LCD.DrawCircle(267, 60, 10);
    LCD.DrawCircle(267, 90, 10);
    LCD.DrawCircle(247, 75, 10);
    LCD.DrawCircle(287, 75, 10);

    //LCD.WriteAt("S",229,105);
    //LCD.WriteAt("S",279,105);
    LCD.SetFontColor(BLUE);
    LCD.DrawCircle(242, 133, 14);
    LCD.WriteAt("10",229,126);
    LCD.SetFontColor(RED);
    LCD.DrawCircle(292, 133, 14);
    LCD.WriteAt("10",279,126);

    LCD.SetFontColor(SIENNA);
    LCD.DrawLine(1,1,217,1);
    LCD.DrawLine(217,1,217,217);
    LCD.DrawLine(217,217,1,217);
    LCD.DrawLine(1,217,1,1);
    
    
    

    //LCD.SetFontColor(RED);
    //LCD.FillCircle(211, 211, 2);
    //LCD.DrawCircle(211, 211, 2);
    LCD.SetFontColor(GRAY);
    LCD.WriteAt("MOVE",242,20);
    LCD.WriteAt("Moves Left:",5,220);

    LCD.SetFontColor(BLUE);
    LCD.FillCircle(7, 7, 2);
    LCD.DrawCircle(7, 7, 2);

    LCD.SetFontColor(RED);
    LCD.FillCircle(211, 211, 2);
    LCD.DrawCircle(211, 211, 2);
    

}

char Win(char lose)
{
    LCD.SetBackgroundColor(GHOSTWHITE);
    if (lose=='b')
    {
        LCD.SetFontColor(RED);
        LCD.Write("RED WINS!!!");
        LCD.Write("  ");
    }
    if (lose=='r')
    {
        LCD.SetFontColor(BLUE);
        LCD.Write("BLUE WINS!!!");
        LCD.Write("  ");
    }
    if (lose=='t')
    {
        LCD.SetFontColor(BLACK);
        LCD.Write("TIE!!!");
        LCD.Write("  ");
    }
}

char BoostCheck(int *pp, char *s, char *a)
{

    for (int i=0;i<4;i=i+2)
    {
        if (pp[i]>160&&pp[i]<178&&pp[i+1]>40&&pp[i+1]<58&&s[0]=='n'&&s[1]=='n')
        {
            LCD.SetFontColor(SILVER);
            if (i==0)
                {
                    
                    s[0]='t';
                    LCD.WriteAt("S",229,105);
                }
            if (i==2)
                {
                    s[1]='t';
                    LCD.WriteAt("S",279,105);
                }

            LCD.SetFontColor(SILVER);
            for (i=1;i<35;i++)
            {
                LCD.DrawLine(5,4+6*i,214,4+6*i);
                LCD.DrawLine(4+6*i,5,4+6*i,214);
                LCD.Update();
                Sleep(10);
            }

            LCD.SetFontColor(GREEN);
            LCD.FillRectangle(160, 40, 18, 18);

            LCD.SetFontColor(DARKGREEN);
            for (i=1;i<35;i++)
            {
                LCD.DrawLine(5,4+6*i,214,4+6*i);
                LCD.DrawLine(4+6*i,5,4+6*i,214);
                LCD.Update();
                Sleep(10);
            }
            LCD.SetFontColor(BLUE);
            LCD.FillCircle(pp[0], pp[1], 2);
            LCD.DrawCircle(pp[0], pp[1], 2);

            LCD.SetFontColor(RED);
            LCD.FillCircle(pp[2], pp[3], 2);
            LCD.DrawCircle(pp[2], pp[3], 2);
        }

        if (pp[i]>40&&pp[i]<58&&pp[i+1]>160&&pp[i+1]<178&&a[0]=='n'&&a[1]=='n')
        {
            LCD.SetFontColor(BURLYWOOD);
            if (i==0)
                {
                    a[0]='t';
                    LCD.WriteAt("A",229,105);
                }
            if (i==2)
                {
                    a[1]='t';
                    LCD.WriteAt("A",279,105);
                }
            
            LCD.SetFontColor(BURLYWOOD);
            for (i=1;i<35;i++)
            {
                LCD.DrawLine(5,4+6*i,214,4+6*i);
                LCD.DrawLine(4+6*i,5,4+6*i,214);
                LCD.Update();
                Sleep(10);
            }

            LCD.SetFontColor(GREEN);
            LCD.FillRectangle(40, 160, 18, 18);

            LCD.SetFontColor(DARKGREEN);
            for (i=1;i<35;i++)
            {
                LCD.DrawLine(5,4+6*i,214,4+6*i);
                LCD.DrawLine(4+6*i,5,4+6*i,214);
                LCD.Update();
                Sleep(10);
            }
            LCD.SetFontColor(BLUE);
            LCD.FillCircle(pp[0], pp[1], 2);
            LCD.DrawCircle(pp[0], pp[1], 2);

            LCD.SetFontColor(RED);
            LCD.FillCircle(pp[2], pp[3], 2);
            LCD.DrawCircle(pp[2], pp[3], 2);
        }
    }
    //LCD.FillRectangle(160, 40, 18, 18);
    //LCD.FillRectangle(40, 160, 18, 18);
}

char HitCheck(int *pp,int *xa,int *ya, int *bp)
{
    int bc=0, rc=0;
    for (int i=0; i<20; i++)
    {
        if (pp[0]==xa[i]&&pp[1]==ya[i])
        {
            bc=1;
        }
        else if (pp[0]<=(bp[0]+3)||pp[1]<=(bp[0]+3)||pp[0]>=(bp[1]-3)||pp[1]>=(bp[1]-3))
        {
            bc=1;
        }
        if (pp[2]==xa[i]&&pp[3]==ya[i])
        {
            rc=1;
        }
        else if (pp[2]<=(bp[0]+3)||pp[3]<=(bp[0]+3)||pp[2]>=(bp[1]-3)||pp[3]>=(bp[1]-3))
        {
            rc=1;
        }
    }
    if(rc==1&&bc==1)
    {

        LCD.SetFontColor(BLACK);
        LCD.FillCircle(pp[2], pp[3], 2);
        LCD.DrawCircle(pp[2], pp[3], 2);
        LCD.FillCircle(pp[0], pp[1], 2);
        LCD.DrawCircle(pp[0], pp[1], 2);
        Sleep(1000);
        return 't';
    }
    else if(rc==1)
    {
        LCD.SetFontColor(BLACK);
        LCD.FillCircle(pp[2], pp[3], 2);
        LCD.DrawCircle(pp[2], pp[3], 2);
        Sleep(1000);
        return 'r';
    }
    else if(bc==1)
    {
        LCD.SetFontColor(BLACK);
        LCD.FillCircle(pp[0], pp[1], 2);
        LCD.DrawCircle(pp[0], pp[1], 2);
        Sleep(1000);
        return 'b';
        
    }
    else
    {
        return 'n';
    }
}

int Border(int *bp)
{
    bp[0]+=6;
    bp[1]-=6;
    LCD.SetFontColor(SIENNA);
    LCD.DrawLine(bp[0],bp[0],bp[1],bp[0]);
    LCD.DrawLine(bp[1],bp[0],bp[1],bp[1]);
    LCD.DrawLine(bp[1],bp[1],bp[0],bp[1]);
    LCD.DrawLine(bp[0],bp[1],bp[0],bp[0]);
}
    

char Ammo(int *pp, char *as)
{
    if (pp[0]>95&&pp[0]<125&&pp[1]>95&&pp[1]<125)
    {
        for (int i=0; i<10; i++)
        {
            if(as[i]=='g')
            {
                as[i]='i';
            }
        }
    }

    if (pp[2]>95&&pp[2]<125&&pp[3]>95&&pp[3]<125)
    {
        for (int i=10; i<20; i++)
        {
            if(as[i]=='g')
            {
                as[i]='i';
            }
        }
    }
}


char Acounter(char *as)
{
    int cb=0, cr=0;
    LCD.SetFontColor(DARKGREEN);
    LCD.FillCircle(242, 133, 14);
    //LCD.WriteAt("6",229,126);
    LCD.FillCircle(292, 133, 14);
    //LCD.WriteAt("6",279,126);

    for (int i=0;i<10;i++)
    {
        if (as[i]=='i')
        {
            cb++;
        }
    }

    for (int i=10;i<20;i++)
    {
        if (as[i]=='i')
        {
            cr++;
        }
    }

    LCD.SetFontColor(BLUE);
    LCD.WriteAt(cb,229,126);
    LCD.SetFontColor(RED);
    LCD.WriteAt(cr,279,126);
}

char TrailFix(int *xa,int *ya, char *as, int *bp)
{
    int i;
    for (i=0;i<20;i++)
            {
                if (as[i]!='i'&&as[i]!='g')
                {
                    if (as[i]=='n'&&ya[i]>8)
                    {
                        

                        LCD.SetFontColor(SIENNA);
                        LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i], ya[i]-2, 0);
                        
                        
                    }
                    else if (as[i]=='s'&&ya[i]<208)
                    {
                        
                        LCD.SetFontColor(SIENNA);
                        LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i], ya[i]+2, 0);
                        
                        
                    }
                    else if (as[i]=='e'&&xa[i]<208)
                    {
                       

                        LCD.SetFontColor(SIENNA);
                        LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i]+2, ya[i], 0);
                        
                        
                    }
                    else if (as[i]=='w'&&xa[i]>8)
                    {
                       

                        LCD.SetFontColor(SIENNA);
                        LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i]-2, ya[i], 0);
                        
                        
                    }
                    
                }
            }
    for (i=0;i<=((bp[0]-1)/6);i++)
        {
            if (i>=1)
            {
            LCD.SetFontColor(SIENNA);
            LCD.DrawLine(1+6*i,1+6*i,217-6*i,1+6*i);
            LCD.DrawLine(217-6*i,1+6*i,217-6*i,217-6*i);
            LCD.DrawLine(217-6*i,217-6*i,1+6*i,217-6*i);
            LCD.DrawLine(1+6*i,217-6*i,1+6*i,1+6*i);
            }
        }
}

char Aboost(int *xa,int *ya,char *as,char *abo)
{
    int i,r;
    if (abo[0]=='t')
    {
    for (i=0;i<10;i++)
            {
                if (as[i]!='i'&&as[i]!='g')
                {
                    LCD.SetFontColor(LIGHTGREEN);
                    if (as[i]=='n'&&ya[i]>8)
                    {
                        LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                        LCD.DrawCircle(xa[i], ya[i]-2, 0);

                        ya[i]-=6;

                        LCD.SetFontColor(SIENNA);
                        LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i], ya[i]-2, 0);
                        as[i]='n';
                        
                    }
                    else if (as[i]=='s'&&ya[i]<208)
                    {
                        LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                        LCD.DrawCircle(xa[i], ya[i]+2, 0);

                        ya[i]+=6;

                        LCD.SetFontColor(SIENNA);
                        LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i], ya[i]+2, 0);
                        as[i]='s';
                        
                    }
                    else if (as[i]=='e'&&xa[i]<208)
                    {
                        LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                        LCD.DrawCircle(xa[i]+2, ya[i], 0);

                        xa[i]+=6;

                        LCD.SetFontColor(SIENNA);
                        LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i]+2, ya[i], 0);
                        as[i]='e';
                        
                    }
                    else if (as[i]=='w'&&xa[i]>8)
                    {
                        LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                        LCD.DrawCircle(xa[i]-2, ya[i], 0);

                        xa[i]-=6;

                        LCD.SetFontColor(SIENNA);
                        LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i]-2, ya[i], 0);
                        as[i]='w';
                        
                    }
                    else
                    {
                        LCD.SetFontColor(LIGHTGREEN);
                        if (as[i]=='n')
                        {
                            LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                            LCD.DrawCircle(xa[i], ya[i]-2, 0);

                            ya[i]=0;
                            xa[i]=0;

                            
                            
                        }
                        else if (as[i]=='s')
                        {
                            LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                            LCD.DrawCircle(xa[i], ya[i]+2, 0);

                            ya[i]=0;
                            xa[i]=0;

                            
                            
                        }
                        else if (as[i]=='e')
                        {
                            LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                            LCD.DrawCircle(xa[i]+2, ya[i], 0);

                            ya[i]=0;
                            xa[i]=0;

                            
                            
                        }
                        else if (as[i]=='w')
                        {
                            LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                            LCD.DrawCircle(xa[i]-2, ya[i], 0);

                            ya[i]=0;
                            xa[i]=0;

                            
                            
                        }
                        as[i]='g';
                    }
                }
            }
    }

    if (abo[1]=='t')
    {
    for (i=10;i<20;i++)
            {
                if (as[i]!='i'&&as[i]!='g')
                {
                    LCD.SetFontColor(LIGHTGREEN);
                    if (as[i]=='n'&&ya[i]>8)
                    {
                        LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                        LCD.DrawCircle(xa[i], ya[i]-2, 0);

                        ya[i]-=6;

                        LCD.SetFontColor(SIENNA);
                        LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i], ya[i]-2, 0);
                        as[i]='n';
                        
                    }
                    else if (as[i]=='s'&&ya[i]<208)
                    {
                        LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                        LCD.DrawCircle(xa[i], ya[i]+2, 0);

                        ya[i]+=6;

                        LCD.SetFontColor(SIENNA);
                        LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i], ya[i]+2, 0);
                        as[i]='s';
                        
                    }
                    else if (as[i]=='e'&&xa[i]<208)
                    {
                        LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                        LCD.DrawCircle(xa[i]+2, ya[i], 0);

                        xa[i]+=6;

                        LCD.SetFontColor(SIENNA);
                        LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i]+2, ya[i], 0);
                        as[i]='e';
                        
                    }
                    else if (as[i]=='w'&&xa[i]>8)
                    {
                        LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                        LCD.DrawCircle(xa[i]-2, ya[i], 0);

                        xa[i]-=6;

                        LCD.SetFontColor(SIENNA);
                        LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i]-2, ya[i], 0);
                        as[i]='w';
                        
                    }
                    else
                    {
                        LCD.SetFontColor(LIGHTGREEN);
                        if (as[i]=='n')
                        {
                            LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                            LCD.DrawCircle(xa[i], ya[i]-2, 0);

                            ya[i]=0;
                            xa[i]=0;

                            
                            
                        }
                        else if (as[i]=='s')
                        {
                            LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                            LCD.DrawCircle(xa[i], ya[i]+2, 0);

                            ya[i]=0;
                            xa[i]=0;

                            
                            
                        }
                        else if (as[i]=='e')
                        {
                            LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                            LCD.DrawCircle(xa[i]+2, ya[i], 0);

                            ya[i]=0;
                            xa[i]=0;

                            
                            
                        }
                        else if (as[i]=='w')
                        {
                            LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                            LCD.DrawCircle(xa[i]-2, ya[i], 0);

                            ya[i]=0;
                            xa[i]=0;

                            
                            
                        }
                        as[i]='g';
                    }
                }
            }
    }
}

char Amove(int *xa,int *ya,char *as)
{
    int i;
    for (i=0;i<20;i++)
            {
                if (as[i]!='i'&&as[i]!='g')
                {
                    LCD.SetFontColor(LIGHTGREEN);
                    if (as[i]=='n'&&ya[i]>8)
                    {
                        LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                        LCD.DrawCircle(xa[i], ya[i]-2, 0);

                        ya[i]-=6;

                        LCD.SetFontColor(SIENNA);
                        LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i], ya[i]-2, 0);
                        as[i]='n';
                        
                    }
                    else if (as[i]=='s'&&ya[i]<208)
                    {
                        LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                        LCD.DrawCircle(xa[i], ya[i]+2, 0);

                        ya[i]+=6;

                        LCD.SetFontColor(SIENNA);
                        LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i], ya[i]+2, 0);
                        as[i]='s';
                        
                    }
                    else if (as[i]=='e'&&xa[i]<208)
                    {
                        LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                        LCD.DrawCircle(xa[i]+2, ya[i], 0);

                        xa[i]+=6;

                        LCD.SetFontColor(SIENNA);
                        LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i]+2, ya[i], 0);
                        as[i]='e';
                        
                    }
                    else if (as[i]=='w'&&xa[i]>8)
                    {
                        LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                        LCD.DrawCircle(xa[i]-2, ya[i], 0);

                        xa[i]-=6;

                        LCD.SetFontColor(SIENNA);
                        LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i]-2, ya[i], 0);
                        as[i]='w';
                        
                    }
                    else
                    {
                        LCD.SetFontColor(LIGHTGREEN);
                        if (as[i]=='n')
                        {
                            LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                            LCD.DrawCircle(xa[i], ya[i]-2, 0);

                            ya[i]=0;
                            xa[i]=0;

                            
                            
                        }
                        else if (as[i]=='s')
                        {
                            LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                            LCD.DrawCircle(xa[i], ya[i]+2, 0);

                            ya[i]=0;
                            xa[i]=0;

                            
                            
                        }
                        else if (as[i]=='e')
                        {
                            LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                            LCD.DrawCircle(xa[i]+2, ya[i], 0);

                            ya[i]=0;
                            xa[i]=0;

                            
                            
                        }
                        else if (as[i]=='w')
                        {
                            LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                            LCD.DrawCircle(xa[i]-2, ya[i], 0);

                            ya[i]=0;
                            xa[i]=0;

                            
                            
                        }
                        as[i]='g';
                    }
                }
            }

}

char Arrow(int *pp, int *xa, int *ya, char d, char *as, int rt, int bt)
{
    int x, y, i;

    LCD.SetFontColor(GRAY);
    LCD.DrawCircle(267, 60, 10);
    LCD.DrawCircle(267, 90, 10);
    LCD.DrawCircle(247, 75, 10);
    LCD.DrawCircle(287, 75, 10);

    if(rt==0)
    {
        x=0;
        y=1;
        for (i=0;i<10;i++)
            {
                if (as[i]=='i')
                {
                    LCD.SetFontColor(SIENNA);
                    if (d=='n'&&pp[y]>8)
                    {
                        ya[i] = pp[y]-6;
                        xa[i] = pp[x];
                        
                        LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i], ya[i]-2, 0);
                        as[i]='n';
                        return 'n';
                    }
                    else if (d=='s'&&pp[y]<208)
                    {
                        ya[i] = pp[y]+6;
                        xa[i] = pp[x];

                        LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i], ya[i]+2, 0);
                        as[i]='s';
                        return 's';
                    }
                    else if (d=='e'&&pp[x]<208)
                    {
                        xa[i] = pp[x]+6;
                        ya[i] = pp[y];

                        LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i]+2, ya[i], 0);
                        as[i]='e';
                        return 'e';
                    }
                    else if (d=='w'&&pp[x]>8)
                    {
                        xa[i] = pp[x]-6;
                        ya[i] = pp[y];

                        LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i]-2, ya[i], 0);
                        as[i]='w';
                        return 'w';
                    }
                    else
                    {
                        return 'o';
                    }
                }
            }
    }
    if(bt==0)
    {
        x=2;
        y=3;
        for (i=10;i<20;i++)
            {
                if (as[i]=='i')
                {
                    LCD.SetFontColor(SIENNA);
                    if (d=='n'&&pp[y]>8)
                    {
                        ya[i] = pp[y]-6;
                        xa[i] = pp[x];
                        
                        LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i], ya[i]-2, 0);
                        as[i]='n';
                        return 'n';
                    }
                    else if (d=='s'&&pp[y]<208)
                    {
                        ya[i] = pp[y]+6;
                        xa[i] = pp[x];

                        LCD.DrawLine(xa[i],ya[i]+2,xa[i],ya[i]-3);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i], ya[i]+2, 0);
                        as[i]='s';
                        return 's';
                    }
                    else if (d=='e'&&pp[x]<208)
                    {
                        xa[i] = pp[x]+6;
                        ya[i] = pp[y];

                        LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i]+2, ya[i], 0);
                        as[i]='e';
                        return 'e';
                    }
                    else if (d=='w'&&pp[x]>8)
                    {
                        xa[i] = pp[x]-6;
                        ya[i] = pp[y];

                        LCD.DrawLine(xa[i]+2,ya[i],xa[i]-3,ya[i]);
                        LCD.SetFontColor(DARKGRAY);
                        LCD.DrawCircle(xa[i]-2, ya[i], 0);
                        as[i]='w';
                        return 'w';
                    }
                    else
                    {
                        return 'o';
                    }
                }
            }
    }

    return 'o';
}

char Move(int *p,char d,int rt, int bt,char *s)
{   
    int x, y, a=6;
    if(rt!=0)
    {
        x=0;
        y=1;
        if (s[0]=='t')
        {
            a=12;
        }

    }
    if(bt!=0)
    {
        x=2;
        y=3;
        if (s[1]=='t')
        {
            a=12;
        }
    }
    
    LCD.SetFontColor(LIGHTGREEN);
    LCD.FillCircle(p[0], p[1], 2);
    LCD.DrawCircle(p[0], p[1], 2);

    LCD.FillCircle(p[2], p[3], 2);
    LCD.DrawCircle(p[2], p[3], 2);

    LCD.SetFontColor(GRAY);
    LCD.DrawCircle(267, 60, 10);
    LCD.DrawCircle(267, 90, 10);
    LCD.DrawCircle(247, 75, 10);
    LCD.DrawCircle(287, 75, 10);

    if (d=='n'&&p[y]>8)
    {
        p[y] -= a;
    }
    else if (d=='s'&&p[y]<208)
    {
        p[y] += a;
    }
    else if (d=='e'&&p[x]<208)
    {
        p[x] += a;
    }
    else if (d=='w'&&p[x]>8)
    {
        p[x] -= a;
    }
    else
    {
        LCD.SetFontColor(BLUE);
        LCD.FillCircle(p[0], p[1], 2);
        LCD.DrawCircle(p[0], p[1], 2);

        LCD.SetFontColor(RED);
        LCD.FillCircle(p[2], p[3], 2);
        LCD.DrawCircle(p[2], p[3], 2);
        return 'o';
        
    }

    
    LCD.SetFontColor(BLUE);
    LCD.FillCircle(p[0], p[1], 2);
    LCD.DrawCircle(p[0], p[1], 2);

    LCD.SetFontColor(RED);
    LCD.FillCircle(p[2], p[3], 2);
    LCD.DrawCircle(p[2], p[3], 2);
}




int main() {
    float x,y;
    int i, p[4]={7,7,211,211}, bt=0, rt=0, apx[20], apy[20] ,bc=-1, bp[2]={1,217};
    char d='o',ts='r',as[20], lose='n', sboost[2], aboost[2];

    for (int i=0;i<20;i++)
    {
        as[i]='i';
        apx[i]=0;
        apy[i]=0;
    }
    for (int i=0;i<2;i++)
    {
        sboost[i]='n';
        aboost[i]='n';
    }
    // Clear background
    LCD.SetBackgroundColor(DARKGREEN);
    LCD.Clear();

    Start();

    // movement
    while (1) {
        
        if (LCD.Touch(&x,&y)==true&&x>257&&x<277&&y>50&&y<70)
        {
            d='n';
            LCD.SetFontColor(RED);
            LCD.DrawCircle(267, 60, 10);
            while (LCD.Touch(&x,&y)) {};
            LCD.SetFontColor(GRAY);
            //LCD.DrawCircle(267, 60, 10);
            LCD.DrawCircle(267, 90, 10);
            LCD.DrawCircle(247, 75, 10);
            LCD.DrawCircle(287, 75, 10);
            

        }
        if (LCD.Touch(&x,&y)==true&&x>237&&x<257&&y>65&&y<85)
        {
            d='w';
            LCD.SetFontColor(RED);
            LCD.DrawCircle(247, 75, 10);
            while (LCD.Touch(&x,&y)) {};
            LCD.SetFontColor(GRAY);
            LCD.DrawCircle(267, 60, 10);
            LCD.DrawCircle(267, 90, 10);
            //LCD.DrawCircle(247, 75, 10);
            LCD.DrawCircle(287, 75, 10);
            
        }
        if (LCD.Touch(&x,&y)==true&&x>277&&x<297&&y>65&&y<85)
        {
            d='e';
            LCD.SetFontColor(RED);
            LCD.DrawCircle(287, 75, 10);
            while (LCD.Touch(&x,&y)) {};
            LCD.SetFontColor(GRAY);
            LCD.DrawCircle(267, 60, 10);
            LCD.DrawCircle(267, 90, 10);
            LCD.DrawCircle(247, 75, 10);
            //LCD.DrawCircle(287, 75, 10);
            
        }
        if (LCD.Touch(&x,&y)==true&&x>257&&x<277&&y>80&&y<100)
        {
            d='s';
            LCD.SetFontColor(RED);
            LCD.DrawCircle(267, 90, 10);
            while (LCD.Touch(&x,&y)) {};
            LCD.SetFontColor(GRAY);
            LCD.DrawCircle(267, 60, 10);
            //LCD.DrawCircle(267, 90, 10);
            LCD.DrawCircle(247, 75, 10);
            LCD.DrawCircle(287, 75, 10);
            
        }
        
        if (LCD.Touch(&x,&y)==true&&x>237&&x<297&&y>15&&y<40&&d!='o')
        {
            
            LCD.SetFontColor(RED);
            LCD.DrawRectangle(237, 15, 60, 25);
            LCD.WriteAt("MOVE",242,20);
            d=Move(p,d,bt,rt,sboost);
            while (LCD.Touch(&x,&y)) {};
            LCD.SetFontColor(GRAY);
            LCD.DrawRectangle(237, 15, 60, 25);
            LCD.WriteAt("MOVE",242,20);
            
            if(bt>0&&d!='o')
            {
                LCD.SetFontColor(DARKGREEN);
                LCD.WriteAt(bt,138,220);
                Amove(apx,apy,as);
                TrailFix(apx,apy,as,bp);
                lose=HitCheck(p,apx,apy,bp);
                Aboost(apx,apy,as,aboost);
                if (lose=='n')
                {
                lose=HitCheck(p,apx,apy,bp);

                bt--;
                rt=0;
                Ammo(p, as);
                BoostCheck(p, sboost, aboost);
                Acounter(as);
                LCD.SetFontColor(BLUE);
                LCD.WriteAt(bt,138,220);
                }
            }
            if(rt>0&&d!='o')
            {
                LCD.SetFontColor(DARKGREEN);
                LCD.WriteAt(rt,138,220);
                Amove(apx,apy,as);
                TrailFix(apx,apy,as,bp);
                lose=HitCheck(p,apx,apy,bp);
                Aboost(apx,apy,as,aboost);
                if (lose=='n')
               {
                lose=HitCheck(p,apx,apy,bp);

                rt--;
                bt=0;
                Ammo(p, as);
                BoostCheck(p, sboost, aboost);
                Acounter(as);
                LCD.SetFontColor(RED);
                LCD.WriteAt(rt,138,220);
                }
            }
            d='o';
            
            /*
            LCD.Write(bt);
            LCD.Write(" ");
            LCD.Write(rt);
            LCD.Write(" ");
            */
            
        }

                //LCD.DrawCircle(267, 180, 35);
    //LCD.WriteAt("SHOOT",236,173);

        if (LCD.Touch(&x,&y)==true&&x>232&&x<302&&y>145&&y<215&&d!='o')
        {
            LCD.SetFontColor(BLACK);
            LCD.DrawCircle(267, 180, 35);
            LCD.WriteAt("SHOOT",236,173);
            d=Arrow(p, apx, apy, d, as, rt, bt);
            while (LCD.Touch(&x,&y)) {};
            LCD.SetFontColor(GRAY);
            LCD.DrawCircle(267, 180, 35);
            LCD.WriteAt("SHOOT",236,173);

           

            if(bt>0&&d!='o')
            {
                LCD.SetFontColor(DARKGREEN);
                LCD.WriteAt(bt,138,220);
                Amove(apx,apy,as);
                TrailFix(apx,apy,as,bp);
                lose=HitCheck(p,apx,apy,bp);
                Aboost(apx,apy,as,aboost);
                if (lose=='n')
                {
                lose=HitCheck(p,apx,apy,bp);

                bt--;
                rt=0;
                Ammo(p, as);
                BoostCheck(p, sboost, aboost);
                Acounter(as);
                LCD.SetFontColor(BLUE);
                LCD.WriteAt(bt,138,220);
                }
            }
            if(rt>0&&d!='o')
            {
                LCD.SetFontColor(DARKGREEN);
                LCD.WriteAt(rt,138,220);
                Amove(apx,apy,as);
                TrailFix(apx,apy,as,bp);
                lose=HitCheck(p,apx,apy,bp);
                Aboost(apx,apy,as,aboost);
                if (lose=='n')
                {
                lose=HitCheck(p,apx,apy,bp);

                rt--;
                bt=0;
                Ammo(p, as);
                BoostCheck(p, sboost, aboost);
                Acounter(as);
                LCD.SetFontColor(RED);
                LCD.WriteAt(rt,138,220);
                }
            }
            d='o';
        }
    
    
        if (bt==0&&rt==0&&ts=='b')
        {
            LCD.SetFontColor(DARKGREEN);
            LCD.WriteAt(bt,138,220);
            rt=5;
            ts='r';
            bc++;
            LCD.SetFontColor(RED);
            LCD.DrawLine(1,1,217,1);
            LCD.DrawLine(217,1,217,217);
            LCD.DrawLine(217,217,1,217);
            LCD.DrawLine(1,217,1,1);
            LCD.WriteAt(rt,138,220);
            LCD.WriteAt("Moves Left:",5,220);
        }
        if (bt==0&&rt==0&&ts=='r')
        {
            LCD.SetFontColor(DARKGREEN);
            LCD.WriteAt(rt,138,220);
            bt=5;
            bc++;
            ts='b';
            LCD.SetFontColor(BLUE);
            LCD.DrawLine(1,1,217,1);
            LCD.DrawLine(217,1,217,217);
            LCD.DrawLine(217,217,1,217);
            LCD.DrawLine(1,217,1,1);
            LCD.WriteAt(bt,138,220);
            LCD.WriteAt("Moves Left:",5,220);
        }

        if (bc>=2)
        {
            Border(bp);
            bc=0;
            lose=HitCheck(p,apx,apy,bp);
        }
        
        if (lose!='n')
        {
            
            Sleep(70);
            Win(lose);
            
        }
        Sleep(10);

        LCD.Update();
    
    }

    return 0;
    
}