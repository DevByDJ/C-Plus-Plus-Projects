/* --------------------------------------------------------
 *    File: Breakout.cpp
 *  Author: Danny Joseph
 *   Class: Programming Methodology COP 2001
 * Purpose: Creating a breakout style game
 * -------------------------------------------------------- */

#include <SFML/Graphics.hpp>
#include <cmath>                    // trig and linear functionality
#include "breakout_defs.h"


// Function declarations (prototypes)
// --------------------------------------------------------
void gameSetup(Ball &ball, Border &border, Moving_Block &paddle, Brick bricks[BRICK_ROWS][BRICK_COLUMNS]);
Direction processInput() ;
bool update(Direction &input,
            Ball &ball,
            Border border,
            float delta,
            Moving_Block &paddle,
            bool &isStarted,
            Brick bricks[BRICK_ROWS][BRICK_COLUMNS]);
void render(sf::RenderWindow &window,
            Ball &ball,
            float delta,
            Border border,
            Moving_Block paddle,
            Brick bricks[BRICK_ROWS][BRICK_COLUMNS]);
bool doCollisionChecks(Ball &ball, Moving_Block& paddle, Brick bricks[BRICK_ROWS][BRICK_COLUMNS], Border borders);
int getCollision(Ball *pBall, Block *pBlock);
bool checkCollision(Ball* pBall, Block* pBlock);
bool checkBlockCollision(Block* movingBlock, Block* stationaryBlock);


/**
 * The main application
 * @return OS stats message (0=Success)
 */
int main() {

    // create a 2d graphics window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Move Ball");
    window.clear(WINDOW_COLOR);

    // declare a ball variable and populate it in the center of the window
    Ball theBall;

    // Border variable
    Border theBorders;

    // Moving Block variable "paddle"
    Moving_Block paddle;

    // new
    Brick theBricks[BRICK_ROWS][BRICK_COLUMNS];

    // timing variables for the main game loop
    sf::Clock clock;
    sf::Time startTime = clock.getElapsedTime();
    sf::Time stopTime = startTime;
    float delta = 0.0;

    gameSetup(theBall, theBorders, paddle, theBricks);


    bool started = false;
    bool gameOver = false;
    while (!gameOver)
    {
        // calculate frame time
        stopTime = clock.getElapsedTime();
        delta += (stopTime.asMilliseconds() - startTime.asMilliseconds());
        startTime = stopTime;

        // process events
        sf::Event event;
        while (!gameOver && window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                gameOver = true;
        }

        // Process user input
        // ------------------------------------------------
        Direction userInput = processInput();
        if (userInput == Exit)
            gameOver = true;

        // Process Updates
        // ------------------------------------------------
        if (delta >= FRAME_RATE) {    // if we have made it at least a full frame time

            // Assigns the value gathered from update() to determine if the game is over.
            gameOver = update(userInput, theBall, theBorders, delta, paddle, started, theBricks);


            // subtract the frame-rate from the current frame-time
            // for each full frame covered by this update
            while (delta >= FRAME_RATE)
                delta -= FRAME_RATE;
        }

        // Render the window
        // ------------------------------------------------
        render(window, theBall, delta, theBorders, paddle, theBricks);

    } // end main game loop

    // game ending, close the graphics window
    window.close();

    return 0;   // return success to the OSdd
} // end main


void gameSetup(Ball &ball, Border &border, Moving_Block &paddle, Brick bricks[BRICK_ROWS][BRICK_COLUMNS])
{

    // ----- BORDER DECLARATION ------

    // left border properties
    // initialize the left and top side values
    border.leftBlock.leftSide = 0.0;
    border.leftBlock.topSide = 0.0;
    // set the size of the wall based on const variables, WALL THICKNESS and WINDOW HEIGHT
    border.leftBlock.heightOfBlock = WALL_THICKNESS;
    border.leftBlock.widthOfBlock = WINDOW_WIDTH;
    border.leftBlock.blockShape.setSize(sf::Vector2f(border.leftBlock.widthOfBlock,
                                                     border.leftBlock.heightOfBlock));
    // set position of left wall within the window using left and top side values.
    border.leftBlock.blockShape.setPosition(sf::Vector2f(border.leftBlock.leftSide,
                                                         border.leftBlock.topSide));
    // set the color of the wall to the constant value, WALL_COLOR
    border.leftBlock.blockShape.setFillColor(WALL_COLOR);


    //-------------------------------------------------
    // top wall properties
    // initialize the left and top side values
    border.topBlock.leftSide = 0.0;
    border.topBlock.topSide = 0.0;
    // set the size of the wall based on const variables, WALL THICKNESS and WINDOW HEIGHT
    border.topBlock.heightOfBlock = WINDOW_HEIGHT;
    border.topBlock.widthOfBlock = WALL_THICKNESS;
    border.topBlock.blockShape.setSize(sf::Vector2f(border.topBlock.widthOfBlock,
                                                    border.topBlock.heightOfBlock));
    // set position of top wall within the window using left and top side values.
    border.topBlock.blockShape.setPosition(sf::Vector2f(border.topBlock.leftSide,
                                                        border.topBlock.topSide));
    // set the color of the wall to the constant value, WALL_COLOR
    border.topBlock.blockShape.setFillColor(WALL_COLOR);


    //-------------------------------------------------
    // right wall properties
    // initialize the left and top side values
    border.rightBlock.leftSide = WINDOW_WIDTH - WALL_THICKNESS;
    border.rightBlock.topSide = 0.0;
    // set the size of the wall based on const variables, WALL THICKNESS and WINDOW HEIGHT
    border.rightBlock.heightOfBlock = WINDOW_HEIGHT;
    border.rightBlock.widthOfBlock = WALL_THICKNESS;
    border.rightBlock.blockShape.setSize(sf::Vector2f(border.rightBlock.widthOfBlock,
                                                      border.rightBlock.heightOfBlock));
    // set position of right wall within the window using left and top side values.
    border.rightBlock.blockShape.setPosition(sf::Vector2f(border.rightBlock.leftSide,
                                                          border.rightBlock.topSide));
    // set the color of the wall to the constant value, WALL_COLOR
    border.rightBlock.blockShape.setFillColor(WALL_COLOR);


    //-------------------------------------------------
    // bottom wall properties
    // initialize the left and top side values
    border.bottomBlock.leftSide = 0.0;
    border.bottomBlock.topSide = WINDOW_HEIGHT - WALL_THICKNESS;
    // set the size of the wall based on const variables, WALL THICKNESS and WINDOW HEIGHT
    border.bottomBlock.heightOfBlock = WALL_THICKNESS;
    border.bottomBlock.widthOfBlock = WINDOW_WIDTH;
    border.bottomBlock.blockShape.setSize(sf::Vector2f(border.bottomBlock.widthOfBlock,
                                                       border.bottomBlock.heightOfBlock));
    // set position of bottom wall within the window using left and top side values.
    border.bottomBlock.blockShape.setPosition(sf::Vector2f(border.bottomBlock.leftSide,
                                                           border.bottomBlock.topSide));
    // set the color of the wall to the constant value, WALL_COLOR
    border.bottomBlock.blockShape.setFillColor(WALL_COLOR);


    // ------ PADDLE DECLARATION ----------
    paddle.generalBlock.leftSide = (WINDOW_WIDTH - PADDLE_WIDTH) / 2.0;
    paddle.generalBlock.topSide = border.bottomBlock.topSide - (2.0 * PADDLE_THICKNESS);
    paddle.generalBlock.widthOfBlock = PADDLE_WIDTH;
    paddle.generalBlock.heightOfBlock = PADDLE_THICKNESS;
    paddle.generalBlock.blockColor = PADDLE_COLOR;
    paddle.generalBlock.blockShape.setSize(sf::Vector2f(paddle.generalBlock.widthOfBlock,
                                                        paddle.generalBlock.heightOfBlock));
    paddle.generalBlock.blockShape.setFillColor(PADDLE_COLOR);
    paddle.xVelocity = 0.0;
    paddle.yVelocity = 0.0;

    // ------ BALL DECLARATION -----------
    ball.radius = BALL_RADIUS;
    ball.coordinateX = paddle.generalBlock.leftSide +(paddle.generalBlock.widthOfBlock / 2.0);
    ball.coordinateY = paddle.generalBlock.topSide - ball.radius - 1;
    ball.velocityX = 0.0;
    ball.velocityY = 0.0;
    ball.color = BALL_COLOR;

    //-------- BRICKS DECLARATION ----------
    float bricksTop = FIRST_BRICK;

    Brick* pNext = &bricks[0][0];
    for (int row = 0; row < BRICK_ROWS; row++)
    {
        float bricksLeft = BRICKS_LEFT;

        for(int column = 0; column < BRICK_COLUMNS; column++)
        {
            // offset left/top by 1 pixel to give each brick a border
            pNext->block.leftSide = bricksLeft + 1;
            pNext->block.topSide = bricksTop + 1;
            // subtract 2 from width/height to make room for the 1-pixel
            // border on each side
            pNext->block.widthOfBlock = BRICK_WIDTH - 2;
            pNext->block.heightOfBlock = BRICK_HEIGHT - 2;

            // set row specific properties
            if(row < 2)
            {
                pNext->block.blockColor = sf::Color::Green;
                pNext->points = 1;
                pNext->speedAdjust = 0;
            }
            else if(row < 4)
            {
                pNext->block.blockColor = sf::Color::Yellow;
                pNext->points = 3;
                pNext->speedAdjust = 0;
            }
            else if(row < 6)
            {
                pNext->block.blockColor = sf::Color(255, 165,0); // Orange
                pNext->points = 5;
                pNext->speedAdjust = 0;
            }
            else
            {
                pNext->block.blockColor = sf::Color::Red;
                pNext->points = 7;
                pNext->speedAdjust = 0;
            }

            pNext->block.blockShape.setSize(sf::Vector2f(pNext->block.widthOfBlock, pNext->block.heightOfBlock));
            pNext->block.blockShape.setFillColor(pNext->block.blockColor);
            pNext->block.blockShape.setPosition(pNext->block.leftSide, pNext->block.topSide);

            pNext->hit = false;


            pNext++;

            bricksLeft += BRICK_WIDTH;

        } // brick columns

        bricksTop -= BRICK_HEIGHT;

    } // brick rows



} // end of gameSetup



/**
 * convert user keyboard input into recognized integer values
 * for left=1/up=2/right=3/down=4
 * @return int - user input (default no-input=0, quit=-1)
 */
Direction processInput() {
    Direction input = None;  // no input

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)||sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        Direction input = Left;
        return Left;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)||sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        Direction input = Up;
        return Up;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)||sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        Direction input = Right;
        return Right;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)||sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        Direction input = Down;
        return Down;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
        Direction input = Exit;
        return Exit;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        Direction input = Start;
        return Start;
    }
    return None;
} // end getUserInput

/**
 * update the state of game objects
 * @param input - user keyboard input that determines logic
 * @param ball  - update ball position and speed
 * @param border - checks each block if collision was made by ball
 * @param delta - current frame time
 * @param paddle - update paddle position using input
 * @param isStarted - returns if the game has started
 * @return gameOver - determines if the game is over.
 */
bool update(Direction &input, Ball &ball, Border border, float delta, Moving_Block &paddle, bool &isStarted,
            Brick bricks[BRICK_ROWS][BRICK_COLUMNS]) {

    bool gameOver = false;


    // adjust velocity directions for user input
    if (input) {
        switch (input) {
            case Left:
                paddle.xVelocity -= PADDLE_SPEED;
                break;
            case Right:
                paddle.xVelocity += PADDLE_SPEED;
                break;
            case Start:
                if (!isStarted)
                {
                    ball.velocityX = BALL_SPEED_X / 4.0;
                    ball.velocityY = (BALL_SPEED_Y - 1) / 4.0;
                    isStarted = true;
                }
                break;
        }
        // clear input
        input = None;
    }


    // This Block will surround the current ball coordinate X/Y updates
    if (isStarted)
    {
        // adjust the location of the ball for speed * time
        ball.coordinateX += ball.velocityX * delta;
        ball.coordinateY += ball.velocityY * delta;
    }
    else
    {
        ball.coordinateX = paddle.generalBlock.leftSide +(paddle.generalBlock.widthOfBlock / 2.0);
        ball.coordinateY = paddle.generalBlock.topSide - ball.radius - 1;
    }


    // adjust the location of the paddle using the X and Y coordinates
    paddle.generalBlock.leftSide += paddle.xVelocity * delta;


    gameOver = doCollisionChecks(ball, paddle, bricks, border);


    return gameOver;


} // end update


/**
 * draw the ball on the graphics window
 * @param window - handle to open graphics window
 * @param ball   - structure variable with properties for the ball to be rendered
 * @param delta  - amount of frame time plus lag (in ms)
 * @param border - structure variable with properties for the border to be rendered
 * @param paddle - structure variable with properties for the paddle to be rendered
 */
void render(sf::RenderWindow &window, Ball &ball, float delta, Border border, Moving_Block paddle,
            Brick bricks[BRICK_ROWS][BRICK_COLUMNS]) {
    // Render drawing objects
    // ------------------------------------------------

    // clear the window with the background color
    window.clear(WINDOW_COLOR);


    // draw the border
    //-------------------------------------------------
    window.draw(border.leftBlock.blockShape);
    window.draw(border.topBlock.blockShape);
    window.draw(border.rightBlock.blockShape);
    window.draw(border.bottomBlock.blockShape);

    // draw the paddle
    // ------------------------------------------------
    paddle.generalBlock.blockShape.setPosition(sf::Vector2f(paddle.generalBlock.leftSide,
                                                            paddle.generalBlock.topSide));

    window.draw(paddle.generalBlock.blockShape);

    // draw the ball
    // ------------------------------------------------
    sf::CircleShape circle;
    circle.setFillColor(BALL_COLOR);
    circle.setRadius(ball.radius);
    // set screen coordinates relative to the center of the circle
    circle.setOrigin(ball.radius, ball.radius);
    // calculate current drawing location relative to speed and frame-time
    float xPosition = ball.coordinateX + ball.velocityX * delta;
    float yPosition = ball.coordinateY + ball.velocityY * delta;
    circle.setPosition(xPosition, yPosition);
    window.draw(circle);

    // draw bricks
    // -----------------------------------------------
    Brick *pBrick = &bricks[0][0];
    for (int row = 0; row < BRICK_ROWS; row++)
    {
        for (int column = 0; column < BRICK_COLUMNS; column++)
        {
            if(!pBrick->hit)
            {
                window.draw(pBrick->block.blockShape);
            }
            pBrick++;
        } // columns
    } // rows



    // show the new window
    // ------------------------------------------------
    window.display();
} // end render


/**
 * Run all collision detections to perform logic when triggered.
 * @param ball - referencing the game ball
 * @param paddle - will return back true if paddle has touched any left/right border
 * @param bricks - tiles that will dissapear when collision is deteched by ball
 * @param borders - checks collisions with the ball to determine logic
 * @return gameOver - determines if the game is over.
 */
bool doCollisionChecks(Ball &ball, Moving_Block& paddle, Brick bricks[BRICK_ROWS][BRICK_COLUMNS], Border borders)
{
    bool gameOver = false;

    // -----Check Collision between Top and Bottom Borders -----
    if(!checkCollision(&ball, &paddle.generalBlock))
    {

        // If it's not the Top Border than it's the bottom border
        if(!checkCollision(&ball, &borders.topBlock))
        {
            // Return game over if the bottom border was collided.
            gameOver = checkCollision(&ball, &borders.bottomBlock);
        }
    }

    // -----Check Collision between the ball and the Left and Right Borders -----
    if(!checkCollision(&ball, &borders.leftBlock))
    {
        checkCollision(&ball, &borders.rightBlock);
    }


    // ------- Check collision between the paddle and the left and right Borders --------
    if(checkBlockCollision(&paddle.generalBlock,&borders.leftBlock))
    {
        paddle.xVelocity = 0.0;
        paddle.generalBlock.leftSide = borders.leftBlock.leftSide + borders.leftBlock.widthOfBlock + 1.0;
    }
    else if(checkBlockCollision(&paddle.generalBlock, &borders.rightBlock))
    {
        paddle.xVelocity = 0.0;
        paddle.generalBlock.leftSide = borders.rightBlock.leftSide - paddle.generalBlock.widthOfBlock - 1.0;
    }


    // ----- TILE SPAWN ---------
    Brick *pBrick = &bricks[0][0];
    for(int row = 0; row < BRICK_ROWS; row++)
    {
        for(int column = 0; column < BRICK_COLUMNS; column++)
        {
            if(!pBrick->hit)
            {
                pBrick->hit = checkCollision(&ball,&pBrick->block);
            }
            pBrick++;

        } // columns

    } // rows


    return gameOver;

} // doCollisionChecks

/**
 * get the collision point between a ball and a block
 * @param pBall - ball with coordinates and radius
 * @param pBlock - block with coordinates and size
 * @return int - cardinal heading between 1 and 360 ( 0 if no collision was made)
 */
int getCollision(Ball *pBall, Block *pBlock) {

    // determines the value of what the function returns between 1 and 360
    int cardinalHeading = 0;

    // variables that will hold the values to help check the balls position
    float checkPointX, checkPointY;

    // simplified version of the distance between the right and bottom side of the block
    float rightOfWall = pBlock->leftSide + pBlock->widthOfBlock;
    float belowTheWall = pBlock->topSide + pBlock->heightOfBlock;


    // compares the center of the ball from the distance of each side of the wall on the X-coordinate
    if(pBall->coordinateX < pBlock->leftSide)
    {
        checkPointX = pBlock->leftSide;
    }
    else if(pBall->coordinateX > rightOfWall)
    {
        checkPointX = rightOfWall;
    }
    else
    {
        checkPointX = pBall->coordinateX;
    }

    // compares the center of the ball from the distance of each side of the wall on the Y-coordinate
    if(pBall->coordinateY < pBlock->topSide)
    {
        checkPointY = pBlock->topSide;
    }
    else if(pBall->coordinateY > belowTheWall)
    {
        checkPointY = belowTheWall;
    }
    else
    {
        checkPointY = pBall->coordinateY;
    }


    float differenceOfX = checkPointX - pBall->coordinateX;
    float differenceOfY = (WINDOW_HEIGHT - checkPointY) - (WINDOW_HEIGHT - pBall->coordinateY);

    // using a function created from a previous library to calculate the distance of the ball.
    double distance = sqrt(pow(differenceOfX, 2.0) + pow(differenceOfY, 2.0));


    if(distance <= pBall->radius) {
        double theta = atan2(differenceOfY, differenceOfX);

        double degrees = 90.0 - theta * 180 / M_PI;

        if(degrees <= 0)
        {
            degrees = degrees + 360.0;
        }

        cardinalHeading = int(degrees);

    }


    return cardinalHeading;

} // end getCollision
/**
 * check to see if there was a collision using previous function
 * @param pBall - ball with coordinates and radius
 * @param pBlock - block with coordinates and size
 * @return collision value, true or false.
 */
bool checkCollision(Ball* pBall, Block* pBlock)
{

    bool isCollided = false;

    int getCollided = getCollision(pBall, pBlock);

    // Handle the logic if a collision is detected based on the return value from getCollision
    if(getCollided)
    {
        isCollided = true;


        // ---- checks for horizontal collision ----
        if((getCollided > 225) && (getCollided < 315))
        {
            pBall->velocityX = pBall->velocityX * -1;
            pBall->coordinateX = pBlock->leftSide + pBlock->widthOfBlock + pBall->radius + 1;
        }
        else if((getCollided > 45) && (getCollided < 135))
        {
            pBall->velocityX = pBall->velocityX * -1;
            pBall->coordinateX = pBlock->leftSide - pBall->radius - 1;
        }

        // ---- checks for vertical collision ----
        if((getCollided >= 315) || (getCollided <= 45))
        {
            pBall->velocityY = pBall->velocityY * -1;
            pBall->coordinateY = pBlock->topSide + pBlock->heightOfBlock + pBall->radius + 1;
        }

        else if((getCollided >= 135) && (getCollided <= 225))
        {
            pBall->velocityY = pBall->velocityY * -1;
            pBall->coordinateY = pBlock->topSide - pBall->radius - 1;
        }

    }

    return isCollided;

} // end checkCollision

/**
 * check to see if there was a collision using previous function
 * @param pMovingBlock - use to point to the value of "Paddle"
 * @param pStationaryBlock - use to point to the value of a particular "Border"
 * @return collision value, true or false.
 */
bool checkBlockCollision(Block* pMovingBlock, Block* pStationaryBlock)
{
    bool collision = false;


    // If either the left or right border makes contact with the paddle, collision is set to true.
    if (pMovingBlock->leftSide < pStationaryBlock->leftSide + pStationaryBlock->widthOfBlock &&
        pMovingBlock->leftSide + pMovingBlock->widthOfBlock > pStationaryBlock->leftSide &&
        pMovingBlock->topSide < pStationaryBlock->topSide + pStationaryBlock->heightOfBlock &&
        pMovingBlock->topSide + pMovingBlock->heightOfBlock > pStationaryBlock->topSide)
    {
        collision = true;
    }



    return collision;
}

