#pragma once

#include <iostream>

const int MAX_I = 16;
const int MAX_J = 16;
const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 512;
const int SECOES_X = SCREEN_WIDTH/MAX_I;
const int SECOES_Y = SCREEN_HEIGHT/MAX_J;

class ModelMapp{
	public:
		int terreno[MAX_I][MAX_J];
		void mapp_terrain();
};

class ModelPersonagem{
	public: 
    // posição x e y no mapa
		int posicao[2];
    // inicializa  personagem no mapa
		void set_personagem(ModelMapp &M);
};

class ControllerPersonagem{
	public:
		int posicao[2];
		void move(ModelMapp &M, ModelPersonagem &P, int x, int y);
};

class ViewerPersonagem{
  		public:
			ViewerPersonagem(ModelMapp &M, ModelPersonagem &P, ControllerPersonagem &C, bool rodando);
};