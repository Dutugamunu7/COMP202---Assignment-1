/* Author: Warren De Silva
			warren.de-silva@students.mq.edu.au
	Studentid: 44912838
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

struct field {
	int8_t plantation;
	int end;
	int spiders;
	float person;
	int apparatus;
	bool trail;
	bool reading;
	int32_t plastic;
	int loaf;
	char jelly[8];
	double straw;
	uint64_t fight;
	float rhythm;
	bool nest;
	char religion;
	uint16_t fog;
};

int comp(const void *first, const void *second){
	const struct field *firstS = first; 
	const struct field *secS = second;
	
	
	if (firstS->loaf < secS->loaf){
		return -1;
	} else if (firstS->loaf > secS->loaf) {
		return 1;
	}
	
	else if (firstS->fight < secS->fight){
		return -1;
	} else if (firstS->fight > secS->fight) {
		return 1;
	}
	
	else if (firstS->spiders < secS->spiders){
		return 1;
	} else if (firstS->spiders > secS->spiders) {
		return -1;
	}
	
	else if (firstS->straw < secS->straw){
		return 1;
	} else if (firstS->straw > secS->straw) {
		return -1;
	}
	
	else if (firstS->religion < secS->religion){
		return -1;
	} else if (firstS->religion > secS->religion) {
		return 1;
	}
	
	else if (firstS->plantation < secS->plantation){
		return -1;
	} else if (firstS->plantation > secS->plantation) {
		return 1;
	}
	
	else if (firstS->apparatus < secS->apparatus){
		return 1;
	} else if (firstS->apparatus > secS->apparatus) {
		return -1;
	}
	
	else if (firstS->nest < secS->nest){
		return -1;
	} else if (firstS->nest > secS->nest) {
		return 1;
	}
	
	else if (firstS->fog < secS->fog){
		return -1;
	} else if (firstS->fog > secS->fog) {
		return 1;
	}
	
	else if (firstS->end < secS->end){
		return 1;
	} else if (firstS->end > secS->end) {
		return -1;
	}
	
	else if (firstS->person < secS->person){
		return -1;
	} else if (firstS->person > secS->person) {
		return 1;
	}
	
	else if (firstS->plastic < secS->plastic){
		return -1;
	} else if (firstS->plastic > secS->plastic) {
		return 1;
	}
	
	else if (strcmp(firstS->jelly, secS->jelly) < 0){
		return 1;
	} else if (strcmp(firstS->jelly, secS->jelly) > 0) {
		return -1;
	}
	
	else if (firstS->reading < secS->reading){
		return 1;
	} else if (firstS->reading > secS->reading) {
		return -1;
	}
	
	else if (firstS->rhythm < secS->rhythm){
		return -1;
	} else if (firstS->rhythm > secS->rhythm) {
		return 1;
	}
	
	else if (firstS->trail < secS->trail){
		return 1;
	} else if (firstS->trail > secS->trail) {
		return -1;
	}
	
	return 0;
}

int main(int argc,char **argv) {
	
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
	
	
		fread(&test[i].loaf, sizeof(test[i].loaf), 1, Sample);  //4
		fread(&test[i].fight, sizeof(test[i].fight), 1, Sample); //8
		fread(&test[i].spiders, sizeof(test[i].spiders), 1, Sample); //4
		fread(&test[i].straw, sizeof(test[i].straw), 1, Sample); //8
		fread(&test[i].religion, sizeof(test[i].religion), 1, Sample); //1
		fread(&test[i].plantation, sizeof(test[i].plantation), 1, Sample); //1
		fread(&test[i].apparatus, sizeof(test[i].apparatus), 1, Sample); //4
		fread(&test[i].nest, sizeof(test[i].nest), 1, Sample); //1
		fread(&test[i].fog, sizeof(test[i].fog), 1, Sample); //2
        fread(&test[i].end, sizeof(test[i].end), 1, Sample); //4
        fread(&test[i].person, sizeof(test[i].person), 1, Sample); //4
		fread(&test[i].plastic, sizeof(test[i].plastic), 1, Sample); //4
		fread(&test[i].jelly, sizeof(test[i].jelly), 1, Sample); //8
		fread(&test[i].reading, sizeof(test[i].reading), 1, Sample);	//1	
		fread(&test[i].rhythm, sizeof(test[i].rhythm), 1, Sample); //4
		fread(&test[i].trail, sizeof(test[i].trail), 1, Sample); //1
		
		printf("%d, %d, %d, %f, %x, %d, %d, %d, %d, %s, %f, %lu, %f, %d, %c,
		%u\n", test[i].plantation, test[i].end, test[i].spiders,
		test[i].person, test[i].apparatus, test[i].trail, test[i].reading,
		test[i].plastic, test[i].loaf, test[i].jelly, test[i].straw,
		test[i].fight, test[i].rhythm, test[i].nest, test[i].religion,
		test[i].fog);
		
	}
	
	//Stage 3 work Below
	qsort(test, linesInFile, sizeof(test[0]), comp);
	
	for (int i = 0; i < linesInFile; i++) {
	
		printf("%d, %d, %d, %f, %x, %d, %d, %d, %d, %s, %f, %lu, %f, %d, %c,
		%u\n", test[i].plantation, test[i].end, test[i].spiders,
		test[i].person, test[i].apparatus, test[i].trail, test[i].reading,
		test[i].plastic, test[i].loaf, test[i].jelly, test[i].straw,
		test[i].fight, test[i].rhythm, test[i].nest, test[i].religion,
		test[i].fog);
		
	}
	
	for (int i = 0; i < linesInFile; i++) {

		fwrite(&test[i].loaf, sizeof(test[i].loaf), 1, OUT);  //4
		fwrite(&test[i].fight, sizeof(test[i].fight), 1, OUT); //8
		fwrite(&test[i].spiders, sizeof(test[i].spiders), 1, OUT); //4
		fwrite(&test[i].straw, sizeof(test[i].straw), 1, OUT); //8
		fwrite(&test[i].religion, sizeof(test[i].religion), 1, OUT); //1
		fwrite(&test[i].plantation, sizeof(test[i].plantation), 1, OUT); //1
		fwrite(&test[i].apparatus, sizeof(test[i].apparatus), 1, OUT); //4
		fwrite(&test[i].nest, sizeof(test[i].nest), 1, OUT); //1
		fwrite(&test[i].fog, sizeof(test[i].fog), 1, OUT); //2
        fwrite(&test[i].end, sizeof(test[i].end), 1, OUT); //4
        fwrite(&test[i].person, sizeof(test[i].person), 1, OUT); //4
		fwrite(&test[i].plastic, sizeof(test[i].plastic), 1, OUT); //4
		fwrite(&test[i].jelly, sizeof(test[i].jelly), 1, OUT); //8
		fwrite(&test[i].reading, sizeof(test[i].reading), 1, OUT);	//1	
		fwrite(&test[i].rhythm, sizeof(test[i].rhythm), 1, OUT); //4
		fwrite(&test[i].trail, sizeof(test[i].trail), 1, OUT); //1
		
	}

	
	free(test);
	fclose(Sample);
	fclose(OUT);
	return 0;
}
