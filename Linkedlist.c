#include<stdio.h>
#include <stdlib.h>

struct node {// node isminde bir yapý oluþturuyoruz.
	int data;//yapýmýzda verileri tutacagýmýz deðiþkenimizi belirliyoruz.
	struct node*next;//bir sonraki düðümü tutacak pointer ýmýzý tanýmlýyoruz. !!Dikkat edelim yapýmýzla pointer tanýmlýyoruz.
};

void printList(struct node* q){//parametre olarak head ý verilen listenin elenmanlarýný ekrana basar.

	while (q!=NULL)//verilen parametremiz NULL olasýyakadar döngümüz dönüyor.
	{
		printf("%d - ", q->data);//ekrana basýyoruz.
		q = q->next;//birsonraki düðümü q deðiþkenine atýyoruz. 
	}

}

void insertHead(struct node **q, int RefData)//parametre olarak aldýðýmýz q yapýsý ** ile çaðýrlýyor çünkü head deðiþicek.
{
	struct node *tmp = (struct node*)malloc(sizeof(struct node));//bir düðüm oluþturuyoruz.
	
	tmp->next = *q;//oluþturduðumuz düðümün next ine parametre olarak gelen q yu atýyoruz.
	tmp->data = RefData;//parametre olarak gelen datayý oluþturduðumuz tmp düðümüne atýyoruz.
	(*q) = tmp;//temp imizi head olarak tanýmlýyoruz. artýk head tmp imiz.
	
}
void insertLast(struct node *q, int RefData)//head ýmýzý tek * ile çagýrýyoruz head deðiþmeyeceði için ** a gerek yok.
{
	struct node *tmp = (struct note*)malloc(sizeof(struct node));//Ekliyeceðimiz eleman için düðüm oluþturuyoruz.
	tmp->data = RefData;//oluþturdugumuz düðüme parametre olarak gelen veriyi atýyoruz.
	struct node *last = (struct note*)malloc(sizeof(struct node));// sonuncu düðümü bulmak için yeni bir düðüm oluþturuyoruz.
	last = q;//oluþturdugumuz düðüme parametre olarak gelen q yu atýyoruz.
	while (last->next!=NULL)//last düðümümüz next i null olan yani sonuncu düðüme kadar dönücek ve sonuncu düðümü elde etmiþ olucaz.
	{
		last=last->next;//her döngü döndüðünde bi sonraki düðüme geçiyor.
	}
	last->next = tmp;//son düðümün next ine yukarda oluþturduðumuz düðümü atýyoruz.
	tmp->next = NULL;//oluþturdugumuz düðümün next ini null olarak atýyoruz.
}

void insertBetween(struct node **q, int RefData)//parametre olarak gelen düðümün sað tarafýna ekleme yapar.
{
	struct node *tmp = (struct node*)malloc(sizeof(struct node));//yeni ekliyeceðimiz eleman için düðüm oluþturup ram den yer ayýrýyoruz.

	tmp->next = (*q)->next;//parametre olarak gelen düðümün nextini oluþturdugumuz düðümün nextine atýyoruz.
	(*q)->next = tmp;//parametre olarak gelen düðümün next ine oluþturduðumuz düðümü atýyoruz.
	tmp->data = RefData;//oluþturdugumuz düðüme parametre olarak gelen datayý atýyoruz.
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
void deleteNode(struct Node **head_ref, int key)//head de silinebileceði için head ýmýzý ** ile alýyoruz.ve silinicek veriyi parametere olarak alýyoruz.
{
	
	struct Node* temp = *head_ref, *prev;//silmek için bir düðüm oluþturup parametre olarak gelen düðümü atýyoruz.

	if (temp != NULL && temp->data == key)//eðer temp boþ deðilse ve datasý parametere olarak gelen key ile uyuþuyorsa silme iþlemi yapýcaz.
	{
		*head_ref = temp->next;   //head deðiþtiriliyor.
		free(temp);//temp imizi ramden temizliyoruz.               
		return;//fonksiyondan çýkýyoruz.
	}

	while (temp != NULL && temp->data != key)//temp null oluncaya kadar veya key i elmanlar arasýnda bulasýya kadar döngümüz dönüyor.
	{
		prev = temp;
		temp = temp->next;
	}


	if (temp == NULL) return;//temp null ise verilen key e uygun key elemaný yok demek oluyor ve fonksiyondan çýkýyor.


	prev->next = temp->next;//aradan elemansildiðimizde baðlantý kopmamasý için sileceiðimiz elemandan önceki elemanýn next ine sildiðimiz elemanýn next ini atýyoruz.

	free(temp);  //elemanýmýzý siliyoruz.
}

int main()
{
	//aðagýda oluþturduðumuz yapýmýzdan düðümler oluþturup isimlerini veriyoruz. ve bellekten yer açýyoruz.
	struct node *head = (struct node*)malloc(sizeof(struct node));
	struct node *second = (struct node*)malloc(sizeof(struct node));
	struct node *third = (struct node*)malloc(sizeof(struct node));


	head->next = second;//head düðümünün nexti second u gösteriyoruz.
	second->next = third;//secod un nexti third i gösteriyor
	third->next = NULL;//thirdden sonra þimdilik düðüm olmadýgý için next ine null atýyoruz.
	// yapýmýz head->next(second)->next(third)->next(null) þeklinde oluyor. parantez içleri anlamanýz içim kod yazarken kullanýlmýyor.

	head->data = 2;//head düðümümüze veri atamasý yapýyoruz.
	second->data = 5;
	third->data = 10;

	insertHead(&head, 4);
	insertBetween(&head->next, 6);
	insertLast(head, 31);
	
	deleteNode(&head, 31);
   
	printList(head);//head düðümünü oluþturduðumuz fonksiyona gönderip ekrana bastýrýyoruz.
	getchar();//konsol ekranýnýn kapanmamasý için yazdýðýmýz kod.
	return 0;
}