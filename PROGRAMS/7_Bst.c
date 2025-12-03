#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *lchild, *rchild;
};
struct node* insert(struct node* root, int data)
{
    struct node *t1, *t2, *t;
    t1 = root;
    t2 = (struct node*)0;
    while (t1 != (struct node*)0 && t1->data != data)
    {
        t2 = t1;
        if (data < t1->data)
            t1 = t1->lchild;
        else
            t1 = t1->rchild;
    }
    if (t1 == (struct node*)0)
    {
        t = (struct node*)malloc(sizeof(struct node));
        t->data = data;
        t->lchild = t->rchild = (struct node*)0;
        if (root == (struct node*)0)
            root = t;
        else
        {
            if (data < t2->data)
                t2->lchild = t;
            else
                t2->rchild = t;
        }
        printf("%d is inserted", data);
    }
    else
        printf("Duplicate!!");
    return root;
}
void inorder(struct node* root)
{
    if (root != (struct node*)0)
    {
        inorder(root->lchild);
        printf("%d\t", root->data);
        inorder(root->rchild);
    }
}
struct node* search(struct node* root, int item)
{
    struct node* t = root;
    while (t != (struct node*)0 && t->data != item)
        if (item < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    return t;
}
struct node* delete(struct node* root, int item)
{
    struct node *t1, *t, *par, *Sucpar, *suc;
    t = root;
    par = (struct node*)0;
    while (t != (struct node*)0 && t->data != item)
    {
        par = t;
        if (item < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    if (t == (struct node*)0)
        printf("%d not found \n", item);
    else
    {
        if (t->lchild == (struct node*)0 && t->rchild == (struct node*)0)
        {
            if (par == (struct node*)0)
                root = (struct node*)0;
            else if (t->data > par->data)
                par->rchild = (struct node*)0;
            else
                par->lchild = (struct node*)0;
        }
        else if ((t->lchild == (struct node*)0) || (t->rchild == (struct node*)0))
        {
            if (par == (struct node*)0)
                root = (t->rchild == (struct node*)0 ? t->lchild : t->rchild);
            else if (t->data > par->data)
                par->rchild = (t->lchild == (struct node*)0 ? t->rchild : t->lchild);
            else
                par->lchild = (t->lchild == (struct node*)0 ? t->rchild : t->lchild);
        }

        else
        {
            Sucpar = t;
            suc = t->rchild;

            while (suc->lchild != 0)
            {
                Sucpar = suc;
                suc = suc->lchild;
            }

            t->data = suc->data;

            if (suc->data < Sucpar->data)
                Sucpar->lchild = suc->rchild;
            else
                Sucpar->rchild = suc->rchild;
            t = suc;
        }
        free(t);
    }
    return root;
}
int main()
{
    struct node *t1, *t = (struct node*)0;
    int data, opt;
    do
    {
        printf("\n1.Insert\n");
        printf("2.Display\n");
        printf("3.Search\n");
        printf("4.Delete\n");
        printf("5.Exit\n");
        printf("Option");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter data:");
            scanf("%d", &data);
            t = insert(t, data);
            break;
        case 2:
            inorder(t);
            break;
        case 3:
            printf("Item to search:");
            scanf("%d", &data);
            t1 = search(t, data);
            if (t1 == (struct node*)0)
                printf("Not found\n");
            else
                printf("Item found\n");
            break;
        case 4:
            printf("Item to delete:");
            scanf("%d", &data);
            t = delete(t, data);
            break;
        case 5:
            exit(0);
        }
    }
    while (1);
    return 0;
}
