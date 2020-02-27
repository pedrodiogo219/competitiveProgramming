typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node;

node * create_node(int val){
  node * my_node = new node;
  my_node->val = val;
  my_node->left = NULL;
  my_node->right = NULL;
  my_node->ht = 1;
  return my_node;
}

void calc_height(node * root){
  int ht_left = 0;
  if(root->left != NULL) ht_left = (root->left)->ht;
  int ht_right = 0;
  if(root->right != NULL) ht_right = (root->right)->ht;

  root->ht = max(ht_left, ht_right) + 1;
}

int calc_balance_factor(node * root){
  int ht_left = 0;
  if(root->left != NULL) ht_left = (root->left)->ht;
  int ht_right = 0;
  if(root->right != NULL) ht_right = (root->right)->ht;

  return ht_left - ht_right;
}

node * insert(node * root,int val)
{

  if(root == NULL){
    root = create_node(val);
    return root;
  }

  if(val <= root->val){
    root->left = insert(root->left, val);
  }
  else{
    root->right = insert(root->right, val);
  }

  calc_height(root);
  int balanceFactor = calc_balance_factor(root);

  if(balanceFactor > 1){ // left cases
    if(calc_balance_factor(root->left) < 0){ //left right case
      node * n1 = root->left;
      node * n2 = n1->right;

      n1->right = n2->left;
      n2->left = n1;
      root->left = n2;
      calc_height(n1);
      calc_height(n2);
      calc_height(root);
    }
    // left left case
    node * n1 = root;
    node * n2 = n1->left;

    n1->left = n2->right;
    n2->right = n1;
    root = n2;

    calc_height(n1);
    calc_height(root);
  }
  else if(balanceFactor < -1){ // right cases
    if(calc_balance_factor(root->right) > 0){ // right left case
      node * n1 = root->right;
      node * n2 = n1->left;

      n1->left = n2->right;
      n2->right = n1;
      root->right = n2;

      calc_height(n1);
      calc_height(n2);
      calc_height(root);
    }
    // right right case
    node * n1 = root;
    node * n2 = root->right;

    n1->right = n2->left;
    n2->left = n1;
    root = n2;

    calc_height(n1);
    calc_height(root);
  }

  return root;
}
