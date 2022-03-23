#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
	if(argc != 2){
		printf("Usage: %s nome_cartella\n", argv[0]);
		return 1;
	}

	char ls[] = { "ls " };
	strcat(ls, argv[1]);
	strcat(ls, " > ls.txt");
	system(ls);
	
	char files[500][1024];
	char riga[20];
	FILE *fptr = fopen("ls.txt", "r");
	
	if(!fptr){
		printf("Could not open folder\n");
		return 1;	
	}

	int n_files = 0;
	char tmp[1024];
	
	while(fgets(riga, sizeof(riga), fptr)){
		while(riga[strlen(riga)-2] != '3' && riga[strlen(riga)-3] != 'p' && riga[strlen(riga)-4] != 'm' && riga[strlen(riga)-5] != '.'){
			fgets(tmp, sizeof(riga), fptr);
			strcat(riga, tmp);
		}
		if(riga[strlen(riga)-1] == '\n'){
			riga[strlen(riga)-1] = '\0';
		}
		printf("%s\n", riga);
		strcpy(files[n_files], riga);
		n_files++;
	}	

	fclose(fptr);

	fopen("new.html", "w");
	if(!fptr){
		printf("Could not create new.html\n");
		return 1;
	}
	
	fprintf(fptr, "<!DOCTYPE html>\n<html>\n\t<head>\n\t\t<meta charset=\"UTF-8\">\n\t\t<link rel=\"stylesheet\" type\"text/css\" href=\"style.css\"/>\n\t\t<title>basato</title>\n\t</head>\n\n");
	
		fprintf(fptr, "\t<a>%s</a><br>\n\t<audio controls loop preload=\"none\">\n\t\t<source src=\"./mp3/%s\" type=\"audio/mp3\">\n\t</audio><br>\n\n", files[0], files[0]);

	for(int i = 1; i < n_files; i++){
		fprintf(fptr, "\t<a>%s</a><br>\n\t<audio controls loop preload=\"none\">\n\t\t<source src=\"./mp3/%s\" type=\"audio/mp3\">\n\t</audio><br>\n\n", files[i], files[i]);
	}
	
	fprintf(fptr, "</html>");

	fclose(fptr);

	system("mv new.html index.html");
	
	return 0;
}
