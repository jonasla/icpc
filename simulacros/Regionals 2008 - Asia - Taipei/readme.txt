https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=322

////////////////////////////////////////////////////////////////////////


4259: Dangerous Tunnels

Descripción: Uno comienzo en un nodo de salida y para llegar a un nodo de 
llegada puede pasar por nodos intermedios. Para moverse entre nodos hay 
aristas que indican el peso. Se define como peso de una camino de la salida 
hasta la llegada como la arista más pesada del camino. Dado un conjunto de 
caminos sin nodos en común (salvo la salida y la llegada) se defino el peso 
de ese conjunto como el mayor peso de los caminos que contiene.
 En la entrada viene un número k, hay que decidir si existen k caminos sin 
nodos en común, y en caso de existir, devolver el peso del menor conjunto de 
k caminos que van de la salida a la llegada.

Resolución: Próximamente (?).

////////////////////////////////////////////////////////////////////////

4260: Fortune Card Game

Descripción Te definen un juego de cartas, donde cada carta tiene un número 
y un símbolo, junto con un número que indica el número que debe tener la próxima 
carta a ser jugada. Además viene en la entrada un hechizo, que es un string, 
donde cada caracter es el símbolo de una carta. Uno comienza con un maso de 
cartas dado en el número 1, la idea es formar el hechizo utilizando símbolos 
de las cartas. Al jugar una carta, uno suma a un contador global el número que 
debe tener la próxima jugada. Hay que devolver el mayor puntaje que uno puede obtener.

Resolución: La idea es usar programación dinámica. Para ello uno debe notar 
que cuando uno juega una carta, el resto del juego no importa en lo que jugó 
antes de jugar dicha carta. Los distintos estados posibles están dados por 
la última carta en ser jugada y la posición del hechizo en la que uno se encuentra. 
La primer jugada es obligada, luego uno puede ir explorando los distintos estados 
posibles actualizando en cada estado el mayor valor con el que uno lo puede alcanzar. 


////////////////////////////////////////////////////////////////////////

4261: Trip Planning

Descripción: Uno comienza en el hotel 0, y debe llegar al hotel n+1. Nos 
dicen que la distancia entre el hotel i e i+1 está dada por a_i. Uno quiere 
viajar una distancia lo más cercana a 100 kilómetros por día, por eso se 
define a la penalidad de un día como (x-100)^2, donde x es la distancia recorrida 
en un día. Hay que calcular en qué hoteles debemos descansar si queremos minimizar 
la penalidad total (suma de las penalidades por día). 

Resolución: La diea es usar programación dinámica. Para ello uno debe notar que 
cuando uno descansa en un hotel, lo que haga a partir del día siguiente no depende 
del lo realizado en los días anteriores. Supongamos que sabemos movernos de manera 
óptima a todos los hoteles desde 0...k. Entonces, la forma óptima de movernos al 
k+1-ésimo hotel está dada por el mínimo para i de 0 k de: 
(penalidad óptima hasta el i-ésimo hotel + penalidad de ir del i-ésimo hotel al k+1).
Así podemos ir generando iterativamente la solución hasta llegar al n+1-ésimo hotel.



////////////////////////////////////////////////////////////////////////

4262: Road Networks

Descripción: El enunciado nos describe lo que es un componente fuertemente conexa 
y, dado un grafo dirigido, nos pide calcular la cantidad de componentes 
fuertemente conexas que posee dicho grafo.

Resolución: Implementar el algoritmo de Kosaraju que calcula componentes de 
un grafo dirigido.



////////////////////////////////////////////////////////////////////////

4263: Early Morning Pickup

Descripción: Otro día.

Resolución: Otro día posterior al de la descripción.


////////////////////////////////////////////////////////////////////////

4264: Message

Descripción: Te dan n+m imágenes (matrices de 0's y 1's de 10x10). Primero 
te dan m imágenes y el caracter que representan. Después te dan n imágenes con 
posible ruido (algunos píxeles cambiados) y te piden devolver a qué caracter 
de los primeros n se parece más (en casod empate dar el primero que nos dieron 
como input). Además estas n imágenes pueden estar rotadas.

Resolución: Implementar exactamente lo que pide el enunciado. Primero cargamos 
las m imágenes y las asociamos con su caracter, y después para cada una de las 
4 posibles rotaciones de las n imágenes comparamos con cuál de los primeras m 
imágenes se parece más (comparando píxel por píxel).





////////////////////////////////////////////////////////////////////////

4265: Lost Treasure

Descripción: Otro día (es el del Tetris)

Resolución:



////////////////////////////////////////////////////////////////////////

4266: Space Elevator

Descripción: 



////////////////////////////////////////////////////////////////////////

4267: Finding the Heaviest Path

Descripción: Te dan un árbol enraizado. Además, cada nodo tiene su peso. Con 
esos pesos, se puede calcular el peso de un subárbol. Nos definen, cómo a partir 
de los pesos de todos los subárboles construir un camino. Dado el árbol con los 
pesos de los nodos hay que construir el camino (y la suma de los pesos del cammino).

Resolución: El peso del subárbol que tiene como raíz una hoja coincide con el 
peso de dicha hoja. Luego, con una recorrida de DFS podemos computar todos los 
pesos de los subárboles (notar que al recorrer con DFS, al regresar a un nodo ya 
visitamos a todos sus hijos). Teniendo ésto, hay que implementar según el enunciado 
cómo construir el camino pedido.



////////////////////////////////////////////////////////////////////////

4268: Bonus Adjustment

Descripción: Te dan una matriz de n por m. En cada casilla hay un número racional 
con dos cifras decimales. Hay que decidir si es posible construir una matriz del 
mismo tamaño con coeficientes enteros, y donde cada coeficiente de la nueva matriz es 
techo o piso del coeficiente original.

Resolución: Primero que nada observamos que si la suma de las filas y la suma de las 
columnas son todas enteras, entonces existe una solución. Luego generamos la matriz 
que tiene como coeficientes techo de los coeficientes de la matriz original. Luego 
solo queda elegir en qué coeficientes debíamos tomar piso en lugar de techo, lo cual genera 
una diferencia de 1 en la fila y columna de la casilla. Por lo tanto, para cada fila y para cada 
columna hay que ubicar tantos pisos como la diferencia entre la suma actual de la fila/columna 
y la suma original de cada fila/columna. Esto podemos pensarlo como un problema de flujo. Consideremos 
"m" nodos por fila y "n" nodos por columna. Lo que hacemos es construir un nodo fuente (digamos "s") y 
sacamos una arista a un nodo por fila con capacidad igual a la diferencia entre la suma actual y la 
original de la fila. Luego, unimos a cada nodo de fila con todos los nodos de las columnas con capacidad 
igual a 1. Por último creamos un nodo terminal (digamos "t") y a todos los nodos de las columnas los 
unimos con "t" con capacidad igual a la diferencia entre la suma de columnas actual y la original. 
Finalmente, calculamos el flujo máximo que podemos mandar en la red, y si al obtener el máximo flujo nos 
qeuda que pasa flujo por la arista que uno al nodo "i" de las filas con el nodo "j" de las columnas 
entonces debíamos tomar piso en vez de techo en la matriz original. Notar que nos devuelve una 
solución posible, pero podría haber muchas. Además hay que tener en cuenta que si originalmente 
en la matriz había un número entero, entonces este no debe ser modificado.



////////////////////////////////////////////////////////////////////////
