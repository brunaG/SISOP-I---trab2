
/**
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/t2fs.h"
#include "../include/apidisk.h"
#include "../include/t2disk.h"
#include "../include/bitmap2.h"

#define SUCSESS 0
#define ERROR -1

typedef struct {
    FILE2 file;
    int vago;
} ARQUIVO;

typedef struct {
    void *dados;
    struct nodoLista *ant;
    struct nodoLista *prox;
}LISTA;

boolean started = false;
void carrega_superbloco();
void inicializador();
boolean estaVago();
struct t2fs_superbloco *superBlock;
ARQUIVO arquivos[50];
LISTA diretorios;

void carrega_superbloco(){

     superBlock = malloc(sizeof(struct t2fs_superbloco));

    char buffer[SECTOR_SIZE];
    if (read_sector(0, buffer) != 0)
        return;

    int index = 0;
    // id
    strcpy(superBlock->id, buffer);
    superBlock->id[4] = 0;
    index += 4;

    //version
    superBlock->version = buffer[index] | buffer[index+1] << 8;
    index += 2;

    //superblockSize
    superBlock->superblockSize = buffer[index] | buffer[index+1] << 8;
    index += 2;

    //freeBlocksBitmapSize
    superBlock->freeBlocksBitmapSize = buffer[index] | buffer[index+1] << 8;
    index += 2;

    //freeInodeBitmapSize
    superBlock->freeInodeBitmapSize = buffer[index] | buffer[index+1] << 8;
    index += 2;

    //inodeAreaSize
    superBlock->inodeAreaSize = buffer[index] | buffer[index+1] << 8;
    index += 2;

    //blockSize
    superBlock->blockSize = buffer[index] | buffer[index+1] << 8;
    index += 2;

    //diskSize -  quantidade total de blocos na particao
    superBlock->diskSize = buffer[index] | buffer[index+1] << 8| buffer[index+2] << 16 | buffer[index+3] << 24;
    index += 4;

    //Checksum*
	//(DWORD)buffer[10] + (DWORD)buffer[11] * 256 + (DWORD)buffer[12] * 65536 + (DWORD)buffer[13] * 16777216;

}

void inicializador(){
    carrega_superbloco();
    started = true;
    diretorios = NULL;
    for (i = 0; i < 50; i++) {
        arquivos[i].vago = ERRO;
    }
}

boolean estaVago() {
    int count = 0;

    for (int i = 0; i < 50; i++) {
        if (arquivos[i].vago == ERRO) {
            count++;
        }
    }

	if (count > 0){
		return false;
	}

    return true;
}

boolean validaCaminho(char caminho[]) {
	//tratar esse método
    return true;
}

/*-----------------------------------------------------------------------------
Função:	Informa a identificação dos desenvolvedores do T2FS.
-----------------------------------------------------------------------------*/
int identify2 (char *name, int size) {
	char *name_group = "Bruna Gonzaga - 00252743\nLuma Beserra - 00268612\0";
	if(size < strlen(name_group)){
		printf("espaço nao suficiente!\n");
		return -1;
	}
	strncpy(name, name_group, strlen(name_group)+1);
}

/*-----------------------------------------------------------------------------
Função:	Formata logicamente uma partição do disco virtual t2fs_disk.dat para o sistema de
		arquivos T2FS definido usando blocos de dados de tamanho
		corresponde a um múltiplo de setores dados por sectors_per_block.
-----------------------------------------------------------------------------*/
int format2(int partition, int sectors_per_block) {
	return -1;
}

/*-----------------------------------------------------------------------------
Função:	Monta a partição indicada por "partition" no diretório raiz
-----------------------------------------------------------------------------*/
int mount(int partition) {
	return -1;
}

/*-----------------------------------------------------------------------------
Função:	Desmonta a partição atualmente montada, liberando o ponto de montagem.
-----------------------------------------------------------------------------*/
int unmount(void) {
	return -1;
}

/*-----------------------------------------------------------------------------
Função:	Função usada para criar um novo arquivo no disco e abrí-lo,
		sendo, nesse último aspecto, equivalente a função open2.
		No entanto, diferentemente da open2, se filename referenciar um
		arquivo já existente, o mesmo terá seu conteúdo removido e
		assumirá um tamanho de zero bytes.
-----------------------------------------------------------------------------*/
FILE2 create2 (char *filename) {
	char filename2[200];

    strcpy(filename2, filename);

	if (!started){
        inicializador();
    }
    

    if (estaVago() && validaCaminho(filename2) && fileExists(filename2, &regR, &regM, &regAvo) == MISSING_FILE) {

	}

	return ERROR;
}

/*-----------------------------------------------------------------------------
Função:	Função usada para remover (apagar) um arquivo do disco.
-----------------------------------------------------------------------------*/
int delete2 (char *filename) {
	
	if (!started){
        inicializador();
    }
	
	return -1;
}

/*-----------------------------------------------------------------------------
Função:	Função que abre um arquivo existente no disco.
-----------------------------------------------------------------------------*/
FILE2 open2 (char *filename) {
	
	if (!started){
        inicializador();
    }
	
	return -1;
}

/*-----------------------------------------------------------------------------
Função:	Função usada para fechar um arquivo.
-----------------------------------------------------------------------------*/
int close2 (FILE2 handle) {
	return -1;
}

/*-----------------------------------------------------------------------------
Função:	Função usada para realizar a leitura de uma certa quantidade
		de bytes (size) de um arquivo.
-----------------------------------------------------------------------------*/
int read2 (FILE2 handle, char *buffer, int size) {
	
	if (!started){
        inicializador();
    }
	
	return -1;
}

/*-----------------------------------------------------------------------------
Função:	Função usada para realizar a escrita de uma certa quantidade
		de bytes (size) de  um arquivo.
-----------------------------------------------------------------------------*/
int write2 (FILE2 handle, char *buffer, int size) {
	
	if (!started){
        inicializador();
    }
	
	return -1;
}

/*-----------------------------------------------------------------------------
Função:	Função que abre um diretório existente no disco.
-----------------------------------------------------------------------------*/
DIR2 opendir2 (char *pathname) {
	
	if (!started){
        inicializador();
    }
	
	return -1;
}

/*-----------------------------------------------------------------------------
Função:	Função usada para ler as entradas de um diretório.
-----------------------------------------------------------------------------*/
int readdir2 (DIR2 handle, DIRENT2 *dentry) {
	
	if (!started){
        inicializador();
    }
	
	return -1;
}

/*-----------------------------------------------------------------------------
Função:	Função usada para fechar um diretório.
-----------------------------------------------------------------------------*/
int closedir2 (DIR2 handle) {
	
	if (!started){
        inicializador();
    }
	
    /* if (diretoriosAbertos == NULL) {
        return ERROR;
    } 
	else {
        while (diretoriosAbertos->prox != NULL) {
            if (((ODIN *)diretoriosAbertos->dados)->handle == handle) {
                diretoriosAbertos = removeLista(diretoriosAbertos, i);
                diretoriosAbertos = getFirstNodeLista(diretoriosAbertos);
                return OK;
            } else {
                diretoriosAbertos = diretoriosAbertos->prox;
                i++;
            }
        }
		
        if (((ODIN *)diretoriosAbertos->dados)->handle == handle) {
            diretoriosAbertos = removeLista(diretoriosAbertos, i);
            diretoriosAbertos = getFirstNodeLista(diretoriosAbertos);
            return OK;
        }
		
		diretoriosAbertos = getFirstNodeLista(diretoriosAbertos);
        return ERROR;
    } */
	
	return ERROR;
}

/*-----------------------------------------------------------------------------
Função:	Função usada para criar um caminho alternativo (softlink)
-----------------------------------------------------------------------------*/
int sln2 (char *linkname, char *filename) {

    int slink;
    slink = symlink(filename,linkname);
    if (slink == -1);
	return ERROR;

}

/*-----------------------------------------------------------------------------
Função:	Função usada para criar um caminho alternativo (hardlink)
-----------------------------------------------------------------------------*/
int hln2(char *linkname, char *filename) {

    int hlink;
    hlink = link(filename,linkname);
    if (hlink == -1);
        return ERROR;
}



