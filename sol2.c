/*
* Author Name: Warren De Silva
* StudentID: 44912838
* Email: warren.de-silva@students.mq.edu.au
* Date Created: 5-Aug-2018
* Date Updated: 14-Aug-2018
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
 
 struct field {
	 char play[8];
	 int8_t sugar;
	 int8_t voice;
	 uint32_t statement;
	 int16_t skate;
	 bool cast;
	 int16_t health;
	 bool reward;
	 float turn;	 
	 int16_t regret;
	 bool smile;
	 int8_t heart;
	 uint16_t pies;
	 uint64_t chain;
	 double friend;
	 double wrench;
 };	
 
 void main(int argc,char **argv) {
	 
	 //struct field test = {"shelf",-71,'1',0x10F,1,0,0,0,116.093750,1,0,0x2F,1,0576,-0.000887,0.007617};

	FILE *Sample;
	FILE *OUT;
	
	
	if (argc < 2){
		fprintf(stderr, "Usage: the first argument is this program, and the second argument is the binary file you wish to read from. Please do not enter more than one file at a time.\n");
		printf("Exited with error 1: not enough arguments\n");
		exit(1);
	}
	
	Sample = fopen(argv[1], "rb");
	OUT = fopen(argv[2], "wb");
	
	if (Sample == NULL){
		fprintf(stderr, "Error: file %s does not exist\n", argv[1]);
		printf("Exited with error 2: requested file does not exist\n");
		exit(2);
	}

	if (argc > 3) {
        fprintf(stderr, "Error: Too many arguments present in the program\n");
        printf("Exited with with error 3: Too many Arguments\n");
        exit(3);
    }

	if ((argc >= 2) && (argc < 3)) {
		fprintf(stderr, "Error: Doesn't have third argument\n");
		printf("Exit with error 4\n");
		exit(4);
	}
	
	fseek(Sample, 0, SEEK_END);
	int fileSize = ftell(Sample);
	fseek(Sample, 0, SEEK_SET);
	
	int structSize = 59;
	int linesInFile = fileSize/structSize;
	
	struct field *test;
	test = malloc(linesInFile * sizeof(struct field));
	
	
	for (int i = 0; i < linesInFile; i++) {
	
	
		fread(&test[i].play, sizeof(test[i].play), 1, Sample);
		fread(&test[i].sugar, sizeof(test[i].sugar), 1, Sample);
		fread(&test[i].voice, sizeof(test[i].voice), 1, Sample);
		fread(&test[i].statement, sizeof(test[i].statement), 1, Sample);
		fread(&test[i].skate, sizeof(test[i].skate), 1, Sample);
		fread(&test[i].cast, sizeof(test[i].cast), 1, Sample);
		fread(&test[i].health, sizeof(test[i].health), 1, Sample);
		fread(&test[i].reward, sizeof(test[i].reward), 1, Sample);
		fread(&test[i].turn, sizeof(test[i].turn), 1, Sample);
        fread(&test[i].regret, sizeof(test[i].regret), 1, Sample);
        fread(&test[i].smile, sizeof(test[i].smile), 1, Sample);
		fread(&test[i].heart, sizeof(test[i].heart), 1, Sample);
		fread(&test[i].pies, sizeof(test[i].pies), 1, Sample);
		fread(&test[i].chain, sizeof(test[i].chain), 1, Sample);
		fread(&test[i].friend, sizeof(test[i].friend), 1, Sample);
		fread(&test[i].wrench, sizeof(test[i].wrench), 1, Sample);
	 
	 printf("play, sugar, voice, statement, skate, cast, health, reward, turn,
	 regret, smile, heart, pies, chain, friend, wrench\n");
	 
	 printf("%s,%x,%c,%d,%d,%d,%d,%d,%f,%d,%d,%d,%d,%d,%f,%f\n", test.play,
	 test.sugar & 0xff, test.voice, test.statement, test.skate, test.cast,
	 test.health, test.reward, test.turn, test.regret, test.smile, test.heart,
	 test.pies, test.chain, test.friend, test.wrench);
	}

	free(test);
	fclose(Sample);
	fclose(OUT);
	return 0;
	 
 }
