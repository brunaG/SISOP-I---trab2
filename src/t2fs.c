
/**
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/t2fs.h"
#include "../include/apidisk.h"

/*-----------------------------------------------------------------------------
Fun��o:	Informa a identifica��o dos desenvolvedores do T2FS.
-----------------------------------------------------------------------------*/
int identify2 (char *name, int size) {
	char *name_group = "Bruna Gonzaga - 00252743\nLuma Beserra - CODIGO AQUI\0";
	if(size < strlen(name_group)){
		printf("espao nao suficiente!\n");
		return -1;
	}
	strncpy(name, name_group, strlen(name_group)+1);
}

/*-----------------------------------------------------------------------------
Fun��o:	Formata logicamente uma parti��o do disco virtual t2fs_disk.dat para o sistema de
		arquivos T2FS definido usando blocos de dados de tamanho
		corresponde a um m�ltiplo de setores dados por sectors_per_block.
-----------------------------------------------------------------------------*/
int format2(int partition, int sectors_per_block) {
	return -1;
}

/*-----------------------------------------------------------------------------
Fun��o:	Monta a parti��o indicada por "partition" no diret�rio raiz
-----------------------------------------------------------------------------*/
int mount(int partition) {
	return -1;
}

/*-----------------------------------------------------------------------------
Fun��o:	Desmonta a parti��o atualmente montada, liberando o ponto de montagem.
-----------------------------------------------------------------------------*/
int unmount(void) {
	return -1;
}

/*-----------------------------------------------------------------------------
Fun��o:	Fun��o usada para criar um novo arquivo no disco e abr�-lo,
		sendo, nesse �ltimo aspecto, equivalente a fun��o open2.
		No entanto, diferentemente da open2, se filename referenciar um
		arquivo j� existente, o mesmo ter� seu conte�do removido e
		assumir� um tamanho de zero bytes.
-----------------------------------------------------------------------------*/
FILE2 create2 (char *filename) {
	return -1;
}

/*-----------------------------------------------------------------------------
Fun��o:	Fun��o usada para remover (apagar) um arquivo do disco.
-----------------------------------------------------------------------------*/
int delete2 (char *filename) {
	return -1;
}

/*-----------------------------------------------------------------------------
Fun��o:	Fun��o que abre um arquivo existente no disco.
-----------------------------------------------------------------------------*/
FILE2 open2 (char *filename) {
	return -1;
}

/*-----------------------------------------------------------------------------
Fun��o:	Fun��o usada para fechar um arquivo.
-----------------------------------------------------------------------------*/
int close2 (FILE2 handle) {
	return -1;
}

/*-----------------------------------------------------------------------------
Fun��o:	Fun��o usada para realizar a leitura de uma certa quantidade
		de bytes (size) de um arquivo.
-----------------------------------------------------------------------------*/
int read2 (FILE2 handle, char *buffer, int size) {
	return -1;
}

/*-----------------------------------------------------------------------------
Fun��o:	Fun��o usada para realizar a escrita de uma certa quantidade
		de bytes (size) de  um arquivo.
-----------------------------------------------------------------------------*/
int write2 (FILE2 handle, char *buffer, int size) {
	return -1;
}

/*-----------------------------------------------------------------------------
Fun��o:	Fun��o que abre um diret�rio existente no disco.
-----------------------------------------------------------------------------*/
DIR2 opendir2 (char *pathname) {
	return -1;
}

/*-----------------------------------------------------------------------------
Fun��o:	Fun��o usada para ler as entradas de um diret�rio.
-----------------------------------------------------------------------------*/
int readdir2 (DIR2 handle, DIRENT2 *dentry) {
	return -1;
}

/*-----------------------------------------------------------------------------
Fun��o:	Fun��o usada para fechar um diret�rio.
-----------------------------------------------------------------------------*/
int closedir2 (DIR2 handle) {
	return -1;
}

/*-----------------------------------------------------------------------------
Fun��o:	Fun��o usada para criar um caminho alternativo (softlink)
-----------------------------------------------------------------------------*/
int sln2 (char *linkname, char *filename) {
	return -1;
}

/*-----------------------------------------------------------------------------
Fun��o:	Fun��o usada para criar um caminho alternativo (hardlink)
-----------------------------------------------------------------------------*/
int hln2(char *linkname, char *filename) {
	return -1;
}



