#include "../../includes/push_swap.h"
#include "../../includes/operations.h"
#include "../../includes/stack.h"

// --- FASE 1: EL EMBUDO (De A para B) ---
void push_chunks(t_stack *a, t_stack *b)
{
    int chunk_size;
    int limit;

    // Para 100 números, bloques de 20 son perfectos.
    chunk_size = 20; 
    limit = chunk_size;

    while (a->size > 0)
    {
        // Si el índice del número de arriba entra en nuestro grupo actual
        if (a->top->index < limit)
        {
            pb(a, b, 1);
			// LA MAGIA: Si el número es de la mitad "pequeña" del grupo, lo mandamos al fondo de B
            if (b->top->index < (limit - (chunk_size / 2)))
                rb(b, 1);
            // Si ya pasamos todos los de este bloque, ampliamos el límite para el siguiente
            if (b->size >= limit)
                limit += chunk_size;
        }
        else
        {
            // Si es muy grande para este grupo, damos vuelta a la noria
            ra(a, 1);
        }
    }
}

// --- EL RADAR DEL FRANCOTIRADOR ---
// Busca en qué posición exacta está el número más grande de la pila B
int get_max_index_pos(t_stack *b)
{
    t_node  *current;
    int     max_index;
    int     max_pos;
    int     current_pos;

    current = b->top;
    max_index = -1;
    max_pos = 0;
    current_pos = 0;

    while (current != NULL)
    {
        if (current->index > max_index)
        {
            max_index = current->index;
            max_pos = current_pos;
        }
        current_pos++;
        current = current->next;
    }
    return (max_pos); // Nos devuelve si está en la posición 0, 5, 10...
}

// --- FASE 2: EL FRANCOTIRADOR (De B para A) ---
void push_back_to_a(t_stack *a, t_stack *b)
{
    int max_pos;

    while (b->size > 0)
    {
        max_pos = get_max_index_pos(b);

        // Si está en la mitad superior, el camino más corto es hacia arriba
        if (max_pos <= b->size / 2)
        {
            while (max_pos > 0)
            {
                rb(b, 1);
                max_pos--;
            }
        }
        // Si está en la mitad inferior, el camino más corto es por abajo
        else
        {
            while (max_pos < b->size)
            {
                rrb(b, 1);
                max_pos++;
            }
        }
        // ¡Disparo! El número más grande actual vuelve a su casa
        pa(a, b, 1);
    }
}

// --- LA FUNCIÓN PRINCIPAL ---
void chunk_sort(t_stack *a, t_stack *b)
{
    push_chunks(a, b);
    push_back_to_a(a, b);
}