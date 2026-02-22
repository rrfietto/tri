#include <raylib.h>
#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "EnemySquare.h"

#define WIDTH 796
#define HEIGHT 560

int main()
{
    InitWindow(WIDTH, HEIGHT, "tri");

    Player p((Vector2){200, 200});
    EnemySquare e(20, 20, (Vector2){400, 400});

    while (!WindowShouldClose())
    {
        p.computeMovement();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            p.attack();
        }
        ClearBackground(BLACK);
        BeginDrawing();
        e.renderEntity();
        int k = 0;
        for (Bullet *b : p.playerBullets)
        {
            b->moveAndRender();
            if (CheckCollisionRecs(b->getRec(), e.getRec()))
            {
                std::cout << "collide\n";
                p.playerBullets.erase(p.playerBullets.begin() + k);
                delete b;
            }
            k++;
        }
        p.renderEntity();
        EndDrawing();
    }

    return 0;
}
