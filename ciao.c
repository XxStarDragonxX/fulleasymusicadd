#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
	if(argc != 4){
		printf("Usage: %s nome_cartella max_name_lenght(be very generous if special char are present) max_files_number\n", argv[0]);
		return 1;
	}
	
	int max_name_lenght = atoi(argv[2]);
	int max_files_number = atoi(argv[3]);

	char ls[] = { "ls " };
	strcat(ls, argv[1]);
	strcat(ls, " > ls.txt");
	system(ls);
	
	char files[max_files_number][max_name_lenght];
	char riga[max_name_lenght];
	FILE *fptr = fopen("ls.txt", "r");
	
	if(!fptr){
		printf("Could not open folder\n");
		return 1;	
	}

	int n_files = 0;
	int i = 0;	
	while((riga[i] = getc(fptr)) != EOF){
		if(riga[i] == '\n')
			if(riga[i-1] == '3')
				if(riga[i-2] == 'p')
					if(riga[i-3] == 'm')
						if(riga[i-4] == '.'){
							riga[i-4] = '\0';
							strcpy(files[n_files], riga);
							n_files++;
							i = -1;
						}
		i++;
	}

	fclose(fptr);

	fptr = fopen("new.html", "w");
	if(!fptr){
		printf("Could not create new.html\n");
		return 1;
	}
	fprintf(fptr, "<!DOCTYPE html>\n<html>\n\t<head>\n\t\t<meta charset=\"UTF-8\">\n\t\t<link rel=\"stylesheet\" type\"text/css\" href=\"style.css\"/>\n\t\t<title>basato</title>\n\t</head>\n\n");
	
		fprintf(fptr, "\t<a>%s</a><br>\n\t<audio controls loop preload=\"none\">\n\t\t<source src=\"./mp3/%s.mp3\" type=\"audio/mp3\">\n\t</audio><br>\n\n", files[0], files[0]);

	for(int i = 1; i < n_files; i++){
		fprintf(fptr, "\t<a>%s</a><br>\n\t<audio controls loop preload=\"none\">\n\t\t<source src=\"./mp3/%s.mp3\" type=\"audio/mp3\">\n\t</audio><br>\n\n", files[i], files[i]);
	}

	
	
	fprintf(fptr, "\t<div class=\"email\">Se vuoi aggiungere una canzone mandami l'mp3 a <a href=\"mailto: fuffi@manuel.ws\">fuffi@manuel.ws</a><br> e io decidero se metterla o no</div>\n</html>");

	fclose(fptr);

	system("mv new.html index.html");
	
	return 0;
}
