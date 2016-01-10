http://www.spoj.com/problems/ACANVAS/
http://www.spoj.com/problems/BANDW/
http://www.spoj.com/problems/CIRCUITS/
http://www.spoj.com/problems/DONOTHIN/
http://www.spoj.com/problems/EQUI/
http://www.spoj.com/problems/FBRIDGES/
http://www.spoj.com/problems/GETFAST/
http://www.spoj.com/problems/HEISLAZY/
http://www.spoj.com/problems/IMPER/
http://www.spoj.com/problems/JOCTENIS/

////////////////////////////////////////////////////////////////////////

Problema A:



////////////////////////////////////////////////////////////////////////

Problema B:

básicamente hay que contar cuántos intervalos de distintos hay entre la cadena dada y la que se quiere lograr. 

////////////////////////////////////////////////////////////////////////

Problema C:



////////////////////////////////////////////////////////////////////////

Problema D: 



////////////////////////////////////////////////////////////////////////

Problema E: 


////////////////////////////////////////////////////////////////////////

Problema F:



////////////////////////////////////////////////////////////////////////

Problema G:



////////////////////////////////////////////////////////////////////////

Problema H: 

se modela como un grafo. Hay un nodo por cada catapulta (el punto inicial y final son dos catapultas con fuerza 0). La distancia de ir desde una catapulta a otra es una cuenta usando la distancia entre los puntos de las mismas y las fuerzas. Se calcula la distancia para cada par de catapultas en el grafo, y luego el problema es encontrar un camino mínimo desde el punto inicial al final. Se puede calcular con Floyd (como mucho hay 100 nodos). 

////////////////////////////////////////////////////////////////////////

Problema I: 

hay que notar que el grafo dado es siempre un árbol. Luego el problema se reduce a encontrar el diámetro del grafo. Como es un árbol, el díametro puede calcularse corriendo 2 BFS (el primero desde cualquier nodo, y el segundo desde el nodo más lejano del primero). Luego el díametro será la distancia más lejana obtenida en el segundo BFS. Finalmente lo que hay que devolver es el díametro/2 (techo). 

////////////////////////////////////////////////////////////////////////

Problema J:



////////////////////////////////////////////////////////////////////////
