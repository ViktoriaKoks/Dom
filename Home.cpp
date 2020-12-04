#include <iostream>
#include <memory>

#include <SDL2/SDL_main.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
constexpr int WIDTH = 1000, HEIGHT = 720, R = 25;

std::shared_ptr<SDL_Texture> icon;
std::shared_ptr<SDL_Texture> icon2;
std::shared_ptr<SDL_Texture> Make_icon(SDL_Renderer *renderer, const char *name)
{

	std::shared_ptr<SDL_Texture> picture = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(renderer, name),
			SDL_DestroyTexture);
	if(picture == nullptr)
	{
		std::cerr << "Не могу загрузить картинку" <<
		SDL_GetError()<<std::endl;
		return nullptr;
	}
	return picture;
}
void DrawCircle(SDL_Renderer * ren, int x, int y, int r, int X, int Y)
{
            int delta = 1 - 2 * r;
            int error = 0;
            SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);

            while(y >= 0)
            {
                SDL_RenderDrawPoint(ren, X + x, Y + y);
                SDL_RenderDrawPoint(ren, X + x, Y - y);
                SDL_RenderDrawPoint(ren, X - x, Y + y);
                SDL_RenderDrawPoint(ren, X - x, Y - y);
                error = 2 * (delta + y) - 1;
                if (delta < 0 and error <= 0)
                {
                    ++x;
                    delta += 2 * x + 1;
                    continue;
                }
                if (delta > 0 and error > 0)
                {
                    --y;
                    delta -= 2 * y + 1;
                    continue;
                }
                ++x;
                --y;
                delta += 2 * (x - y);
            }
}
int main(int, char **)
{
    std::cout << "Начало работы программы" << std::endl;
    SDL_Init(SDL_INIT_EVERYTHING);
    auto win = std::shared_ptr<SDL_Window>(
            SDL_CreateWindow("My_Home",
                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                    WIDTH, HEIGHT,
                    SDL_WINDOW_SHOWN),
            SDL_DestroyWindow);
    if (win == nullptr) {
        std::cerr << "Ошибка при создании окна: " <<
                SDL_GetError() << std::endl;
        return 1;
    }
    auto ren = std::shared_ptr<SDL_Renderer>(
            SDL_CreateRenderer(win.get(), -1,
                    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC),
            SDL_DestroyRenderer);
    if (ren == nullptr) {
        std::cerr << "Ошибка при создании рендерера: " <<
                SDL_GetError() << std::endl;
        return 1;
    }
	bool f = true;
	int icon_x = 100, icon_y = 60;
	bool f2 = true;
	int icon_x2 = 500, icon_y2 = 450;

	auto keys = SDL_GetKeyboardState(nullptr);

    SDL_Event event;
    bool finish = false;
    while (not finish)
    {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                finish = true;
        }

        SDL_SetRenderDrawColor(ren.get(), 89, 199, 240, 1);
        SDL_RenderClear(ren.get());

        SDL_Rect r { 0, 300, WIDTH, 450 };
        SDL_SetRenderDrawColor(ren.get(), 102, 209, 21, 1);
        SDL_RenderFillRect(ren.get(), &r);

        for (int i = 0; i < WIDTH; i += 80) {
        	SDL_SetRenderDrawColor(ren.get(), 84, 54, 54, 1);
            SDL_Rect r1 { i, 250, 40, 250 };
            SDL_RenderFillRect(ren.get(), &r1);
            SDL_Rect r2 { i + 10, 310, 100, 10 };
            SDL_RenderFillRect(ren.get(), &r2);
            SDL_Rect r3 { i + 10, 420, 100, 10 };
                      SDL_RenderFillRect(ren.get(), &r3);
             }

        SDL_Rect r1 { WIDTH / 2 - 0, 200, 430, 380 };
        SDL_SetRenderDrawColor(ren.get(), 176, 110, 25, 1);
        SDL_RenderFillRect(ren.get(), &r1);

        SDL_Rect r2 { WIDTH / 2 + 260, 200 + 200, 100, 100 };
        SDL_SetRenderDrawColor(ren.get(), 172, 252, 246, 1);
        SDL_RenderFillRect(ren.get(), &r2);

        SDL_SetRenderDrawColor(ren.get(), 107, 75, 26, 1);
        SDL_RenderDrawLine(ren.get(), WIDTH / 2 + 310, 400, WIDTH / 2 + 310, 500);

        SDL_SetRenderDrawColor(ren.get(), 107, 75, 26, 1);
        SDL_RenderDrawLine(ren.get(), WIDTH / 2 + 260, 450, WIDTH / 2 + 360, 450);

        SDL_Rect r22 { WIDTH / 2 + 260, 200 + 50, 100, 100 };
        SDL_SetRenderDrawColor(ren.get(), 172, 252, 246, 1);
        SDL_RenderFillRect(ren.get(), &r22);

        SDL_SetRenderDrawColor(ren.get(), 107, 75, 26, 1);
        SDL_RenderDrawLine(ren.get(), WIDTH / 2 + 310, 250, WIDTH / 2 + 310, 350);

        SDL_SetRenderDrawColor(ren.get(), 107, 75, 26, 1);
        SDL_RenderDrawLine(ren.get(), WIDTH / 2 + 260, 300, WIDTH / 2 + 360, 300);

        SDL_Rect r222 { WIDTH / 2 + 60, 200 + 50, 100, 100 };
        SDL_SetRenderDrawColor(ren.get(), 172, 252, 246, 1);
        SDL_RenderFillRect(ren.get(), &r222);

        SDL_SetRenderDrawColor(ren.get(), 107, 75, 26, 1);
        SDL_RenderDrawLine(ren.get(), WIDTH / 2 + 110, 250, WIDTH / 2 + 110, 350);

        SDL_SetRenderDrawColor(ren.get(), 107, 75, 26, 1);
        SDL_RenderDrawLine(ren.get(), WIDTH / 2 + 60, 300, WIDTH / 2 +160, 300);

        SDL_Rect r4 { WIDTH / 2 + 50, 110, 60, 60 };
        SDL_SetRenderDrawColor(ren.get(), 176, 110, 25, 1);
        SDL_RenderFillRect(ren.get(), &r4);

        SDL_SetRenderDrawColor(ren.get(), 74, 5, 5, 1);
        for (double x1 = WIDTH / 2 + 215, x2 =WIDTH / 2 + 215,  y = 100; y < 200; x1 -= 2.40, x2 += 2.40, y++) {
            SDL_RenderDrawLine(ren.get(), x1, y, x2, y);
        }

        SDL_Rect r5 { WIDTH / 2 + 70 , 440, 85, 140 };
        SDL_SetRenderDrawColor(ren.get(), 74, 5, 5, 1);
        SDL_RenderFillRect(ren.get(), &r5);

        SDL_SetRenderDrawColor(ren.get(), 71, 150, 18, 1);
        for(int i = 0; i <= 25; i += 25)
            for (int x = 5 + i,  y1 = HEIGHT - i, y2 = HEIGHT - (i+50) ; x < WIDTH - 5; x +=50 )
                SDL_RenderDrawLine(ren.get(), x, y1, x, y2);
        SDL_SetRenderDrawColor(ren.get(), 71, 150, 18, 1);
        for(int i = 0; i <= 25; i += 25)
             for (int x = 0 + i,  y1 = HEIGHT - i, y2 = HEIGHT - (i+50) ; x < WIDTH - 0; x +=50 )
                 SDL_RenderDrawLine(ren.get(), x, y1, x, y2);

        DrawCircle(ren.get(), 0, R, R, WIDTH / 2 + 215, 150);

		if (f)
			icon = Make_icon(ren.get(), "tor2.png");
		else
			icon = Make_icon(ren.get(), "tor.png");

		if(keys[SDL_SCANCODE_RIGHT] and icon_x < WIDTH - 100){ icon_x += 8; f = true;}
		if(keys[SDL_SCANCODE_LEFT] and icon_x > 0 ){ icon_x -= 8; f = false;}
		if(keys[SDL_SCANCODE_UP] and icon_y > 0){ icon_y -= 8; }
		if(keys[SDL_SCANCODE_DOWN] and icon_y < HEIGHT - 50){ icon_y += 8; }

		if(icon == nullptr) return 1;
		SDL_Rect icon_rect {icon_x, icon_y, 200, 200};
		SDL_RenderCopy(ren.get(), icon.get(), nullptr, &icon_rect);

		if(icon_x2 < WIDTH - 150 and f2){
			icon2 = Make_icon(ren.get(), "muravey2.png");
			icon_x2 += 2;
		}
		else f2 = false;
		if(icon_x2 > 0 and !f2){
			icon2 = Make_icon(ren.get(), "muravey.png");
			icon_x2 -= 2;
		}
		else f2 = true;

		if(icon2 == nullptr) return 1;
		SDL_Rect icon_rect2 {icon_x2, icon_y2, 100, 200};
		SDL_RenderCopy(ren.get(), icon2.get(), nullptr, &icon_rect2);

        SDL_RenderPresent(ren.get());
        }
        std::cout << "Конец работы программы" << std::endl;
        return 0;
}
