#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct nlist *install(char *, char *);
struct nlist *lookup(char *);
char *strdup2(char *);
void put_hashtab(void);
void undef(char *);

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

int main()
{
    install("masatora", "a");
    install("masatora", "b");
    install("anothoer", "c");
    put_hashtab();
    undef("masatora");
    put_hashtab();
    return 0;
}

void undef(char *name)
{
    struct nlist *np;
    struct nlist *next;
    if ((np = lookup(name)) == NULL) {
        printf("not found");
    } else {
        if ((next = np->next) == NULL) {
            free((void *) np->name);
            free((void *) np->defn);
            free((void *) np->next);
            free((void *) np);
        } else {
            np->name = next->name;
            np->defn = next->defn;
            np->next = next->next;
            free((void *) next->name);
            free((void *) next->defn);
            free((void *) next->next);
            free((void *) np);
        }
    }
}

# define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup2(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free((void *) np->defn);
    if ((np->defn = strdup2(defn)) == NULL)
        return NULL;
    return np;
}

char *strdup2(char *s)
{
    char *p;

    p = (char *) malloc(strlen(s)+1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}

void put_hashtab()
{
   for (int i=0; i < HASHSIZE; i++) {
       if (hashtab[i] != NULL)
           printf("%s: %s\n", hashtab[i]->name, hashtab[i]->defn);
   }
}
