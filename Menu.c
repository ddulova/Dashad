#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "List.c"
static struct BDHEAD *head;

void PrintMenu(char menuT[],int selecRow){
	int done = 1;
	char c;
	struct BDITEM *pt,*l;
	int num;
while(done){
	if(strcmp(menuT,"StartMenu")==0){
	int MaxRows = 2;
	system("clear");
	if(selecRow == 0)	printf("\e[31mНовая база данных\e[0m\n" ); else printf("Новая база данных\n" );
	if(selecRow == 1)	printf("\e[31mЗагрузить\e[0m\n" ); else printf("Загрузить\n" );
	if(selecRow == 2)	printf("\e[31mВыйти\e[0m\n"); else printf("Выйти\n");
	scanf("%s",&c);
	//scanf("%c",&c);
	switch(c){
	case 'w': 
		if(selecRow == MaxRows) selecRow = 0; else selecRow++;
		break;
	case 's': 
		if(selecRow == 0) selecRow = MaxRows; else selecRow--;
		break;
	case '1': 
		head = CreateBD(head);
		done = 0;
		PrintMenu("MainMenu",0);
		break;
	case '2': 
		system("clear");
		FILE *fp;
		char *name = "save.dat";
		fp = fopen(name, "r");
		head = CreateBD(head);
		int co = 0;
  		while (!feof(fp)){
  			co++;
  		 pt = malloc(sizeof(struct BDITEM));
  		 fread(pt, sizeof(struct BDITEM),  1, fp);
  		 pt->next=0;
  		 AddLast(head,pt);
  		};
		fclose(fp);
		printf("%d\n",&co );
		scanf("%d\n",&co);		
		done = 0;
		PrintMenu("MainMenu",0);
		break;
	case '3': 
		done = 0;
		break;
	case '\n': 
		switch(selecRow){
		case 0: 
			head = CreateBD(head);
			done = 0;
			PrintMenu("MainMenu",0);
			break;
		case 1: 
			system("clear");
			FILE *fp;
			char *name = "save.dat";
			fp = fopen(name, "r");
			head = CreateBD(head);
			int co = 0;
  			while (!feof(fp)){
  				co++;
  			 pt = malloc(sizeof(struct BDITEM));
  			 fread(pt, sizeof(struct BDITEM),  1, fp);
  			 pt->next=0;
  			 AddLast(head,pt);
  			};
			fclose(fp);
			printf("%d\n",&co );
			scanf("%d\n",&co);		
			done = 0;
			PrintMenu("MainMenu",0);
			break;
		case 2: 

			break;
		}
	break;
	}

	}
	if(strcmp(menuT,"MainMenu")==0){
		printf("%d\n",(*head).count );
	int MaxRows = 5;
	system("clear");
	if(selecRow == 0)	printf("\e[31mСоздать новую запить\e[0m\n" ); else printf("Создать новую запить\n" );
	if(selecRow == 1)	printf("\e[31mСохранить\e[0m\n" ); else printf("Сохранить\n" );
	if(selecRow == 2)	printf("\e[31mВывести\e[0m\n"); else printf("Вывести\n");
	if(selecRow == 3)	printf("\e[31mУдалить\e[0m\n"); else printf("Удалить\n");
	if(selecRow == 4)	printf("\e[31mИзменить\e[0m\n"); else printf("Изменить\n");
	if(selecRow == 5)	printf("\e[31mВыйти\e[0m\n"); else printf("Выйти\n");
	scanf("%s",&c);
	//scanf("%c",&c);
	switch(c){
		case 'w': 
	if(selecRow == MaxRows) selecRow = 0; else selecRow++;
		break;
				case 's': 
	if(selecRow == 0) selecRow = MaxRows; else selecRow--;
		break;
	case '1': 
		system("clear");
		struct BDITEM *item;
		item = malloc(sizeof(struct BDITEM));
		printf("Введите ФИО заказчика\n");
		scanf("%s", &item->FIO);
		printf("Введите стоимость заказа\n");
		scanf("%d", &item->Price);
		printf("Введите скидку\n");
		scanf("%d", &item->Sale);
		printf("Введите адрес доставки\n");
		scanf("%s", &item->Adress);
		item->next =0;
		head = AddLast(head,item);
		done = 0;
		PrintMenu("MainMenu",0);
		break;
	case '2': 
		system("clear");
		FILE *fp;
		char *name = "save.dat";
		fp = fopen(name, "wb");
		pt = head->first;
  		while (pt != NULL) {
  		 fwrite(pt, sizeof(struct BDITEM),  1, fp);
   		 pt = pt->next; // переход к следующему узлу
  		};
		fclose(fp);
		done = 0;
		PrintMenu("MainMenu",0);
		break;
	case '3': 
		system("clear");
		pt = head->first;
		//struct BDHEAD h = *head;
		//int count = h.count;
		printf("|ФИО заказчика|стоимость|скидка|адрес доставки|\n");
  		while(pt != NULL) {
    	printf("|%13s|%9d|%6d|%14s|\n",&pt->FIO,pt->Price,pt->Sale,&pt->Adress);
    	pt = pt->next; // переход к следующему узлу
  		}
		char b;
		scanf("%s",&b);
		if(b == '1') {done=0; PrintMenu("MainMenu",0);}
		break;
	case '4': 
		printf("Введите номер которого вы хотите удалить\n");
		scanf("%d",&num);
		head = DelNum(head,num);
		done = 0;
		PrintMenu("MainMenu",0);
		break;
	case '5': 
		printf("Введите номер которого вы хотите изменить\n");
		scanf("%d",&num);
		head = EditNum(head,num);
		done = 0;
		PrintMenu("MainMenu",0);	
		done = 0;
		break;
	case '6': 
		pt = head->first;
		struct BDITEM *p;
		while(pt != NULL) {
			p = pt;
			free(p);
    		pt = pt->next; // переход к следующему узлу
  		}
		done = 0;
		break;
	case '\n': 
	switch(selecRow){
			case 0: 

			break;
			case 1: 

			break;
			case 2: 

			break;
			case 3: 

			break;
		}
		break;
	}

	}
		
}

}

