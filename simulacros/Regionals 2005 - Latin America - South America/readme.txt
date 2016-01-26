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



////////////////////////////////////////////////////////////////////////

3473:



////////////////////////////////////////////////////////////////////////

3474:



////////////////////////////////////////////////////////////////////////

3475:



////////////////////////////////////////////////////////////////////////

3476:



////////////////////////////////////////////////////////////////////////
