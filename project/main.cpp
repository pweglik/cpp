#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <math.h>

// Screen dimension constants
const int SCREEN_SIZE= 900;

const int CELL_PIXEL_SIZE = 30;

const int N = floor(SCREEN_SIZE / CELL_PIXEL_SIZE);

bool init();

bool loadMedia();

void close();

SDL_Surface *loadSurface(std::string path);

SDL_Window *gWindow = NULL;

SDL_Surface *gScreenSurface = NULL;

SDL_Surface *gAliveSurface = NULL;

SDL_Surface *gDeadSurface = NULL;

bool init()
{
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        // Create window
        gWindow = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_SIZE, SCREEN_SIZE, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            // Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags))
            {
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                success = false;
            }
            else
            {
                // Get window surface
                gScreenSurface = SDL_GetWindowSurface(gWindow);
            }
        }
    }

    return success;
}

bool loadMedia()
{
    bool success = true;

    gAliveSurface = loadSurface("img/alive.png");
    if (gAliveSurface == NULL)
    {
        printf("Failed to load PNG image!\n");
        success = false;
    }

    gDeadSurface = loadSurface("img/dead.png");
    if (gDeadSurface == NULL)
    {
        printf("Failed to load PNG image!\n");
        success = false;
    }

    return success;
}

void close()
{
    SDL_FreeSurface(gAliveSurface);
    gAliveSurface = NULL;

    SDL_FreeSurface(gDeadSurface);
    gDeadSurface = NULL;

    // Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

SDL_Surface *loadSurface(std::string path)
{
    // The final optimized image
    SDL_Surface *optimizedSurface = NULL;

    // Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        // Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
        if (optimizedSurface == NULL)
        {
            printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return optimizedSurface;
}

int countAliveNeighbours(bool ** board, int i, int j)
{
    int result = 0;
    if (i >= 1 && j >= 1 && board[i - 1][j - 1] == true)
        result++;
    if (i >= 1 && board[i - 1][j] == true)
        result++;
    if (i >= 1 && j <= N - 2 && board[i - 1][j + 1] == true)
        result++;
    if (j <= N - 2 && board[i][j + 1] == true)
        result++;
    if (i <= N - 2 && j <= N - 2 && board[i + 1][j + 1] == true)
        result++;
    if (i <= N - 2 && board[i + 1][j] == true)
        result++;
    if (i <= N - 2 && j >= 1 && board[i + 1][j - 1] == true)
        result++;
    if (j >= 1 && board[i][j - 1] == true)
        result++;

    return result;
}

void processBoard(bool **board)
{
    bool lBoard[30][30];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int aliveNeighbours = countAliveNeighbours(board,i , j);

            if(board[i][j] == false && aliveNeighbours == 3)
                lBoard[i][j] = true;
            else if(board[i][j] == true && (aliveNeighbours == 3 || aliveNeighbours == 2))
                lBoard[i][j] = true;
            else
                lBoard[i][j] = false;
            
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = lBoard[i][j];
        }
    }
}

void drawBoard(bool ** board)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            SDL_Rect target_rect;
            target_rect.x = j * CELL_PIXEL_SIZE;
            target_rect.y = i * CELL_PIXEL_SIZE;
            target_rect.w = CELL_PIXEL_SIZE;
            target_rect.h = CELL_PIXEL_SIZE;

            if (board[i][j] == true)
            {
                SDL_BlitSurface(gAliveSurface, NULL, gScreenSurface, &target_rect);
            }
            else
            {
                SDL_BlitSurface(gDeadSurface, NULL, gScreenSurface, &target_rect);
            }
        }
    }
    
    SDL_UpdateWindowSurface(gWindow);
}

void handleMouse( SDL_Event* e , bool ** board)
{
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		int x, y;
		SDL_GetMouseState( &x, &y );
        switch( e->type )
        {
            case SDL_MOUSEBUTTONDOWN:
                int i = floor(y / CELL_PIXEL_SIZE);
                int j = floor(x / CELL_PIXEL_SIZE);
                printf("%d %d\n", i, j);
                board[i][j] = !board[i][j];
                drawBoard(board);
                break;
        }
		
	}
}

int main(int argc, char *args[])
{
    // Start up SDL and create window
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        // Load media
        if (!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            bool** gBoard = new bool*[N];
            for(int i = 0; i < N; ++i)
                gBoard[i] = new bool[N];

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    gBoard[i][j] = false;
                }
            }

            // example
            gBoard[3][4] = true;
            gBoard[3][5] = true;
            gBoard[3][6] = true;
            gBoard[2][6] = true;
            gBoard[1][5] = true;

            // Main loop flag
            bool quit = false;

            bool pause = true;

            // Event handler
            SDL_Event e;

            // While application is running
            while (!quit)
            {
                // Handle events on queue
                while (SDL_PollEvent(&e) != 0)
                {
                    // User requests quit
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                    else if( e.type == SDL_KEYDOWN )
					{
						//Select surfaces based on key press
						switch( e.key.keysym.sym )
						{
							case SDLK_SPACE:
							pause = !pause;
							break;
						}
                    }

                    if(pause)
                        handleMouse(&e, gBoard);
                }

                if(!pause)
                {
                    // main app loop
                    processBoard(gBoard);
                    drawBoard(gBoard);

                    SDL_Delay(200);
                }
            }

            // free board
            for(int i = 0; i < N; ++i)
                delete[] gBoard[i];
            delete[] gBoard;
        }
    }

    // Free resources and close SDL
    close();

    

    return 0;
}