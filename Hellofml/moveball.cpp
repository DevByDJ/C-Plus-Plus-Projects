/* --------------------------------------------------------
 *    File: moveball.cpp
 *  Author: Danny Joseph
 *   Class: Programming Methodology COP 2001
 * Purpose: make the ball move
 * -------------------------------------------------------- */

#include <SFML/Graphics.hpp>

// Global Constants
// --------------------------------------------------------

// window properties
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const sf::Color WINDOW_COLOR = sf::Color::Black;

// drawing properties
const float FRAME_RATE = (1.0/30.0) * 1000.0;       // FPS in ms
const sf::Color BALL_COLOR = sf::Color::Red;

// These are just for fun
// speed that the can accelerate at to span window in
// n-seconds (in ms) broken up for each frame
const float SPEED_TIME = (3.0 * 1000.0) * 30.0;     //
const float SPEED_X = WINDOW_WIDTH / SPEED_TIME;    // speed horizontally
const float SPEED_Y = WINDOW_HEIGHT / SPEED_TIME;   // span  vertically

// wall properties
const float WALL_THICKNESS = 10.0;
const sf::Color WALL_COLOR = sf::Color::Blue;

// Type definitions
// --------------------------------------------------------

// <direction enum here>
enum Direction{
    Exit = -1,
    None,
    Left,
    Up,
    Right,
    Down
};

// ball properties
struct Ball {
    // <define structure properties here>
    float radius;
    float coordinateX;
    float coordinateY;
    float velocityX;
    float velocityY;
    sf::Color color;
};

// wall properties
struct Wall {
    float leftSide;
    float topSide;
    float widthOfWall;
    float heightOfWall;
    sf::Color wallColor;
    sf::RectangleShape wallShape;
};

// border properties
struct Border {
    Wall leftWall;
    Wall topWall;
    Wall rightWall;
    Wall bottomWall;
};

// Function declarations (prototypes)
// --------------------------------------------------------
Direction processInput() ;
void update(Direction &input, Ball &ball, float delta);
void render(sf::RenderWindow &window, Ball &ball, float delta, Border border);



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
    // <initialize the ball structure properties here>
    theBall.radius = 10.0;
    theBall.coordinateX = WINDOW_WIDTH / 2.0;
    theBall.coordinateY = WINDOW_HEIGHT / 2.0;
    theBall.velocityX = 0.0;
    theBall.velocityY = 0.0;
    theBall.color = BALL_COLOR;

    // timing variables for the main game loop
    sf::Clock clock;
    sf::Time startTime = clock.getElapsedTime();
    sf::Time stopTime = startTime;
    float delta = 0.0;

    // Border variable
    Border theBorders;

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

            update(userInput, theBall, delta);

            // subtract the frame-rate from the current frame-time
            // for each full frame covered by this update
            while (delta >= FRAME_RATE)
                delta -= FRAME_RATE;
        }

        // Render the window
        // ------------------------------------------------
        render(window, theBall, delta, theBorders);

    } // end main game loop

    // game ending, close the graphics window
    window.close();

    return 0;   // return success to the OS
} // end main


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
    return None;
} // end getUserInput


/**
 * update the state of game objects
 * @param input - user keyboard input
 * @param ball  - update ball position and speed
 * @param delta - current frame time
 */
void update(Direction &input, Ball &ball, float delta) {

    // adjust velocity directions for user input
    if (input) {
        switch (input) {
            case Left: // Left
                //<ball's velocityX here>
                ball.velocityX -= SPEED_X;
                break;
            case Up: // Up
                //<ball's velocityY here>
                ball.velocityY -= SPEED_Y;
                break;
            case Right: // Right
                //<ball's velocityX here>
                ball.velocityX += SPEED_X;
                break;
            case Down: // Down
                //<ball's velocityY here>
                ball.velocityY += SPEED_Y;
                break;
        }
        // clear input
        input = None;
    }

    // adjust the location of the ball for speed * time
    //<ball's cooridnateX here>
    ball.coordinateX += ball.velocityX * delta;
    //<ball's cooridnateY here>
    ball.coordinateY += ball.velocityY * delta;
} // end update


/**
 * draw the ball on the graphics window
 * @param window - handle to open graphics window
 * @param ball   - structure variable with properties for the ball
 * @param delta  - amount of frame time plus lag (in ms)
 */
void render(sf::RenderWindow &window, Ball &ball, float delta, Border border) {
    // Render drawing objects
    // ------------------------------------------------
    // clear the window with the background color
    window.clear(WINDOW_COLOR);

    // draw the border
    //-------------------------------------------------
    Border newBorder;

    // left wall properties
    // initialize the left and top side values
    newBorder.leftWall.leftSide = 0.0;
    newBorder.leftWall.topSide = 0.0;
    // set the size of the wall based on const variables, WALL THICKNESS and WINDOW HEIGHT
    newBorder.leftWall.heightOfWall = WALL_THICKNESS;
    newBorder.leftWall.widthOfWall = WINDOW_WIDTH;
    newBorder.leftWall.wallShape.setSize(sf::Vector2f(newBorder.leftWall.widthOfWall,
                                                      newBorder.leftWall.heightOfWall));
    // set position of left wall within the window using left and top side values.
    newBorder.leftWall.wallShape.setPosition(sf::Vector2f(newBorder.leftWall.leftSide,
                                                          newBorder.leftWall.topSide));
    // set the color of the wall to the constant value, WALL_COLOR
    newBorder.leftWall.wallShape.setFillColor(WALL_COLOR);
    window.draw(newBorder.leftWall.wallShape);

    // top wall properties
    // initialize the left and top side values
    newBorder.topWall.leftSide = 0.0;
    newBorder.topWall.topSide = 0.0;
    // set the size of the wall based on const variables, WALL THICKNESS and WINDOW HEIGHT
    newBorder.topWall.heightOfWall = WINDOW_HEIGHT;
    newBorder.topWall.widthOfWall = WALL_THICKNESS;
    newBorder.topWall.wallShape.setSize(sf::Vector2f(newBorder.topWall.widthOfWall,
                                                     newBorder.topWall.heightOfWall));
    // set position of left wall within the window using left and top side values.
    newBorder.topWall.wallShape.setPosition(sf::Vector2f(newBorder.topWall.leftSide,
                                                         newBorder.topWall.topSide));
    // set the color of the wall to the constant value, WALL_COLOR
    newBorder.topWall.wallShape.setFillColor(WALL_COLOR);
    window.draw(newBorder.topWall.wallShape);

    // right wall properties
    // initialize the left and top side values
    newBorder.rightWall.leftSide = WINDOW_WIDTH - WALL_THICKNESS;
    newBorder.rightWall.topSide = 0.0;
    // set the size of the wall based on const variables, WALL THICKNESS and WINDOW HEIGHT
    newBorder.rightWall.heightOfWall = WINDOW_HEIGHT;
    newBorder.rightWall.widthOfWall = WALL_THICKNESS;
    newBorder.rightWall.wallShape.setSize(sf::Vector2f(newBorder.rightWall.widthOfWall,
                                                       newBorder.rightWall.heightOfWall));
    // set position of left wall within the window using left and top side values.
    newBorder.rightWall.wallShape.setPosition(sf::Vector2f(newBorder.rightWall.leftSide,
                                                           newBorder.rightWall.topSide));
    // set the color of the wall to the constant value, WALL_COLOR
    newBorder.rightWall.wallShape.setFillColor(WALL_COLOR);
    window.draw(newBorder.rightWall.wallShape);

    // bottom wall properties
    // initialize the left and top side values
    newBorder.bottomWall.leftSide = 0.0;
    newBorder.bottomWall.topSide = WINDOW_HEIGHT - WALL_THICKNESS;
    // set the size of the wall based on const variables, WALL THICKNESS and WINDOW HEIGHT
    newBorder.bottomWall.heightOfWall = WALL_THICKNESS;
    newBorder.bottomWall.widthOfWall = WINDOW_WIDTH;
    newBorder.bottomWall.wallShape.setSize(sf::Vector2f(newBorder.bottomWall.widthOfWall,
                                                        newBorder.bottomWall.heightOfWall));
    // set position of left wall within the window using left and top side values.
    newBorder.bottomWall.wallShape.setPosition(sf::Vector2f(newBorder.bottomWall.leftSide,
                                                            newBorder.bottomWall.topSide));
    // set the color of the wall to the constant value, WALL_COLOR
    newBorder.bottomWall.wallShape.setFillColor(WALL_COLOR);
    window.draw(newBorder.bottomWall.wallShape);



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


    // show the new window
    // ------------------------------------------------
    window.display();
} // end render