#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct record{
	char name[50];
	char surname[50];
	char policlinicName[50];
	int id;
	struct record*next;
};
struct record* Add(struct record*head){
	struct record*new_record;
	new_record=(struct record*)malloc(sizeof(struct record));
	printf("Enter the Name :\n");scanf("%s",&new_record->name);
	printf("Enter the surname :\n");scanf("%s",&new_record->surname);
	printf("Enter the policlinic Name :(Orthodontics,Endoscopy,Implant,Cardiology)\n");scanf("%s",&new_record->policlinicName);
	printf("Enter the id :\n");scanf("%d",&new_record->id);
	
	if(head==NULL){
		head=new_record;
		head->next=NULL;
		printf("You added the first pation");
	}
	else{
		new_record->next=head;
		head=new_record;
		printf("Added pation");
	}
	return head;
	
}
struct record* print(struct record*head){
	struct record*control=head;
	while(head!=NULL){
		printf("Name:%s surname:%s policlinic:%s id:%d\n",head->name,head->surname,head->policlinicName,head->id);
		head=head->next;
	}
	head=control;
	return head;
}
struct record* search(struct record*head){
	int ctr;
	printf("1-By name: 2-By surname: 3-By policlinic name:");scanf("%d",&ctr);
	struct record*control=head;
	switch(ctr){
		case 1:
			char Name[50];
			printf("Enter the pation Name:");scanf("%s",&Name);
			while(head!=NULL){
			if(strcmp(head->name,Name)==0){
			printf("Name:%s  Surname:%s policlinicName:%s id:%d",head->name,head->surname,head->policlinicName,head->id);
			break;
			}
			head=head->next;
			}
			break;
		case 2:
			char SurName[50];
			printf("Enter the pation surname:");scanf("%s",&SurName);
			while(head!=NULL){
			if(strcmp(head->surname,SurName)==0){
			printf("Name:%s  Surname:%s policlinicName:%s id:%d",head->name,head->surname,head->policlinicName,head->id);
			break;
			}
			head=head->next;
			}
			break;
		case 3:
			char policlinic[50];
			printf("Enter the pation policlinic name:");scanf("%s",&policlinic);
			while(head!=NULL){
			if(strcmp(head->policlinicName,policlinic)==0){
			printf("Name:%s  Surname:%s policlinicName:%s id:%d",head->name,head->surname,head->policlinicName,head->id);
			break;
			}
			head=head->next;
			}
			break;
		}
	head=control;
	return head;
}
struct record* Delete(struct record*head){
	int ctr;
	printf("1-By name: 2-By surname: 3-By policlinic name:");scanf("%d",&ctr);
	switch (ctr){
		case 1:
			char Name[50];
			printf("Enter the name that you wanna delete:");scanf("%s",&Name);
			if((strcmp(head->name,Name)==0)&&(head->next==NULL)){
			free(head);
			head=NULL;
			printf("You delete the pation by name %s succesfully",Name);
			}
			else if((strcmp(head->name,Name)==0)&&(head->next!=NULL)){
			struct record*tmp=head->next;
			free(head);
			head=tmp;
			printf("You delete the pation by name %s succesfully",Name);
			}
			else{
			struct record*tmp=head;
			struct record*p=head;
			while(tmp->next!=NULL){
			if(strcmp(tmp->name,Name)==0){
			p->next=tmp->next;
			free(tmp);
			printf("You delete the pation by name %s succesfully",Name);
			break;
			}
			p=tmp;
			tmp=tmp->next;
			}
			if(strcmp(tmp->name,Name)==0){
			p->next=NULL;
			free(tmp);
			printf("You delete the pation by name %s succesfully",Name);
			}
			}
			return head;
		case 2:
			char Surname[50];
			printf("Enter the surname that you wanna delete:");scanf("%s",&Surname);
			if((strcmp(head->surname,Surname)==0)&&(head->next==NULL)){
			free(head);
			head=NULL;
			printf("You delete the pation by surname %s succesfully",Surname);
			}
			else if((strcmp(head->surname,Surname)==0)&&(head->next!=NULL)){
			struct record*tmp=head->next;
			free(head);
			head=tmp;
			printf("You delete the pation by surname %s succesfully",Surname);
			}
			else{
			struct record*tmp=head;
			struct record*p=head;
			while(tmp->next!=NULL){
			if(strcmp(tmp->surname,Surname)==0){
			p->next=tmp->next;
			free(tmp);
			printf("You delete the pation by surname %s succesfully",Surname);
			}
			p=tmp;
			tmp=tmp->next;
			}
			if(strcmp(tmp->surname,Surname)==0){
			p->next=NULL;
			free(tmp);
			printf("You delete the pation by surname %s succesfully",Surname);
			}
			}
			return head;	
		case 3:
			char Policlinic[50];
			printf("Enter the Policlinic name that you wanna delete:");scanf("%s",&Policlinic);
			if((strcmp(head->policlinicName,Policlinic)==0)&&(head->next==NULL)){
			free(head);
			head=NULL;
			printf("You delete the pation by policlinic name %s succesfully",Policlinic);
			}
			else if((strcmp(head->policlinicName,Policlinic)==0)&&(head->next!=NULL)){
			struct record*tmp=head->next;
			free(head);
			head=tmp;
			printf("You delete the pation by policlinic name %s succesfully",Policlinic);
			}
			else{
			struct record*tmp=head;
			struct record*p=head;
			while(tmp->next!=NULL){
			if(strcmp(tmp->policlinicName,Policlinic)==0){
			p->next=tmp->next;
			free(tmp);
			printf("You delete the pation by policlinic name %s succesfully",Policlinic);
			}
			p=tmp;
			tmp=tmp->next;
			}
			if(strcmp(tmp->policlinicName,Policlinic)==0){
			p->next=NULL;
			free(tmp);
			printf("You delete the pation by policlinic name %s succesfully",Policlinic);
			}
			}
			return head;
	}	
}
struct record* sortByName(struct record*head){
	char *lst[50]={};
	int counter=0;
	struct record*ctr=head;
	while(head!=NULL){
		lst[counter]=head->name;
		counter+=1;
		head=head->next;
	}
	int lstLen=counter;
	int control=0;
	while(control<lstLen){
		for(int i=0;i<(lstLen-1);i++){
			if(strcmp(lst[i],lst[i+1])>0){
				char *k=lst[i];
				lst[i]=lst[i+1];
				lst[i+1]=k;
			}
		}
		control+=1;
	}
	for(int i=0;i<lstLen;i++){
		printf("%s ",lst[i]);
	}
	printf("  (you sorted the pations by their names succesfully)");
	head=ctr;
	return head;
}
struct record* sortBySurname(struct record*head){
	char *lst[50]={};
	int counter=0;
	struct record*ctr=head;
	while(head!=NULL){
		lst[counter]=head->surname;
		counter+=1;
		head=head->next;
	}
	int lstLen=counter;
	int control=0;
	while(control<lstLen){
		for(int i=0;i<(lstLen-1);i++){
			if(strcmp(lst[i],lst[i+1])>0){
				char *k=lst[i];
				lst[i]=lst[i+1];
				lst[i+1]=k;
			}
		}
		control+=1;
	}
	for(int i=0;i<lstLen;i++){
		printf("%s ",lst[i]);
	}
	printf("  (you sorted the pations by their surnames succesfully)");
	head=ctr;
	return head;
}
struct record* sortByPoliclinicname(struct record*head){
	char *lst[50]={};
	int counter=0;
	struct record*ctr=head;
	while(head!=NULL){
		lst[counter]=head->policlinicName;
		counter+=1;
		head=head->next;
	}
	int lstLen=counter;
	int control=0;
	while(control<lstLen){
		for(int i=0;i<(lstLen-1);i++){
			if(strcmp(lst[i],lst[i+1])>0){
				char *k=lst[i];
				lst[i]=lst[i+1];
				lst[i+1]=k;
			}
		}
		control+=1;
	}
	for(int i=0;i<lstLen;i++){
		printf("%s ",lst[i]);
	}
	printf("  (you sorted the pations by their policlinic names succesfully)");
	head=ctr;
	return head;
}
int main(){
	struct record*head=NULL;
	int choice;
	printf("****Hospital Managment System****\n");
	printf("1 -- Add a new pation:\n");
	printf("2 -- search a pation:\n");
	printf("3 -- Delete a pation:\n");
	printf("4 -- Sort pations by their names:\n");
	printf("5 -- Sort pations by their surnames:\n");
	printf("6 -- Sort pations by their policlinic names:\n");
	printf("7 -- exit\n");
	printf("8 -- Display the pations:\n");
	while(1){
		scanf("%d",&choice);
		switch(choice){
			case 1:head=Add(head);
			break;
			case 2:head=search(head);
			break;
			case 3:head=Delete(head);
			break;
			case 4:head=sortByName(head);
			break;
			case 5:head=sortBySurname(head);
			break;
			case 6:head=sortByPoliclinicname(head);
			break;
			case 7:exit(0);
			case 8:head=print(head);
			break;
			break;
		}
	}
}

