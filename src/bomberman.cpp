
#include <iostream>

//sugestão de convenção para nome das classes e métodos "MVCClasse"
class ModelMapp{
	private:


	public:
		int terreno[16][16];
		void mapp_terrain();
};


void ModelMapp::mapp_terrain(){

	int i,j;

	for(i=0;i<16;i++){
		for(j=0;j<16;j++)
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
	
	if(xini>15)
                xini = 15;
        if(yini>15)
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
       	

int main(){
	ModelMapp M;
	ModelPersonagem P1;
	ControllerPersonagem C1;
	M.mapp_terrain();
	
	int i,j;
	
	/*for (i=0;i<16;i++){
		for(j=0;j<16;j++)
			std::cout << M.terreno[i][j];
		std::cout << "\n";
		}*/
		
	P1.set_personagem(M);
	
	for (i=0;i<16;i++){
		for(j=0;j<16;j++)
			std::cout << M.terreno[i][j];
		std::cout << "\n";
		}
	std::cout <<"("<< P1.posicao[0]<<"," << P1.posicao[1] <<")" << "\n";
	
	C1.move(M,P1);	
	
	for (i=0;i<16;i++){
		for(j=0;j<16;j++)
			std::cout << M.terreno[i][j];
		std::cout << "\n";
		}
	std::cout <<"("<< P1.posicao[0]<<"," << P1.posicao[1] <<")" << "\n";

	return 0;
	
}

