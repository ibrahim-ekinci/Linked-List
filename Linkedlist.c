#include<stdio.h>
#include <stdlib.h>

struct node {// node isminde bir yap� olu�turuyoruz.
	int data;//yap�m�zda verileri tutacag�m�z de�i�kenimizi belirliyoruz.
	struct node*next;//bir sonraki d���m� tutacak pointer �m�z� tan�ml�yoruz. !!Dikkat edelim yap�m�zla pointer tan�ml�yoruz.
};

void printList(struct node* q){//parametre olarak head � verilen listenin elenmanlar�n� ekrana basar.

	while (q!=NULL)//verilen parametremiz NULL olas�yakadar d�ng�m�z d�n�yor.
	{
		printf("%d - ", q->data);//ekrana bas�yoruz.
		q = q->next;//birsonraki d���m� q de�i�kenine at�yoruz. 
	}

}

void insertHead(struct node **q, int RefData)//parametre olarak ald���m�z q yap�s� ** ile �a��rl�yor ��nk� head de�i�icek.
{
	struct node *tmp = (struct node*)malloc(sizeof(struct node));//bir d���m olu�turuyoruz.
	
	tmp->next = *q;//olu�turdu�umuz d���m�n next ine parametre olarak gelen q yu at�yoruz.
	tmp->data = RefData;//parametre olarak gelen datay� olu�turdu�umuz tmp d���m�ne at�yoruz.
	(*q) = tmp;//temp imizi head olarak tan�ml�yoruz. art�k head tmp imiz.
	
}
void insertLast(struct node *q, int RefData)//head �m�z� tek * ile �ag�r�yoruz head de�i�meyece�i i�in ** a gerek yok.
{
	struct node *tmp = (struct note*)malloc(sizeof(struct node));//Ekliyece�imiz eleman i�in d���m olu�turuyoruz.
	tmp->data = RefData;//olu�turdugumuz d���me parametre olarak gelen veriyi at�yoruz.
	struct node *last = (struct note*)malloc(sizeof(struct node));// sonuncu d���m� bulmak i�in yeni bir d���m olu�turuyoruz.
	last = q;//olu�turdugumuz d���me parametre olarak gelen q yu at�yoruz.
	while (last->next!=NULL)//last d���m�m�z next i null olan yani sonuncu d���me kadar d�n�cek ve sonuncu d���m� elde etmi� olucaz.
	{
		last=last->next;//her d�ng� d�nd���nde bi sonraki d���me ge�iyor.
	}
	last->next = tmp;//son d���m�n next ine yukarda olu�turdu�umuz d���m� at�yoruz.
	tmp->next = NULL;//olu�turdugumuz d���m�n next ini null olarak at�yoruz.
}

void insertBetween(struct node **q, int RefData)//parametre olarak gelen d���m�n sa� taraf�na ekleme yapar.
{
	struct node *tmp = (struct node*)malloc(sizeof(struct node));//yeni ekliyece�imiz eleman i�in d���m olu�turup ram den yer ay�r�yoruz.

	tmp->next = (*q)->next;//parametre olarak gelen d���m�n nextini olu�turdugumuz d���m�n nextine at�yoruz.
	(*q)->next = tmp;//parametre olarak gelen d���m�n next ine olu�turdu�umuz d���m� at�yoruz.
	tmp->data = RefData;//olu�turdugumuz d���me parametre olarak gelen datay� at�yoruz.
}
int valueList(struct node * head)
{
	int count = 0;
	while (head->next!=NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}
void insertToKey(struct node *q, int RefData,int key)
{
	struct node *tmp = (struct node*)malloc(sizeof(struct node));
	int count = 0;
	while (q->data!=key)
	{
		
		q = q->next;
		if (count==valueList(q))
		{
			printf("Verilen key bulunamadi \n");
			return;
		}
		count++;
	}
	if (q->data == key)
	{
		insertBetween(&q, RefData);

	/*	tmp->next = q->next;
		tmp->data = RefData;
		q->next = tmp;*/
	}

}
void deleteNode(struct Node **head_ref, int key)//head de silinebilece�i i�in head �m�z� ** ile al�yoruz.ve silinicek veriyi parametere olarak al�yoruz.
{
	
	struct Node* temp = *head_ref, *prev;//silmek i�in bir d���m olu�turup parametre olarak gelen d���m� at�yoruz.

	if (temp != NULL && temp->data == key)//e�er temp bo� de�ilse ve datas� parametere olarak gelen key ile uyu�uyorsa silme i�lemi yap�caz.
	{
		*head_ref = temp->next;   //head de�i�tiriliyor.
		free(temp);//temp imizi ramden temizliyoruz.               
		return;//fonksiyondan ��k�yoruz.
	}

	while (temp != NULL && temp->data != key)//temp null oluncaya kadar veya key i elmanlar aras�nda bulas�ya kadar d�ng�m�z d�n�yor.
	{
		prev = temp;
		temp = temp->next;
	}


	if (temp == NULL) return;//temp null ise verilen key e uygun key eleman� yok demek oluyor ve fonksiyondan ��k�yor.


	prev->next = temp->next;//aradan elemansildi�imizde ba�lant� kopmamas� i�in silecei�imiz elemandan �nceki eleman�n next ine sildi�imiz eleman�n next ini at�yoruz.

	free(temp);  //eleman�m�z� siliyoruz.
}

int main()
{
	//a�ag�da olu�turdu�umuz yap�m�zdan d���mler olu�turup isimlerini veriyoruz. ve bellekten yer a��yoruz.
	struct node *head = (struct node*)malloc(sizeof(struct node));
	struct node *second = (struct node*)malloc(sizeof(struct node));
	struct node *third = (struct node*)malloc(sizeof(struct node));


	head->next = second;//head d���m�n�n nexti second u g�steriyoruz.
	second->next = third;//secod un nexti third i g�steriyor
	third->next = NULL;//thirdden sonra �imdilik d���m olmad�g� i�in next ine null at�yoruz.
	// yap�m�z head->next(second)->next(third)->next(null) �eklinde oluyor. parantez i�leri anlaman�z i�im kod yazarken kullan�lm�yor.

	head->data = 2;//head d���m�m�ze veri atamas� yap�yoruz.
	second->data = 5;
	third->data = 10;

	insertHead(&head, 4);
	insertBetween(&head->next, 6);
	insertLast(head, 31);
	
	deleteNode(&head, 31);
   
	printList(head);//head d���m�n� olu�turdu�umuz fonksiyona g�nderip ekrana bast�r�yoruz.
	getchar();//konsol ekran�n�n kapanmamas� i�in yazd���m�z kod.
	return 0;
}