http://www.spoj.com/problems/TAP2015A/
http://www.spoj.com/problems/TAP2015B/
http://www.spoj.com/problems/TAP2015C/
http://www.spoj.com/problems/TAP2015D/
http://www.spoj.com/problems/TAP2015E/
http://www.spoj.com/problems/TAP2015F/
http://www.spoj.com/problems/TAP2015G/
http://www.spoj.com/problems/TAP2015H/
http://www.spoj.com/problems/TAP2015I/
http://www.spoj.com/problems/TAP2015J/
http://www.spoj.com/problems/TAP2015K/

////////////////////////////////////////////////////////////////////////

Problema A: 



////////////////////////////////////////////////////////////////////////

Problema B:



////////////////////////////////////////////////////////////////////////

Problema C: 



////////////////////////////////////////////////////////////////////////

Problema D: 



////////////////////////////////////////////////////////////////////////

Problema E: 



////////////////////////////////////////////////////////////////////////

Problema F: 

Descripción: 
Hay un reino con N ciudades (2 <= N <= 5x10^5). Las ciudades están conectadas entre sí, 
de manera que existe un único camino entre cada par de ciudades. 
El rey quiere instaurar el curling como deporte nacional, y para eso quiere asignar 
a cada ciudad un equipo de curling. Hay algunas ciudades que ya tienen un equipo asignado y no 
puede cambiarse, y otras ciudades que no. 
Hay C (1 <= C <= 50) equipos disponibles para asignar a las ciudades, y para cada par de equipos se 
conoce el índice de disturbios entre los dos equipos. Si dos ciudades son vecinas y 
tienen equipos i y j, se agrega al índice de disturbios nacional D_{i,j}. 
Se quiere asignar equipos a todas las ciudades de manera de minimizar el índice de disturbios nacional. 
El índice nacional es la suma de los disturbios producidos entre cada par de ciudades vecinas. 

Resolución: 
Sabemos que las ciudades forman un árbol, dado que hay un único camino entre cada par de ciudades. 
Podemos resolver el problema con una dinámica en el árbol (es un problema muy similar al 3472 "Optical Fiber" 
de la Regional 2005 LaTam South). 
Para esto, corremos un DFS desde cualquier nodo (no importa desde cual). Lo queremos calcular para cada nodo es 
el índice total hasta ese nodo si se usa el equipo i. De modo que nuestra dinámica es de NxC (nodos por equipos). 
Si un nodo es una hoja en el DFS, entonces usar cualquier equipo tiene respuesta 0. 
Si no, usamos los que sean hijos de dicho nodo en el DFS para calcular la respuesta. En este caso, calculamos la respuesta 
para cada equipo posible. Fijado el equipo en un nodo, para cada hijo hay que obtener el equipo del hijo 
que produce menos disturbios. Así, la respuesta es la suma de estos mínimos. Hay que tener cuidado únicamente 
con las ciudades que tienen equipo fijo además. 

////////////////////////////////////////////////////////////////////////

Problema G: 



////////////////////////////////////////////////////////////////////////

Problema H: 



////////////////////////////////////////////////////////////////////////

Problema I: 



////////////////////////////////////////////////////////////////////////

Problema J: 



////////////////////////////////////////////////////////////////////////

Problema K: 



////////////////////////////////////////////////////////////////////////
