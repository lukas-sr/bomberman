#pragma once

#include <iostream>

class Model{
	private:
		float m,b,k;
	
	public: 
		void set_parametros(float new_m, float new_b, float new_k);
	
};

class View{
	public:
		float a;
};

class Controller{
	private:
	
	public:
		float solve(Model M, float t, float T, float delta, float new_m, float new_b, float new_k, float *x_new, float *x_old, float *vx);
	};

