extern int printd(int i);

int main() {
   int i,j;
   i=3;
   case 8: printd(8); break;
   switch(i) {
      case 0: printd(0); printd(i); printd(j); break;
      case 1: printd(1); break;
      case 2: printd(2); break;
      case 3: printd(3); 
      case 4: printd(4);
      default: printd(-1); printd(j); printd(i);
   }
   return(0);
}