struct BDITEM
{
char *FIO;
int Price;
int Sale;
char *Adress;
struct BDITEM *next;
};
struct BDHEAD
{
	struct	BDITEM *first;
	int count;
};

struct BDHEAD *CreateBD(struct BDHEAD *HEAD){
HEAD = malloc(sizeof(struct BDHEAD));
HEAD->first = 0;
HEAD->count =0;
return HEAD;
}
struct BDHEAD *AddLast(struct BDHEAD *HEAD,struct BDITEM *item){
	struct BDITEM *pt,*p;
	if(HEAD->count == 0){
		HEAD->first = malloc(sizeof(struct BDITEM));
			HEAD->first = item;
			HEAD->first->next = 0;
			HEAD->count = 1;
	}else{
  pt = HEAD->first;
  do {
    p = pt;
    pt = pt->next; // переход к следующему узлу
  } while (pt != 0);
	p->next= item;
	HEAD->count++;
	}
return HEAD;
}
struct BDHEAD *DelNum(struct BDHEAD *HEAD,int Num){
	struct BDITEM *pt,*p;
	pt = HEAD->first;
	if(Num == 0){
		p =	HEAD->first->next;
		HEAD->first = p;
	}else{
  for(int i=0;i<Num;i++) {

    p = pt;
    pt = pt->next; // переход к следующему узлу
    } 
	p->next = pt->next;
	}
return HEAD;
}
struct BDHEAD *EditNum(struct BDHEAD *HEAD,int Num){
	struct BDITEM *pt,*p;
	pt = HEAD->first;
		struct BDITEM *item;
	item = malloc(sizeof(struct BDITEM));
	printf("Введите ФИО заказчика\n");
	scanf("%s",&item->FIO);
	printf("Введите стоимость заказа\n");
	scanf("%d",&item->Price);
	printf("Введите скидку\n");
	scanf("%d",&item->Sale);
	printf("Введите адрес доставки\n");
	scanf("%s",&item->Adress);
	if(Num == 0){
		p =	HEAD->first->next;
		item->next =p;
		HEAD->first = item;
	}else{
  for(int i=0;i<Num;i++) {

    p = pt;
    pt = pt->next; // переход к следующему узлу
    } 
    item->next = pt->next;
	p->next = item;
	}
return HEAD;
}