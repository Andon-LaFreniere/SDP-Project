#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
void Start();
char Move(int *,char,int, int);


/*    Next steps for SDP:


1. create object for user one, user two, and program all functions related to them (andon)

2. create start menu for (distance traveled, arrows fired, reset button, wins, for each player) - (andon)

3. figure out how to draw the arrow (nolan)

4. create object for the arrows, press direction button - then the arrow fires in that direction arrows (nolan)

5. users have limited number of arrows, but with ability to reload (undecided)
*/ 

void Start() {

    int i;
    LCD.SetFontColor(GREEN);
    LCD.FillRectangle(5, 5, 209, 209);


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
    LCD.SetFontColor(DARKORCHID);
    LCD.FillCircle(267, 180, 35);

    LCD.SetFontColor(GRAY);
    LCD.DrawRectangle(237, 15, 60, 25);
    LCD.DrawCircle(267, 180, 35);

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

    
    

    //LCD.SetFontColor(RED);
    //LCD.FillCircle(211, 211, 2);
    //LCD.DrawCircle(211, 211, 2);

    LCD.WriteAt("MOVE",242,20);
    LCD.WriteAt("Moves Left:",5,220);

    LCD.SetFontColor(BLUE);
    LCD.FillCircle(7, 7, 2);
    LCD.DrawCircle(7, 7, 2);

    LCD.SetFontColor(RED);
    LCD.FillCircle(211, 211, 2);
    LCD.DrawCircle(211, 211, 2);
    

}


char Move(int *p,char d,int rt, int bt)
{   
    int x, y;
    if(rt!=0)
    {
        x=0;
        y=1;
    }
    if(bt!=0)
    {
        x=2;
        y=3;
    }
    
    LCD.SetFontColor(GREEN);
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
        p[y] -= 6;
    }
    else if (d=='s'&&p[y]<208)
    {
        p[y] += 6;
    }
    else if (d=='e'&&p[x]<208)
    {
        p[x] += 6;
    }
    else if (d=='w'&&p[x]>8)
    {
        p[x] -= 6;
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
    int i, p[4]={7,7,211,211}, bt=0, rt=0;
    char d='o',ts='r';

 
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
            d=Move(p,d,bt,rt);
            while (LCD.Touch(&x,&y)) {};
            LCD.SetFontColor(GRAY);
            LCD.DrawRectangle(237, 15, 60, 25);
            LCD.WriteAt("MOVE",242,20);
            
            if(bt>0&&d!='o')
            {
                LCD.SetFontColor(DARKGREEN);
                LCD.WriteAt(bt,138,220);
                bt--;
                rt=0;
                LCD.SetFontColor(BLUE);
                LCD.WriteAt(bt,138,220);
            }
            if(rt>0&&d!='o')
            {
                LCD.SetFontColor(DARKGREEN);
                LCD.WriteAt(rt,138,220);
                rt--;
                bt=0;
                LCD.SetFontColor(RED);
                LCD.WriteAt(rt,138,220);
            }
            d='o';
            
            /*
            LCD.Write(bt);
            LCD.Write(" ");
            LCD.Write(rt);
            LCD.Write(" ");
            */
            
        }
    
        if (bt==0&&rt==0&&ts=='b')
        {
            LCD.SetFontColor(DARKGREEN);
            LCD.WriteAt(bt,138,220);
            rt=5;
            ts='r';
            LCD.SetFontColor(RED);
            LCD.WriteAt(rt,138,220);
            LCD.WriteAt("Moves Left:",5,220);
        }
        if (bt==0&&rt==0&&ts=='r')
        {
            LCD.SetFontColor(DARKGREEN);
            LCD.WriteAt(rt,138,220);
            bt=5;
            ts='b';
            LCD.SetFontColor(BLUE);
            LCD.WriteAt(bt,138,220);
            LCD.WriteAt("Moves Left:",5,220);
        }

        
        LCD.Update();
        
    }
    return 0;
    
}
