#include <stdio.h>
#include <stdlib.h>

typedef struct rep rep;
typedef struct node node;

typedef struct node {
    int value;
    rep *repptr;
    node *next;
} node;

typedef struct rep {
    node *head;
    node *tail;
} rep;

typedef struct nodaddr {
    int key;
    node *obj_node_ptr;
    struct nodaddr *next;
} nodaddr;

nodaddr *ndr = NULL;

void makeset(int a)
{
    nodaddr *t = malloc(sizeof(nodaddr));
    rep *newset = malloc(sizeof(rep));
    node *n = malloc(sizeof(node));

    n->value = a;
    n->repptr = newset;
    n->next = NULL;

    newset->head = newset->tail = n;

    t->obj_node_ptr = n;
    t->key = a;
    t->next = ndr;
    ndr = t;
}

rep* find(int x)
{
    nodaddr *t = ndr;
    while (t != NULL && t->key != x)
        t = t->next;
    if (t == NULL)
        return NULL;
    return t->obj_node_ptr->repptr;
}

void unionset(int key1, int key2)
{
    rep *set1 = find(key1);
    rep *set2 = find(key2);

    if (set1 == NULL || set2 == NULL) {
        printf("\nOne or both elements do not exist.\n");
        return;
    }

    if (set1 == set2) {
        printf("\n%d and %d are already in the same set.\n", key1, key2);
        return;
    }

    node *temp = set2->head;
    while (temp != NULL) {
        temp->repptr = set1;
        temp = temp->next;
    }

    set1->tail->next = set2->head;
    set1->tail = set2->tail;

    free(set2);

    printf("\nUnion completed for %d and %d\n", key1, key2);
}

void display(int a)
{
    rep *r = find(a);
    if (r == NULL) {
        printf("\nElement %d not found.\n", a);
        return;
    }

    node *t = r->head;
    printf("\nSet containing %d: ", a);
    while (t != NULL) {
        printf("%d ", t->value);
        t = t->next;
    }
    printf("\n");
}

int main()
{
    int data, data1, data2, opt;

    while (1) {
        printf("\n1. MakeSet");
        printf("\n2. FindSet");
        printf("\n3. UnionSet");
        printf("\n4. Display Set");
        printf("\n5. Exit");
        printf("\nEnter your option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                makeset(data);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &data);
                if (find(data) != NULL)
                    printf("Reference of set containing %d is %p\n", data, find(data));
                else
                    printf("Element not found.\n");
                break;

            case 3:
                printf("\nFirst element: ");
                scanf("%d", &data1);
                printf("Second element: ");
                scanf("%d", &data2);
                unionset(data1, data2);
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &data);
                display(data);
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid option\n");
        }
    }

    return 0;
}
