#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define HASHSIZE 5

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtable[HASHSIZE];

char *strduplicate(char *s) {
    char *p;
    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}

unsigned hash(char *s) { // unsigned to ensure hashval is non-negative
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }

    return hashval % HASHSIZE;
}

struct nlist *myloopup(char *s) {
    struct nlist *np;

    for (np = hashtable[hash(s)]; np != NULL; np = np -> next) {
        // printf("np: %p, %s: %s\n", np, np->name, np->defn);
        if (strcmp(s, np -> name) == 0) {
            return np;
        }
    }
    return NULL;
}

struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = myloopup(name)) == NULL) { // if string is different, but hash value collide, then a linked list in a stack manner
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np -> name = strduplicate(name)) == NULL) {
            return NULL;
        } 
        hashval = hash(name); 
        printf("hashval = hash(%s) = %u\n", name, hash(name));
        np -> next = hashtable[hashval];
        hashtable[hashval] = np;
    } else {
        free((void *) np -> defn);
    }
    if ((np -> defn = strduplicate(defn)) == NULL) { // it is assgining the defn here!!!
        return NULL;
    }
    // printf("hashtable[0]: %p\n", hashtable[0]);
    printf("hashtable[2]: %s, %p\n", hashtable[2]->defn, hashtable[2]->next);
    if ((hashtable[2]->next) != 0x0) {
        printf("next: %s\n", hashtable[2]->next->defn);
    }
    printf("hashtable[%u] = (%s, %s)\n\n", hashval, np->name, np->defn);
    return np;
}

int undef(char *name) { // remove name entry
    struct nlist *np1, *np2;

    if ((np1 = myloopup(name)) == NULL) { // if not found
        return 1;
    }

    // if found, we should relink the linkned list, hence we need to go through the list from beginning
    // np2 is for previous block, np1 is current block
    for (np1 = np2 = hashtable[hash(name)]; np1 != NULL; np2 = np1, np1 = np1->next) { 
        if (strcmp(name, np1->name) == 0) { // if match
            if (np1 == np2) { // if match at the beginning, entry pointer is: current -> next
                hashtable[hash(name)] = np1->next;
            } else { // if it is in the middle, previous -> next = current -> next
                np2->next = np1->next;
            }
            free(np1->name);
            free(np1->defn);
            free(np1);
            return 0;
        }
    }
    return 0;
}

int main(void) {
    install("given", "chen1");
    install("given", "chen2");
    install("family", "zhao1");
    install("family", "zhao2");
    install("ebmily", "zhao3");
    undef("ebmily");
    printf("%s\n", hashtable[2]->name);
    printf("%s\n", hashtable[2]->next->name);
    printf("%p\n", hashtable[2]->next->next);
    return 0;
}