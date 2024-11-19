/*    Next steps for SDP:
1. create object for user one, user two, and program all functions related to them (andon)
2. create start menu for (distance traveled, arrows fired, reset button, wins, for each player) - (andon)
3. figure out how to draw the arrow (nolan)
3. create object for the arrows, press direction button - then the arrow fires in that direction arrows (nolan)
4. users have limited number of arrows, but with ability to reload (undecided)
*/ 

/*  11/19/2024
    -The characters can still move out of bounds?
    -Still need to implement Stats() menu and function
    -Integration of arrows into this function
    -Further divide operations in current code
*/

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void Start(); //function to initialize game grid and UI
void Menu(); //function to initialize the game menu 
//void Stats(); //function to initialize the statistics screen
int randomTurn(); // function to randomly return either 1 or 0 to determine which player goes first
char dpadStatus(int, int);

class player 
{
    public:
        player(int, int, const char playername[], int color);
        void move(char); //need to know current position of player, the direction the player needs to move, 
    private:
        char name[30];
        int xpos, ypos; //variables for a player's x-coordinate and y-coordinate
        bool isPlayerTurn; //true or false for if it is the player's turn, can only use this variable in the member functions
        int playerColor;
};

player::player(int startX, int startY, const char playername[], int color)
{
    playerColor = color;
    strcpy(name, playername);
    xpos = startX;
    ypos = startY;
}

void Menu()
{
    float x, y; // Variables for touch coordinates

    // Set background color and clear the screen
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    // Display the title
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("GAME TITLE", 80, 30);

    // Draw the "Start" button
    LCD.SetFontColor(GREEN);
    LCD.FillRectangle(80, 100, 160, 40); // x, y, width, height
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("START", 125, 115); // x, y (centered in the button)

    // Draw the "Stats" button
    LCD.SetFontColor(BLUE);
    LCD.FillRectangle(80, 160, 160, 40); // x, y, width, height
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("STATS", 125, 175); // x, y (centered in the button)

    // Update the display
    LCD.Update();

    // Wait for the user to press a button
    while (true) {
        if (LCD.Touch(&x, &y)) {
            // Check if the "Start" button was pressed
            if (x > 80 && x < 240 && y > 100 && y < 140) {
                // "Start" button action
                while (LCD.Touch(&x, &y)); // Wait for release
                LCD.Clear();
                Start(); // Call the Start function
                break;
            }

            // Check if the "Stats" button was pressed
            if (x > 80 && x < 240 && y > 160 && y < 200) {
                // "Stats" button action
                while (LCD.Touch(&x, &y)); // Wait for release
                LCD.Clear();
                //Stats(); // Call the Stats function
                break;
            }
        }
    }
}

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

    
    

    LCD.WriteAt("MOVE",242,20);
    LCD.WriteAt("Moves Left:",5,220);

    //draw initial position of blue circle
    LCD.SetFontColor(BLUE);
    LCD.FillCircle(7, 7, 2);
    LCD.DrawCircle(7, 7, 2);

    //draw initial position of red circle
    LCD.SetFontColor(RED);
    LCD.FillCircle(211, 211, 2);
    LCD.DrawCircle(211, 211, 2);
    

}

void player::move(char d) {
    // Make the player's current position the same as the background
    LCD.SetFontColor(GREEN);
    LCD.FillCircle(xpos, ypos, 2);
    LCD.DrawCircle(xpos, ypos, 2);

    // Based on the user input, adjust the location of the player
    switch (d) {
        case 'n':
            if (ypos > 7 || ypos < 208 ){
            ypos -= 6;}
            break;
        case 's':
         if (ypos > 7 || ypos < 208 ){
            ypos += 6;}
            break;
        case 'e':
            if (xpos > 7 || xpos < 208 ){
            xpos += 6;}
            break;
        case 'w':
            if (xpos > 7 || xpos < 208 ){
            xpos -= 6;}
            break;
        default:
            break;
    }
    //movecount++;
    
    // Update the location of the player
    LCD.SetFontColor(playerColor);
    LCD.FillCircle(xpos, ypos, 2);
    LCD.DrawCircle(xpos, ypos, 2);
}

int randomTurn()
{
    FEHRandom randomGeneration; //RandInt() is a non-static method, so we must create an instance of FEHRandom to use it
    return randomGeneration.RandInt() % 2; //use the RandInt() function to get a random number 1 or 0
}

char dpadStatus(int a, int b) {
    // Loop until the user touches the screen
    while (true) {
        if (LCD.Touch(&a, &b)) {
            // Check if the touch is within a specific direction area
            if (a > 257 && a < 277 && b > 50 && b < 70) {
                LCD.SetFontColor(RED);
                LCD.DrawCircle(267, 60, 10);
                return 'n'; // North direction
            }
            if (a > 237 && a < 257 && b > 65 && b < 85) {
                LCD.SetFontColor(RED);
                LCD.DrawCircle(247, 75, 10);
                return 'w'; // West direction
            }
            if (a > 277 && a < 297 && b > 65 && b < 85) {
                LCD.SetFontColor(RED);
                LCD.DrawCircle(287, 75, 10);
                return 'e'; // East direction
            }
            if (a > 257 && a < 277 && b > 80 && b < 100) {
                LCD.SetFontColor(RED);
                LCD.DrawCircle(267, 90, 10);
                return 's'; // South direction
            }
        }
        Sleep(1); // Sleep for a short time to prevent high CPU usage while waiting for touch
    }
}

int main() {
    player p1(7,7, "Blue Player", 0x0000FF), p2(211,211, "Red Player Two", 0xFF0000); //create two player objects with starting coordinates (7,7) and (211, 211), names and colors added
    int x, y;
    int bt=5, rt=5;
    char d='o',ts='r';
    int currentPlayer = randomTurn();

    // Clear background
    LCD.SetBackgroundColor(DARKGREEN);
    LCD.Clear();

    Menu(); //pull up the start menu

while (1) {
        // Reset moves count for each player
        bt = 5;  
        rt = 5;
    while (bt > 0 && rt > 0) {  // Outer loop for each player's turn
    if (currentPlayer == 0) {  // Player 1's turn
        for (int i = 0; i < 5 && bt > 0; i++) {  // Only loop 5 times or until bt reaches 0
            LCD.SetFontColor(BLACK);
            LCD.DrawRectangle(138, 220, 100, 30);  // Clear the area where the previous text was
            LCD.FillRectangle(138, 220, 100, 30); 
            LCD.SetFontColor(BLUE);
            LCD.WriteAt(bt, 138, 220);
            LCD.WriteAt("Moves Left:", 5, 220);
            
            // Capture direction for each move
            d = dpadStatus(x, y); 

            // Wait for the MOVE button to be pressed before executing the move
            if (d != 'o') {  // Only allow move if a direction is selected
                // Wait for the MOVE button to be pressed
                while (!(LCD.Touch(&x, &y) && x > 237 && x < 297 && y > 15 && y < 40)) {
                    // Optionally add feedback like flashing button
                    Sleep(50);  // Avoid overloading the processor
                }
                
                // Perform the move and update the moves left count
                p1.move(d);
                bt--;  // Decrement moves left for Player 1
                
                //Stats(p1, p2);
                // Provide feedback after the move
                LCD.SetFontColor(GRAY);
                LCD.DrawRectangle(237, 15, 60, 25); // Reset MOVE button
                LCD.WriteAt("MOVE", 242, 20);
                LCD.DrawCircle(267, 60, 10);
                LCD.DrawCircle(267, 90, 10);
                LCD.DrawCircle(247, 75, 10);
                LCD.DrawCircle(287, 75, 10);

                // Wait until the MOVE button is released
                while (LCD.Touch(&x, &y)) {}  // Ensure the button is released
            }
        }
        currentPlayer = 1;  // Switch to player 2 after player 1 completes their moves

    } else {  // Player 2's turn
        for (int i = 0; i < 5 && rt > 0; i++) {  // Only loop 5 times or until rt reaches 0
            LCD.SetFontColor(BLACK);
            LCD.DrawRectangle(138, 220, 100, 30);  // Clear the area where the previous text was
            LCD.FillRectangle(138, 220, 100, 30); 
            LCD.SetFontColor(RED);
            LCD.WriteAt(rt, 138, 220);
            LCD.WriteAt("Moves Left:", 5, 220);

            // Capture direction for each move
            d = dpadStatus(x, y);

            // Wait for the MOVE button to be pressed before executing the move
            if (d != 'o') {  // Only allow move if a direction is selected
                
                // Wait for the MOVE button to be pressed
                while (!(LCD.Touch(&x, &y) && x > 237 && x < 297 && y > 15 && y < 40)) {
                    // Optionally add feedback like flashing button
                    Sleep(50);  // Avoid overloading the processor
                }
                
                // Perform the move and update the moves left count
                p2.move(d);
                rt--;  // Decrement moves left for Player 2
                
                //Stats(p1, p2);
                // Provide feedback after the move
                LCD.SetFontColor(GRAY);
                LCD.DrawRectangle(237, 15, 60, 25); // Reset MOVE button
                LCD.WriteAt("MOVE", 242, 20);
                LCD.DrawCircle(267, 60, 10);
                 LCD.DrawCircle(267, 90, 10);
                 LCD.DrawCircle(247, 75, 10);
                 LCD.DrawCircle(287, 75, 10);
                
                // Wait until the MOVE button is released
                while (LCD.Touch(&x, &y)) {};  // Ensure the button is released
            }
        }
        currentPlayer = 0;  // Switch to player 1 after player 2 completes their moves
    }
}

LCD.Update();  // Refresh the LCD after each turn
}
    
    return 0;
}
