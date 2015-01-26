
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

void CSV_Arquivo( ifstream* origem, int** destino, int largura );
int  CSV_Largura( ifstream* origem );

/* Exemplo de aplica��o do CFM */
int main( int argc, char *argv[] ) {

	const char *nomeArquivoAdjac = argv[1];
	const char *nomeArquivoOrdem = strcat( strcpy( (char*)malloc(256), nomeArquivoAdjac ), ".ordem" );
	
	ifstream entrada ( nomeArquivoAdjac );
	ofstream saida   ( nomeArquivoOrdem, ofstream::trunc );

	const int total = CSV_Largura( &entrada );

	int **matrizadj = new int*[total];
	for( int i = 0; i < total; i++ ) matrizadj[i] = new int[total];

	CSV_Arquivo( &entrada, matrizadj, total );
	entrada.close();

	return CFM( matrizadj, total, &saida );

}

/* Arquivo de entrada no formato CSV */
void CSV_Arquivo( ifstream* origem, int** destino, int largura ) {
	
	char numero[50], c;
	int d = 0, i = 0, j = 0, v;

	while( ! (*origem).eof() ){

		c = (*origem).get();

		switch( c ){
			case ',' :
			case ';' :
			case '|' :
			case ' ' :
			case '\t' :
			case '\n' :
				numero[d++] = '\0';
				v = strtol( numero, NULL, 10 );
				destino[i][j] = v;
				j++;
				d = 0;
				break;
			case '"' :
			case '\'' :
			case '\r' :
				break;
			default :
				numero[d++] = c;
				break;
		}

		if( j == largura ){
			i++;
			j = 0;
		}

	}

	if( d > 0 && j > 0 && j < largura ){
		numero[d++] = '\0';
		v = strtol( numero, NULL, 10 );
		destino[i][j] = v;
	}

}

/* Ordem da Matriz de Adjac�ncia */
int CSV_Largura( ifstream* origem ){
	int total = 1;
	char c;
	while( ! (*origem).eof() ){
		c = (*origem).get();
		if( c == '\n' ) break;
		if( c == ',' || c == ';' || c == '|' || c == ' ' || c == '\t' ) total++;
	}
	(*origem).seekg( 0, (*origem).beg );
	return total;
}
