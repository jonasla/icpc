
void rotar (vector<string> &origi) // Rota una matriz de (n X n) 90° en sentido horario. (se puede cambiar vector<string> por vector<vector<tint> > a piacere)
{
	tint n = origi.size();
	string aux (n,'x');
	vector<string> rotado (n,aux);
	forn(i,n)
	forn(j,n)
		rotado[j][n-i-1] = origi[i][j];
	origi = rotado;
}

// EJEMPLO DE LO QUE NO HAY QUE HACER PARA ROTAR (FUNCIONA, PERO ES MAS COMPLICADO AL PEPE (VA ROTANDO POR CAPAS))
//
//void rotar (vector<string> &origi) // Rota una matriz de (n X n) 90° en sentido horario.
//{
//	tint n = origi.size();
//	string aux (n,'x');
//	vector<string> rotado (n,aux);
//	tint comienzo = 0, fin = n-1;
//	while (comienzo <= fin)
//	{
//		forsn(i,comienzo,fin+1)
//		{
//			rotado[i][fin] = origi[comienzo][i];
//			rotado[fin][fin - i + comienzo] = origi[i][fin];
//			rotado[fin - i + comienzo][comienzo] = origi[fin][fin-i + comienzo];
//			rotado[comienzo][i] = origi[fin-i+comienzo][comienzo];
//		}
//		comienzo++;
//		fin--;
//	}
//	origi = rotado;
//}
