#include <stdio.h>
#include <stdlib.h>

typedef struct link_s{
    struct link_s* next;
    int value;
}link_t;

link_t *new()
{
    link_t *newLink = malloc(sizeof(link_t*));

    if (newLink == NULL)
    {
        exit(EXIT_FAILURE);
    }

    newLink->value = 0;
    newLink->next = NULL;

    return newLink;
}

void addValue(link_t **in_list, int in_newValue)
{
    link_t *addLink = malloc(sizeof(*addLink));
    
    if (*in_list == NULL || addLink == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    addLink->value = in_newValue;
    addLink->next = *in_list;

    *in_list = addLink;
}

link_t* create_list(int* in_list, unsigned int in_size)
{
    link_t *out_list = new();
    
    for (unsigned int i=0; i < in_size; i++)
    {
        addValue(&out_list, in_list[i]);
    }
    
    return out_list;
}

void print_list(link_t *in_list)
{
    if (in_list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while (in_list != NULL)
    {
        printf("%d -> ", in_list->value);
        in_list = in_list->next;
    }
    printf("NULL\n");
}

link_t *reverse(link_t* list)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    link_t *p_list = list;
    link_t *reversed = new();
    
    if (reversed == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    while(p_list->next != NULL)
    {
        addValue(&reversed, p_list->value);
        p_list = p_list->next;
    }
    
    return reversed;
}

link_t *merge_list(link_t *l1, link_t *l2)
{
    
    if ((l1 == NULL) || (l2 == NULL))
    {
        exit(EXIT_FAILURE);
    }
    
    link_t *p_l1 = l1;
    link_t *p_l2 = l2;
    
    link_t *merged = new();
    
    if (merged == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    while ((p_l1->next != NULL) || (p_l2->next != NULL))
    {
        if (p_l1->value > p_l2->value)
        {
            addValue(&merged, p_l1->value);
            p_l1 = p_l1->next;
        }
        else
        {
            addValue(&merged, p_l2->value);
            p_l2 = p_l2->next;
        }
        
    }
    
    //merged = reverse(merged);
    
    return merged;
}

int main()
{
    int src1[4] = {1, 2, 3, 4};
    int src2[3] = {4, 5, 6};
    
    link_t * l1 = create_list(src1, 4);
    link_t * l2 = create_list(src2, 3);
    
    print_list(l1);
    print_list(l2);
    
    link_t * res = merge_list(l1, l2);
    
    print_list(res);
    
    return 0;
}