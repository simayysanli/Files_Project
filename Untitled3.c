#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <locale.h>
#define bufSize 100
#define size 30
#define dictSize 55670


char *temp;
char *dictionary[dictSize]; 
char *textFile[20];
char buf[bufSize];
char *word;
void *rw_file(char*);
void insert(char*);
void findWord();
int letterDistance=3;
int main()
{
	setlocale(LC_ALL, "Turkish");
	int i;
	FILE *fp;//used to read dictionary file
	FILE *fp1;
	char letter[size];
	char a;
	int addr;
	char string[8];
	int letterDistance;
	
	for(i=0;i<dictSize;i++)
	{
		dictionary[i]=(char*)calloc(bufSize,sizeof(char));
	}
	for(i=0;i<30;i++)
	{
		textFile[i]=(char*)calloc(30,sizeof(char));
	}
	/*printf("enter letter distance:");
	scanf("%d",&letterDistance);*/
	fp=fopen("C://Users//asus//Documents//textFile.txt","r");
	if (fp == NULL) {
		printf("Error occured while opening file\n");
		exit(0);
}
	while (fgets(letter,sizeof(letter),fp)!= NULL)
	{
		i=0;
		letter[strlen(letter) - 1] = '\0';
	//	printf("%s\n",letter);
		while(i<30&&textFile[i][0]!='\0')
		{
			i++;
		}
		strcpy(textFile[i],letter);
		printf("%s - %d\n",textFile[i],i);
	}
	//open and read file
	rw_file("C://Users//asus//Documents//kilavuz//A.TXT");
	rw_file("C://Users//asus//Documents//kilavuz//B.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//C.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//Ç.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//D.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//E.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//F.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//G.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//H.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//I.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//Ý.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//J.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//K.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//L.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//M.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//N.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//O.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//Ö.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//P.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//Q.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//R.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//S.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//Þ.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//T.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//U.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//Ü.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//V.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//W.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//Y.TXT");
  	rw_file("C://Users//asus//Documents//kilavuz//Z.TXT");
  	fclose(fp);
  	printf("Programme loading");
  	findWord();
  	
    return 0;
}
void *rw_file(char *filename)
{
	FILE *fp2;
	fp2=fopen(filename,"r");
	if (fp2 == NULL)
	{
		printf("Error occured while opening file\n");
		exit(0);
	}
	while (fgets(buf,sizeof(buf),fp2)!= NULL)//read text until new line
	{
  	
   	buf[strlen(buf) - 1] = '\0';
 //   printf("%s\n", buf);
    insert(buf);

	}
	
	fclose(fp2);
  
}

void insert(char *word)
{
	//printf("burda");
	int i=0;
	while(i<dictSize&&dictionary[i][0]!='\0')
	{
		i++;
	}
	//printf("%s\n",word);
	strcpy(dictionary[i],strlwr(word));
//	printf("%s - %d\n",dictionary[i],i);
}

void findWord(/*char *textFile,char *dictionar*/)
{
	FILE *fp;
	int j,i,k,m;
	int result,count;
	fp=fopen("C://Users//asus//Documents//kilavuz//outputfile.txt","w");
	FILE *fp3;
	fp3=fopen("C://Users//asus//Documents//kilavuz//yedek.txt","w");
	if(fp==NULL){
		printf("dosya acilamadi\n");
	}
for(i=0;i<8;i++)
	{
	//	for(j=0;j<1;j++)
	//	{
		j=0;
		printf("boyut:%d\n",strlen(textFile[i]));
		int isFound =0;
		while((j<dictSize)&& (isFound==0))
		{
			if(strlen(textFile[i])==strlen(dictionary[j]))
			{
				result=strcmp(textFile[i],dictionary[j]);
				
				if(result==0)
				{
					printf("eslesme saglandi\n");
					isFound=1;	
				}
				else //result>0 or result<0
				{
					//isFound=0;
				}
			}
				
			j++;	
		}
	//	}
		
		if (isFound==1){
			fprintf(fp,"%s +\n",textFile[i]);
			
		}
		else 
		{
			
					for(k=0;k<strlen(textFile[i]);k++)
					{
						m=0;
						while((m<strlen(dictionary[j]))&&(textFile[i][k]!='\0')&&(dictionary[j][m]!='\0'))
						{
							if(textFile[i][k]!=dictionary[j][m])
							{
								count++;
							}
							m++;
						}
						
					}
					if(count<=letterDistance)
					{
						FILE *fp3;
						fp3=fopen("C://Users//asus//Documents//kilavuz//yedek.txt","w");
						fprintf(fp3,"%s -\n %s",textFile[i],dictionary[j]);
					}
					printf("eslenmeyen kelime:%s\n",textFile[i]);	
					*/
		}
		}
	//	}
		
		
	}


				

