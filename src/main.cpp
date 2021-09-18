#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
//#include "func.h"

const int SCREEN_WIDTH = 760;
const int SCREEN_HEIGHT = 760;
const int MAX_I = 16;
const int MAX_J = 16;


class ModelMapp{
	private:


	public:
		int terreno[16][16];
		void mapp_terrain();
};


void ModelMapp::mapp_terrain(){

	int i,j;

	for(i=0;i<MAX_I;i++){
		for(j=0;j<MAX_J;j++)
			terreno[i][j] = 1; //1 codifica posição habilitada/disponivel
	}

}

class ModelPersonagem{
	private:

	public: 
		int posicao[2];
		void set_personagem(ModelMapp &M);// inicializa  personagem no mapa
};

void ModelPersonagem::set_personagem(ModelMapp &M){
	
	int xini, yini;
	std::cin>> xini;
	std::cin>> yini;
	
	if(xini>MAX_I-1)
    xini = 15;
  
  if(yini>MAX_J-1)
    yini = 15;        
	
	
	M.terreno[xini][yini] = 0;
	posicao[0] = xini;
	posicao[1] = yini;
}

class ControllerPersonagem{
	
	private:

	public:
		int posicao[2];
		void move(ModelMapp &M, ModelPersonagem &P);
};

void ControllerPersonagem::move(ModelMapp &M, ModelPersonagem &P){
	
	int x=0,y=0;
	std::cin>> x;
	std::cin>> y;
	//Preciso descobrir como ler as direções do teclado
	if(x>15)
                x = 15;
        if(y>15)
        	y = 15;        
	
	
	M.terreno[x][y] = 0; // No futuro podemos diferenciar posicoes ocupadas de posicoes proibidas
	M.terreno[P.posicao[0]][P.posicao[1]] = 1;
	
	P.posicao[0] = x;
	P.posicao[1] = y;
}

class ViewerPersonagem{
  private:

  public:
    ViewerPersonagem();
}

ViewerPersonagem::ViewerPersonagem(){
  // Inicializando o subsistema de video do SDL

  if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
    std::cout << SDL_GetError();
    return 1;
  }

  // Criando uma janela
  SDL_Window* window = nullptr;

  window = SDL_CreateWindow("BombermanRPG v0.01",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      SCREEN_WIDTH,
      SCREEN_HEIGHT,
      SDL_WINDOW_SHOWN);
  
  // Caso a janela não tiver sido setada corretamente
  if (window == nullptr) {
    std::cout << SDL_GetError();
    SDL_Quit();
    return 1;
  }

  // Inicializando o renderizador
  SDL_Renderer* renderer = SDL_CreateRenderer(
      window, -1,
      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  
  if (renderer == nullptr) { // Em caso de erro...
    SDL_DestroyWindow(window);
    std::cout << SDL_GetError();
    SDL_Quit();
    return 1;
  }

  // Carregando texturas
  // personagem
  SDL_Texture *personagem = IMG_LoadTexture(renderer, "./images/bomberman.png");
  // fundo
  SDL_Texture *tabuleiro = IMG_LoadTexture(renderer, "./images/tabuleiro.png");


  // Quadrado onde a textura sera desenhada
  SDL_Rect target;
  target.x = 100;
  target.y = 100;
  SDL_QueryTexture(personagem, nullptr, nullptr, &target.w, &target.h);

  // Controlador:
  bool rodando = true;

  // Variaveis para verificar eventos
  SDL_Event evento; // eventos discretos
  const Uint8* state = SDL_GetKeyboardState(nullptr); // estado do teclado

}

int main() {


  // Laco principal do jogo
  while(rodando) {
    // Polling de eventos
    SDL_PumpEvents(); // atualiza estado do teclado
      
    /* Capivara.cpp
    target.x = 50*C.solve(M,t,T,delta,m,b,k,x_new,x_old,vx);
    printf("targetX: %d\n", target.x);
    t = t+delta;
    */

    
    if (state[SDL_SCANCODE_LEFT]) target.x -= 1;
    if (state[SDL_SCANCODE_RIGHT]) target.x += 1;
    if (state[SDL_SCANCODE_UP]) target.y -= 1;
    if (state[SDL_SCANCODE_DOWN]) target.y += 1;

    while (SDL_PollEvent(&evento)) {
      if (evento.type == SDL_QUIT) {
        rodando = false;
      }
      // Exemplos de outros eventos.
      // Que outros eventos poderiamos ter e que sao uteis?
      //if (evento.type == SDL_KEYDOWN) {
      //}
      //if (evento.type == SDL_MOUSEBUTTONDOWN) {
      //}
    }

    // Desenhar a cena
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, tabuleiro, nullptr, nullptr);
    SDL_RenderCopy(renderer, personagem, nullptr, &target);
    SDL_RenderPresent(renderer);

    // Delay para diminuir o framerate
    SDL_Delay(10);
  }

  SDL_DestroyTexture(personagem);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
