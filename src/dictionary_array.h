/* Rappresentazione con vettore ordinato
 * si utilizza un vettore con un cursore all'ultima posizone occupata
 * avendo definito una relazione di ordinamento totale <= sulle chiavi,
 * queste si memorizano nel vettore in posizioni contigue e in ordine
 * crescente a partire dalla prima posizione. Per verificare
 * l'appartenenza di un elemento o chiave k, si utilizza la ricerca binaria
 * (dicotomica, logaritmica), si confranta cioè il valore da ricercare k
 * con il valore v che occupa la posizione centrale del vettore e si
 * stabilisce in quale metà continuare la ricerca.
 *
 * Ricerca binaria
 *
 * bool appartiene(tipoelem k, dizionario per riferimento D)
 *     return RICBIN(D.eleenti, k, 1, D.ultimo)
 *
 * bool RICBIN(V:vettore per riferiemnto, k:tipoelem, i:int, j:int)
 *     if(i>j) return false;
 *     else
 *         m=(i+j)/2
 *         if(k=V[m]) return true;
 *         else
 *             return (k<V[m]) ? RICBIN(V,k,i,m-1) : RICBIN(V,k,m+1,j)
 *
 */

#ifndef DICTIONARY_ARRAY_H_
#define DICTIONARY_ARRAY_H_





#endif /* DICTIONARY_ARRAY_H_ */
