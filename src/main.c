#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <LinkedList.h>

#define FPS 20

#define RANDOM(start, stop) ((rand() % (stop - start)) + start)

#define GRID_SIZE 32
#define GRID_WIDTH 25

const int SCREEN_WIDTH = GRID_SIZE * GRID_WIDTH;
const int SCREEN_HEIGHT = GRID_SIZE * GRID_WIDTH;

void DrawNode(Node *node)
{
    DrawRectangle(GRID_WIDTH * node->x, GRID_WIDTH * node->y, GRID_WIDTH, GRID_WIDTH, BLACK);
}

/// @brief Used to check if the head has intersected with the body.
/// @return
bool nodeInBody(Node *element, Node *node)
{
    return (element->x == node->x) && (element->y == node->y);
}

void placeApple(LinkedList *list, Node *apple)
{
    do
    {
        apple->x = RANDOM(0, GRID_SIZE);
        apple->y = RANDOM(0, GRID_SIZE);
    } while (anyLinkedList(list, apple, nodeInBody));
}

void resetGame(LinkedList *list, Node *apple, int *keyPressed)
{
    clearLinkedList(list);
    insertTail(list, newNode(GRID_SIZE / 2, GRID_SIZE / 2));
    placeApple(list, apple);
    *keyPressed = RANDOM(262, 266);
}

int main()
{
    time_t t;
    srand((unsigned int)time(&t));
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake");
    SetTargetFPS(FPS);

    unsigned long frameCounter = 0;

    LinkedList *list = newLinkedList();
    Node *apple = newNode(0, 0);
    int keyPressed;

    resetGame(list, apple, &keyPressed);

    bool gameOver = false;
    bool showGrid = true;

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_UP) && keyPressed != KEY_DOWN)
        {
            keyPressed = KEY_UP;
        }
        else if (IsKeyDown(KEY_DOWN) && keyPressed != KEY_UP)
        {
            keyPressed = KEY_DOWN;
        }
        else if (IsKeyDown(KEY_LEFT) && keyPressed != KEY_RIGHT)
        {
            keyPressed = KEY_LEFT;
        }
        else if (IsKeyDown(KEY_RIGHT) && keyPressed != KEY_LEFT)
        {
            keyPressed = KEY_RIGHT;
        }

        if (gameOver && IsKeyDown(KEY_P))
        {
            resetGame(list, apple, &keyPressed);
            gameOver = false;
        }

        if (IsKeyPressed(KEY_G))
        {
            showGrid = !showGrid;
        }

        if (frameCounter % 8 == 0 && !gameOver)
        {
            Node *head = getHead(list);
            Node *tail = removeTail(list);
            if (keyPressed == KEY_UP || keyPressed == KEY_DOWN)
            {
                tail->y = head->y + ((keyPressed == KEY_UP) ? -1 : 1);
                if (tail->y < 0)
                {
                    tail->y += GRID_SIZE;
                }
                tail->y %= GRID_SIZE;
                tail->x = head->x;
            }
            else if (keyPressed == KEY_LEFT || keyPressed == KEY_RIGHT)
            {
                tail->x = head->x + ((keyPressed == KEY_LEFT) ? -1 : 1);
                if (tail->x < 0)
                {
                    tail->x += GRID_SIZE;
                }
                tail->x %= GRID_SIZE;
                tail->y = head->y;
            }
            // Check if the head has enetered the body.
            if (anyLinkedList(list, tail, nodeInBody))
            {
                gameOver = true;
            }

            insertHead(list, tail);

            // Check if the apple is eaten.
            if (anyLinkedList(list, apple, nodeInBody))
            {
                placeApple(list, apple);
                insertTail(list, newNode(getTail(list)->x, getTail(list)->y));
            }
        }

        BeginDrawing();
        ClearBackground(WHITE);
        if (showGrid)
        {
            for (int w = 0; w < GRID_SIZE; w++)
            {
                DrawLine(0, w * GRID_WIDTH, SCREEN_WIDTH, w * GRID_WIDTH, BLACK);
            }
            for (int h = 0; h < GRID_SIZE; h++)
            {
                DrawLine(h * GRID_WIDTH, 0, h * GRID_WIDTH, SCREEN_HEIGHT, BLACK);
            }
        }
        forEachLinkedList(list, DrawNode);
        DrawRectangle(GRID_WIDTH * apple->x, GRID_WIDTH * apple->y, GRID_WIDTH, GRID_WIDTH, RED);

        if (gameOver)
        {
            DrawText("GAME OVER!", SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, 64, BLACK);
        }

        EndDrawing();

        frameCounter++;
    }

    deleteLinkedList(list);
    free(apple);

    CloseWindow();
}