#include "utils.h"
#include "stdlib.h"

#define m 3


typedef struct b_tree{
	
	bool is_full;

	bool is_root;

	struct b_tree *parent;
	
	int keys[m];
	
	int length;

	struct b_tree *gate[m+1];

	int content;

}b_tree;



void pretty_print(b_tree *node){
	printf("----------\n");
	printf("is_full: %d\n", node->is_full);
	printf("is_root: %d\n", node->is_root);
	printf("all keys: ");
	test(node->keys, node->length);
	printf("length content: %d %d\n", node->length, node->content);
	printf("----------\n");
}


void select_insert(int array[], int length, int x){
	int sentior = x;
	int k = 0;
	for(;k < length; k++){
		if(array[k] > x){
			std::swap(sentior, array[k++]);
			break;
		}
	}
	for(;k < length+1;k++){
		std::swap(sentior, array[k]);
	}
}


b_tree *search(b_tree *root, int x){
	int p = -1;
	for(int i = 0;i < root->length;i++){
		if(root->keys[i] == x){
			return root;
		}
		if(root->keys[i] > x){
			p = i;
			break;
		}
	}
	if(p == -1){
		p = root->length;
	}

	if(root->content > p){
		return search(root->gate[p], x);
	}
	else{
		return root;
	}
}


b_tree *Build(){
	b_tree *tree = (b_tree *)malloc(sizeof(b_tree));
	tree->length = 0;
	tree->content = 0;
	tree->is_root = false;
	tree->is_full = false;
	return tree;
}


void Append(b_tree *root, int x){
	select_insert(root->keys, root->length++, x);
}

void Mount(b_tree *root, b_tree *node){
	root->gate[root->content++] = node;
	node->parent = root;
}



void Split(b_tree **root){
	b_tree *father;

	if((*root)->is_root){
		father = Build();
		father->is_root = true;
	}
	else{
		father = (*root)->parent;
		father->content--;
	}
	
	Append(father, (*root)->keys[m/2]);

	b_tree *left = Build();	

	b_tree *right = Build();


	for(int i = 0;i < m/2; i++){
		left->keys[i] = (*root)->keys[i];
		left->length++;
	}
	
	if((*root)->is_full){	
		int i;
		for(i = 0; i < (m+1) / 2; i++){
			left->gate[i] = (*root)->gate[i];	
			left->gate[i]->parent = left;
			left->content++;
		}
		int tmp = i;
		for(;i<(*root)->content;i++){
			right->gate[i-tmp] = (*root)->gate[i];
			right->gate[i-tmp]->parent = right;
			right->content++;
		}
	}


	for(int j = m/2 +1;j < m;j++){
		int tmp = j - m/2 -1;
		right->keys[tmp] = (*root)->keys[j];
		right->length++;
	}

	Mount(father, left);	

	Mount(father, right);
	
	if(father->content == ((father->length)+1)){
		father->is_full = true;
	}

	*root = father;
	
	if((*root)->length >= m){
		Split(root);
	}

}


void Insert(b_tree **root, int x){

	printf("%p\n", *root);

	b_tree *p = search(*root, x);

	Append(p, x);

	if(p->length >= m){
		Split(&p);
	}
	if(p->is_root){
		*root = p;
	}

	printf("%p %p\n", *root, p);

}


void delete_keys(b_tree *p, int x){
	bool flag = false;
	for(int i = 0;i < p->length;i++){
		if(flag){
			if(i+1 < p->length){
				p->keys[i] = p->keys[i+1];
			}
		}

		if(p->keys[i] == x){
			p->keys[i] = p->keys[i+1];
			flag = true;
		}
	}
	p->length--;
}


void simple_delete(b_tree *p, int x){
	delete_keys(p, x);
}


void delete_leaf(b_tree *leaf, int x){
	

}


b_tree *check_around(b_tree *p, int x){
	int k;
	for(int i = 0;i < p->length;i++){
		if(p->keys[i] == x){
			k = i;
			break;
		}
	}

	if(p->content > k){
		return p->gate[k];
	}
	else{
		return NULL;
	}

}


bool view(b_tree *p, int x){
	for(int i = 0;i < p->length;i++){
		if(p->keys[i] == x){
			return true;
		}
	}
	return false;
}


int Delete(b_tree **root, int x){
	
	b_tree *p = search(*root, x);

	if(!view(p, x)){
		printf("KEYS:%d  NOT IN B-TREE!\n", x);
		printf("DELETE ABORT!\n");
		return 1;		
	}

	if(p->length - 1 > m/2 ){
		simple_delete(p, x);
		return 0;
	}

	if(p->content == 0){
		delete_leaf(p, x);
		return 0;
	}
	else{
		
		b_tree *brother = check_around(p, x);
		if(brother!=NULL){
			simple_delete(p, x);
			Append(p, brother->keys[brother->length-1]);
			delete_leaf(brother, brother->keys[brother->length-1]);
		}

			
	}




}


void test(b_tree *node){
	for(int i = 0;i < node->length;i++)
		printf("%d ", node->keys[i]);
	printf("\n");
}


void Show(b_tree *root){
	test(root);
	printf("&root root root->parent:%p %p %p\n", &root, root, root->parent);
	for(int i = 0;i < root->content;i++)
		Show(root->gate[i]);
}


b_tree *get_sample(){
	b_tree *new_tree = Build();

	new_tree->is_root = true;

	int a[10] = {3,1, 4, 5,6, 8, 9, 11, 35,17};

	for(int i = 0;i < 10;i++){
		Insert(&new_tree, a[i]);
		printf("---------\n");
		Show(new_tree);
	}

	return new_tree;
}

int main(){
	
	b_tree *btree = get_sample();

	printf("Done!\n");

	printf("%p\n", btree);

	printf("%p\n", btree->gate[0]->parent);

	printf("%p\n", btree->gate[1]->parent);

	pretty_print(btree);

	pretty_print(btree->gate[0]);

	pretty_print(btree->gate[1]);

	pretty_print(btree->gate[0]->gate[0]);

	pretty_print(btree->gate[0]->gate[1]);

	pretty_print(btree->gate[1]->gate[0]);

	pretty_print(btree->gate[1]->gate[1]);


	Show(btree);
	
	return 0;
}

