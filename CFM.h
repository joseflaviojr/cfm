
/*
 *  Copyright (C) 2015 José Flávio de Souza Dias Júnior
 *  
 *  This file is part of Cost Function Method (CFM).
 *  <https://github.com/joseflaviojr/cfm>
 *  
 *  CFM was designed by José Luiz Rybarczyk-Filho.
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
 *  Direitos Autorais Reservados (C) 2015 José Flávio de Souza Dias Júnior
 *  
 *  Este arquivo é parte de Cost Function Method (CFM).
 *  <https://github.com/joseflaviojr/cfm>
 *  
 *  CFM foi projetado por José Luiz Rybarczyk-Filho.
 *  
 *  CFM é software livre: você pode redistribuí-lo e/ou modificá-lo
 *  sob os termos da Licença Pública Menos Geral GNU conforme publicada pela
 *  Free Software Foundation, tanto a versão 3 da Licença, como
 *  (a seu critério) qualquer versão posterior.
 *  
 *  CFM é distribuído na expectativa de que seja útil,
 *  porém, SEM NENHUMA GARANTIA; nem mesmo a garantia implícita de
 *  COMERCIABILIDADE ou ADEQUAÇÃO A UMA FINALIDADE ESPECÍFICA. Consulte a
 *  Licença Pública Menos Geral do GNU para mais detalhes.
 *  
 *  Você deve ter recebido uma cópia da Licença Pública Menos Geral do GNU
 *  junto com CFM. Se não, veja <http://www.gnu.org/licenses/>.
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
