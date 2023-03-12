#include <stdio.h>
#include <stdlib.h> // for exit function used by uthash
#include "uthash.h"
#include "ast.h"

struct List {
    int scope;
    struct List *next; //Previous List w.r.t Scope
    struct SymTab *symTab;
};

struct SymTab {
    char *symbolName;    //questa è la mia chiave
    enum SymbolType symbolType;
    enum DataType dataType;
    enum DataType returnType;
    char *funcName; //nome della funzione a cui a appartiene il parametro
    union ValueOper valueOper;
    UT_hash_handle hh;    //comando che rende la struct hashable. Chiamato hh come suggerito dalla documentazione
};

//Gestione delle tabelle
struct List *createList(int scope, struct List *next);   //crea lista
struct List *deleteList(struct List *symList);      //cancella lista
struct SymTab *findSymtab(struct List *symList, char *symbolName); //Ricerca symble table all'interno della lista

//Gestione dei simboli
struct SymTab *createSym(char *symbolName, struct List *list, enum SymbolType symbolType, enum DataType dataType, enum DataType returnType, char *funcName, union ValueOper valueOper);
struct SymTab *findSym(struct List *symList, char *symbolName);

struct List *createList(int scope, struct List *next) {
    struct SymTab *symTab = NULL;   //uthash richiede di inizializzarlo a null
    struct List *list = (struct List*) malloc(sizeof(struct List));

    list->symTab = symTab;
    list->next = next;
    list->scope = scope;
    return list;
}

struct List *deleteList(struct List *symList) {   //più che cancellare la lista, cancella tutte le symtab al suo interno

    struct SymTab *sym;
    struct SymTab *temp;
    struct List *l = symList;
    HASH_ITER(hh, l->symTab, sym, temp)
    HASH_DEL(l->symTab, sym); //hash table ovvero la symtab, puntatore alla struct che vogliamo rimuovere
    free(sym);   //opzionale

//uthash rimuove solo la struct dalla hash table, non libera lo spazio in memoria. Quello è opzionale
//in seguito a HASH_DEL cambia il puntatore alla tabella che prima puntava al primo oggetto aggiunto. Questo se cancello il primo oggetto
//HASH_ITER è un costrutto che si espande in un ciclo for iterando su tutte le symtab della lista 

}

struct SymTab *findSymtab(struct List *symList, char *symbolName) {
    struct SymTab *sym;
    struct List *l = symList;
    while (l != NULL) {
        sym = findSym(l, symbolName);
        if (sym != NULL) {
            return sym;
        }
        l = l->next;
    }
}



//aggiunge una symbol table con simbolo alla lista 
struct SymTab *createSym(char *symbolName, struct List *list, enum SymbolType symbolType, enum DataType dataType, enum DataType returnType, char *funcName, union ValueOper valueOper) {
    struct SymTab *sym;
    sym = findSym(list, symbolName);
    if(sym == NULL) {
        sym = (struct SymTab*) malloc(sizeof(struct SymTab));
        sym->symbolName = symbolName;
        sym->symbolType = symbolType;
        sym->dataType = dataType;
        sym->returnType = returnType;
        sym->funcName = funcName;
        sym->valueOper = valueOper;

        HASH_ADD_STR(list->symTab, symbolName, sym);  // hash table lista, chiave che identifica il simbolo, tabella puntatore struct da aggiungere
    } else {
        printf("\n Error: Symbol %s already exists\n", symbolName);
    }
}

struct SymTab *findSym(struct List *symList, char *symbolName) {
    struct SymTab *sym;
    HASH_FIND_STR(symList->symTab, symbolName, sym);  //hash table lista, puntatore alla chiave che cerco, puntatore alla struct con la chiave cercata
    return sym; //puntatore alla symbol table cercata
    if (sym == NULL) {
        printf("\n Error: Symbol %s not found \n", symbolName);
        return NULL;
    } else {
        return sym;
    }
}