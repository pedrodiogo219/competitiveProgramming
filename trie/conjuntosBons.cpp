#include<bits/stdc++.h>
using namespace std;



char keys[100010][105];


struct node{
	struct node * filhos[26];
	int is_end;
	
	node(){
		for(int i=0;i<26;i++){
			filhos[i] = NULL;
		}
	}
};


node * cria_node(){
	
	node * novo_node = new node;
	
	novo_node->is_end = 0; 
	return novo_node;
}

void insere(node* root, char s[]){
	
	node * atual = root;
	
	for(int i=0; i < strlen(s); i++){
		if( atual -> filhos[ s[i] - 'a' ] == NULL ){
			atual -> filhos[ s[i] - 'a' ] = cria_node();
		}
		
		atual = atual -> filhos[ s[i] - 'a' ];
	}
	
	atual->is_end++;
}

void printa( node * root, int nivel){
	for(int i=0;i<26;i++){
		if(root->filhos[i] != NULL){
			printf("to indo pro node: %c  is_end:%d  nivel: %d\n", 'a'+i, root->filhos[i]->is_end, nivel+1);
			printa(root->filhos[i], nivel+1);
			printf("voltei um nivel\n");	
		}
	}
	
}

bool eh_bom(node * root){
	if( root->is_end == 0 ){
		for(int i=0;i<26;i++){
			if( root->filhos[i]!=NULL && !eh_bom(root->filhos[i]) ){
				return false;
			}
		}
		
		return true;
	}
	else{
		if(root->is_end > 1) return false;
	
		for(int i=0;i<26;i++){
			if(root->filhos[i]!= NULL){
				return false;
			}
		}	
		return true;
	}	
}


int main(){

	int n;
	
	while(scanf("%d", &n) && n!=0){
		
		node * raiz = cria_node();
		for(int i=0;i<n;i++){
			scanf("%s", keys[i]);
			insere(raiz, keys[i]);
		}
		//printa(raiz, 0);
		bool res = eh_bom(raiz);
		
		if(res) printf("Conjunto Bom\n");
		else printf("Conjunto Ruim\n");
		
	}
	
			

}
