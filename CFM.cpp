
/*
 *  Copyright (C) 2015 Jos� Fl�vio de Souza Dias J�nior
 *  
 *  This file is part of Cost Function Method (CFM).
 *  <https://github.com/joseflaviojr/cfm>
 *  
 *  CFM was designed by Jos� Luiz Rybarczyk-Filho.
 *  
 *  CFM is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  CFM is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *  
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with CFM. If not, see <http://www.gnu.org/licenses/>.
 */

/*
 *  Direitos Autorais Reservados (C) 2015 Jos� Fl�vio de Souza Dias J�nior
 *  
 *  Este arquivo � parte de Cost Function Method (CFM).
 *  <https://github.com/joseflaviojr/cfm>
 *  
 *  CFM foi projetado por Jos� Luiz Rybarczyk-Filho.
 *  
 *  CFM � software livre: voc� pode redistribu�-lo e/ou modific�-lo
 *  sob os termos da Licen�a P�blica Menos Geral GNU conforme publicada pela
 *  Free Software Foundation, tanto a vers�o 3 da Licen�a, como
 *  (a seu crit�rio) qualquer vers�o posterior.
 *  
 *  CFM � distribu�do na expectativa de que seja �til,
 *  por�m, SEM NENHUMA GARANTIA; nem mesmo a garantia impl�cita de
 *  COMERCIABILIDADE ou ADEQUA��O A UMA FINALIDADE ESPEC�FICA. Consulte a
 *  Licen�a P�blica Menos Geral do GNU para mais detalhes.
 *  
 *  Voc� deve ter recebido uma c�pia da Licen�a P�blica Menos Geral do GNU
 *  junto com CFM. Se n�o, veja <http://www.gnu.org/licenses/>.
 */

#include "CFM.h"

/*
 *  Cost Function Method - CFM
 *
 *  Original:
 *    Rybarczyk-Filho, J. L. L., Castro, M. A., Dalmolin, R. J., Moreira, J. C.,
 *        Brunnet, L. G., and de Almeida, R. M. (2011).
 *        Towards a genome-wide transcriptogram: the Saccharomyces cerevisiae case.
 *        Nucleic acids research, 39(8):3005�3016.
 */
int CFM( int** matrizadj, int total, ofstream* saida ) {

	// Inicializa��o

	int ordem[total];
	int ordem_melhor[total];
	for( int i = 0; i < total; i++ ) ordem[i] = ordem_melhor[i] = i;

	long custo, custo_novo, custo_melhor;
	custo = Custo( matrizadj, ordem, total );
	custo_melhor = custo;

	double temperatura = 0.0001 * custo;
	double temperatura_reducao = 0.8;
	int temperatura_passos = 100;

	// Monte Carlo

	int passo = 1, sorteio = 0;
	int s1, s2;

	while( custo_melhor > 0 ){

		if( ++sorteio > total ){
			passo++;
			if( ( passo % temperatura_passos ) == 0 ) temperatura *= temperatura_reducao;
			sorteio = 1;
		}

		s1 = Sortear(total);
		s2 = Sortear(total);

		Permutar( ordem, total, s1, s2 );

		custo_novo = Custo( matrizadj, ordem, total );

		if( custo_novo < custo || Sortear(1) <= exp((custo-custo_novo)/temperatura) ){
			
			custo = custo_novo;

			if( custo < custo_melhor ){

				custo_melhor = custo;
				memcpy( ordem_melhor, ordem, total * sizeof(int) );
				
				saida->seekp( 0, saida->beg );
				ImprimirResultado( ordem, total, saida );
				saida->flush();

			}

		}else{
			Permutar( ordem, total, s1, s2 );
		}

	}

	return 0;

}

/* Fun��o Custo do CFM */
long Custo( int** matrizadj, int* ordem, int total ) {

	long custo = 0;

	const int ultimo = total - 1;
	int i, j, valor;

	for( i = 0; i < total; i++ ){
		for( j = 0; j < total; j++ ){
			if( i == j ) continue;
			valor = 0;
			if( matrizadj[ordem[i]][ordem[j]] ){
				if( i != ultimo ) valor += 1 - matrizadj[ordem[i+1]][ordem[j  ]];
				if( j != ultimo ) valor += 1 - matrizadj[ordem[i  ]][ordem[j+1]];
				if( i != 0 )      valor += 1 - matrizadj[ordem[i-1]][ordem[j  ]];
				if( j != 0 )      valor += 1 - matrizadj[ordem[i  ]][ordem[j-1]];
			}else{
				if( i != ultimo ) valor += matrizadj[ordem[i+1]][ordem[j  ]];
				if( j != ultimo ) valor += matrizadj[ordem[i  ]][ordem[j+1]];
				if( i != 0 )      valor += matrizadj[ordem[i-1]][ordem[j  ]];
				if( j != 0 )      valor += matrizadj[ordem[i  ]][ordem[j-1]];
			}
			custo += abs(i-j) * valor;
		}
	}

	return custo;

}

/* Permuta��o */
void Permutar( int* ordem, int total, int a, int b ) {
	int x = ordem[a];
	ordem[a] = ordem[b];
	ordem[b] = x;
}

/* Impress�o de Resultado */
void ImprimirResultado( int* ordem, int total, ostream* saida ) {
	*saida << ordem[0] + 1;
	for( int i = 1; i < total; i++ ) *saida << ',' << ordem[i] + 1;
}

/* Sorteio */
inline double Sortear( int limiteNaoIncluso ) {
	return ( ( rand() % 100 ) / 100.0 ) * limiteNaoIncluso;
}
