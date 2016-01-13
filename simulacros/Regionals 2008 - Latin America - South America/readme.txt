https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=330

////////////////////////////////////////////////////////////////////////


4210: Almost Shortest Path

Descripción: Te dan un grafo dirigido con N (2<= N <= 500) vértices y M 
(1 <= M <= 10^4) aristas con peso, y dos vértices distinguidos S (salida)
 y D (destino). El problema pide calcular el camino más corto de S a D que
 no utilicen aristas que estén en algún camino mínimo de S a D.
 
Resolución:



////////////////////////////////////////////////////////////////////////

4211: Bases

Descripción: Te dan una igualdad de dos expresiones y hay que decidir para
qué bases de numeración la relación es válida.

Resolución:



////////////////////////////////////////////////////////////////////////

4212: Candy

Descripción: Te dan un tablero de M x N (1 <= M x N <= 10^5) que en cada
casilla tiene un cantidad de caramelos menor o igual que 10^3. Uno tiene 
como única operación válida elegir una casilla, agarrar la cantidad de 
caramelos de esa casilla, sumarla al total, y quitar los caramelos de la
fila anterior y posterior, junto con las dos casillas adyacentes a 
izquierda y derecha de la casilla seleccionada. El problema pide calcular
la mayor cantidad de caramelos que se pueden recolectar aplicando
sucesivamente la operación descrita.

Resolución: Primero resolvemos el problema para cada fila. Al elegir una
casilla, uno no puede elegir ninguna adyacente. Para resolver cada fila
se utiliza programación dinámica. Luego de resolver cada fila de manera
óptima nos queda el problema de elegir filas que no sean adyacentes que 
sumen la mayor cantidad posible. Nuevamente basta resolver el mismo
problema con programación dinámica sobre el vector con la solución de cada
fila.





////////////////////////////////////////////////////////////////////////

4213: DNA Sequences

Descripción: Te dan dos strings en minúscula de largo a lo sumo 10^3 y hay 
que calcular la mayor subsecuencia común, pero con la salvedad de que la 
subsecuencia está formada por substrings disjuntos de largo como mínimo 
K (1 <= K <= 100).

Resolución:



////////////////////////////////////////////////////////////////////////

4214: Electricity Bills

Descripción: Te dan N (1 <= N <= 10^3) fechas ordenadas en orden cronológico,
y además cada fecha viene acompañada con un número que identifica el consumo 
eléctrico acumulado. El problema pide dar la cantidad total de consumo 
eléctrico de los días en los que se puede calcular con certeza el consumo.

Resolución: Como te dan el consumo acumulado, uno solo puede saber el consumo
de un día con certeza si se conoce el consumo acumulado en un día y en el 
siguiente, en ese caso el consumo es la diferencia de consumo acumulado 
en ambos días. Por lo tanto el problema se resume a leer las fechas, y
cuando aparecen dos consecutivas sumar a un acumulador la diferencia 
de consumo acumulado entre ambos días.





////////////////////////////////////////////////////////////////////////

4215: Feynman

Descripción: Te dan una grilla cuadrada de N x N (1 <= N <= 100) y te 
piden calcular la cantidad de cuadrados en total que hay en la grilla.

Resolución: Podemos particionar a todos los cuadrados que hay en el tablero
según el largo de su lado. Por lo tanto basta calcular la cantidad de
cuadrados con lado 1, lado 2, lado 3, ... , lado N. Para 1 <= k <= N fijo, 
la cantidad de cuadrados de largo k en un tablero de N x N es: (N-k+1)^2



////////////////////////////////////////////////////////////////////////

4216: Pole Position

Descripción: Inicialmente hay N autos (2 <= N <= 10^3). En el orden actual 
de la carrera el número de identificación del auto C (1 <= C <= 10^4) y 
P (-10^6 <= P <= 10^6) la posición relativa respecto de la posición inicial 
de dicho auto. De ser posible hay que reconstruir la configuración inicial, 
y, si esto no es posible hay que imprimir -1.

Resolución: Para cada auto, vamos a calcular su posición inicial. Esto lo 
hacemos sumando P a la posición actual (notar que P puede ser negativo).
Para que este número sea válido debe estar entre 1 y N inclusive (o 0 y N-1 
según cómo indexamos), y además no pueden coincidir dos autos en una misma
posición de salida. Podemos ir guardando en un vector las posiciones iniciales 
de salida, y al agregar cada auto verificamos si cumple lo pedido. Si algún
auto no cumple lo pedido, devolvemos -1, y si todos cumplen imprimimos el 
orden pedido.



////////////////////////////////////////////////////////////////////////

4217: Higgs Boson

Descripción: Te describen la trayectoria de dos partículas en coordenadas 
polares, donde tanto el radio como el ángulo son una función lineal del tiempo.
El problema pide devolver como fracción irreducible el menor tiempo para el 
que las trayectorias de las partículas coincide, o "0 0" (sin comillas) 
si las partículas no coinciden en ningún momento.

Resolución:



////////////////////////////////////////////////////////////////////////

4218: Traveling Shoemaker Problem

Descripción: Te dan N ciudades (1 <= N <= 500), cada ciudad pertenece 
exactamente a una o dos de las C (1 <= C <= 100) confederaciones distintas.
Podemos pensar a las confederaciones como colores. Inicialmente 
uno puede elegir la ciudad donde comienza y uno de los colores de la ciudad.
Una vez elegida la ciudad y el color, solo se puede mover a una ciudad que 
tenga el mismo color. Si la ciudad donde uno arriba tiene otro color además 
del nuestro, nuestro color cambia por este último, sino se mantiene igual.
El problema pide decidir si es posible visitar todas las ciudades exactamente 
una vez haciendo las operaciones descritas.

Resolución:



////////////////////////////////////////////////////////////////////////

4219: Bora Bora

Descripción: Se describe un juego de cartas. Inicialmente hay P (1 <= P <= 10) 
jugadores distintos y se les reparten M cartas (1 <= M <= 11) de una maso que
contiene N cartas (3 <= N <= 300). Te dan en orden las N cartas, te garantizan 
que la cantidad de cartas que te dan alcanzan para discernir un ganador, 
y te piden calcular cuál es el ganador.

Resolución: Implementación de las reglas del juego (bastante largas y tediosas,
se parecen al UNO).





////////////////////////////////////////////////////////////////////////

4220: Shrinking Polygons

Descripción: Te dan N (3 <= N <= 10^4) vértices de un polígono inscripto 
en una circunferencia y las N distancias de arco entre vértices consecutivos 
(notar que es un arreglo circular), que cada una está entre 1 y 1000.
Hay que decidir la menor cantidad de vértices que se pueden remover, para que 
con los vértices restantes se forme un polígono regular. En caso de no ser 
posible formar un polígono regular removiendo vértices hay que imprimir -1.

Resolución: Lo primero que hay que notar es que la suma de los arcos dados 
permanece invariante al remover un vértice. Luego, si el polígono que se 
forma al final tiene q lados de largo l, tenemos que sumaArcos = q*l, de 
donde se deduce que q divide a sumaArcos. Además, q <= n, entonces podemos 
iterar desde q = n hasta que q sea menor que 3, y si q divide a suma debemos 
testear si es posible armar un polígono de largo l = sumaArcos/q.
Para hacer este testeo lo que hacemos es calcular las sumas parciales de todos 
los arcos módulo l y contar las ocurrencias de cada resto. Si existe un resto que 
aparece más de q veces, entonces se puede, sino no.





////////////////////////////////////////////////////////////////////////
