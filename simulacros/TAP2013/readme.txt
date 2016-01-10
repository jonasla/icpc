http://www.spoj.com/problems/TAP2013A/
http://www.spoj.com/problems/TAP2013B/
http://www.spoj.com/problems/TAP2013C/
http://www.spoj.com/problems/TAP2013D/
http://www.spoj.com/problems/TAP2013E/
http://www.spoj.com/problems/TAP2013F/
http://www.spoj.com/problems/TAP2013G/
http://www.spoj.com/problems/TAP2013H/
http://www.spoj.com/problems/TAP2013I/
http://www.spoj.com/problems/TAP2013J/

////////////////////////////////////////////////////////////////////////

Problema A: 



////////////////////////////////////////////////////////////////////////

Problema B:

problema fácil. Simplemente hay que hacer varios chequeos para cada candidato (ver que tengas más votos que todos los otros, en cuyo caso continuar viendo si tiene 45% o más del porcentaje de los votos, o si tiene 40% o más y le saca 10% o más de diferencia a todos los demás). 

////////////////////////////////////////////////////////////////////////

Problema C: 

el grafo es un DAG. El problema es calcular un par de caminos máximos en el DAG (se resuelve con un par de dinámicas simples). Primero se hace una pasada de atrás para adelante para calcular la cantidad de caminos que hay hasta el último nodo (el caso base es en el último nodo, donde la cantidad de caminos es 1). Luego para cada nodo hacia atrás, la cantidad de caminos hasta el final es la sumatoria de la cantidad de caminos de los nodos que sean adyacentes a este (que estarán todos más adelante, porque es un DAG y lo estamos recorriendo al revés). Ojo que puede haber multi ejes. Calculada la cantidad de caminos para cada nodo hasta el final (llamado 'level'), se hace otra pasada también de atrás para adelante, para calcular el 'maxLevel' de cada nodo (que es lo que el problema define como 'level of alternatives'). El 'maxLevel' para cada nodo es la suma entre su 'level' y el máximo entre los 'maxLevel' de sus adyacentes (nuevamente los adyacentes estarán todos más adelante porque es un DAG y lo recorremos hacia atrás, de modo que su 'maxLevel' ya fue calculado). Finalmente, la respuesta es el 'maxLevel' del primer nodo. 

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



////////////////////////////////////////////////////////////////////////

Problema I: 



////////////////////////////////////////////////////////////////////////

Problema J: 



////////////////////////////////////////////////////////////////////////
