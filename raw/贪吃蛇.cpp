#include <iostream>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <chrono>
#define Wide 10
#define Length 10
#define Speed 10
//SDL_Surface *screen=NULL;				12.4计划使用SDL2的createwindow
SDL_Event event;
class she                //蛇
{
	private:
		int headx;
		int heady;
		int vx;
		int vy;
		int length;			//蛇长度
	public:
		she();
		void change();
		void move();
		void grow();		   //吃了fruit则length++
		void check();       //判断碰撞	12.4计划使用SDL2碰撞检测函数SDL_HasIntersection
};
class timer                  //计时器    12.4计划更改为使用std::chrono模板 具体见cppreference
{
	private:
		int starttime;
		int pausetime;
	public:
		void start();
		void pause();
		int gettime();
};
int init()
{
	if(SDL_Init(SDL_INIT_EVERYTHING)==-1) return -1;
	if(TTF_Init()==-1) return -1;
	/*screen=SDL_SetVideoMode(640,320,32,SDL_SWSURFACE);
	if(screen==NULL) return -1;
	SDL_WM_SetCaption("贪吃蛇");*/
	SDL_CreatWindow("贪吃蛇",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,320,0);
	if(window==NULL) return -1;
	screen = SDL_GetWindowSurface(window);				//刷新为SDL_UpdateWindowSurface(window)
	return 1;
};
void quit()
{
	SDL_DestoryWindow(window);
	TTF_Quit();
	SDL_Quit();
};
SDL_Surface *loadimage(char* filename)			//12.4计划将surface转到render
{
	SDL_Surface *loadimage=NULL;
	SDL_Surface *opimage=NULL;
	loadimage=IMG_Load(filename);
	opimage=SDL_DispalyFormat(loadimage);
	SDL_FreeSurface(loadimage);
	return opimage;
};
int main(int argc,char* argc[])
{
	if(init()==-1)
	{
		std::cout<<"初始化失败";
		return 0;
	}
	
	return 0;
}
she::she()
{
	hendx=320;
	heady=160;
	length=4;
	SDL_Rect head;
	SDL_Rect body[length];
	head.x=headx;
	head.y=heady;
	head.width=Wide;
	head.height=Length;
}
void she::move()
{
	
}
