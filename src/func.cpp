#include <iostream>
#include <math.h>
#include "func.h"

void Model::set_parametros(float new_m, float new_b, float new_k){

	m = new_m;
	b = new_b;
	k = new_k;
};


float Controller::solve(Model M, float t, float T, float delta, float new_m, float new_b, float new_k, float *x_new, float *x_old, float *vx){

	float w, alpha, ww = new_k/new_m; 
	
	w = sqrt(ww);
	alpha = new_b/(new_m*2*w);
	float x, vx_new; // variaveis auxiliares
	
	M.set_parametros(new_m,new_b,new_k);
	// Atualiza a variavel auxiliar x antes de rodar o método	
	x = (*vx)*delta + (*x_old);
	//Novos valores de posição e velocidade
	*x_new = (x*(-ww*delta*delta +2) + (*x_old)*(alpha*delta*w -1))/(1 + delta*alpha*w);
	vx_new = ((*x_new)-(*x_old))/(2*delta);
	//Atualiza ponteiros	
	*x_old = x;
	x = (*x_new);
	*vx = vx_new;

	printf("%f %f\n", *x_new, *vx);
	return *x_new;
}

