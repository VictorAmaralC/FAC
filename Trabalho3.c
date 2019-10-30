#include <stdio.h>

double validas (double X, double E);
double encontaInteiros(double X, double limiteSup);
double calcRaiz(double E);
void erroRaiz(double X);
void imprimeSaida(double X, double saida, double interacoes);
double calcResultado(double interacoes, double limiteInf, double limiteSup, double limite, double X);

int main(){
    double X, E; //entradas
    double saida, interacoes = 1; //saidas
    double limiteInf, limiteSup, limite, aux = 0; //auxiliares

    scanf("%lf %lf", &X, &E);
    aux = validas (X, E);
    if (aux != 0){
        return 0;
    }else{
        limiteSup = encontraInteiros(X);
        limiteInf = limiteSup-1;
        limite = calcRaiz(E);
        limiteSup = X / limiteInf;
        interacoes = calcResultado(interacoes, limiteInf, limiteSup, limite, X);
    }

    return 0;
}

double validas(double X, double E){
    int aux;
    if (X < 2 || E < 1){
        printf("Entradas invalidas.\n");
        return aux = 1;
    }
    return 0;
}

double encontraInteiros(double X){
    int i=0;
    while ((i*i) < X) {
        i++;
    }
    return i;
}

double calcRaiz(double E){
    int i = 0, A = 1;
    while (i < E){
        A /= 10;
    }
    return A;
}

void erroRaiz(double X){
    printf("Nao foi possivel calular a sqrt(%lf).\n", X);
}
void imprimeSaida(double X, double saida, double interacoes){
    printf("A raiz quadrada de %lf eh %lf, calculada em %lf interacoes.\n", X, saida, interacoes);
}

double calcResultado(double interacoes, double limiteInf, double limiteSup, double limite, double X){
    printf("oi\n");
    if(interacoes > 100){
        erroRaiz(X);
    }else if (limite > limiteInf){
        imprimeSaida(X, limiteInf, interacoes);
    }else{
        interacoes++;
        limiteInf = (limiteInf + limiteSup) / 2;
        limiteSup = X / limiteInf;
        calcResultado(interacoes, limiteInf, limiteSup, limite, X);
    }
    return interacoes;
}
