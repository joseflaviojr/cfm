
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

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <fstream>

using namespace std;

int  CFM( int** matrizadj, int total, ofstream* saida );
long Custo( int** matrizadj, int total );
void Permutar( int** matriz, int* ordem, int total, int a, int b );
void ImprimirResultado( int* ordem, int total, ostream* saida );
inline double Sortear( int limiteNaoIncluso );
