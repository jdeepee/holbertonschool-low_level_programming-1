int op_add(int, int);
int op_sub(int, int);
int op_mul(int, int);
int op_div(int, int);
int op_mod(int, int);

int (*get_op_func(char c))(int, int) {

  int (*op_func[256])(int, int); /* Prototype, we use pointers to assign the correct function */

  int i;
  for (i=0 ; i<256 ; i++) {
  	op_func[i]=0;
  }

  op_func[(unsigned char)'+'] = op_add; /* assign to operator */
  op_func[(unsigned char)'-'] = op_sub;
  op_func[(unsigned char)'*'] = op_mul;
  op_func[(unsigned char)'/'] = op_div;
  op_func[(unsigned char)'%'] = op_mod;

  return op_func[(unsigned char)c];
}
