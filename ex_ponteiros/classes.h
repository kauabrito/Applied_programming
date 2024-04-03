 #include <iostream>
 using namespace std;

class veiculo
{
    public:
    int velocidade;
    int blindagem;
    int rodas;

    private:
    int tipo;
    int velocidadeMaxima;
    bool arma;

};

class Moto:public veiculo //public significa a forma com que eu posso acessar 
{
    public:
    Moto();
};

Moto :: Moto(){
    velocidade = 0;
    blindagem = 0;
    rodas = 2;
}