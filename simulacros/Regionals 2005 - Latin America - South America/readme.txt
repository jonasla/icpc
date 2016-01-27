https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=227

////////////////////////////////////////////////////////////////////////


3468:



////////////////////////////////////////////////////////////////////////

3469:



////////////////////////////////////////////////////////////////////////

3470:



////////////////////////////////////////////////////////////////////////

3471:

Descripción: 
Hay T tareas (1 <= T <= 1000) y E empleados (1 <= E <= 1000). 
Las tareas pueden depender de otras tareas además, cada tarea tiene una paga básica, 
y la paga total por una tarea es su paga básica más las pagas totales de las tareas 
que dependen de ella. 
En cada tarea trabajan ciertos empleados (puede ser varios), y cada empleado además puede 
trabajar en distintas tareas. 
La paga de un empleado es la paga total de las tareas que realiza, tales que no sean dependientes 
de otras tareas que realice el mismo empleado. 
Se garantiza que no hay circularidad en cuanto a las dependencias de las tareas. 
Se pide calcular la paga para cada empleado. 

Resolución: 
Las tareas pueden pensarse como un árbol (o en realidad un DAG, no queda claro si puede haber 
tareas que dependan de más de una tarea, pero no es relevante para su resolución). 
La solución sale con un DFS en el árbol de tareas que lleve cuenta de las distintas cosas. 
Por cada nodo no visitado, se hace un DFS desde allí, y así con sus hijos no visitados, etc. 
Así podemos calcular recursivamente la paga total de cada nodo (tarea), y además todas las tareas 
que dependen directamente (hijos) o indirectamente de cada tarea. 
Para cada empleado además llevamos la cuenta de las tareas que se le pagan (inicialmente son todas las tareas 
que realiza). 
Durante el DFS, cada vez que se finaliza un nodo X, ahora que sabemos todas las tareas que cuelgan de dicha tarea X, 
podemos quitar estas tareas dependientes D_i de los empleados que realicen la tarea X (porque queremos las tareas de más 
arriba para cada empleado). 
Finalmente, tenemos para cada empleado las tareas que sí se le deben pagar, y las pagas totales de cada tarea. 

////////////////////////////////////////////////////////////////////////

3472:

Descripción: 
Hay N (1 <= N <= 1000) ciudades en un país. Cada una de estas ciudades tiene su propia red para 
comunicación interna con C_i estaciones (1 <= C_i <= 50). Lo que se quiere es armar 
una red de fibra óptica para conectar las ciudades entre sí. 
Está determinado qué ciudades deben conectarse entre sí, y se sabe que entre cada par de 
ciudades habrá un único camino de fibra óptica. 
Para tirar fibra óptica entre un par de ciudades, debe instalarse un router de fibra óptica en cada 
ciudad. Debe instalarse un sólo router en cada ciudad, y el mismo debe ser instalado 
en alguna de las estaciones existentes de dicha ciudad. 
Se pide encontrar la mínima cantidad de fibra óptica necesaria para hacer las conexiones. 

Resolución: 
Las ciudades pueden pensarse como los nodos, del enunciado se deduce que entre ellos se forma un 
árbol (se especifican además las N-1 conexiones para hacer). Dentro de cada nodo tenemos que elegir alguno 
de sus C_i estaciones (puntos en el plano) para que funcione como router de fibra óptica. 
Esto puede resolverse haciendo una dinámica sobre el árbol. Para ellos, recorremos el árbol con un DFS 
(empezando de cualquier nodo, es indistinto). Cada vez que visitamos un nodo s, los vecinos de s 
que visitemos desde s serán los hijos de s. Los casos base de la DP son las hojas de este DFS (allí, para 
cada estación la respuesta es 0). Luego, si s no es una hoja, resolvemos usando las soluciones de sus hijos 
(que ya habrán sido calculadas). 
Para esto, para cada estación i del nodo s, computamos lo mejor que podemos hacer (mínimo uso de cable) si 
elegimos esa estación para s. Fijada una estación en s, simplemente hay que recorrer los hijos de s, y para cada hijo 
j recorrer sus estaciones. Para cada hijo, hay que quedarse con la suma mínima de:
	_la distancia entre la estación i del nodo s y las estacion k del nodo hijo j
	_la solución precalculada de elegir la estació j para el nodo j
Finalmente, la solución de elegir la estación i para el nodo s, es la suma de estos mínimos. 
Para devolver la respuesta, nos quedamos con la mejor soluciones de las estaciones de la ciudad donde empezamos el DFS.

////////////////////////////////////////////////////////////////////////

3473:



////////////////////////////////////////////////////////////////////////

3474:

Descripción: 
Dado N, se desarrolla la secuencia infinita de las palabras de largo i 
(i empieza en 1 y crece infinitamente) con las N primeras letras, en orden 
lexicográfico. 
Por ejemplo, si N=3, una parte de la secuencia empezaría así
ABCAAABACBABBBCCACBCCAAAAABAACABAABBABC...
Dados N y Q queries con números K (1 <= K <= 100000000), 
conseguir la K-ésima letra de la secuencia de N. 

Resolución: 
Si la secuencia es de N, hay N palabras de largo 1 (1*N), N**2 palabras de largo 2 
(2*N**2), N**3 de largo 3 (3*N**3) y así. Dado un K, podemos ir restando estas longitudes 
hasta que sea menor que lo acumulado. Luego sabemos a qué parte de la secuencia pertenece 
la letra que queremos (es decir, sabemos que pertenece a alguna palabra de largo j). 
Usando el resultado K' haberle restado a K las longitudes, y dividiendo por el largo j podemos saber 
a qué palabra de esa sección pertenece. Luego lo que queremos es la i-ésima palabra en base N de largo j. 
Finalmente, la respuesta será el caracter (K' % j) de la palabra. 

////////////////////////////////////////////////////////////////////////

3475:



////////////////////////////////////////////////////////////////////////

3476:



////////////////////////////////////////////////////////////////////////
