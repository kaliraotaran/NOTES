//axe game
//** you cant just click RUN, you go to run->start Debugging
//initwindow(width, height, "what to dispay");
/*                      CLEAR THE WINDOW BACKGROUND(bascially how a window appears)
while(true){
    BeginDrawing();
    clearBackground(WHITE);// this will set the background to whit, or bascially just clears the background
    EndDrawing();
}
`                            TO CLOSE A WINDOW
while(WindowShouldClose() != true){ 
    statemets 
}                               OR
while(WindowShouldClose() == false){
    statements
}
`                            DRAWING A CIRCLE
DrawCircle(centerX, centerY, radius, color);

`                       MOVING THE CIRCLE
if(IsKeyDown(KEY_D)){        -- this sets the download motion to the key D(can set it to anything)
    cirlce_x = circle_x+1; (if you want the circle to move right when D is pressed)
}

`                       SETTING THE FRAMES PER SECOND
SetTargetFPS(60);

`                       DRAW A RECTANGLE
DrawRectangle(position_x, postion_y, widht, height, color)

`                       DRAW TEXT/ PUT TEXT ON WINDOW
drawtext("text", positionx,positiony,font_size, color );

*/

#include "raylib.h"
 
int main(){
    // window dimentions    
    int width= 450;
    int height = 450;
   InitWindow(width, height,"My Window");
    // where i want the circle to spawn
    int circle_x= 200;
    int circle_y=200;

    int circle_radius = 25;

    // circle edges
    int l_cirlce_x = circle_x-circle_radius;// x coordinate of circles left edge
    int r_circle_x= circle_x+circle_radius;
    int u_circle_y= circle_y-circle_radius ;// the upper part of circle
    int b_cirlce_y=circle_y+circle_radius; 


    
    // axe coordinates
    int axe_x=250;
    int axe_y=250;
    int axe_length = 50;

    //axe edges
    int l_axe_x= axe_x;
    int r_axe_x=axe_y+axe_length;
    int u_axe_y=axe_y;
    int b_axe_y=axe_y+axe_length;

    int direction =10;

    // collision of axe with circle
    bool collosion_with_axe = 
                            (b_axe_y >= u_circle_y)&&
                            (u_axe_y <= b_cirlce_y)&&
                            (r_axe_x >= l_cirlce_x)&&
                            (l_axe_x <= r_circle_x);
                                
    SetTargetFPS(90);
    // what is actually in the window
    while (WindowShouldClose() != true)
    {
        BeginDrawing();

        ClearBackground(RED);
       // here we put the game logic in the else statement cause it bascially 
       //says that if the circle collides with the axe, then it will display the game over text
       // , else keep playing
       if (collosion_with_axe)
       {
           DrawText("Game Over", 200,200,30, BLACK);
       }
       else{
        // game logic begins

        // updating the edges of the circle in real time 
        l_cirlce_x = circle_x - circle_radius;
        r_circle_x = circle_x +circle_radius;
        u_circle_y = circle_y- circle_radius;
        b_cirlce_y = circle_y + circle_radius;

        l_axe_x = axe_x;
        r_axe_x = axe_x +axe_length; 
        u_axe_y = axe_y;
        b_axe_y = axe_y+axe_length;

        // updating the collosion with axe
        collosion_with_axe = 
                            (b_axe_y >= u_circle_y)&&
                            (u_axe_y <= b_cirlce_y)&&
                            (r_axe_x >= l_cirlce_x)&&
                            (l_axe_x <= r_circle_x);

        DrawCircle(circle_x,circle_y, circle_radius,BLACK);
        DrawRectangle(axe_x,axe_y,axe_length,axe_length,WHITE);
        
        axe_y = axe_y +direction;// this is just making the axe move
        if (axe_y>height || axe_y<0)// height gives dimention of window
        {                               // bascially just made it bounce
            direction=-direction;       // bascially said that if the axe tries to go further
                                        // than the 900 boundry then it would reverse diection
        }
        



        if (IsKeyDown(KEY_D) && circle_x<440)// set a bounday at pixel 400
        {
            circle_x= circle_x+10;      // makes circle move to the right
        }
        if (IsKeyDown(KEY_A) && circle_x>10)// again set a boundary here
        {
            circle_x = circle_x-10;
        }
        if (IsKeyDown(KEY_W) && circle_y>10)
        {
            circle_y = circle_y-10;
        }
        if (IsKeyDown(KEY_S) && circle_y<440) 
        {
         circle_y=circle_y+10;
        }  
        
        
       }
        // game logic ends
        EndDrawing();


    }
    

    return 0;
}